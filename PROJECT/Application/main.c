/*
 * main.c
 *
 *  Created on: 10/02/2024
 *      Author: salah salah mohamed
 */

#define F_CPU 16000000UL // Define the clock frequency as 16MHz

// Include necessary libraries
#include <util/delay.h>
/* UTILIES_LIB*/
#include "../Utilies/STD_TYPES.h"
#include "../Utilies/BIT_MATH.h"
#include "../Utilies/ATMEGA32_REG.h"
/* MCAL */
#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/ADC/ADC_interface.h"
#include "../MCAL/EXTI/EXTI_interface.h"
#include "../MCAL/GI/GI_interface.h"
#include "../MCAL/TMR0/TMR0_interface.h"
#include "../MCAL/TMR0/TMR0_config.h"
#include "../MCAL/TMR1/TMR1_interface.h"
#include "../MCAL/TMR2/TMR2_interface.h"
#include "../MCAL/TMR2/TMR2_config.h"
#include "../MCAL/TWI/TWI_interface.h"
/* HAL */
#include "../HAL/LED/LED_interface.h"
#include "../HAL/SSD/SSD_interface.h"
#include "../HAL/SSD/SSD_Config.h"
#include "../HAL/DCM/DCM_interface.h"
#include "../HAL/HTR/HTR_interface.h"
#include "../HAL/LM35/LM35_interface.h"
#include "../HAL/EEPROM/EEPROM_interface.h"

//Defining Constants
#define SETTING_MODE 0
#define NORMAL_MODE 1
#define ON 1
#define OFF 0
#define MAX_TEMP 75
#define MIN_TEMP 35

//Declare Global Variables
u8 Temp;
u8 Temparr[10] = {0};
u8 Tempindex;
u8 SET_TEMP;
u8 Display_TEMP;
u8 heat = 0;
u8 mode = NORMAL_MODE;
u8 state = OFF;
static u16 ctcCounter2 = 0;

//Function Prototypes
void TempSenseInit(void);
u8 TempAvg(void);
void systemOn(void);
void systemOFF(void);

//MAIN
int main()
{
	//System initialization
	LED_init();
	GI_enable();
	ADC_init();
	LM35_init();
	HTR_init();
	DCM_init();
	SSD_init();
	TMR0_init();
	EEPROM_init();
	TMR0_setCompareMatchValue(249);
	TMR2_init();
	TMR2_setCompareMatchValue(249);
	EXTI_enable(EXTI_INT0,EXTI_FALLING_EDGE); //External Interrupt Responsible for System State (ON or OFF)
	systemOFF();


	while (1)
	{

	//During Setting Mode
	if (SETTING_MODE == mode && state == ON)
	{
		/*
		 *  Toggle the SSD
		 * Display the Change in the setting Temperature
		 */
		SSD_toggleState();
		SSD_displayMultibleNum(Display_TEMP);
		_delay_ms(1000);
	}

	//Comparing Temperatures

	if((Temp >= (SET_TEMP + 5)) && state == ON) //Above Set Temperature by 5 or more degrees
	{
		/*
		 * Turn On DC Motor (Cooler)
		 * Turn on LED
		 */
		DCM_on(CW);
		DCM_ctrlSpeed(100);
		LED_on();
	}
	else if((Temp <= (SET_TEMP - 5)) && state == ON) //Bellow Set Temperature by 5 or more degrees
	{
		HTR_ON();
		heat = 1;
	}
	else //Within acceptable range
	{
		//Turn of Heater, Cooler and LED
		 DCM_off();
		 LED_off();
		 HTR_OFF();
	}
	}


	return 0;
}

//Function to initialize the temperature array
void TempSenseInit(void)
{
	for (u8 i = 0; i < 10; i++)
	{
		LM35_tempSense(&Temparr[i]);
	}
}

/*
 * Function to calculate the average temperature from the values
 * stored in the Temperature array and returns it
 */
u8 TempAvg(void)
{
	u16 averageTemp = 0;
	for (u8 i = 0; i < 10; i++)
	{
		averageTemp += Temparr[i];
	}
	averageTemp = averageTemp / 10;
	return averageTemp;
}

/*
 * Function to turn on system components
 * Calls TempSenseInit and TempAvg functions to initialize temperature sensing
 * Sets the desired temperature based on EEPROM data
 */
void systemOn(void)
{

	EXTI_enable(EXTI_INT1,EXTI_FALLING_EDGE);
	EXTI_enable(EXTI_INT2,EXTI_FALLING_EDGE);
	TMR0_start();
	TMR1_start();
	SSD_ON();
	TempSenseInit();
	Temp = TempAvg();
	Tempindex = 0;
	u8 data =  EEPROM_readByte(50);
	if (data > 75 || data < 35)
	{
		SET_TEMP = 60;
	}
	else
	{
		SET_TEMP = data;
	}

}

//Function to turn off system components
void systemOFF(void)
{
	EXTI_disable(EXTI_INT1);
	EXTI_disable(EXTI_INT2);
	TMR0_stop();
	TMR1_stop();
	TMR2_stop();
	LED_off();
	SSD_OFF();
	DCM_off();
	HTR_OFF();
}


// ISR to checks the state of the system either turns it on or off
void __vector_1(void) __attribute__ ((signal));
void __vector_1(void)
{
	if (state == OFF)
	{
		systemOn();
		state = ON;
	}
	else
	{
		systemOFF();
		state = OFF;
	}
}

/*
 * ISR to enter the temperature setting mode or
 * increase the set temperature by 1 degrees
 */
void __vector_2(void) __attribute__ ((signal));
void __vector_2(void)
{

	ctcCounter2 = 0;
	if (NORMAL_MODE == mode)
	{
		mode = SETTING_MODE;
		Display_TEMP = SET_TEMP;
		TMR2_start();
	}
	else
	{
		Display_TEMP += 5;
		if (Display_TEMP >= MAX_TEMP)
			Display_TEMP = MAX_TEMP;
	}


}

/*
 * ISR to enter the temperature setting mode or
 * decrease the set temperature by 1 degrees
 */
void __vector_3(void) __attribute__ ((signal));
void __vector_3(void)
{

	ctcCounter2 = 0; // Reset the counter
	if (NORMAL_MODE == mode)
	{
		mode = SETTING_MODE;
		Display_TEMP = SET_TEMP;
		TMR2_start();
	}
	else
	{
		Display_TEMP -= 5;
		if (Display_TEMP <= MIN_TEMP)
			Display_TEMP = MIN_TEMP;
	}


}

//ISR to exit from the Temperature Setting mode and store the set temperature in EEPROM
void __vector_4(void) __attribute__ ((signal));
void __vector_4(void)
{

	ctcCounter2++; // Increment the counter for Timer 2
	if(TMR2_CTC_COUNTER == ctcCounter2)
	{
		// Reset the Timer 2 counter, stop Timer 2 and switch to Normal mode
		ctcCounter2 = 0;
		TMR2_stop();
		mode = NORMAL_MODE;
		// Update the SET_TEMP to the new Display_TEMP and save to EEPROM
		SET_TEMP = Display_TEMP;
		EEPROM_writeByte(50,SET_TEMP);
		SSD_ON(); //Ensure SSD is ON
	}
}

/*
 * ISR :
 * For Temperature Sense
 * Calling Function to Calculate Average Temp
 * Toggle LED when Heater is ON
 */
void __vector_10(void) __attribute__ ((signal));
void __vector_10(void)
{
	//Static Counters for Timer0
	static u16 ctcCounter1 = 0;
	static u16 ledCounter = 0;

	ctcCounter1++; //Increment the Temperature sense counter for Timer 0

	if (heat == 1) //when Heater is ON
	{
		ledCounter++; //Increment the Heater LED counter for Timer 0

		if(ledCounter == 1000) //Toggle LED after a second when Heater is ON
			{
				LED_toggle();
				ledCounter  = 0; //Reset Heater LED counter for Timer 0
			}
	}
	else
		ledCounter = 0; //Reset Heater LED counter for Timer 0 when Heater is OFF


	if(TMR0_CTC_COUNTER == ctcCounter1)
	{
		ctcCounter1 = 0; //Reset emperature sense counter for Timer 0

		//Storing Temperature Sensor Readings in the Temperature array
		if(Tempindex > 10)
			Tempindex = 0;
		LM35_tempSense(&Temparr[Tempindex]);
		Tempindex++;

		Temp = TempAvg(); //Calculate Temperature Average

		//Display Average Temperature on the SSD during Normal Mode
		if (NORMAL_MODE == mode)
		{
		SSD_displayMultibleNum(Temp);
		}
	}
}






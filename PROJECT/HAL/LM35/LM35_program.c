
/* UTILES_LIB */
#include "../../Utilies/STD_TYPES.h"
#include "../../Utilies/BIT_MATH.h"
#include "../../Utilies/ATMEGA32_REG.h"
/* MCAL */
#include "../../MCAL/ADC/ADC_interface.h"
/* HAAL */
#include "../../MCAL/DIO/DIO_interface.h"
#include "LM35_interface.h"

//Function to initialize the Temperature Sensor by setting its pin as Output
void LM35_init(void)
{
	DIO_setPinDirection(DIO_PORTA,DIO_PIN0,DIO_PIN_INPUT);
}

//Function to obtain the Correct Temperature Value from
void LM35_tempSense(u8* TempValue)
{
	u16 digitalVal;
	u8 analogVal;
	ADC_getDigitalValue(ADC_CHANNEL_4,&digitalVal);

	//Mapping the Values taken from the ADC to compute the correct temperature
	if(digitalVal >= 0 && digitalVal <= 10)
		analogVal = (digitalVal / 2);
	else if(digitalVal > 10 && digitalVal <= 49)
		analogVal = (digitalVal-1) / 2 ;
	else if(digitalVal > 24 && digitalVal <= 86)
		analogVal = (digitalVal-2) / 2 ;
	else if(digitalVal > 42 && digitalVal <= 125)
		analogVal = (digitalVal-3) / 2 ;
	else if(digitalVal > 61 && digitalVal <= 164)
		analogVal = (digitalVal-4) / 2 ;
	else if(digitalVal > 80 && digitalVal <= 203)
		analogVal = (digitalVal-5) / 2 ;
	else if(digitalVal > 99 && digitalVal <= 242)
		analogVal = (digitalVal-6) / 2 ;
	else if(digitalVal > 118 && digitalVal <= 281)
		analogVal = (digitalVal-7) / 2 ;
	else
		analogVal = (digitalVal-8) / 2 ;

	*TempValue = analogVal; //Correct Temperature
}

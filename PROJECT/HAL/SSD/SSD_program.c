
/* UTILIES_LIB*/
#include "../../Utilies/STD_TYPES.h"
#include "../../Utilies/BIT_MATH.h"
#include "../../Utilies/ATMEGA32_REG.h"
/* MCAL */
#include "../../MCAL/DIO/DIO_interface.h"
/* HAL */
#include "SSD_interface.h"
#include "SSD_Config.h"

//Function to initialize the Two SSDs by setting their pins as Output
void SSD_init(void)
{
	//SSD 1 pins
    DIO_setPinDirection(SSDPort1,DIO_PIN0,DIO_PIN_OUTPUT);
    DIO_setPinDirection(SSDPort1,DIO_PIN1,DIO_PIN_OUTPUT);
    DIO_setPinDirection(SSDPort1,DIO_PIN2,DIO_PIN_OUTPUT);
    DIO_setPinDirection(SSDPort1,DIO_PIN3,DIO_PIN_OUTPUT);

    //SSD 2 pins
    DIO_setPinDirection(SSDPort2,DIO_PIN4,DIO_PIN_OUTPUT);
    DIO_setPinDirection(SSDPort2,DIO_PIN5,DIO_PIN_OUTPUT);
    DIO_setPinDirection(SSDPort2,DIO_PIN6,DIO_PIN_OUTPUT);
    DIO_setPinDirection(SSDPort2,DIO_PIN7,DIO_PIN_OUTPUT);

    //Enable Pins
    DIO_setPinDirection(SSDPort1,DIO_PIN6,DIO_PIN_OUTPUT);
    DIO_setPinDirection(SSDPort2,DIO_PIN1,DIO_PIN_OUTPUT);
}

//Function to Turn SSDs ON
void SSD_ON(void)
{
	DIO_setPinValue(SSDPort1,DIO_PIN6,DIO_PIN_HIGH);
	DIO_setPinValue(SSDPort2,DIO_PIN1,DIO_PIN_HIGH);
}

//Function to Turn SSDs OFF
void SSD_OFF(void)
{
	DIO_setPinValue(SSDPort1,DIO_PIN6,DIO_PIN_LOW);
	DIO_setPinValue(SSDPort2,DIO_PIN1,DIO_PIN_LOW);
}

//Function To Display a Number on the SSD
void SSD_displayNumber(u8 ssdID,u8 desiredNumber)
{
    switch (ssdID)
    {
    case SSD_ONE:

        SSDPortOUT1 = (SSDPortOUT1 & (0xF0)) | ( desiredNumber & ~(0xF0));
        break;
    
    case SSD_TWO:

    	SSDPortOUT2 = (SSDPortOUT2 & 0x0F) | ((desiredNumber << 4) & 0xF0);
        break;
    }

}

//Function to Display a 2-Digit Number on the SSDs
void SSD_displayMultibleNum(u8 Num)
{
	SSD_displayNumber(SSD_ONE,Num/10);
	SSD_displayNumber(SSD_TWO,Num%10);
}

//Function to toggle the State of the SSDs
void SSD_toggleState(void)
{
	DIO_togglePinValue(SSDPort1,DIO_PIN6);
	DIO_togglePinValue(SSDPort2,DIO_PIN1);

}


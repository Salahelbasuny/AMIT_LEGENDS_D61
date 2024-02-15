

/* UTILIES_LIB*/
#include "../../Utilies/STD_TYPES.h"
#include "../../Utilies/BIT_MATH.h"
#include "../../Utilies/ATMEGA32_REG.h"
/* MCAL */
#include "DIO_interface.h"

//Function to set the Direction of the Desired Pin
 void DIO_setPinDirection(u8 PortId, u8 PinId, u8 PinDirection)
 {
    switch (PortId) //Determining the Port
    {
        case DIO_PORTA:
        if(DIO_PIN_OUTPUT == PinDirection)
        {
            SET_BIT(DDRA,PinId);
        }
        else
        {
            CLR_BIT(DDRA,PinId);
        }
        break;
        case DIO_PORTB:
        if(DIO_PIN_OUTPUT == PinDirection)
        {
            SET_BIT(DDRB,PinId);
        }
        else
        {
            CLR_BIT(DDRB,PinId);
        }
        break;
        case DIO_PORTC:
        if(DIO_PIN_OUTPUT == PinDirection)
        {
            SET_BIT(DDRC,PinId);
        }
        else
        {
            CLR_BIT(DDRC,PinId);
        }
        break;
        case DIO_PORTD:
        if(DIO_PIN_OUTPUT == PinDirection)
        {
            SET_BIT(DDRD,PinId);
        }
        else
        {
            CLR_BIT(DDRD,PinId);
        }
        break;
    }
 }

 //Function to set the Value of the Desired Pin HIGH or LOW
 void DIO_setPinValue(u8 PortId, u8 PinId, u8 PinValue)
 {
    switch(PortId) //Determining the Port
    {
        case DIO_PORTA:
        if(DIO_PIN_HIGH == PinValue)
        {
            SET_BIT(PORTA,PinId);
        }
        else
        {
            CLR_BIT(PORTA,PinId);
        }
        break;
        case DIO_PORTB:
        if(DIO_PIN_HIGH == PinValue)
        {
            SET_BIT(PORTB,PinId);
        }
        else
        {
            CLR_BIT(PORTB,PinId);
        }
        break;
        case DIO_PORTC:
        if(DIO_PIN_HIGH == PinValue)
        {
            SET_BIT(PORTC,PinId);
        }
        else
        {
            CLR_BIT(PORTC,PinId);
        }
        break;
        case DIO_PORTD:
        if(DIO_PIN_HIGH == PinValue)
        {
            SET_BIT(PORTD,PinId);
        }
        else
        {
            CLR_BIT(PORTD,PinId);
        }
        break;
    }
 }

 //Function to get the Value of the Desired Pin HIGH or LOW
 void DIO_getPinValue(u8 PortId, u8 PinId, u8* PinValue)
 {
    switch(PortId) //Determining the Port
    {
        case DIO_PORTA:
        *PinValue = GET_BIT(PINA,PinId);
        break;
        case DIO_PORTB:
        *PinValue = GET_BIT(PINB,PinId);
        break;
        case DIO_PORTC:
        *PinValue = GET_BIT(PINC,PinId);
        break;
        case DIO_PORTD:
        *PinValue = GET_BIT(PIND,PinId);
        break;
    }
 }

 //Function to toggle the Value of the Desired Pin
 void DIO_togglePinValue(u8 PortId, u8 PinId)
 {
    switch(PortId) //Determining the Port
    {
        case DIO_PORTA:
        TOG_BIT(PORTA,PinId);
        break;
        case DIO_PORTB:
        TOG_BIT(PORTB,PinId);
        break;
        case DIO_PORTC:
        TOG_BIT(PORTC,PinId);
        break;
        case DIO_PORTD:
        TOG_BIT(PORTD,PinId);
        break;
    }
 }

//Function to activate the internal pull-up resistor of a desired pin in a specific port.
 void DIO_activeInPullUpResistance(u8 PortId, u8 PinId)
 {
   switch(PortId) //Determining the Port
   {
       case DIO_PORTA:
       SET_BIT(PORTA,PinId);
       break;
       case DIO_PORTB:
       SET_BIT(PORTB,PinId);
       break;
       case DIO_PORTC:
       SET_BIT(PORTC,PinId);
       break;
       case DIO_PORTD:
       SET_BIT(PORTD,PinId);
       break;
   }
 }



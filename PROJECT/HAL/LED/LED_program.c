
/* UTILIES_LIB*/
#include "../../Utilies/STD_TYPES.h"
#include "../../Utilies/BIT_MATH.h"
#include "../../Utilies/ATMEGA32_REG.h"
/* MCAL */
#include "../../MCAL/DIO/DIO_interface.h"
/* HAL */
#include "LED_interface.h"

//Function to initialize the LED by setting its pin as Output
void LED_init(void)
{
	DIO_setPinDirection(DIO_PORTC,DIO_PIN5,DIO_PIN_OUTPUT);
}

//Function to Turn ON the LED
void LED_on(void)
{
	DIO_setPinValue(DIO_PORTC,DIO_PIN5,DIO_PIN_HIGH);
}

//Function to Turn OFF the LED
void LED_off(void)
{
	DIO_setPinValue(DIO_PORTC,DIO_PIN5,DIO_PIN_LOW);
}

//Function to Toggle the LED
void LED_toggle(void)
{
	DIO_togglePinValue(DIO_PORTC,DIO_PIN5);
}


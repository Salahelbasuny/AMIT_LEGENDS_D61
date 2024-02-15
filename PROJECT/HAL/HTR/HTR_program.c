/* UTILIES_LIB*/
#include "../../Utilies/STD_TYPES.h"
#include "../../Utilies/BIT_MATH.h"
#include "../../Utilies/ATMEGA32_REG.h"
/* MCAL */
#include "../../MCAL/DIO/DIO_interface.h"
/* HAL */
#include "HTR_interface.h"

//Function to initialize the Heater by setting its pin as Output
void HTR_init(void)
{
	DIO_setPinDirection(DIO_PORTC,DIO_PIN7,DIO_PIN_OUTPUT);
}

//Function to Turn ON the Heater
void HTR_ON(void)
{
	DIO_setPinValue(DIO_PORTC,DIO_PIN7,DIO_PIN_HIGH);
}

//Function to Turn OFF the Heater
void HTR_OFF(void)
{
	DIO_setPinValue(DIO_PORTC,DIO_PIN7,DIO_PIN_LOW);
}

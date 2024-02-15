/* UTILIES_LIB*/
#include "../../Utilies/STD_TYPES.h"
#include "../../Utilies/BIT_MATH.h"
#include "../../Utilies/ATMEGA32_REG.h"
/* MCAL */
#include "TMR1_interface.h"

//Function to Initialize Timer 1 according to PWM Mode 14
void TMR1_init(void)
{
	//Fast PWM Mode 14
	CLR_BIT(TCCR1A,WGM10);
	SET_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1B,WGM13);


	//Non Inverting Mode
	CLR_BIT(TCCR1A,COM1A0);
	SET_BIT(TCCR1A,COM1A1);


	SET_BIT(DDRD,5);

    // ICR1 >> period time = 20ms >> freq. = 50HZ
	ICR1_u16 = CounterValue;


}

//Function to Start Timer 1 CLK
void TMR1_start(void)
{
	//Prescaler 64
	SET_BIT(TCCR1B,CS10);
	SET_BIT(TCCR1B,CS11);
	CLR_BIT(TCCR1B,CS12);
}

//Function to Stop Timer 1 CLK
void TMR1_stop(void)
{

	CLR_BIT(TCCR1B,CS10);
	CLR_BIT(TCCR1B,CS11);
	CLR_BIT(TCCR1B,CS12);
}


// Function to set the compare match value for Timer 1 by setting the value of the OCR1 register.
void TMR1_setCompareMatchValueA(u16 value)
{
	//Compare Value
	OCR1A_u16 = value;
}


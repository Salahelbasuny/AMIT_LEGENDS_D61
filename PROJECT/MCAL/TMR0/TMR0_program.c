/* UTILIES_LIB*/
#include "../../Utilies/STD_TYPES.h"
#include "../../Utilies/BIT_MATH.h"
#include "../../Utilies/ATMEGA32_REG.h"
/* MCAL */
#include "TMR0_interface.h"
#include "TMR0_config.h"

//Function to Initialize Timer 0 according to a Desired Mode
void TMR0_init(void)
{
#if TMR0_MODE == TMR0_NORMAL_MODE
	//NORMAL MODE
	CLR_BIT(TCCR0,PWM0);
	CLR_BIT(TCCR0,CTC0);
	//Preload Value
	TCNT0 = TMR0_PRELOAD_VALUE;

	SET_BIT(TIMSK,TMR0_OverflowIn);
#elif TMR0_MODE == TMR0_CTC_MODE
	//NORMAL MODE
	CLR_BIT(TCCR0,PWM0);
	SET_BIT(TCCR0,CTC0);

	SET_BIT(TIMSK,TMR0_OutputCompareMatchIn); //CTC INTERRUPT
#elif TMR0_MODE == TMR0_FAST_PWM_MODE
	
	//Fast PWM Mode
	SET_BIT(TCCR0 , PWM0);
	SET_BIT(TCCR0 , CTC0);

	//NON INVERTING MODE
	CLR_BIT(TCCR0 , COM00);
	SET_BIT(TCCR0 , COM01);

	SET_BIT(DDRB,3); //SET 0C0 AS OUTPUT

#endif
}

//Function to Start Timer 0 CLK
void TMR0_start(void)
{
	//PRESCALER = 64
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS01);
	CLR_BIT(TCCR0,CS02);
}

//Function to Stop Timer 0 CLK
void TMR0_stop(void)
{
	CLR_BIT(TCCR0,CS00);
	CLR_BIT(TCCR0,CS01);
	CLR_BIT(TCCR0,CS02);
}

// Function to set the compare match value for Timer 0 by setting the value of the OCR0 register.
void TMR0_setCompareMatchValue(u8 OCR0_Value)
{
	OCR0 = OCR0_Value;
}


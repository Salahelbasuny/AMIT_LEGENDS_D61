/* UTILIES_LIB*/
#include "../../Utilies/STD_TYPES.h"
#include "../../Utilies/BIT_MATH.h"
#include "../../Utilies/ATMEGA32_REG.h"
/* MCAL */
#include "TMR2_interface.h"
#include "TMR2_config.h"

//Function to Initialize Timer 2 according to a Desired Mode
void TMR2_init(void)
{
#if TMR2_MODE == TMR2_NORMAL_MODE
	//NORMAL MODE
	CLR_BIT(TCCR2,PWM2);
	CLR_BIT(TCCR2,CTC2);
	//Preload Value
	TCNT2 = TMR2_PRELOAD_VALUE;

	SET_BIT(TIMSK,TMR2_OverflowIn);
#elif TMR2_MODE == TMR2_CTC_MODE
	//NORMAL MODE
	CLR_BIT(TCCR2,PWM2);
	SET_BIT(TCCR2,CTC2);

	SET_BIT(TIMSK,TMR2_OutputCompareMatchIn); //CTC INTERRUPT
#elif TMR2_MODE == TMR2_FAST_PWM_MODE
	
	//Fast PWM Mode
	SET_BIT(TCCR2 , PWM2);
	SET_BIT(TCCR2 , CTC2);

	//NON INVERTING MODE
	CLR_BIT(TCCR2 , COM20);
	SET_BIT(TCCR2 , COM21);

	SET_BIT(DDRB,3); //SET 0C0 AS OUTPUT

#endif
}

//Function to Start Timer 2 CLK
void TMR2_start(void)
{
	//PRESCALER = 64
	CLR_BIT(TCCR2,CS20);
	CLR_BIT(TCCR2,CS21);
	SET_BIT(TCCR2,CS22);
}

//Function to Stop Timer 2 CLK
void TMR2_stop(void)
{
	//PRESCALER = 64
	CLR_BIT(TCCR2,CS20);
	CLR_BIT(TCCR2,CS21);
	CLR_BIT(TCCR2,CS22);
}

// Function to set the compare match value for Timer 2 by setting the value of the OCR2 register.
void TMR2_setCompareMatchValue(u8 OCR2_Value)
{
	OCR2 = OCR2_Value;
}


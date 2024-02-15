
/* UTILIES_LIB*/
#include "../../Utilies/STD_TYPES.h"
#include "../../Utilies/BIT_MATH.h"
#include "../../Utilies/ATMEGA32_REG.h"
/* MCAL */
#include "EXTI_interface.h"

//Function to enable the Desired External Interrupt along with its event of occurrence
void EXTI_enable(u8 interruptSource, u8 interruptTriggerEdge)
{
	switch(interruptSource)
	{
		case EXTI_INT0 :
			if(EXTI_RISING_EDGE == interruptTriggerEdge)
			{
				SET_BIT(MCUCR,ISC00);
				SET_BIT(MCUCR,ISC01);
			}
			else if(EXTI_FALLING_EDGE == interruptTriggerEdge)
			{
				CLR_BIT(MCUCR,ISC00);
				SET_BIT(MCUCR,ISC01);
			}
			else if(EXTI_LOW_LEVEL == interruptTriggerEdge)
			{
				CLR_BIT(MCUCR,ISC00);
				CLR_BIT(MCUCR,ISC01);
			}
			else if(EXTI_ANY_LOGICAL_CHANGE == interruptTriggerEdge)
			{
				CLR_BIT(MCUCR,ISC00);
				SET_BIT(MCUCR,ISC01);
			}
			CLR_BIT(DDRD,2);
			SET_BIT(GICR,INT0); //ENABLE INT0
			break;
		case EXTI_INT1 :
			if(EXTI_RISING_EDGE == interruptTriggerEdge)
			{
				SET_BIT(MCUCR,ISC10);
				SET_BIT(MCUCR,ISC11);
			}
			else if(EXTI_FALLING_EDGE == interruptTriggerEdge)
			{
				CLR_BIT(MCUCR,ISC10);
				SET_BIT(MCUCR,ISC11);
			}
			else if(EXTI_LOW_LEVEL == interruptTriggerEdge)
			{
				CLR_BIT(MCUCR,ISC10);
				CLR_BIT(MCUCR,ISC11);
			}
			else if(EXTI_ANY_LOGICAL_CHANGE == interruptTriggerEdge)
			{
				SET_BIT(MCUCR,ISC10);
				CLR_BIT(MCUCR,ISC11);
			}
			CLR_BIT(DDRD,3);
			SET_BIT(GICR,INT1); //ENABLE INT1
			break;
		case EXTI_INT2 :
			if(EXTI_RISING_EDGE == interruptTriggerEdge)
			{
				SET_BIT(MCUCSR,ISC2);
			}
			else if(EXTI_FALLING_EDGE == interruptTriggerEdge)
			{
				CLR_BIT(MCUCSR,ISC2);
			}
			CLR_BIT(DDRB,2);
			SET_BIT(GICR,INT2); //ENABLE INT2
			break;

	}
}

//Function to Disable the Desired External Interrupt
void EXTI_disable(u8 interruptSource)
{
	switch(interruptSource)
	{
		case EXTI_INT0 :
			CLR_BIT(GICR,INT0);
			break;
		case EXTI_INT1 :
			CLR_BIT(GICR,INT1);
			break;
		case EXTI_INT2 :
			CLR_BIT(GICR,INT2);
			break;
	}
}

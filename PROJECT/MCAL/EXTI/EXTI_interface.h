
#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

#define ISC2 6

typedef enum
{
	EXTI_INT0 = 0, //PD1
	EXTI_INT1,     //PD2
	EXTI_INT2      //PB2
}EXTI_source;


typedef enum 
{
	EXTI_RISING_EDGE = 0,
	EXTI_FALLING_EDGE,
	EXTI_LOW_LEVEL,
	EXTI_ANY_LOGICAL_CHANGE
}EXTI_trigger;


typedef enum
{
	ISC00 = 0,
	ISC01,
	ISC10,
	ISC11
}Interrupt_Sense_Control;

typedef enum
{
	INT2 = 5,
	INT0,
	INT1
}External_Interrupt_Request;



void EXTI_enable(u8 interruptSource, u8 interruptTriggerEdge);
void EXTI_disable(u8 interruptSource);


#endif /* EXTI_INTERFACE_H_ */

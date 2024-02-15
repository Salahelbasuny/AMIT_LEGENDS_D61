/* UTILIES_LIB*/
#include "../../Utilies/STD_TYPES.h"
#include "../../Utilies/BIT_MATH.h"
#include "../../Utilies/ATMEGA32_REG.h"
/* MCAL */
#include "GI_interface.h"

//Function to Enable the Global Interrupt
void GI_enable(void)
{
	SET_BIT(SREG,7);
}

//Function to Disable the Global Interrupt
void GI_disable(void)
{
	CLR_BIT(SREG,7);
}

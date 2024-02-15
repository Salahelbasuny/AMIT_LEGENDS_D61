
/* UTILIES_LIB*/
#include "../../Utilies/STD_TYPES.h"
#include "../../Utilies/BIT_MATH.h"
#include "../../Utilies/ATMEGA32_REG.h"
/* MCAL */
#include "ADC_interface.h"

//Function to initialize ADC
void ADC_init(void)
{
	//V REF = Vcc
	SET_BIT(ADMUX,REFS0);
	CLR_BIT(ADMUX,REFS1);

	//RIGHT ADJUSTMENT
	CLR_BIT(ADMUX,ADLAR);

	//SINGLE CONVERSION
	CLR_BIT(ADCSRA,ADC_Trigger_Enable);

	//PRESCALER 128
	SET_BIT(ADCSRA,ADPS0);
	SET_BIT(ADCSRA,ADPS1);
	SET_BIT(ADCSRA,ADPS2);

	//ENABLE ADC
	SET_BIT(ADCSRA,ADC_Enable);
}

//Function to read the value from the specified channel and store it in the provided variable
void ADC_getDigitalValue(u8 channelNum,u16* digitalValue)
{
	/*
	 * Check :
	 * if The Number in the Valid Range
	 * Digital Value Pointer is not NULL
	 */
	if((channelNum < 32) && (digitalValue != NULL))
	{
		//Clear ADMUX Channel Bits 
		ADMUX &= 0b11100000;

		//Select Channel Number
		ADMUX |= channelNum;

		//Start Conversion 
		SET_BIT(ADCSRA,ADC_Start_Conv);

		//Wait for the conversion to complete
		while(0 == GET_BIT(ADCSRA,ADC_Flag));

		//Clear Flag
		SET_BIT(ADCSRA,ADC_Flag);

		//Read Digital Value from ADC Register
		*digitalValue = ADC_u16;

	}

}


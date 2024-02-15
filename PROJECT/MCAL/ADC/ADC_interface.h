

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

//Reference Voltage Selection Bits
#define REFS0 6
#define REFS1 7

//ADC Left Adjust bit
#define ADLAR 5

//Trigger Enable Bit
#define ADC_Trigger_Enable 5

//ADC Prescaler Bits
#define ADPS0 0
#define ADPS1 1
#define ADPS2 2

//ADC Enable
#define ADC_Enable 7

//ADC Start Conversion
#define ADC_Start_Conv 6

//ADC Interrupt Flag
#define ADC_Flag 4



typedef enum 
{
    ADC_CHANNEL_0 = 0,
    ADC_CHANNEL_1,
    ADC_CHANNEL_2,
    ADC_CHANNEL_3,
    ADC_CHANNEL_4,
    ADC_CHANNEL_5,
    ADC_CHANNEL_6,
    ADC_CHANNEL_7,
}ADC_CHANNEL;


void ADC_init(void);
void ADC_getDigitalValue(u8 channelNum, u16* digitalValue);


#endif /* ADC_INTERFACE_H_ */

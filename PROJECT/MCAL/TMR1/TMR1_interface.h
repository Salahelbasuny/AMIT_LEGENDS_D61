
#ifndef TMR1_INTERFACE_H_
#define TMR1_INTERFACE_H_

//WaveForm Generation Bits
typedef enum
{
    WGM10 = 0,
    WGM11,
    WGM12 = 3,
    WGM13
}Waveform_Generation;

//Compare Output Mode for Compare unit A
#define  COM1A0 6
#define  COM1A1 7

//Counter TOP Value
#define CounterValue 4999

//Clock Select Bits
typedef enum
{
    CS10 = 0,
    CS11,
    CS12
}Clock_Select;

void TMR1_init(void);
void TMR1_start(void);
void TMR1_stop(void);
void TMR1_setCompareMatchValueA(u16 value);


#endif /* TMR1_INTERFACE_H_ */

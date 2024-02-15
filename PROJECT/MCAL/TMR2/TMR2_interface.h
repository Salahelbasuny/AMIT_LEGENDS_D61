
#ifndef TMR2_INTERFACE_H_
#define TMR2_INTERFACE_H_

#define TMR2_NORMAL_MODE 1
#define TMR2_CTC_MODE 2
#define TMR2_FAST_PWM_MODE 3

//Waveform Generation Mode Bits
#define PWM2 6
#define CTC2 3

//Compare Match Output Mode Bits
#define COM20 4
#define COM21 5

// Clock Select Bits
#define CS20 0
#define CS21 1
#define CS22 2

//Timer 2 Overflow Interrupt Enable
#define TMR2_OverflowIn 6

//Timer 2 Output Compare Match Interrupt Enable
#define TMR2_OutputCompareMatchIn 7


void TMR2_init(void);
void TMR2_start(void);
void TMR2_stop(void);
void TMR2_setCompareMatchValue(u8 OCR2_Value);


#endif /* TMR2_INTERFACE_H_ */


#ifndef TMR0_INTERFACE_H_
#define TMR0_INTERFACE_H_

#define TMR0_NORMAL_MODE 1
#define TMR0_CTC_MODE 2
#define TMR0_FAST_PWM_MODE 3

//Waveform Generation Mode Bits
#define PWM0 6
#define CTC0 3

//Compare Match Output Mode Bits
#define COM00 4
#define COM01 5

// Clock Select Bits
#define CS00 0
#define CS01 1
#define CS02 2

//Timer 0 Overflow Interrupt Enable
#define TMR0_OverflowIn 0

//Timer 0 Output Compare Match Interrupt Enable
#define TMR0_OutputCompareMatchIn 1


void TMR0_init(void);
void TMR0_start(void);
void TMR0_stop(void);
void TMR0_setCompareMatchValue(u8 OCR0_Value);


#endif /* TMR0_INTERFACE_H_ */


#ifndef DCM_INTERFACE_H_
#define DCM_INTERFACE_H_

#define CW 1
#define CCW 0

void DCM_init(void);
void DCM_on(u8 motorDirection);
void DCM_ctrlSpeed(u8 motorSpeed);
void DCM_off(void);

#endif /* DCM_INTERFACE_H_ */

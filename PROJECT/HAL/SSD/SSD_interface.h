
#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_

#define SSD_ONE 1
#define SSD_TWO 2


void SSD_init(void);
void SSD_displayNumber(u8 ssdID,u8 desiredNumber);
void SSD_ON(void);
void SSD_OFF(void);
void SSD_displayMultibleNum(u8 Num);
void SSD_toggleState(void);
#endif /* SSD_INTERFACE_H_ */

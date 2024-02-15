
#ifndef ATMEGA32_REG_H_
#define ATMEGA32_REG_H_

/* DIO REGISTERS */
/* DATA DIRECTION REGISTERS */
#define DDRA    (*(volatile u8*)0x3A) 
#define DDRB    (*(volatile u8*)0x37)
#define DDRC    (*(volatile u8*)0x34)
#define DDRD    (*(volatile u8*)0x31)

/* OUTPUT REGISTERS */
#define PORTA    (*(volatile u8*)0x3B)
#define PORTB    (*(volatile u8*)0x38)
#define PORTC    (*(volatile u8*)0x35)
#define PORTD    (*(volatile u8*)0x32)

/* INPUT REGISTERS */
#define PINA    (*(volatile u8*)0x39)
#define PINB    (*(volatile u8*)0x36)
#define PINC    (*(volatile u8*)0x33)
#define PIND    (*(volatile u8*)0x30)

/* External Interrupt Registers*/
#define MCUCR   (*(volatile u8*)0x55) //MCU Control Register
#define MCUCSR  (*(volatile u8*)0x54) //MCU Control & Status Register
#define GICR    (*(volatile u8*)0x5B) //General Interrupt Control Register
#define GIFR    (*(volatile u8*)0x5A) //General Interrupt Flag Register 

/* Global Interrupt Register */
#define SREG    (*(volatile u8*)0x5F) //Status Register

/* ADC Registers */
#define ADMUX    (*(volatile u8*)0x27)  //ADC Multiplexer Selection Register
#define ADCSRA   (*(volatile u8*)0x26)  //ADC Control and Status Register A
#define ADC_u16  (*(volatile u16*)0x24) //ADC Data Register
#define SFIOR    (*(volatile u8*)0x50)  //Special FunctionIO Register

/* Timer0 Registers */
#define TCCR0   (*(volatile u8*)0x53) //Timer0 Control Register
#define TCNT0   (*(volatile u8*)0x52) //Timer0 Register
#define OCR0    (*(volatile u8*)0x5C) //Timer0 Output Compare Register
#define TIMSK   (*(volatile u8*)0x59) //Timer Interrupt Mask Register
#define TIFR    (*(volatile u8*)0x58) //Timer Interrupt Flag Register

/* Timer1 Registers */
#define TCCR1A      (*(volatile u8*)0x4F)  //Timer1 Control RegisterA
#define TCCR1B      (*(volatile u8*)0x4E)  //Timer1 Control RegisterB
#define TCNT1_u16   (*(volatile u16*)0x4C) //Timer1 Register
#define OCR1A_u16   (*(volatile u16*)0x4A) //Timer1 Output Compare RegisterA
#define OCR1B_u16   (*(volatile u16*)0x48) //Timer1 Output Compare RegisterB
#define ICR1_u16    (*(volatile u16*)0x46) //Timer 1 Input Capture Register 

/* Timer2 Registers */
#define TCCR2   (*(volatile u8*)0x45) //Timer0 Control Register
#define TCNT2   (*(volatile u8*)0x44) //Timer0 Register
#define OCR2    (*(volatile u8*)0x43) //Timer0 Output Compare Register


/* Watchdog Timer */
#define WDTCR   (*(volatile u8*)0x41) //Watchdog Timer Control Register

/* UART Registers */
#define UDR     (*(volatile u8*)0x2C) //USART I/O Data Register
#define UCSRA   (*(volatile u8*)0x2B) //USART Control and Status Register A
#define UCSRB   (*(volatile u8*)0x2A) //USART Control and Status Register B
#define UCSRC   (*(volatile u8*)0x40) //USART Control and Status Register C
//USART Baud Rate Registers
#define UBRRL   (*(volatile u8*)0x29)
#define UBRRH   (*(volatile u8*)0x40)

/* SPI REGISTERS */
#define SPCR   (*(volatile u8*)0x2D) //SPI Control Register
#define SPSR   (*(volatile u8*)0x2E) //SPI Status Register
#define SPDR   (*(volatile u8*)0x2F) //SPI Data Register

/* TWI REGISTERS */
#define TWBR   (*(volatile u8*)0x20) // TWI Bit Rate Register
#define TWCR   (*(volatile u8*)0x56) // TWI Control Register
#define TWSR   (*(volatile u8*)0x21) // TWI Status Register
#define TWDR   (*(volatile u8*)0x23) // TWI Data Register
#define TWAR   (*(volatile u8*)0x22) // TWI (Slave) Address Register
#endif

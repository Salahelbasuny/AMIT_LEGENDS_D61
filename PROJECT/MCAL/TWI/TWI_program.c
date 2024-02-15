
/* UTILIES_LIB*/
#include "../../Utilies/STD_TYPES.h"
#include "../../Utilies/BIT_MATH.h"
#include "../../Utilies/ATMEGA32_REG.h"
/* MCAL */
#include "TWI_interface.h"

//Function to initialize the I2C interface as a master
void TWI_initMaster(void)
{
	//SER PRESCALER = 1 => FREQ 400KHZ
	 TWBR = 12;
	 CLR_BIT(TWSR,0);
	 CLR_BIT(TWSR,1);

	 //ENABLE ACK BIT
	 SET_BIT(TWCR,6);

	 SET_BIT(TWCR,2); //TWI Enable
}

//Function to send a start condition to the slave
void TWI_sendStartCondition(void)
{
	SET_BIT(TWCR,5); //send start condition

	//clear flag to start current job
	SET_BIT(TWCR,7);

	//wait for flag
	while(0 == GET_BIT(TWCR,7));

	//check ACK = Slave address ACK
    while((TWSR&0xF8)  != 0x08);
}

//Function to send a repeated start condition to the slave
void TWI_sendRepStartCondition(void)
{
	SET_BIT(TWCR,5); //send start condition

	//clear flag to start current job
	SET_BIT(TWCR,7);

	//wait for flag
	while(0 == GET_BIT(TWCR,7));

	//check ACK = repeated start condition ACK
    while((TWSR&0xF8) != 0x10);

}

//Function to send a stop condition to the slave
void TWI_sendStopCondition(void)
{
	SET_BIT(TWCR,4); //send stop condition

	//clear flag to start current job
	SET_BIT(TWCR,7);
}

//Function to send the slave address with write operation
void TWI_sendSlaveAddWithWrite(u8 slaveAdd)
{

	TWDR = slaveAdd << 1;
	//select Write operation
	CLR_BIT(TWDR,0);

	CLR_BIT(TWCR,5); //CLEAR  SC BIT

	//clear flag to start current job
	SET_BIT(TWCR,7);
	//wait for flag
	while(0 == GET_BIT(TWCR,7));

	//check ACK = Slave address with write operation ACK
    while((TWSR&0xF8) != 0x18);

}

//Function to send the slave address with read operation
void TWI_sendSlaveAddWithRead(u8 slaveAdd)
{
	TWDR = slaveAdd << 1;
	//select read operation
	SET_BIT(TWDR,0);

	CLR_BIT(TWCR,5); //CLEAR  SC BIT

	//clear flag to start current job
	SET_BIT(TWCR,7);
	//wait for flag
	while(0 == GET_BIT(TWCR,7));

	//check ACK = Slave address with read operation ACK
    while( (TWSR&0xF8) != 0x40);
}

//Function to send  data byte to the slave
void TWI_sendMasterDataByte(u8 data)
{
	TWDR = data; //write data in register
	//clear flag to start current job
	SET_BIT(TWCR,7);
	//wait for flag
	while(0 == GET_BIT(TWCR,7));

	//check ACK = Transmit Data
    while( (TWSR&0xF8) != 0x28);

}

//Function to receive  data byte to the slave
u8 WI_recieveMasterDataByte(void)
{
	u8 returnedData;
	//clear flag to start current job
	SET_BIT(TWCR,7);
	//wait for flag
	while(0 == GET_BIT(TWCR,7))
	//check ACK = Receive Data
	while( (TWSR&0xF8) != 0x50);
	returnedData = TWDR;
	return returnedData;

}

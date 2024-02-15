
#define F_CPU 16000000UL
#include <util/delay.h>
/* UTILIES_LIB*/
#include "../../Utilies/STD_TYPES.h"
#include "../../Utilies/BIT_MATH.h"
#include "../../Utilies/ATMEGA32_REG.h"
/* MCAL */
#include "../../MCAL/TWI/TWI_interface.h"
/* HAL */
#include "EEPROM_interface.h"

//Function to initialize the EEPROM
void EEPROM_init(void)
{
	TWI_initMaster();
}

//Function to write data in a specific address in the EEPROM
void EEPROM_writeByte(u16 byteAddress, u8 data)
{
	//Compute the address to be used in the write operation
	u8 address = (EEPROM_FIXED_ADDRESS|(u8)(byteAddress >> 8));

	//send start condition
	TWI_sendStartCondition();

	//send slave address with write operation
	TWI_sendSlaveAddWithWrite(address);

	//send byte address
	TWI_sendMasterDataByte((u8)byteAddress);

	//send byte data
	TWI_sendMasterDataByte(data);

	//send stop condition
	TWI_sendStopCondition();

	//Delay for 5ms for the EEPROM to complete the write operation
	_delay_ms(5);

}

//Function to read data from a specific address in the EEPROM
u8 EEPROM_readByte(u16 byteAddress)
{
	u8 returnedData;
	//Compute the address to be used in the read operation
	u8 address = (EEPROM_FIXED_ADDRESS|(u8)(byteAddress >> 8));

	//send start condition
	TWI_sendStartCondition();

	//send slave address with write operation
	TWI_sendSlaveAddWithWrite(address);

	//send byte address
	TWI_sendMasterDataByte((u8)byteAddress);

	//send repeat start condition
	TWI_sendRepStartCondition();

	//send slave add with read operation
	TWI_sendSlaveAddWithRead(address);

	//receive data
	returnedData = WI_recieveMasterDataByte();

	//send stop condition
	TWI_sendStopCondition();

	return returnedData;
}

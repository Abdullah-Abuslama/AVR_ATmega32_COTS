/*
 *	 Made By Eng: << Abdullah Abuslama >>
 */

#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_

#define SLAVE_ADDRESS  0xA0

void EEPROM_vRead(u8 Copy_u8LocationAddress,u8 *Copy_pu8Data);
void EEPROM_vWrite(u8 Copy_u8LocationAddress,u8 Copy_pu8Data);

#endif

/*
 *	 Made By Eng: << Abdullah Abuslama >>
 */

 
#ifndef CLCD_INTERFACE_H_
#define CLCD_INTERFACE_H_



void CLCD_voidINIT(void);

void CLCD_voidSendData(u8 Copy_u8Data);
void CLCD_voidSendCommand(u8 Copy_u8Command);
void CLCD_voidSendString(u8 * Copy_u8String);

void CLCD_voidWriteNumber(u32 Copy_u32Number , u8 Copy_u8X , u8 Copy_u8Y );
void CLCD_voidWriteSpecialCharacter(u8 * Copy_pu8Pattern , u8 Copy_pu8PatternNumber , u8 Copy_u8XPos , u8 Copy_u8YPos  ) ;

void CLCD_voidGOTOXY(u8 Copy_u8XPosition, u8 Copy_u8YPosition);
void CLCD_voidClearScreen(void);




#endif /* CLCD_INTERFACE_H_ */

/*
 *	 Made By Eng: << Abdullah Abuslama >>
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "../../MCAL/DIO/DIO_interface.h"

#include "CLCD_private.h"
#include "CLCD_config.h"
#include "CLCD_interface.h"

#include <util/delay.h>

 void CLCD_voidSendCommand(u8 Copy_u8Command)
 {
	 /* Set RS For Command */

	 DIO_SetPinValue(CLCD_CONTROL_PORT,CLCD_RS_PIN,PIN_LOW);

	 /* Set R/W TO write */

	 DIO_SetPinValue(CLCD_CONTROL_PORT,CLCD_RW_PIN,PIN_LOW);

	 /* Send Command */

	 DIO_SetPort_value(CLCD_DATA_PORT,Copy_u8Command) ;

	 /* Enable Pulse */

	 DIO_SetPinValue(CLCD_CONTROL_PORT,CLCD_E_PIN,PIN_HIGH);

	 _delay_ms(2);

	 DIO_SetPinValue(CLCD_CONTROL_PORT,CLCD_E_PIN,PIN_LOW);
 
 }
 
 void CLCD_voidSendData(u8 Copy_u8Data)
  {
 	 /* Set RS For Command */

 	 DIO_SetPinValue(CLCD_CONTROL_PORT,CLCD_RS_PIN,PIN_HIGH);

 	 /* Set R/W TO write */

 	 DIO_SetPinValue(CLCD_CONTROL_PORT,CLCD_RW_PIN,PIN_LOW);

 	 /* Send Command */

 	 DIO_SetPort_value(CLCD_DATA_PORT,Copy_u8Data) ;

 	 /* Enable Pulse */

 	 DIO_SetPinValue(CLCD_CONTROL_PORT,CLCD_E_PIN,PIN_HIGH);

 	 _delay_ms(2);

 	 DIO_SetPinValue(CLCD_CONTROL_PORT,CLCD_E_PIN,PIN_LOW);

  }

 void CLCD_voidINIT(void)

 {
	 /* wait 50 ms */

	 _delay_ms(50);

	 /* Set Function Set */
	 CLCD_voidSendCommand(Function_Set);
	 _delay_ms(1);
	 /* Display ON/OFF Control - no cursor - no blink */
	 CLCD_voidSendCommand(Display_Control);
	 _delay_ms(1);
	 /* Display Clear */

	 CLCD_voidSendCommand(Display_Clear);
	 _delay_ms(1);
 }

 void CLCD_voidSendString(u8 * Copy_u8String)
 {
	 while(*Copy_u8String != '\0' ){
		 CLCD_voidSendData(*(Copy_u8String++));
	 }
 }

 void CLCD_voidGOTOXY(u8 Copy_u8XPosition, u8 Copy_u8YPosition)
 {

	 u8 Local_u8Address = 128 + Copy_u8YPosition + (64 * Copy_u8XPosition);

	 CLCD_voidSendCommand(Local_u8Address);
 }

 void CLCD_voidClearScreen(void)
 {
	 CLCD_voidSendCommand(Display_Clear);
 }

 void CLCD_voidWriteSpecialCharacter(u8 * Copy_pu8Pattern , u8 Copy_pu8PatternNumber , u8 Copy_u8XPos , u8 Copy_u8YPos  ) {

  	u8 Local_u8CGRAMAddress , Counter ;

  	/* Set CGRAM Address whose each block is 8 byte */

  	Local_u8CGRAMAddress = Copy_pu8PatternNumber * 8 ;

  /* Send CGRAM Address command to lcd with setting bit 6 , clearing bit 7 */

  	CLCD_voidSendCommand(Local_u8CGRAMAddress + 64 ) ;

  	/* write the pattern into  CGRAM*/
  	for(Counter = 0 ; Counter < 8 ; Counter++){
  	CLCD_voidSendData(Copy_pu8Pattern[Counter]);

  	}
  }

 void CLCD_voidWriteNumber(u32 Copy_u32Number , u8 Copy_u8X , u8 Copy_u8Y ){

  		u8 Local_u8Digits = 0 ;
  		u32  Local_u32TempNumber = Copy_u32Number ;

  		while(Local_u32TempNumber != 0){
  			Local_u32TempNumber /= 10 ;
  			Local_u8Digits++ ;
  		}
  		for( ; Local_u8Digits > 0 ; Local_u8Digits-- ){

  				CLCD_voidGOTOXY(Copy_u8X, Copy_u8Y + Local_u8Digits - 1 );

  				switch(Copy_u32Number % 10){
  				case 0 : CLCD_voidSendData('0'); break ;
  				case 1 : CLCD_voidSendData('1'); break ;
  				case 2 : CLCD_voidSendData('2'); break ;
  				case 3 : CLCD_voidSendData('3'); break ;
  				case 4 : CLCD_voidSendData('4'); break ;
  				case 5 : CLCD_voidSendData('5'); break ;
  				case 6 : CLCD_voidSendData('6'); break ;
  				case 7 : CLCD_voidSendData('7'); break ;
  				case 8 : CLCD_voidSendData('8'); break ;
  				case 9 : CLCD_voidSendData('9'); break ;
  				}
  				Copy_u32Number /= 10 ;
  			}
 }

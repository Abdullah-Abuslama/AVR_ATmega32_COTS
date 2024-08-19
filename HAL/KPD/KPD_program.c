/*
 *	 Made By Eng: << Abdullah Abuslama >>
 */
 
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "KPD_private.h"
#include "KPD_config.h"
#include "KPD_interface.h"


void KPD_voidInit(void)
{
	DIO_SetPin_Direction(KPD_PORT,KPD_COLUMN0_PIN,PIN_OUTPUT);
	DIO_SetPin_Direction(KPD_PORT,KPD_COLUMN1_PIN,PIN_OUTPUT);
	DIO_SetPin_Direction(KPD_PORT,KPD_COLUMN2_PIN,PIN_OUTPUT);
	DIO_SetPin_Direction(KPD_PORT,KPD_COLUMN3_PIN,PIN_OUTPUT);

	DIO_SetPin_Direction(KPD_PORT,KPD_ROW0_PIN,PIN_INPUT);
	DIO_SetPin_Direction(KPD_PORT,KPD_ROW1_PIN,PIN_INPUT);
	DIO_SetPin_Direction(KPD_PORT,KPD_ROW2_PIN,PIN_INPUT);
	DIO_SetPin_Direction(KPD_PORT,KPD_ROW3_PIN,PIN_INPUT);

	DIO_SetPort_value(KPD_PORT,PORT_HIGH);
}


u8 KPD_u8GetPressedKey(void)
{
	u8 Local_ButtonStatus = 0 , Local_u8Iterator_1 = 0 , Local_u8Iterator_2 = 0;
	u8 Local_u8ButtonValue = NO_Pressed_KEY ;

	u8 KPD_ARR[ROWS_NUM][COLUMNS_NUM] = KPD_ARR_VAL ;
	static u8 KPD_Column_ARR[4] = {KPD_COLUMN0_PIN, KPD_COLUMN1_PIN, KPD_COLUMN2_PIN, KPD_COLUMN3_PIN};
	static u8 KPD_ROW_ARR[4] = {KPD_ROW0_PIN,KPD_ROW1_PIN,KPD_ROW2_PIN,KPD_ROW3_PIN};


	for (Local_u8Iterator_1 = 0 ; Local_u8Iterator_1 < COLUMNS_NUM  ; Local_u8Iterator_1 ++ )
	{
		DIO_SetPinValue(KPD_PORT , KPD_Column_ARR[Local_u8Iterator_1] , PIN_LOW);
		for(Local_u8Iterator_2 = 0 ; Local_u8Iterator_2 < ROWS_NUM ; Local_u8Iterator_2 ++ )
		{
			Local_ButtonStatus = DIO_GetPinValue(KPD_PORT,KPD_ROW_ARR[Local_u8Iterator_2]) ;

			if(Local_ButtonStatus ==  PIN_LOW)
			{
				while(Local_ButtonStatus == PIN_LOW)
				{
					Local_ButtonStatus = DIO_GetPinValue(KPD_PORT,KPD_ROW_ARR[Local_u8Iterator_2]) ;
				}
				Local_u8ButtonValue = KPD_ARR[Local_u8Iterator_2][Local_u8Iterator_1] ;
				DIO_SetPinValue(KPD_PORT , KPD_Column_ARR[Local_u8Iterator_1] , PIN_HIGH);
				return Local_u8ButtonValue ;
			}
		}
		DIO_SetPinValue(KPD_PORT , KPD_Column_ARR[Local_u8Iterator_1] , PIN_HIGH);
	}

	return Local_u8ButtonValue ;
}
 
 

/*
 *	 Made By Eng: << Abdullah Abuslama >>
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_interface.h"

#include "Stepper_Motor_private.h"
#include "Stepper_Motor_config.h"
#include "Stepper_Motor_interface.h"

#include <util/delay.h>

void Stepper_Motor_Rotate_CLoclWise(u16 Copy_u16Angle)

{
	u16 Local_u16Stpes =  Copy_u16Angle / 0.7 ;
	u16 Local_u16Counter = 0 ;

	while(Local_u16Counter < Local_u16Stpes)
	{
		/* For First Step -> 0.175 */
		DIO_SetPinValue(ULN_PORT,ULN_BASE0,PIN_LOW);
		DIO_SetPinValue(ULN_PORT,ULN_BASE1,PIN_LOW);
		DIO_SetPinValue(ULN_PORT,ULN_BASE2,PIN_LOW);
		DIO_SetPinValue(ULN_PORT,ULN_BASE3,PIN_HIGH);

		_delay_ms(10);

		/* For Second Step -> 0.175 */
		DIO_SetPinValue(ULN_PORT,ULN_BASE0,PIN_LOW);
		DIO_SetPinValue(ULN_PORT,ULN_BASE1,PIN_LOW);
		DIO_SetPinValue(ULN_PORT,ULN_BASE2,PIN_HIGH);
		DIO_SetPinValue(ULN_PORT,ULN_BASE3,PIN_LOW);

		_delay_ms(10);

		/* For Third Step -> 0.175 */
		DIO_SetPinValue(ULN_PORT,ULN_BASE0,PIN_LOW);
		DIO_SetPinValue(ULN_PORT,ULN_BASE1,PIN_HIGH);
		DIO_SetPinValue(ULN_PORT,ULN_BASE2,PIN_LOW);
		DIO_SetPinValue(ULN_PORT,ULN_BASE3,PIN_LOW);

		_delay_ms(10);



		/* For Fourth Step -> 0.175 */
		DIO_SetPinValue(ULN_PORT,ULN_BASE0,PIN_HIGH);
		DIO_SetPinValue(ULN_PORT,ULN_BASE1,PIN_LOW);
		DIO_SetPinValue(ULN_PORT,ULN_BASE2,PIN_LOW);
		DIO_SetPinValue(ULN_PORT,ULN_BASE3,PIN_LOW);

		_delay_ms(10);


		/* Complete 0.175 * 4 Steps -> 0.7 degree */

		Local_u16Counter ++ ;
	}


}




void Stepper_Motor_Rotate_CounterCLoclWise(u16 Copy_u16Angle)

{
	u16 Local_u16Stpes =  Copy_u16Angle / 0.7 ;
	u16 Local_u16Counter = 0 ;

	while(Local_u16Counter < Local_u16Stpes)
	{
		/* For First Step -> 0.175 */
		DIO_SetPinValue(ULN_PORT,ULN_BASE0,PIN_HIGH);
		DIO_SetPinValue(ULN_PORT,ULN_BASE1,PIN_LOW);
		DIO_SetPinValue(ULN_PORT,ULN_BASE2,PIN_LOW);
		DIO_SetPinValue(ULN_PORT,ULN_BASE3,PIN_LOW);

		_delay_ms(10);

		/* For Second Step -> 0.175 */
		DIO_SetPinValue(ULN_PORT,ULN_BASE0,PIN_LOW);
		DIO_SetPinValue(ULN_PORT,ULN_BASE1,PIN_HIGH);
		DIO_SetPinValue(ULN_PORT,ULN_BASE2,PIN_LOW);
		DIO_SetPinValue(ULN_PORT,ULN_BASE3,PIN_LOW);

		_delay_ms(10);

		/* For Third Step -> 0.175 */
		DIO_SetPinValue(ULN_PORT,ULN_BASE0,PIN_LOW);
		DIO_SetPinValue(ULN_PORT,ULN_BASE1,PIN_LOW);
		DIO_SetPinValue(ULN_PORT,ULN_BASE2,PIN_HIGH);
		DIO_SetPinValue(ULN_PORT,ULN_BASE3,PIN_LOW);

		_delay_ms(10);



		/* For Fourth Step -> 0.175 */
		DIO_SetPinValue(ULN_PORT,ULN_BASE0,PIN_LOW);
		DIO_SetPinValue(ULN_PORT,ULN_BASE1,PIN_LOW);
		DIO_SetPinValue(ULN_PORT,ULN_BASE2,PIN_LOW);
		DIO_SetPinValue(ULN_PORT,ULN_BASE3,PIN_HIGH);

		_delay_ms(10);


		/* Complete 0.175 * 4 Steps -> 0.7 degree */

		Local_u16Counter ++ ;
	}

}



void Stepper_Motor_Stop()
{

	DIO_SetPinValue(ULN_PORT,ULN_BASE0,PIN_LOW);
	DIO_SetPinValue(ULN_PORT,ULN_BASE1,PIN_LOW);
	DIO_SetPinValue(ULN_PORT,ULN_BASE2,PIN_LOW);
	DIO_SetPinValue(ULN_PORT,ULN_BASE3,PIN_LOW);

}



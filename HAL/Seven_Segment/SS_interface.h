/*
 *	 Made By Eng: << Abdullah Abuslama >>
 */

#ifndef HAL_SEVEN_SEGMENT_SS_INTERFACE_H_
#define HAL_SEVEN_SEGMENT_SS_INTERFACE_H_

/*------------------------------------------------------*/
/*------------------------------------------------------*/

#define Zero  0
#define one   1
#define Two   2
#define Three 3
#define Four  4
#define Five  5
#define Six   6
#define Seven 7
#define eight 8
#define Nine  9

/*------------------------------------------------------*/

void HSSD_voidInit(u8 A_PortNum);
void HSSD_VoidDisplayNumber(u8 A_u8SSD_PORT ,u8 A_u8Num);
void HSSD_voidTurnOff(u8 A_u8SSD_PORT);
void HSSD_voidCountUp(u8 A_u8SSD_PORT,u8 A_u8Num);
void HSSD_voidCountdown(u8 A_u8SSD_PORT,u8 A_u8Num);

/*------------------------------------------------------*/
/*------------------------------------------------------*/

#endif /* HAL_SEVEN_SEGMENT_SS_INTERFACE_H_ */

/*
 *	 Made By Eng: << Abdullah Abuslama >>
 */


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "SPI_private.h"
#include "SPI_interface.h"
#include "SPI_config.h"

void SPI_voidMasterInit(void)
{
	/* Select Data Order */

	//SET_BIT(SPCR,SPCR_DORD);

	/* Master Select */

	SET_BIT(SPCR,SPCR_MSTR);

	/* Clock Polarity --> Leading Edge -> Rising */

	/* Clock Phase --> Sample First */

	/* Select SPI Clock */
	SET_BIT(SPCR,SPCR_SPR0);
	CLR_BIT(SPCR,SPCR_SPR1);
	//CLR_BIT(SPSR,SPSR_SPI2X);

	/* Enable SPI */
	SET_BIT(SPCR,SPCR_SPE );
}

void SPI_voidSlaveInit(void)
{

	/* Select Data Order */

	//SET_BIT(SPCR,SPCR_DORD);

	/* Slave Select */


	CLR_BIT(SPCR,SPCR_MSTR);
	/* Clock Polarity --> Leading Edge -> Rising */

	/* Clock Phase --> Sample First */


	/* Enable SPI */
	SET_BIT(SPCR,SPCR_SPE );
}

u8 SPI_u8Transreceive(u8 Copy_u8Data)
{
	/* Send Data */
	SPDR = Copy_u8Data;

	/* Wait SPIF */

	while(0 == GET_BIT(SPSR,SPSR_SPIF));

	return SPDR ;
}

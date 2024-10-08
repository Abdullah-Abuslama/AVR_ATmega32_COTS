/*
 *	 Made By Eng: << Abdullah Abuslama >>
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "TWI_interface.h"
#include "TWI_private.h"
#include "TWI_config.h"


void TWI_vMasterInit(void)
{
	/* Set Clock configuration  TWBR = 2 */
	TWBR = 2;
	CLR_BIT(TWSR , TWSR_TWPS0);
	CLR_BIT(TWSR , TWSR_TWPS1);

	/* Enable Acknowledge bit */
	SET_BIT(TWCR , TWCR_TWEA);
	/* Set my own Address */
	TWAR = MASTER_ADDRESS << 1;
	/* Enable TWI */
	SET_BIT(TWCR , TWCR_TWEN);
}
void TWI_vSlaveInit(void)
{
	/* Enable Acknowledge bit */
	SET_BIT(TWCR , TWCR_TWEA);
	/* Set my own Address */
	TWAR = SLAVE_ADDRESS << 1;
	/* Enable TWI */
	SET_BIT(TWCR , TWCR_TWEN);
}

TWI_ErrorState_t TWI_enStartCondition(void)
{
	TWI_ErrorState_t Local_ErrorState = NO_ERROR;

	/* enable start condition */
	SET_BIT(TWCR , TWCR_TWSTA);
	/* Clear interrupt flag to start the operation */
	SET_BIT(TWCR , TWCR_TWINT);
	/*Wait until the interrupt flag is raised again  */
	while(GET_BIT(TWCR , TWCR_TWINT) == 0);

	if((TWSR & 0XF8) != START_CONDITION)
	{
		Local_ErrorState = START_CONDTITION_ERR;
	}
	else
	{
		/* Do Nothing */
	}

	return Local_ErrorState;
}
TWI_ErrorState_t TWI_enRepeateStart(void)
{
	TWI_ErrorState_t Local_ErrorState = NO_ERROR;
	/* enable start condition */
	SET_BIT(TWCR , TWCR_TWSTA);
	/* Clear interrupt flag to start the operation */
	SET_BIT(TWCR , TWCR_TWINT);
	/*Wait until the interrupt flag us raised again  */
	while(GET_BIT(TWCR , TWCR_TWINT) == 0);

	if((TWSR & 0XF8) != REPEATE_START_CONDITION)
	{
		Local_ErrorState = REPEAT_START_ERR;
	}
	else
	{
		/* Do Nothing */
	}

	return Local_ErrorState;
}
TWI_ErrorState_t TWI_enSetSlaveAddressWithWrite(u8 Copy_u8SlaveAddress)
{
	TWI_ErrorState_t Local_ErrorState = NO_ERROR;
	/* Clear bit 0 to make write operation */
		CLR_BIT(TWDR , TWDR_TWD0);
	/* Set Slave address in TWDR register */
		TWDR = Copy_u8SlaveAddress;
	/* Clear the start condition bit */
		CLR_BIT(TWCR , TWCR_TWSTA);


	/* Clear interrupt flag to start the operation */
	SET_BIT(TWCR , TWCR_TWINT);

	/*Wait until the interrupt flag us raised again  */
	while(GET_BIT(TWCR , TWCR_TWINT) == 0);

	if((TWSR & 0XF8) == SLA_WITH_W_NOAK)
	{
		Local_ErrorState = SLA_W_NOACK_ERR;
	}
	else
	{
		/* Do Nothing */
	}
	return Local_ErrorState;

}
TWI_ErrorState_t TWI_enSetSlaveAddressWithRead(u8 Copy_u8SlaveAddress)
{
	TWI_ErrorState_t Local_ErrorState = NO_ERROR;

	/* Set Slave address in TWDR register */
	TWDR = Copy_u8SlaveAddress | 1;

	/* Clear the start condition bit */
	CLR_BIT(TWCR , TWCR_TWSTA);
	/* Set bit 0 to make Read operation */
	//SET_BIT(TWDR , TWDR_TWD0);
	/* Clear interrupt flag to start the operation */
	SET_BIT(TWCR , TWCR_TWINT);

	/*Wait until the interrupt flag us raised again  */
	while(GET_BIT(TWCR , TWCR_TWINT) == 0);

	if((TWSR & 0XF8) == SLA_WITH_R_NOAK)
	{
		Local_ErrorState = SLA_R_NOACK_ERR;
	}
	else
	{
		/* Do Nothing */
	}
	return Local_ErrorState;

}
TWI_ErrorState_t TWI_enMasterWriteData(u8 Copy_u8Data)
{
	TWI_ErrorState_t Local_ErrorState = NO_ERROR;
	/* Write data to TWDR */
	TWDR = Copy_u8Data;
	/* Clear interrupt flag to start the operation */
	SET_BIT(TWCR , TWCR_TWINT);
	/* Enable TWI */
	SET_BIT(TWCR , TWCR_TWEN);

	/*Wait until the interrupt flag us raised again  */
	while(GET_BIT(TWCR , TWCR_TWINT) == 0);

	if((TWSR & 0XF8) == MASTER_SEND_DATA_NOAK)
	{
		Local_ErrorState = MASTER_SEND_DATA_ERR;
	}
	else
	{
		/* Do Nothing */
	}

	return Local_ErrorState;

}
TWI_ErrorState_t TWI_enMasterReadData(u8 *Copy_u8Data)
{
	TWI_ErrorState_t Local_ErrorState = NO_ERROR;

	/* Enable TWI */
	SET_BIT(TWCR , TWCR_TWEN);
	/* Clear interrupt flag to start the operation */
	SET_BIT(TWCR , TWCR_TWINT);

	/*Wait until the interrupt flag us raised again  */
	while(GET_BIT(TWCR , TWCR_TWINT) == 0);

	if((TWSR & 0XF8) == MASTER_RECEIVE_DATA_NOAK)
	{
		Local_ErrorState = MASTER_RECEIVE_DATA_ERR;
	}
	else
	{

	}

	*Copy_u8Data = TWDR;

	return Local_ErrorState;

}
void TWI_vStopCondition(void)
{

	/* Set bit TWSTOP to make stop condition */
	SET_BIT(TWCR , TWCR_TWSTOP);
	/* Clear interrupt flag to start the operation */
	SET_BIT(TWCR , TWCR_TWINT);
	/* Enable TWI */
	SET_BIT(TWCR , TWCR_TWEN);
}

/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Dio_Lcfg.c
 *        \brief
 *
 *      \details  Source file for Dio Module's user configurations at linking stage
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Dio_Cfg.h"
/**********************************************************************************************************************
 *  LOCAL MACROS CONSTANT\FUNCTION
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/* PB structure used with Dio_Init API */
Dio_ConfigType Dio_Configuration =
	{
		{{DIO_CONFIG_LED1_PORT_NUM, DIO_CONFIG_LED1_CHANNEL_NUM}}};

/**********************************************************************************************************************
 *  END OF FILE: Dio_Lcfg.c
 *********************************************************************************************************************/

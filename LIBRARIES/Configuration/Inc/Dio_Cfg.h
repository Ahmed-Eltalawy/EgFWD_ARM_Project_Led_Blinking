/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Dio_Cfg.h
 *       Module:  -
 *
 *  Description:  Dio Module's user configurations    
 *  
 *********************************************************************************************************************/
#ifndef DIO_CFG_H
#define DIO_CFG_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

#include "Dio_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/* Number of the configured Dio Channels */
#define DIO_CONFIGURED_CHANNLES                 (1U)

/* Channel Index in the array of structures */
#define DioConf_LED1_CHANNEL_ID_INDEX           (uint8)0x00


/* DIO Configured Port ID's  */
#define DIO_CONFIG_LED1_PORT_NUM                (Dio_PortType)PORT_A /* PORTA */


/* DIO Configured Channel ID's */
#define DIO_CONFIG_LED1_CHANNEL_NUM             (Dio_ChannelType)PORT_A_0 /* Pin 0 in PORTA */
/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
/* Data Structure required for initializing the Dio Driver */
typedef struct Dio_ConfigType
{
	Dio_ConfigChannel Channels[DIO_CONFIGURED_CHANNLES];
} Dio_ConfigType;

/* Extern PB structures to be used by Dio  */
extern  Dio_ConfigType Dio_Configuration;
 
#endif  /* DIO_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Dio_Cfg.h
 *********************************************************************************************************************/

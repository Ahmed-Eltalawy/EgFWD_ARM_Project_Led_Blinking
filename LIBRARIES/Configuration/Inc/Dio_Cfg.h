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
#define DIO_CONFIGURED_CHANNLES                 (3U)

/* Channel Index in the array of structures */
#define DioConf_LED1_CHANNEL_ID_INDEX           (uint8)0x00
#define DioConf_BUTTON1_CHANNEL_ID_INDEX        (uint8)0x01
#define DioConf_BUTTON2_CHANNEL_ID_INDEX        (uint8)0x01

/* DIO Configured Port ID's  */
#define DIO_CONFIG_LED1_PORT_NUM                (Dio_PortType)PORTNUMBER_C /* PORTC */
#define DIO_CONFIG_BUTTON1_PORT_NUM             (Dio_PortType)PORTNUMBER_D /* PORTD */
#define DIO_CONFIG_BUTTON2_PORT_NUM             (Dio_PortType)PORTNUMBER_D /* PORTD */

/* DIO Configured Channel ID's */
#define DIO_CONFIG_LED1_CHANNEL_NUM             (Dio_ChannelType)PORT_C_5 /* Pin 5 in PORTC */
#define DIO_CONFIG_BUTTON1_CHANNEL_NUM          (Dio_ChannelType)PORT_D_2 /* Pin 2 in PORTD */
#define DIO_CONFIG_BUTTON2_CHANNEL_NUM          (Dio_ChannelType)PORT_D_3 /* Pin 3 in PORTD */
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

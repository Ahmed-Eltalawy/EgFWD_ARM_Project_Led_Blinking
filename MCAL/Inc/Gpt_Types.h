/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Gpt_Types.h
 *       Module:  -
 *
 *  Description:  Types Of Gpt Module     
 *  
 *********************************************************************************************************************/
#ifndef GPT_TYPES_H
#define GPT_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/* Type definition for GPT_ChannelType used by the GPT APIs - Numeric ID of a GPT channel */
typedef enum GPT_ChannelIdType
{
    TIMER_0_16_32_BIT = 0,
    TIMER_1_16_32_BIT,
    TIMER_2_16_32_BIT,
    TIMER_3_16_32_BIT,
    TIMER_4_16_32_BIT,
    TIMER_5_16_32_BIT,

    TIMER_WIDE_0,
    TIMER_WIDE_1,
    TIMER_WIDE_2,
    TIMER_WIDE_3,
    TIMER_WIDE_4,
    TIMER_WIDE_5,

	
}GPT_ChannelIdType;

/* Type definition for GPT_OperationConfigType used by the GPT APIs - Gpt Operation */
typedef enum 
{
    GPT_OPERATION_CONCATENATED     = 0x00,
    GPT_OPERATION_CONCATENATED_RTC = 0x01,
    GPT_OPERATION_INDIVIDUAL       = 0x04 ,
	
}GPT_OperationConfigType;

/* Type definition for GPT_ModeConfigType used by the GPT APIs - Gpt Modes */
typedef enum 
{
    GPT_MODE_ONE_SHOOT     = 0x01,
    GPT_MODE_PERIODIC      = 0x02,
    GPT_MODE_CAPTURE       = 0x03,
	
}GPT_ModeConfigType;

/* Type definition for GPT_EdgeConfigType used by the GPT APIs - Gpt Edge Types */
typedef enum 
{
    GPT_Edge_COUNT    = 0x00,
    GPT_Edge_TIME     = 0x01,
	
}GPT_EdgeConfigType;

/* Type definition for GPT_AlternateModeConfigType used by the GPT APIs - Gpt Alternate Mode Types */
typedef enum 
{
    GPT_CAPTURE_COMPARE_MODE    = 0x00,
    GPT_PWM_MODE                = 0x01,
	
}GPT_AlternateModeConfigType;

/* Type definition for GPT_CountDirectionConfigType used by the GPT APIs - Gpt Count Direction Types */
typedef enum 
{
    GPT_COUNT_DOWN    = 0x00,
    GPT_COUNT_UP      = 0x01,
	
}GPT_CountDirectionConfigType;

/* Type definition for GPT_ChannelType used by the GPT APIs - Numeric ID of a GPT channel */
typedef uint8 Gpt_ChannelType;

/* Type definition for GPT_OperationType used by the GPT APIs for pertaion types */
typedef uint8 Gpt_OperationType;

/* Type definition for GPT_ChannelModeType used by the GPT APIs for Mode types */
typedef uint8 Gpt_ChannelModeType;

/* Type definition for GPT_EdgeType used by the GPT APIs for Edge types */
typedef uint8 Gpt_ChannelEdgeType;

/* Type definition for GPT_AlternateType used by the GPT APIs for Alternate types */
typedef uint8 Gpt_ChannelAlternateType;

/* Type definition for GPT_CountDirectionType used by the GPT APIs for count down or up types */
typedef uint8 Gpt_ChannelCountDirectionType;

/* Type definition for Gpt_ValueType used by the GPT APIs for value of Timer Regiser */
typedef uint32 Gpt_ValueType;

/* Type definition for Gpt_ChannelTickFrequencyType used by the GPT APIs for Tick Frequency in MHz */
typedef uint32 Gpt_ChannelTickFrequencyType;

/* Type definition for Gpt_ChannelTickValueMaxType used by the GPT APIs for maximum tick value */
typedef uint32 Gpt_ChannelTickValueMaxType;

/*  Type definition for  Gpt_NotificationType  used by the GPT APIs for 
    A pointer to the callback function (Notification) */
typedef void (*Gpt_ChannelNotificationType)(void);

/* Type definition for Gpt_NotificationPriority used by the GPT APIs for 
    A priority for the interrupt attached to the channel's timer */
typedef uint8 Gpt_ChannelNotificationPriorityType;

typedef struct 
{
    Gpt_ChannelType ChannelId;
    Gpt_OperationType OperationType ;
    Gpt_ChannelModeType ChannelMode;
    Gpt_ChannelEdgeType ChannelEdge;
    Gpt_ChannelAlternateType ChannelAlternate;
    Gpt_ChannelCountDirectionType ChannelCountDirection;
    Gpt_ChannelTickFrequencyType ChannelTickFrequency;
    Gpt_ChannelTickValueMaxType ChannelTickValueMax;
    Gpt_ChannelNotificationType ChannelNotification;
	Gpt_ChannelNotificationPriorityType ChannelNotificationPriority;

} GPT_Channel_ConfigType;





/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 
#endif  /* GPT_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: Gpt_Types.h
 *********************************************************************************************************************/

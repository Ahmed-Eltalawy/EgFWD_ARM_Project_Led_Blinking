/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  SysTick_Types.h
 *       Module:  -
 *
 *  Description:  Types Of SysTick Module     
 *  
 *********************************************************************************************************************/
#ifndef SYSTICK_TYPES_H
#define SYSTICK_TYPES_H

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


/* Type definition for SYSTICK_ClockSourceType used by the SysTick APIs  */
typedef enum SYSTICK_ClockSourceType
{
    PRECISION_INERNAL_OSCILLATOR     = 0x00,
    SYSTEM_CLOCK                     = 0x01
	
}SYSTICK_ClockSourceType;


/* Type definition for SysTick_ClockSourceType used by the SysTick APIs for value of Timer Regiser */
typedef uint8 SysTick_ClockSourceType;

/* Type definition for SysTick_ValueType used by the SysTick APIs for value of Timer Regiser */
typedef uint32 SysTick_ValueType;

/* Type definition for SysTick_TickFrequencyType used by the SysTick APIs for Tick Frequency in MHz */
typedef uint32 SysTick_TickFrequencyType;

/* Type definition for SysTick_TickValueMaxType used by the SysTick APIs for maximum tick value */
typedef uint32 SysTick_TickValueMaxType;

/*  Type definition for  SysTick_NotificationType  used by the SysTick APIs for 
    A pointer to the callback function (Notification) */
typedef  void  (*SysTick_NotificationType)(void);

/* Type definition for SysTick_NotificationPriority used by the SysTick APIs for 
    A priority for the interrupt attached to the 's timer */
typedef uint8 SysTick_NotificationPriorityType;

typedef struct SysTick_ConfigType
{
    SysTick_TickFrequencyType TickFrequency;
    SysTick_TickValueMaxType TickValueMax;
    SysTick_NotificationType Notification;
	SysTick_NotificationPriorityType NotificationPriority;
    SysTick_ClockSourceType ClockSource;

} SysTick_ConfigType;





/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 
#endif  /* SYSTICK_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: SysTick_Types.h
 *********************************************************************************************************************/

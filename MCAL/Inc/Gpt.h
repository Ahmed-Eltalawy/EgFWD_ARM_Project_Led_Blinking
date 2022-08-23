/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Gpt.h
 *       Module:  -
 *
 *  Description:  Header file for Gpt Module.
 *                Note : The Module Support only timer_0 (16/32-Bit).     
 *  
 *********************************************************************************************************************/
#ifndef GPT_H
#define GPT_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Gpt_Types.h"
#include "Gpt_Cfg.h"
#include "Gpt_Registers.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


/******************************************************************************
 * \Syntax             : void Gpt_Init(const Gpt_ConfigType* ConfigPtr)
 * \Description        : Function to Intialize the Gpt Module.
 * \Sync\Async         : Synchronous.
 * \Reentrancy         : NonReentrant.
 * \Parameters (in)    : ConfigPtr - Configuration of Timer module.
 * \Parameters (inout) : None.
 * \Parameters (out)   : None.
 * \Return value:      : None.
 *******************************************************************************/
void Gpt_Init(const Gpt_ConfigType *ConfigPtr);


/******************************************************************************
 * \Syntax             : void Gpt_EnableNotification(Gpt_ChannelType ChannelId)
 * \Description        : Function to enable call back notofication .
 * \Sync\Async         : Synchronous
 * \Reentrancy         : Reentrant
 * \Parameters (in)    : ChannelId - ID of Timer Module.
 * \Parameters (inout) : None
 * \Parameters (out)   : None
 * \Return value:      : None
 *******************************************************************************/
void Gpt_EnableNotification(Gpt_ChannelType ChannelId);



/******************************************************************************
 * \Syntax             : void Gpt_DisableNotification(Gpt_ChannelType ChannelId)
 * \Description        : Function to disable call back notofication .
 * \Sync\Async         : Synchronous
 * \Reentrancy         : Reentrant
 * \Parameters (in)    : ChannelId - ID of Timer Module.
 * \Parameters (inout) : None
 * \Parameters (out)   : None
 * \Return value:      : None
 *******************************************************************************/
void Gpt_DisableNotification(Gpt_ChannelType ChannelId);



/******************************************************************************
 * \Syntax             : Gpt_ValueType Gpt_GetTimeElapsed(Gpt_ChannelType ChannelId)
 * \Description        : Function to get elapsed time .
 * \Sync\Async         : Synchronous
 * \Reentrancy         : Reentrant
 * \Parameters (in)    : ChannelId - ID of Timer Module.
 * \Parameters (inout) : None
 * \Parameters (out)   : None
 * \Return value:      : Gpt_ValueType
 *******************************************************************************/
Gpt_ValueType Gpt_GetTimeElapsed(Gpt_ChannelType ChannelId);

/******************************************************************************
 * \Syntax               : Std_ReturnType Gpt_GetPredefTimerValue(Gpt_PredefTimerType PredefTimer , uint32* TimeValuePtr)
 * \Description          : Function to return the current value of the Gpt predefined timer value  passed by predef timer.
 * \Sync\Async           : Synchronous
 * \Reentrancy           : Reentrant
 * \Parameters (in)      : PredefTimer  - Pre Defined TImer Value.
 *                         TimeValuePtr -  The current value of predefinied timer
 * * \Parameters (inout) : None
 * \Parameters (out)     : None
 * \Return value:        : Std_ReturnType
 *******************************************************************************/
// Std_ReturnType Gpt_GetPredefTimerValue(Gpt_PredefTimerType PredefTimer, uint32 *TimeValuePtr);



/******************************************************************************
 * \Syntax             : Gpt_ValueType Gpt_GetTimeRemaining(Gpt_ChannelType ChannelId)
 * \Description        : Function to get Remaining time .
 * \Sync\Async         : Synchronous
 * \Reentrancy         : Reentrant
 * \Parameters (in)    : ChannelId - ID of Timer Module.
 * \Parameters (inout) : None
 * \Parameters (out)   : None
 * \Return value:      : Gpt_ValueType
 *******************************************************************************/
Gpt_ValueType Gpt_GetTimeRemaining(Gpt_ChannelType ChannelId);




/******************************************************************************
 * \Syntax             : void Gpt_StartTimer(Gpt_ChannelType ChannelId, Gpt_ValueType Value)
 * \Description        : Function to start the selected timer channel with a defined target time .
 * \Sync\Async         : Synchronous
 * \Reentrancy         : Reentrant
 * \Parameters (in)    : ChannelId - ID of Timer Module.
 *                       Value     - The defined target time .
 * \Parameters (inout) : None
 * \Parameters (out)   : None
 * \Return value:      : None
 *******************************************************************************/
void Gpt_StartTimer(Gpt_ChannelType ChannelId, Gpt_ValueType Value);


/******************************************************************************
 * \Syntax             : void Gpt_StopTimer(Gpt_ChannelType ChannelId)
 * \Description        : Function to stop the selected timer channel .
 * \Sync\Async         : Synchronous
 * \Reentrancy         : Reentrant
 * \Parameters (in)    : ChannelId - ID of Timer Module.
 * \Parameters (inout) : None
 * \Parameters (out)   : None
 * \Return value:      : None
 *******************************************************************************/
void Gpt_StopTimer(Gpt_ChannelType ChannelId);



/******************************************************************************
 * \Syntax             : void Gpt_Notification_Timer(Gpt_ChannelType ChannelId)
 * \Description        : Function to Set the callback notification .
 * \Sync\Async         : Synchronous
 * \Reentrancy         : Reentrant
 * \Parameters (in)    : ChannelId - ID of Timer Module.
 * \Parameters (inout) : None
 * \Parameters (out)   : None
 * \Return value       : None
 *******************************************************************************/
void Gpt_Notification_Timer(Gpt_ChannelType ChannelId);
 
#endif  /* GPT_H */

/**********************************************************************************************************************
 *  END OF FILE: Gpt.h
 *********************************************************************************************************************/

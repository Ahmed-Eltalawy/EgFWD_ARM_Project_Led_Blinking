/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  SysTick.h
 *       Module:  -
 *
 *  Description:  Header file for SysTick Module.
 *                     
 *  
 *********************************************************************************************************************/
#ifndef SYSTICK_H
#define SYSTICK_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "SysTick_Types.h"
#include "SysTick_Cfg.h"
#include "Mcu_Hw.h"
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
 * \Syntax             : void SysTick_Init(const SysTick_ConfigType* ConfigPtr)
 * \Description        : Function to Intialize the SysTick Module.
 * \Sync\Async         : Synchronous.
 * \Reentrancy         : NonReentrant.
 * \Parameters (in)    : ConfigPtr - Configuration of SysTick module.
 * \Parameters (inout) : None.
 * \Parameters (out)   : None.
 * \Return value:      : None.
 *******************************************************************************/
void SysTick_Init(const SysTick_ConfigType *ConfigPtr);

/******************************************************************************
 * \Syntax             : void SysTick_EnableNotification(void)
 * \Description        : Function to enable call back notofication .
 * \Sync\Async         : Synchronous
 * \Reentrancy         : Reentrant
 * \Parameters (in)    : None
 * \Parameters (inout) : None
 * \Parameters (out)   : None
 * \Return value:      : None
 *******************************************************************************/
void SysTick_EnableNotification(void);

/******************************************************************************
 * \Syntax             : void SysTick_DisableNotification(void)
 * \Description        : Function to disable call back notofication .
 * \Sync\Async         : Synchronous
 * \Reentrancy         : Reentrant
 * \Parameters (in)    : None
 * \Parameters (inout) : None
 * \Parameters (out)   : None
 * \Return value:      : None
 *******************************************************************************/
void SysTick_DisableNotification(void);

/******************************************************************************
 * \Syntax             : SysTick_ValueType SysTick_GetTimeRemaining(void)
 * \Description        : Function to get Remaining time .
 * \Sync\Async         : Synchronous
 * \Reentrancy         : Reentrant
 * \Parameters (in)    : None
 * \Parameters (inout) : None
 * \Parameters (out)   : None
 * \Return value:      : SysTick_ValueType
 *******************************************************************************/
SysTick_ValueType SysTick_GetTimeRemaining(void);




/******************************************************************************
 * \Syntax             : void SysTick_StartTimer(SysTick_ValueType Value)
 * \Description        : Function to start SysTick with a defined target time .
 * \Sync\Async         : Synchronous
 * \Reentrancy         : Reentrant
 * \Parameters (in)    : Value - The defined target time .
 * \Parameters (inout) : None
 * \Parameters (out)   : None
 * \Return value:      : None
 *******************************************************************************/
void SysTick_StartTimer(SysTick_ValueType Value);

/******************************************************************************
 * \Syntax             : void SysTick_StopTimer(void)
 * \Description        : Function to stop the selected timer channel .
 * \Sync\Async         : Synchronous
 * \Reentrancy         : Reentrant
 * \Parameters (in)    : None
 * \Parameters (inout) : None
 * \Parameters (out)   : None
 * \Return value:      : None
 *******************************************************************************/
void SysTick_StopTimer(void);

/******************************************************************************
 * \Syntax             : void SysTick_SetNotification(void)
 * \Description        : Function to Set the callback notification .
 * \Sync\Async         : Synchronous
 * \Reentrancy         : Reentrant
 * \Parameters (in)    : None
 * \Parameters (inout) : None
 * \Parameters (out)   : None
 * \Return value       : None
 *******************************************************************************/
void SysTick_SetNotification(void);
 
#endif  /* SYSTICK_H */

/**********************************************************************************************************************
 *  END OF FILE: SysTick.h
 *********************************************************************************************************************/

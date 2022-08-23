/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  SysTick.c
 *        \brief
 *
 *      \details Source File for SysTick Module's driver .
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "SysTick.h"
/**********************************************************************************************************************
 *  LOCAL MACROS CONSTANT\FUNCTION
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/
/* Global pointer to function used to point upper layer functions
 * to be used in Call Back */
static  void (*g_SysTick_Call_Back_Ptr)(void) = NULL_PTR;

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
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
void SysTick_Init(const SysTick_ConfigType *ConfigPtr)
{

    /* Check of the user filled the configuration Successfully*/
    if (NULL_PTR == ConfigPtr)
    {
        /* Configurations Error */
        return;
    }

    else
    {
        /* Configurations Successfully */
        /* No Action Required */
    }

    /* Disable all the interrupts before initializations the timer module */
    INTERRUPTS_DISABLE();

    if (ConfigPtr->ClockSource == PRECISION_INERNAL_OSCILLATOR)
    {
        /* Precision internal oscillator (PIOSC) divided by 4 */
        SYSTICK_STCTRL.CLK_SRC = 0;
    }
    else
    {
        /* System clock */
        SYSTICK_STCTRL.CLK_SRC = 1;
    }

    /* Enable all the interrupts after initializations of Gpt Module  */
    INTERRUPTS_ENABLE();
}
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
void SysTick_EnableNotification(void)
{

    /* Enable SysTick Interrupt */
    SYSTICK_STCTRL.INTEN = ENABLE;
}

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
void SysTick_DisableNotification(void)
{

    /* Disable SysTick Interrupt */
    SYSTICK_STCTRL.INTEN = DISABLE;
}

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
SysTick_ValueType SysTick_GetTimeRemaining(void)
{

    return SYSTICK_STCURRENT;
}

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
void SysTick_StartTimer(SysTick_ValueType Value)
{

   /* Load the value on SysTick  */
    SYSTICK_STRELOAD = Value;

    /* Start the SysTick */
    SYSTICK_STCTRL.ENABLES = ENABLE;
}

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
void SysTick_StopTimer(void)
{

    /* Stop the SysTick */
    SYSTICK_STCTRL.ENABLES = DISABLE;
}

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
void SysTick_SetNotification(void)
{

    /* Check of the user filled the configuration Successfully*/
    if (NULL_PTR == SysTick_Config.Notification)
    {
        /* Configurations Error */
        return;
    }

    else
    {
        /* Configurations Successfully */
        /* No Action Required */
    }

    g_SysTick_Call_Back_Ptr = SysTick_Config.Notification;
}

/******************************************************************************
 * \Syntax             : void SysTick_Handler(void)
 * \Description        : Interrupt Service Routine for SysTick .
 * \Sync\Async         : Synchronous
 * \Reentrancy         : Reentrant
 * \Parameters (in)    : None.
 * \Parameters (inout) : None
 * \Parameters (out)   : None
 * \Return value       : None
 *******************************************************************************/
void SysTick_Handler(void)
{
    /* Check if the SysTick_setCallBack is already called */
    if (NULL_PTR != g_SysTick_Call_Back_Ptr)
    {
        /* call the functionusing call-back concept */
        (*g_SysTick_Call_Back_Ptr)();
    }

    else
    {
        /* Configurations Successfully */
        /* No Action Required */
    }
}
/**********************************************************************************************************************
 *  END OF FILE: SysTick.c
 *********************************************************************************************************************/

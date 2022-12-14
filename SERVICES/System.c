/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  System.c
 *        \brief
 *
 *      \details Source File for System Service .
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "System.h"
/**********************************************************************************************************************
 *  LOCAL MACROS CONSTANT\FUNCTION
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/


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
 * \Syntax             : void System_Init(void)
 * \Description        : Function to Init ECU.
 * \Sync\Async         : Synchronous.
 * \Reentrancy         : NonReentrant.
 * \Parameters (in)    : None.
 * \Parameters (inout) : None.
 * \Parameters (out)   : None.
 * \Return value:      : None.
 *******************************************************************************/
void System_Init(void)
{
    /* Intialize Port Driver according to user Configurations*/
	Port_Init(&Port_Configurations);

     /* Intialize NVIC Driver according to user Configurations*/
    IntCrtl_Init();

   
    
    /* Intialize SysTick Driver according to user Configurations*/
    SysTick_Init(&SysTick_Config);

     SysTick_Config.Notification = &Blinking_Change_Status;

     SysTick_SetNotification();

    /* Enable SysTick Intrrupt*/
    SysTick_EnableNotification();
}




/**********************************************************************************************************************
 *  END OF FILE: System.c
 *********************************************************************************************************************/

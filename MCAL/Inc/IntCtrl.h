/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IntCrtl.h
 *       Module:  IntCrtl
 *
 *  Description:  header file for NVIC Module    
 *  
 *********************************************************************************************************************/
#ifndef IntCrtl_H
#define IntCrtl_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "IntCtrl_Types.h"
#include "IntCtrl_Cfg.h"
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
 * \Syntax          : void IntCrtl_Init(void)
 * \Description     : initialize IntCrtl Module .
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : None
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/
void IntCrtl_Init(void);

/******************************************************************************
 * \Syntax          : void IntCtrl_EnableInterrupt(IntCtrl_InterruptID InterruptId, IntCtrl_InterruptPriorityLevel Priority)
 * \Description     : Enable the specified interrupt and assign prriority to it .
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : InterruptId -  the specified interrupt Id to be enabled .
 *                    Priority    -  the specified interrupt Priority .
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/
void IntCtrl_EnableInterrupt(IntCtrl_InterruptID InterruptId, IntCtrl_InterruptPriorityLevel Priority);

/******************************************************************************
 * \Syntax          : void IntCtrl_DisableInterrupt(IntCtrl_InterruptID InterruptId)
 * \Description     : Disable the specified interrupt Id .
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : InterruptId - the specified interrupt Id to be disabled .
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/
void IntCtrl_DisableInterrupt(IntCtrl_InterruptID InterruptId);
 
#endif  /* IntCrtl_H */

/**********************************************************************************************************************
 *  END OF FILE: IntCrtl.h
 *********************************************************************************************************************/

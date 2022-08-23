/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IntCtrl_Types.h
 *       Module:  -
 *
 *  Description:  Type Definition for Nvic Module     
 *  
 *********************************************************************************************************************/
#ifndef INTCTRL_TYPES_H
#define INTCTRL_TYPES_H

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


/* Type definition for IntCtrl_PriorityLevel used by the NVIC APIs */
typedef uint8 IntCtrl_PriorityLevel;

/* Type definition for IntCtrl_ExceptionType used by the NVIC APIs */
typedef enum IntCtrl_ExceptionType
{
	RESET                = 0,
	NMI                  = 1,
	HARD_FAULT           = 2,
	MEMORY_MANAGE_FAULT  = 3,
	BUS_FAULT            = 4,
	USAGE_FAULT          = 5,
	SVCALL               = 6,
	DEBUG_MONITOR        = 7,
	PENDSV               = 8,
	SYSTICK              = 9
} IntCtrl_ExceptionType;

/* Type definition for IntCtrl_InterruptType used by the NVIC APIs */
typedef enum IntCtrl_InterruptType
{
	/*** 16/32-Bit Timers ***/
	TIMER_16_32_BIT_0A = 19,
	TIMER_16_32_BIT_0B = 20,
	TIMER_16_32_BIT_1A = 21,
	TIMER_16_32_BIT_1B = 22,
	TIMER_16_32_BIT_2A = 23,
	TIMER_16_32_BIT_2B = 24,
	TIMER_16_32_BIT_3A = 35,
	TIMER_16_32_BIT_3B = 36,
	TIMER_16_32_BIT_4A = 70,
	TIMER_16_32_BIT_4B = 71,
	TIMER_16_32_BIT_5A = 92,
	TIMER_16_32_BIT_5B = 93,
	
	/*** 32/64-Bit Timers ***/
	TIMER_32_64_BIT_0A = 94,
	TIMER_32_64_BIT_0B = 95,
	TIMER_32_64_BIT_1A = 96,
	TIMER_32_64_BIT_1B = 97,
	TIMER_32_64_BIT_2A = 98,
	TIMER_32_64_BIT_2B = 99,
	TIMER_32_64_BIT_3A = 100,
	TIMER_32_64_BIT_3B = 101,
	TIMER_32_64_BIT_4A = 102,
	TIMER_32_64_BIT_4B = 103,
	TIMER_32_64_BIT_5A = 104,
	TIMER_32_64_BIT_5B = 105
} IntCtrl_InterruptType;

/* Type definition for IntCtrl_ExceptionModeType used by the NVIC APIs */
typedef enum IntCtrl_ExceptionModeType
{
	EXC_DISABLED = 0,
	EXC_ENABLED  = 1
} IntCtrl_ExceptionModeType;

/* Type definition for IntCtrl_InterruptModeType used by the NVIC APIs */
typedef enum IntCtrl_InterruptModeType
{
	INT_DISABLED = 0,
	INT_ENABLED  = 1
} IntCtrl_InterruptModeType;


/* Type definition for IntCtrl_ExceptionID used by the NVIC APIs */
typedef uint8 IntCtrl_ExceptionID;
/* Type definition for IntCtrl_ExceptionMode used by the NVIC APIs */
typedef uint8 IntCtrl_ExceptionMode;
/* Type definition for IntCtrl_ExceptionPriorityLevel used by the NVIC APIs */
typedef sint8 IntCtrl_ExceptionPriorityLevel;

/* Type definition for IntCtrl_ExceptionConfigType used by the NVIC APIs */
typedef struct IntCtrl_ExceptionConfigType
{
	IntCtrl_ExceptionID exceptionId;
	IntCtrl_ExceptionMode mode;
	IntCtrl_ExceptionPriorityLevel priority;

} IntCtrl_ExceptionConfigType;


/* Type definition for IntCtrl_InterruptID used by the NVIC APIs */
typedef uint8 IntCtrl_InterruptID;
/* Type definition for IntCtrl_InterruptMode used by the NVIC APIs */
typedef uint8 IntCtrl_InterruptMode;
/* Type definition for IntCtrl_InterruptPriorityLevel used by the NVIC APIs */
typedef uint8 IntCtrl_InterruptPriorityLevel;

/* Type definition for IntCtrl_InterruptConfigType used by the NVIC APIs */
typedef struct IntCtrl_InterruptConfigType
{
	IntCtrl_InterruptID interruptId;
	IntCtrl_InterruptMode mode;
	IntCtrl_InterruptPriorityLevel priority;

} IntCtrl_InterruptConfigType;


 
#endif  /* INTCTRL_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Types.h
 *********************************************************************************************************************/

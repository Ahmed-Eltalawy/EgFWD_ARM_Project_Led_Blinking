/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Common_Macros.h
 *       Module:  -
 *
 *  Description:  Commonly used Macros     
 *  
 *********************************************************************************************************************/
#ifndef COMMON_MACROS_H
#define COMMON_MACROS_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/* Set a certain bit in any register */
#define SET_BIT(REG,BIT) (REG|=(1<<BIT))

/* Clear a certain bit in any register */
#define CLEAR_BIT(REG,BIT) (REG&=(~(1<<BIT)))

/* Toggle a certain bit in any register */
#define TOGGLE_BIT(REG,BIT) (REG^=(1<<BIT))

/* Rotate right the register value with specific number of rotates */
#define ROR(REG,num) ( REG= (REG>>num) | (REG<<(8-num)) )

/* Rotate left the register value with specific number of rotates */
#define ROL(REG,num) ( REG= (REG<<num) | (REG>>(8-num)) )

/* Check if a specific bit is set in any register and return true if yes */
#define BIT_IS_SET(REG,BIT) ( REG & (1<<BIT) )

/* Check if a specific bit is cleared in any register and return true if yes */
#define BIT_IS_CLEAR(REG,BIT) ( !(REG & (1<<BIT)) )

/* Access Specific register */
#define GET_REG(BASE_ADDR , REG_OFFSET)                     (*((volatile uint32*)(BASE_ADDR+REG_OFFSET)))

/* Access Specific register */
#define GET_REGISTER(BASE_ADDR, REG_TYPE, REG_OFFSET)       (*((volatile REG_TYPE*)(BASE_ADDR+REG_OFFSET)))

/*Assembly instruction to enable interrupts "Change Processor State Interrupt Enable"*/
#define INTERRUPTS_ENABLE() __asm(" CPSIE i")

/*Assembly instruction to disable interrupts "Change Processor State Interrupt Enable"*/
#define INTERRUPTS_DISABLE() __asm(" CPSID i")

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

 
#endif  /* COMMON_MACROS_H */

/**********************************************************************************************************************
 *  END OF FILE: Common_Macros.h
 *********************************************************************************************************************/

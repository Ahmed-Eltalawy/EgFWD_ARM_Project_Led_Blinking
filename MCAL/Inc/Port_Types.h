/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Port_Types.h
 *       Module:  -
 *
 *  Description:  API Types Of Port Module      
 *  
 *********************************************************************************************************************/
#ifndef PORT_TYPES_H
#define PORT_TYPES_H

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

/* Type definition for Port_PinType used by the Port APIs */
typedef enum 
{
    PORT_A_0 = 0,
    PORT_A_1,
    PORT_A_2,
    PORT_A_3,
    PORT_A_4,
    PORT_A_5,
    PORT_A_6,
    PORT_A_7,

    PORT_B_0 = 0,
    PORT_B_1,
    PORT_B_2,
    PORT_B_3,
    PORT_B_4,
    PORT_B_5,
    PORT_B_6,
    PORT_B_7,

    PORT_C_0 = 0,
    PORT_C_1,
    PORT_C_2,
    PORT_C_3,
    PORT_C_4,
    PORT_C_5,
    PORT_C_6,
    PORT_C_7,

    PORT_D_0 = 0,
    PORT_D_1,
    PORT_D_2,
    PORT_D_3,
    PORT_D_4,
    PORT_D_5,
    PORT_D_6,
    PORT_D_7,

    PORT_E_0 = 0,
    PORT_E_1,
    PORT_E_2,
    PORT_E_3,
    PORT_E_4,
    PORT_E_5,

    PORT_F_0 = 0,
    PORT_F_1,
    PORT_F_2,
    PORT_F_3,
    PORT_F_4,
	
}Port_PinType;

/* Type definition for Port_NumberType used by the Port APIs */
typedef enum 
{
    PORT_A = 0,
    PORT_B,
    PORT_C,
    PORT_D,
    PORT_E,
    PORT_F,
	
}Port_NumberType;

/* Type definition for Port_PinDirectionType used by the Port APIs */
typedef enum 
{
    PIN_DIRECTION_INPUT  = 0,
    PIN_DIRECTION_OUTPUT,
	
}Port_PinDirectionType;


/* Type definition for Port_PinModeType used by the Port APIs */
typedef enum 
{
    PINMODE_DIGITAL = 0,          // This signal is controlled by Digital Module 
    PINMODE_ANALOG,               // This signal is controlled by Analog Module 
    PINMODE_UART,                 // This signal is controlled by UART Module 
    PINMODE_PWM,                  // This signal is controlled by PWM Module 
    PINMODE_TIMER_CAPTURE,        // This signal is controlled by Timer Capture Module 
    PINMODE_TIMER_COMPARE,        // This signal is controlled by Timer Compare Module 
    PINMODE_USB,                  // This signal is controlled by USB Module 
    PINMODE_CAN,                  // This signal is controlled by CAN Module 
    PINMODE_SSI,                  // This signal is controlled by SSI Module
    PINMODE_I2C,                  // This signal is controlled by I2C Module
    PINMODE_QEI,                  // This signal is controlled by QEI Module
    PINMODE_NMI,                  // Non Muskable Interrupt

}Port_PinModeType;

/* Type definition for Port_PinInternalAttachType used by the Port APIs */
typedef enum 
{
    PINATTACH_PULLUP    = 0,
    PINATTACH_PULLDOWN,
    PINATTACH_OPENDRAIN,
	
}Port_PinInternalAttachType;

/* Type definition for Port_PinOutputCurrentType used by the Port APIs */
typedef enum 
{
    PINOUTPUTCURRENT_2_MA = 0,
    PINOUTPUTCURRENT_4_MA,
    PINOUTPUTCURRENT_8_MA,
	
}Port_PinOutputCurrentType;


/* Type definition for Port_PinLevelType used by the Port APIs */
typedef enum 
{
    PIN_LEVEL_LOW = 0,
    PIN_LEVEL_HIGH,
	
}Port_PinLevelType;

/* Description: Structure to describe each individual PIN contains:
 *	1. the Pin  Number  Which the pin belongs to. 0, 1, 2 or 3 .....7 .
 *  2. the Port Number PORT_A , PORT_B or PORT_C ....PORT_F .
 *  3. the Port pin Mode UART, Analog or Digital .....
 *	4. the Port pin Level Value High or Low .
 *  5. the Port Pin direction of pin --> INPUT or OUTPUT
 *  6. the Port Pin Internal atatch which can be pullup, pull down or open drain .
 *  7. the Port Pin ourput current
 */

typedef struct 
{
    uint8 PinNumber;
    uint8 PortNumber;
    uint8 PortPinMode; 
	uint8 PortPinLevelValue; 
	uint8 PortPinDirection;
    uint8 PortPinInternalAttach;
    uint8 PortPinOutputCurrent; 
} Port_Channel_ConfigType;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 
#endif  /* PORT_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: Port_Types.h
 *********************************************************************************************************************/

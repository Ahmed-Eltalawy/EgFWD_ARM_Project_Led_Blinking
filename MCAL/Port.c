/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Port.c
 *        \brief
 *
 *      \details Port Module's driver
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "Port.h"

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
 * \Syntax          : void Port_Init(const Port_ConfigType* ConfigPtr)
 * \Description     : Function to Initialize Port Module.
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : ConfigPtr - Pointer to configuration data
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/
void Port_Init(const Port_ConfigType *ConfigPtr)
{
    /* Iterator Counter used to iterate on the array of the configuration strucrtues of all configures of Port Driver */
    uint8 counter = 0;

    /* Base Address of GPT Peripheral*/
    volatile uint32 *gptBaseAddress = NULL_PTR;

    if (NULL_PTR == ConfigPtr)
    {
        return; // Configurations Error .
    }

    else
    {
        /* No Action Required */
    }

    for (counter = 0; counter < PORT_CONFIGURED_CHANNLES; counter++)
    {

        switch (ConfigPtr->Channel[counter].PortNumber)
        {
        case PORT_A:

            /* Enable GPIO PORT_A Advanced High Performance Bus*/
            SYSTEM_CONTROL_REG_GPIOHBCTL.PORTA = ENABLE;

            /* Enable GPIO PORT_A Clock*/
            SYSTEM_CONTROL_REG_RCGCGPIO.R0 = ENABLE;

            /* Get the Base Address of GPIO PORT_A Module*/
            gptBaseAddress = (volatile uint32 *)GPIO_A_AHB_PERI_BASE_ADDRESS;

            break;
        case PORT_B:

            /* Enable GPIO PORT_B Advanced High Performance Bus*/
            SYSTEM_CONTROL_REG_GPIOHBCTL.PORTB = ENABLE;

            /* Enable GPIO PORT_B Clock*/
            SYSTEM_CONTROL_REG_RCGCGPIO.R1 = ENABLE;

            /* Get the Base Address of GPIO PORT_B Module*/
            gptBaseAddress = (volatile uint32 *)GPIO_B_AHB_PERI_BASE_ADDRESS;

            break;
        case PORT_C:
            /* Enable GPIO PORT_C Advanced High Performance Bus*/
            SYSTEM_CONTROL_REG_GPIOHBCTL.PORTC = ENABLE;

            /* Enable GPIO PORT_C Clock*/
            SYSTEM_CONTROL_REG_RCGCGPIO.R2 = ENABLE;

            /* Get the Base Address of GPIO PORT_C Module*/
            gptBaseAddress = (volatile uint32 *)GPIO_C_AHB_PERI_BASE_ADDRESS;

            break;
        case PORT_D:
            /* Enable GPIO PORT_D Advanced High Performance Bus*/
            SYSTEM_CONTROL_REG_GPIOHBCTL.PORTD = ENABLE;

            /* Enable GPIO PORT_D Clock*/
            SYSTEM_CONTROL_REG_RCGCGPIO.R3 = ENABLE;

            /* Get the Base Address of GPIO PORT_D Module*/
            gptBaseAddress = (volatile uint32 *)GPIO_D_AHB_PERI_BASE_ADDRESS;

        case PORT_E:
            /* Enable GPIO PORT_E Advanced High Performance Bus*/
            SYSTEM_CONTROL_REG_GPIOHBCTL.PORTE = ENABLE;

            /* Enable GPIO PORT_E Clock*/
            SYSTEM_CONTROL_REG_RCGCGPIO.R4 = ENABLE;

            /* Get the Base Address of GPIO PORT_E Module*/
            gptBaseAddress = (volatile uint32 *)GPIO_E_AHB_PERI_BASE_ADDRESS;

            break;
        case PORT_F:
            /* Enable GPIO PORT_F Advanced High Performance Bus*/
            SYSTEM_CONTROL_REG_GPIOHBCTL.PORTF = ENABLE;

            /* Enable GPIO PORT_F Clock*/
            SYSTEM_CONTROL_REG_RCGCGPIO.R5 = ENABLE;

            /* Get the Base Address of GPIO PORT_F Module*/
            gptBaseAddress = (volatile uint32 *)GPIO_F_AHB_PERI_BASE_ADDRESS;

            break;
        default:
            /* No Action Required */
            break;
        }

        /* Check of the user filled the configuration Successfully*/
        if (NULL_PTR == gptBaseAddress)
        {
            /* Configurations Error */
            return ;
        }

        else
        {
            /* Configurations Successfully */
            /* No Action Required */
        }
        /********************************Enable GPIO PORT Digital Mode **********************************/
        if (ConfigPtr->Channel[counter].PortPinMode == PINMODE_DIGITAL)
        {
            SET_BIT(GET_REGISTER((volatile uint8 *)gptBaseAddress, uint32, GPIODEN_OFFSET), ConfigPtr->Channel[counter].PinNumber);
        }
        else
        {
            /* No Action Required */
        }

        /********************************Set Port Pins Direction **********************************/
        if (ConfigPtr->Channel[counter].PortPinDirection == PIN_DIRECTION_OUTPUT)
        {
            SET_BIT(GET_REGISTER((volatile uint8 *)gptBaseAddress, uint32, GPIODIR_OFFSET), ConfigPtr->Channel[counter].PinNumber);
        }
        else if (ConfigPtr->Channel[counter].PortPinDirection == PIN_DIRECTION_INPUT)
        {
            CLEAR_BIT(GET_REGISTER((volatile uint8 *)gptBaseAddress, uint32, GPIODIR_OFFSET), ConfigPtr->Channel[counter].PinNumber);
        }
        else
        {
            /* No Action Required */
        }
        /********************************Set Port Pins Output Current **************************/
        if (ConfigPtr->Channel[counter].PortPinOutputCurrent == PINOUTPUTCURRENT_2_MA)
        {
            SET_BIT(GET_REGISTER((volatile uint8 *)gptBaseAddress, uint32, GPIODR2R_OFFSET), ConfigPtr->Channel[counter].PinNumber);
        }
        else if (ConfigPtr->Channel[counter].PortPinOutputCurrent == PINOUTPUTCURRENT_4_MA)
        {
            SET_BIT(GET_REGISTER((volatile uint8 *)gptBaseAddress, uint32, GPIODR4R_OFFSET), ConfigPtr->Channel[counter].PinNumber);
        }
        else if (ConfigPtr->Channel[counter].PortPinOutputCurrent == PINOUTPUTCURRENT_8_MA)
        {
            SET_BIT(GET_REGISTER((volatile uint8 *)gptBaseAddress, uint32, GPIODR8R_OFFSET), ConfigPtr->Channel[counter].PinNumber);
        }
        else
        {
            /* No Action Required */
        }

        /********************************Set Port Pins Internal Resitors **************************/
        if (ConfigPtr->Channel[counter].PortPinInternalAttach == PINATTACH_OPENDRAIN)
        {
            SET_BIT(GET_REGISTER((volatile uint8 *)gptBaseAddress, uint32, GPIOODR_OFFSET), ConfigPtr->Channel[counter].PinNumber);
        }
        else if (ConfigPtr->Channel[counter].PortPinInternalAttach == PINATTACH_PULLUP)
        {
            SET_BIT(GET_REGISTER((volatile uint8 *)gptBaseAddress, uint32, GPIOPUR_OFFSET), ConfigPtr->Channel[counter].PinNumber);
        }
        else if (ConfigPtr->Channel[counter].PortPinInternalAttach == PINATTACH_PULLDOWN)
        {
            SET_BIT(GET_REGISTER((volatile uint8 *)gptBaseAddress, uint32, GPIOPDR_OFFSET), ConfigPtr->Channel[counter].PinNumber);
        }
        else
        {
            /* No Action Required */
        }

        /********************************Set Port Pins Level **********************************/
        if (ConfigPtr->Channel[counter].PortPinLevelValue == PIN_LEVEL_HIGH)
        {
            SET_BIT(GET_REGISTER((volatile uint8 *)gptBaseAddress, uint32, GPIODATA_OFFSET), ConfigPtr->Channel[counter].PinNumber);
        }
        else if (ConfigPtr->Channel[counter].PortPinLevelValue == PIN_LEVEL_LOW)
        {
            CLEAR_BIT(GET_REGISTER((volatile uint8 *)gptBaseAddress, uint32, GPIODATA_OFFSET), ConfigPtr->Channel[counter].PinNumber);
        }
        else
        {
            /* No Action Required */
        }
    }
}

/**********************************************************************************************************************
 *  END OF FILE: Port.c
 *********************************************************************************************************************/

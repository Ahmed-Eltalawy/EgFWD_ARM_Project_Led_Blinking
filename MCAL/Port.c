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

		uint8 counter = 0;
    /*
    Note that each GPIO module clock must be enabled before the registers can be programmed (see
    page 340). There must be a delay of 3 system clocks after the GPIO module clock is enabled before
    any GPIO module registers are accessed .
    */
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
        case PORTNUMBER_A:

            /********************************Set PortA Pins Direction **********************************/
            if (ConfigPtr->Channel[counter].PortPinDirection == PIN_DIRECTION_INPUT)
            {
                SET_BIT(GET_REG(GPIO_A_AHB_PERI_BASE_ADDRESS, GPIODIR_OFFSET), ConfigPtr->Channel[counter].PinNumber);
            }
            else if (ConfigPtr->Channel[counter].PortPinDirection == PIN_DIRECTION_OUTPUT)
            {
                CLEAR_BIT(GET_REG(GPIO_A_AHB_PERI_BASE_ADDRESS, GPIODIR_OFFSET), ConfigPtr->Channel[counter].PinNumber);
            }
            else
            {
                /* No Action Required */
            }
            /********************************Set PortA Pins Output Current **************************/
            if (ConfigPtr->Channel[counter].PortPinOutputCurrent == PINOUTPUTCURRENT_2_MA)
            {
                SET_BIT(GET_REG(GPIO_A_AHB_PERI_BASE_ADDRESS, GPIODR2R_OFFSET), ConfigPtr->Channel[counter].PinNumber);
            }
            else if (ConfigPtr->Channel[counter].PortPinOutputCurrent == PINOUTPUTCURRENT_4_MA)
            {
                SET_BIT(GET_REG(GPIO_A_AHB_PERI_BASE_ADDRESS, GPIODR4R_OFFSET), ConfigPtr->Channel[counter].PinNumber);
            }
            else if (ConfigPtr->Channel[counter].PortPinOutputCurrent == PINOUTPUTCURRENT_8_MA)
            {
                SET_BIT(GET_REG(GPIO_A_AHB_PERI_BASE_ADDRESS, GPIODR8R_OFFSET), ConfigPtr->Channel[counter].PinNumber);
            }
            else
            {
                /* No Action Required */
            }

            /********************************Set PortA Pins Internal Resitors **************************/
            if (ConfigPtr->Channel[counter].PortPinInternalAttach == PINATTACH_OPENDRAIN)
            {
                SET_BIT(GET_REG(GPIO_A_AHB_PERI_BASE_ADDRESS, GPIOODR_OFFSET), ConfigPtr->Channel[counter].PinNumber);
            }
            else if (ConfigPtr->Channel[counter].PortPinInternalAttach == PINATTACH_PULLUP)
            {
                SET_BIT(GET_REG(GPIO_A_AHB_PERI_BASE_ADDRESS, GPIOPUR_OFFSET), ConfigPtr->Channel[counter].PinNumber);
            }
            else if (ConfigPtr->Channel[counter].PortPinInternalAttach == PINATTACH_PULLDOWN)
            {
                SET_BIT(GET_REG(GPIO_A_AHB_PERI_BASE_ADDRESS, GPIOPDR_OFFSET), ConfigPtr->Channel[counter].PinNumber);
            }
            else
            {
                /* No Action Required */
            }

            /********************************Set PortA Pins Level **********************************/
            if (ConfigPtr->Channel[counter].PortPinLevelValue == PIN_LEVEL_HIGH)
            {
                SET_BIT(GET_REG(GPIO_A_AHB_PERI_BASE_ADDRESS, GPIODATA_OFFSET), ConfigPtr->Channel[counter].PinNumber);
            }
            else if (ConfigPtr->Channel[counter].PortPinLevelValue == PIN_LEVEL_LOW)
            {
                CLEAR_BIT(GET_REG(GPIO_A_AHB_PERI_BASE_ADDRESS, GPIODATA_OFFSET), ConfigPtr->Channel[counter].PinNumber);
            }
            else
            {
                /* No Action Required */
            }
            break;
        case PORTNUMBER_B:
            /********************************Set PortB Pins Direction **********************************/
            if (ConfigPtr->Channel[counter].PortPinDirection == PIN_DIRECTION_INPUT)
            {
                SET_BIT(GET_REG(GPIO_B_AHB_PERI_BASE_ADDRESS, GPIODIR_OFFSET), ConfigPtr->Channel[counter].PinNumber);
            }
            else if (ConfigPtr->Channel[counter].PortPinDirection == PIN_DIRECTION_OUTPUT)
            {
                CLEAR_BIT(GET_REG(GPIO_B_AHB_PERI_BASE_ADDRESS, GPIODIR_OFFSET), ConfigPtr->Channel[counter].PinNumber);
            }
            else
            {
                /* No Action Required */
            }

            /********************************Set PortB Pins Output Current **************************/
            if (ConfigPtr->Channel[counter].PortPinOutputCurrent == PINOUTPUTCURRENT_2_MA)
            {
                SET_BIT(GET_REG(GPIO_B_AHB_PERI_BASE_ADDRESS, GPIODR2R_OFFSET), ConfigPtr->Channel[counter].PinNumber);
            }
            else if (ConfigPtr->Channel[counter].PortPinOutputCurrent == PINOUTPUTCURRENT_4_MA)
            {
                SET_BIT(GET_REG(GPIO_B_AHB_PERI_BASE_ADDRESS, GPIODR4R_OFFSET), ConfigPtr->Channel[counter].PinNumber);
            }
            else if (ConfigPtr->Channel[counter].PortPinOutputCurrent == PINOUTPUTCURRENT_8_MA)
            {
                SET_BIT(GET_REG(GPIO_B_AHB_PERI_BASE_ADDRESS, GPIODR8R_OFFSET), ConfigPtr->Channel[counter].PinNumber);
            }
            else
            {
                /* No Action Required */
            }

            /********************************Set PortB Pins Internal Resitors **************************/
            if (ConfigPtr->Channel[counter].PortPinInternalAttach == PINATTACH_OPENDRAIN)
            {
                SET_BIT(GET_REG(GPIO_B_AHB_PERI_BASE_ADDRESS, GPIOODR_OFFSET), ConfigPtr->Channel[counter].PinNumber);
            }
            else if (ConfigPtr->Channel[counter].PortPinInternalAttach == PINATTACH_PULLUP)
            {
                SET_BIT(GET_REG(GPIO_B_AHB_PERI_BASE_ADDRESS, GPIOPUR_OFFSET), ConfigPtr->Channel[counter].PinNumber);
            }
            else if (ConfigPtr->Channel[counter].PortPinInternalAttach == PINATTACH_PULLDOWN)
            {
                SET_BIT(GET_REG(GPIO_B_AHB_PERI_BASE_ADDRESS, GPIOPDR_OFFSET), ConfigPtr->Channel[counter].PinNumber);
            }
            else
            {
                /* No Action Required */
            }

            /********************************Set PortB Pins Level **********************************/
            if (ConfigPtr->Channel[counter].PortPinLevelValue == PIN_LEVEL_HIGH)
            {
                SET_BIT(GET_REG(GPIO_B_AHB_PERI_BASE_ADDRESS, GPIODATA_OFFSET), ConfigPtr->Channel[counter].PinNumber);
            }
            else if (ConfigPtr->Channel[counter].PortPinLevelValue == PIN_LEVEL_LOW)
            {
                CLEAR_BIT(GET_REG(GPIO_B_AHB_PERI_BASE_ADDRESS, GPIODATA_OFFSET), ConfigPtr->Channel[counter].PinNumber);
            }
            else
            {
                /* No Action Required */
            }
            break;
        case PORTNUMBER_C:
            /********************************Set PortC Pins Direction **********************************/
            if (ConfigPtr->Channel[counter].PortPinDirection == PIN_DIRECTION_INPUT)
            {
                SET_BIT(GET_REG(GPIO_C_AHB_PERI_BASE_ADDRESS, GPIODIR_OFFSET), ConfigPtr->Channel[counter].PinNumber);
            }
            else if (ConfigPtr->Channel[counter].PortPinDirection == PIN_DIRECTION_OUTPUT)
            {
                CLEAR_BIT(GET_REG(GPIO_C_AHB_PERI_BASE_ADDRESS, GPIODIR_OFFSET), ConfigPtr->Channel[counter].PinNumber);
            }
            else
            {
                /* No Action Required */
            }

            /********************************Set PortC Pins Output Current **************************/
            if (ConfigPtr->Channel[counter].PortPinOutputCurrent == PINOUTPUTCURRENT_2_MA)
            {
                SET_BIT(GET_REG(GPIO_C_AHB_PERI_BASE_ADDRESS, GPIODR2R_OFFSET), ConfigPtr->Channel[counter].PinNumber);
            }
            else if (ConfigPtr->Channel[counter].PortPinOutputCurrent == PINOUTPUTCURRENT_4_MA)
            {
                SET_BIT(GET_REG(GPIO_C_AHB_PERI_BASE_ADDRESS, GPIODR4R_OFFSET), ConfigPtr->Channel[counter].PinNumber);
            }
            else if (ConfigPtr->Channel[counter].PortPinOutputCurrent == PINOUTPUTCURRENT_8_MA)
            {
                SET_BIT(GET_REG(GPIO_C_AHB_PERI_BASE_ADDRESS, GPIODR8R_OFFSET), ConfigPtr->Channel[counter].PinNumber);
            }
            else
            {
                /* No Action Required */
            }

            /********************************Set PortC Pins Internal Resitors **************************/
            if (ConfigPtr->Channel[counter].PortPinInternalAttach == PINATTACH_OPENDRAIN)
            {
                SET_BIT(GET_REG(GPIO_C_AHB_PERI_BASE_ADDRESS, GPIOODR_OFFSET), ConfigPtr->Channel[counter].PinNumber);
            }
            else if (ConfigPtr->Channel[counter].PortPinInternalAttach == PINATTACH_PULLUP)
            {
                SET_BIT(GET_REG(GPIO_C_AHB_PERI_BASE_ADDRESS, GPIOPUR_OFFSET), ConfigPtr->Channel[counter].PinNumber);
            }
            else if (ConfigPtr->Channel[counter].PortPinInternalAttach == PINATTACH_PULLDOWN)
            {
                SET_BIT(GET_REG(GPIO_C_AHB_PERI_BASE_ADDRESS, GPIOPDR_OFFSET), ConfigPtr->Channel[counter].PinNumber);
            }
            else
            {
                /* No Action Required */
            }

            /********************************Set PortC Pins Level **********************************/
            if (ConfigPtr->Channel[counter].PortPinLevelValue == PIN_LEVEL_HIGH)
            {
                SET_BIT(GET_REG(GPIO_C_AHB_PERI_BASE_ADDRESS, GPIODATA_OFFSET), ConfigPtr->Channel[counter].PinNumber);
            }
            else if (ConfigPtr->Channel[counter].PortPinLevelValue == PIN_LEVEL_LOW)
            {
                CLEAR_BIT(GET_REG(GPIO_C_AHB_PERI_BASE_ADDRESS, GPIODATA_OFFSET), ConfigPtr->Channel[counter].PinNumber);
            }
            else
            {
                /* No Action Required */
            }
            break;
        case PORTNUMBER_D:
            /********************************Set PortD Pins Direction **********************************/
            if (ConfigPtr->Channel[counter].PortPinDirection == PIN_DIRECTION_INPUT)
            {
                SET_BIT(GET_REG(GPIO_D_AHB_PERI_BASE_ADDRESS, GPIODIR_OFFSET), ConfigPtr->Channel[counter].PinNumber);
            }
            else if (ConfigPtr->Channel[counter].PortPinDirection == PIN_DIRECTION_OUTPUT)
            {
                CLEAR_BIT(GET_REG(GPIO_D_AHB_PERI_BASE_ADDRESS, GPIODIR_OFFSET), ConfigPtr->Channel[counter].PinNumber);
            }
            else
            {
                /* No Action Required */
            }
            /********************************Set PortD Pins Output Current **************************/
            if (ConfigPtr->Channel[counter].PortPinOutputCurrent == PINOUTPUTCURRENT_2_MA)
            {
                SET_BIT(GET_REG(GPIO_D_AHB_PERI_BASE_ADDRESS, GPIODR2R_OFFSET), ConfigPtr->Channel[counter].PinNumber);
            }
            else if (ConfigPtr->Channel[counter].PortPinOutputCurrent == PINOUTPUTCURRENT_4_MA)
            {
                SET_BIT(GET_REG(GPIO_D_AHB_PERI_BASE_ADDRESS, GPIODR4R_OFFSET), ConfigPtr->Channel[counter].PinNumber);
            }
            else if (ConfigPtr->Channel[counter].PortPinOutputCurrent == PINOUTPUTCURRENT_8_MA)
            {
                SET_BIT(GET_REG(GPIO_D_AHB_PERI_BASE_ADDRESS, GPIODR8R_OFFSET), ConfigPtr->Channel[counter].PinNumber);
            }
            else
            {
                /* No Action Required */
            }

            /********************************Set PortD Pins Internal Resitors **************************/
            if (ConfigPtr->Channel[counter].PortPinInternalAttach == PINATTACH_OPENDRAIN)
            {
                SET_BIT(GET_REG(GPIO_D_AHB_PERI_BASE_ADDRESS, GPIOODR_OFFSET), ConfigPtr->Channel[counter].PinNumber);
            }
            else if (ConfigPtr->Channel[counter].PortPinInternalAttach == PINATTACH_PULLUP)
            {
                SET_BIT(GET_REG(GPIO_D_AHB_PERI_BASE_ADDRESS, GPIOPUR_OFFSET), ConfigPtr->Channel[counter].PinNumber);
            }
            else if (ConfigPtr->Channel[counter].PortPinInternalAttach == PINATTACH_PULLDOWN)
            {
                SET_BIT(GET_REG(GPIO_D_AHB_PERI_BASE_ADDRESS, GPIOPDR_OFFSET), ConfigPtr->Channel[counter].PinNumber);
            }
            else
            {
                /* No Action Required */
            }

            /********************************Set PortD Pins Level **********************************/
            if (ConfigPtr->Channel[counter].PortPinLevelValue == PIN_LEVEL_HIGH)
            {
                SET_BIT(GET_REG(GPIO_D_AHB_PERI_BASE_ADDRESS, GPIODATA_OFFSET), ConfigPtr->Channel[counter].PinNumber);
            }
            else if (ConfigPtr->Channel[counter].PortPinLevelValue == PIN_LEVEL_LOW)
            {
                CLEAR_BIT(GET_REG(GPIO_D_AHB_PERI_BASE_ADDRESS, GPIODATA_OFFSET), ConfigPtr->Channel[counter].PinNumber);
            }
            else
            {
                /* No Action Required */
            }
            break;
        case PORTNUMBER_E:
            /********************************Set PortE Pins Direction **********************************/
            if (ConfigPtr->Channel[counter].PortPinDirection == PIN_DIRECTION_INPUT)
            {
                SET_BIT(GET_REG(GPIO_E_AHB_PERI_BASE_ADDRESS, GPIODIR_OFFSET), ConfigPtr->Channel[counter].PinNumber);
            }
            else if (ConfigPtr->Channel[counter].PortPinDirection == PIN_DIRECTION_OUTPUT)
            {
                CLEAR_BIT(GET_REG(GPIO_E_AHB_PERI_BASE_ADDRESS, GPIODIR_OFFSET), ConfigPtr->Channel[counter].PinNumber);
            }
            else
            {
                /* No Action Required */
            }

            /********************************Set PortE Pins Output Current **************************/
            if (ConfigPtr->Channel[counter].PortPinOutputCurrent == PINOUTPUTCURRENT_2_MA)
            {
                SET_BIT(GET_REG(GPIO_E_AHB_PERI_BASE_ADDRESS, GPIODR2R_OFFSET), ConfigPtr->Channel[counter].PinNumber);
            }
            else if (ConfigPtr->Channel[counter].PortPinOutputCurrent == PINOUTPUTCURRENT_4_MA)
            {
                SET_BIT(GET_REG(GPIO_E_AHB_PERI_BASE_ADDRESS, GPIODR4R_OFFSET), ConfigPtr->Channel[counter].PinNumber);
            }
            else if (ConfigPtr->Channel[counter].PortPinOutputCurrent == PINOUTPUTCURRENT_8_MA)
            {
                SET_BIT(GET_REG(GPIO_E_AHB_PERI_BASE_ADDRESS, GPIODR8R_OFFSET), ConfigPtr->Channel[counter].PinNumber);
            }
            else
            {
                /* No Action Required */
            }

            /********************************Set PortE Pins Internal Resitors **************************/
            if (ConfigPtr->Channel[counter].PortPinInternalAttach == PINATTACH_OPENDRAIN)
            {
                SET_BIT(GET_REG(GPIO_E_AHB_PERI_BASE_ADDRESS, GPIOODR_OFFSET), ConfigPtr->Channel[counter].PinNumber);
            }
            else if (ConfigPtr->Channel[counter].PortPinInternalAttach == PINATTACH_PULLUP)
            {
                SET_BIT(GET_REG(GPIO_E_AHB_PERI_BASE_ADDRESS, GPIOPUR_OFFSET), ConfigPtr->Channel[counter].PinNumber);
            }
            else if (ConfigPtr->Channel[counter].PortPinInternalAttach == PINATTACH_PULLDOWN)
            {
                SET_BIT(GET_REG(GPIO_E_AHB_PERI_BASE_ADDRESS, GPIOPDR_OFFSET), ConfigPtr->Channel[counter].PinNumber);
            }
            else
            {
                /* No Action Required */
            }

            /********************************Set PortE Pins Level **********************************/
            if (ConfigPtr->Channel[counter].PortPinLevelValue == PIN_LEVEL_HIGH)
            {
                SET_BIT(GET_REG(GPIO_E_AHB_PERI_BASE_ADDRESS, GPIODATA_OFFSET), ConfigPtr->Channel[counter].PinNumber);
            }
            else if (ConfigPtr->Channel[counter].PortPinLevelValue == PIN_LEVEL_LOW)
            {
                CLEAR_BIT(GET_REG(GPIO_E_AHB_PERI_BASE_ADDRESS, GPIODATA_OFFSET), ConfigPtr->Channel[counter].PinNumber);
            }
            else
            {
                /* No Action Required */
            }
            break;
        case PORTNUMBER_F:
            /********************************Set PortF Pins Direction **********************************/
            if (ConfigPtr->Channel[counter].PortPinDirection == PIN_DIRECTION_INPUT)
            {
                SET_BIT(GET_REG(GPIO_F_AHB_PERI_BASE_ADDRESS, GPIODIR_OFFSET), ConfigPtr->Channel[counter].PinNumber);
            }
            else if (ConfigPtr->Channel[counter].PortPinDirection == PIN_DIRECTION_OUTPUT)
            {
                CLEAR_BIT(GET_REG(GPIO_F_AHB_PERI_BASE_ADDRESS, GPIODIR_OFFSET), ConfigPtr->Channel[counter].PinNumber);
            }
            else
            {
                /* No Action Required */
            }
            /********************************Set PortF Pins Output Current **************************/
            if (ConfigPtr->Channel[counter].PortPinOutputCurrent == PINOUTPUTCURRENT_2_MA)
            {
                SET_BIT(GET_REG(GPIO_F_AHB_PERI_BASE_ADDRESS, GPIODR2R_OFFSET), ConfigPtr->Channel[counter].PinNumber);
            }
            else if (ConfigPtr->Channel[counter].PortPinOutputCurrent == PINOUTPUTCURRENT_4_MA)
            {
                SET_BIT(GET_REG(GPIO_F_AHB_PERI_BASE_ADDRESS, GPIODR4R_OFFSET), ConfigPtr->Channel[counter].PinNumber);
            }
            else if (ConfigPtr->Channel[counter].PortPinOutputCurrent == PINOUTPUTCURRENT_8_MA)
            {
                SET_BIT(GET_REG(GPIO_F_AHB_PERI_BASE_ADDRESS, GPIODR8R_OFFSET), ConfigPtr->Channel[counter].PinNumber);
            }
            else
            {
                /* No Action Required */
            }
     

            /********************************Set PortF Pins Internal Resitors **************************/
            if (ConfigPtr->Channel[counter].PortPinInternalAttach == PINATTACH_OPENDRAIN)
            {
                SET_BIT(GET_REG(GPIO_F_AHB_PERI_BASE_ADDRESS, GPIOODR_OFFSET), ConfigPtr->Channel[counter].PinNumber);
            }
            else if (ConfigPtr->Channel[counter].PortPinInternalAttach == PINATTACH_PULLUP)
            {
                SET_BIT(GET_REG(GPIO_F_AHB_PERI_BASE_ADDRESS, GPIOPUR_OFFSET), ConfigPtr->Channel[counter].PinNumber);
            }
            else if (ConfigPtr->Channel[counter].PortPinInternalAttach == PINATTACH_PULLDOWN)
            {
                SET_BIT(GET_REG(GPIO_F_AHB_PERI_BASE_ADDRESS, GPIOPDR_OFFSET), ConfigPtr->Channel[counter].PinNumber);
            }
            else
            {
                /* No Action Required */
            }

            /********************************Set PortF Pins Level **********************************/
            if (ConfigPtr->Channel[counter].PortPinLevelValue == PIN_LEVEL_HIGH)
            {
                SET_BIT(GET_REG(GPIO_F_AHB_PERI_BASE_ADDRESS, GPIODATA_OFFSET), ConfigPtr->Channel[counter].PinNumber);
            }
            else if (ConfigPtr->Channel[counter].PortPinLevelValue == PIN_LEVEL_LOW)
            {
                CLEAR_BIT(GET_REG(GPIO_F_AHB_PERI_BASE_ADDRESS, GPIODATA_OFFSET), ConfigPtr->Channel[counter].PinNumber);
            }
            else
            {
                /* No Action Required */
            }
						break;
        default:
            /* No Action Required */
            break;
        }
    }
}

/**********************************************************************************************************************
 *  END OF FILE: Port.c
 *********************************************************************************************************************/

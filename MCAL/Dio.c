/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Dio.c
 *        \brief
 *
 *      \details  Dio Module's driver
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "Dio.h"

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
 * \Syntax          : Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
 * \Description     : Function to return the value of the specified DIO channel.
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Reentrant
 * \Parameters (in) : ChannelId - ID of DIO channel.
 * \Parameters (out): None
 * \Return value:   : Dio_LevelType - the value of the specified DIO channel .
 *******************************************************************************/
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{

    /* Intial Value for Output Level*/
    Dio_LevelType outputLevel = DIO_LEVEL_ERROR;

    /* Check if the used channel is within the valid range */
    if (DIO_CONFIGURED_CHANNLES <= ChannelId)
    {

        return DIO_LEVEL_ERROR;
    }
    else
    {
        /* No Action Required */
    }

    /* Check if the used channel is within the valid Port range and read the requied channel*/
    switch (Dio_Configuration.Channels[ChannelId].Port_Number)
    {
    case PORT_A:
        if (BIT_IS_SET(GET_REG(GPIO_A_AHB_PERI_BASE_ADDRESS, GPIODATA_OFFSET), Dio_Configuration.Channels[ChannelId].Channel_Number))
        {
            outputLevel = DIO_LEVEL_HIGH;
        }

        else
        {
            outputLevel = DIO_LEVEL_LOW;
        }

        break;

    case PORT_B:
        if (BIT_IS_SET(GET_REG(GPIO_B_AHB_PERI_BASE_ADDRESS, GPIODATA_OFFSET), Dio_Configuration.Channels[ChannelId].Channel_Number))
        {
            outputLevel = DIO_LEVEL_HIGH;
        }

        else
        {
            outputLevel = DIO_LEVEL_LOW;
        }

        break;
    case PORT_C:
        if (BIT_IS_SET(GET_REG(GPIO_C_AHB_PERI_BASE_ADDRESS, GPIODATA_OFFSET), Dio_Configuration.Channels[ChannelId].Channel_Number))
        {
            outputLevel = DIO_LEVEL_HIGH;
        }

        else
        {
            outputLevel = DIO_LEVEL_LOW;
        }

        break;

    case PORT_D:
        if (BIT_IS_SET(GET_REG(GPIO_D_AHB_PERI_BASE_ADDRESS, GPIODATA_OFFSET), Dio_Configuration.Channels[ChannelId].Channel_Number))
        {
            outputLevel = DIO_LEVEL_HIGH;
        }

        else
        {
            outputLevel = DIO_LEVEL_LOW;
        }

        break;

    case PORT_E:
        if (BIT_IS_SET(GET_REG(GPIO_E_AHB_PERI_BASE_ADDRESS, GPIODATA_OFFSET), Dio_Configuration.Channels[ChannelId].Channel_Number))
        {
            outputLevel = DIO_LEVEL_HIGH;
        }

        else
        {
            outputLevel = DIO_LEVEL_LOW;
        }

        break;

    case PORT_F:
        if (BIT_IS_SET(GET_REG(GPIO_F_AHB_PERI_BASE_ADDRESS, GPIODATA_OFFSET), Dio_Configuration.Channels[ChannelId].Channel_Number))
        {
            outputLevel = DIO_LEVEL_HIGH;
        }

        else
        {
            outputLevel = DIO_LEVEL_LOW;
        }

        break;

    default:
        /* Error In Port Number Configuration */
        outputLevel = DIO_LEVEL_ERROR;
        break;
    }

    /* return the value of the specified DIO channel. */
    return outputLevel;
}

/******************************************************************************
 * \Syntax          : void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level)
 * \Description     : Function to set a level of a channel .
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Reentrant
 * \Parameters (in) : ChannelId - ID of DIO channel.
 *                    Level - Value to be written.
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level)
{

    /* Check if the used channel is within the valid range */
    if (DIO_CONFIGURED_CHANNLES <= ChannelId)
    {

        /* return error */
        return;
    }
    else
    {
        /* No Action Required */
    }

    /* Base Address of GPT Peripheral*/
    volatile uint32 *gptBaseAddress = NULL_PTR;

    /* Check if the used channel is within the valid Port range and Write the requied level on the requied channel*/
    switch (Dio_Configuration.Channels[ChannelId].Port_Number)
    {
    case PORT_A:
        /* Get the Base Address of GPIO PORT_A Module*/
        gptBaseAddress = (volatile uint32 *)GPIO_A_AHB_PERI_BASE_ADDRESS;
        break;
    case PORT_B:
        /* Get the Base Address of GPIO PORT_B Module*/
        gptBaseAddress = (volatile uint32 *)GPIO_B_AHB_PERI_BASE_ADDRESS;
        break;
    case PORT_C:
        /* Get the Base Address of GPIO PORT_C Module*/
        gptBaseAddress = (volatile uint32 *)GPIO_C_AHB_PERI_BASE_ADDRESS;
        break;

    case PORT_D:
        /* Get the Base Address of GPIO PORT_D Module*/
        gptBaseAddress = (volatile uint32 *)GPIO_D_AHB_PERI_BASE_ADDRESS;
        break;

    case PORT_E:
        /* Get the Base Address of GPIO PORT_E Module*/
        gptBaseAddress = (volatile uint32 *)GPIO_E_AHB_PERI_BASE_ADDRESS;
        break;

    case PORT_F:
        /* Get the Base Address of GPIO PORT_F Module*/
        gptBaseAddress = (volatile uint32 *)GPIO_F_AHB_PERI_BASE_ADDRESS;
        break;

    default:
        /* Error In Port Number Configuration */
        break;
    }
    /* Check of the user filled the configuration Successfully*/
    if (NULL_PTR == gptBaseAddress)
    {
        /* Configurations Error */
        return;
    }

    else
    {
        /* Configurations Successfully */
        /* No Action Required */
    }
    if (Level == DIO_LEVEL_HIGH)
    {
        /* Write Logic High */
        SET_BIT(GET_REGISTER((volatile uint8 *)gptBaseAddress, uint32, GPIODATA_OFFSET), Dio_Configuration.Channels[ChannelId].Channel_Number);
    }
    else
    {
        /* Write Logic Low */
        CLEAR_BIT(GET_REGISTER((volatile uint8 *)gptBaseAddress, uint32, GPIODATA_OFFSET), Dio_Configuration.Channels[ChannelId].Channel_Number);
    }
}

/******************************************************************************
 * \Syntax          : Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId)
 * \Description     : Function to return the value of the specified Port ID Level .
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Reentrant
 * \Parameters (in) : PortId - ID of Port.
 * \Parameters (out): None
 * \Return value:   : Dio_PortLevelType - Level of Port .
 *******************************************************************************/
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId)
{
    /* Intial Value for port Output Level*/
    Dio_PortLevelType outputPort = 0;

    /* Check if the used channel is within the valid Port range and return the port level */
    switch (Dio_Configuration.Channels[PortId].Port_Number)
    {
    case PORT_A:
        outputPort = (Dio_PortLevelType)GET_REG(GPIO_A_AHB_PERI_BASE_ADDRESS, GPIODATA_OFFSET);
        break;

    case PORT_B:
        outputPort = (Dio_PortLevelType)GET_REG(GPIO_B_AHB_PERI_BASE_ADDRESS, GPIODATA_OFFSET);
        break;

    case PORT_C:
        outputPort = (Dio_PortLevelType)GET_REG(GPIO_C_AHB_PERI_BASE_ADDRESS, GPIODATA_OFFSET);
        break;

    case PORT_D:
        outputPort = (Dio_PortLevelType)GET_REG(GPIO_D_AHB_PERI_BASE_ADDRESS, GPIODATA_OFFSET);
        break;

    case PORT_E:
        outputPort = (Dio_PortLevelType)GET_REG(GPIO_E_AHB_PERI_BASE_ADDRESS, GPIODATA_OFFSET);
        break;

    case PORT_F:
        outputPort = (Dio_PortLevelType)GET_REG(GPIO_F_AHB_PERI_BASE_ADDRESS, GPIODATA_OFFSET);
        break;

    default:
        /* Error In Port Number Configuration */
        break;
    }

    /* return the level value of the specified Port. */
    return outputPort;
}

/******************************************************************************
 * \Syntax          : void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level)
 * \Description     : Function to set a level of a Port .
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Reentrant
 * \Parameters (in) : PortId - ID of Port.
 *                    Level - Level to be written.
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/
void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level)
{

    /* Check if the used port is within the valid Port range and write the port level */
    switch (Dio_Configuration.Channels[PortId].Port_Number)
    {
    case PORT_A:
        GET_REG(GPIO_A_AHB_PERI_BASE_ADDRESS, GPIODATA_OFFSET) = Level;
        break;

    case PORT_B:
        GET_REG(GPIO_B_AHB_PERI_BASE_ADDRESS, GPIODATA_OFFSET) = Level;
        break;

    case PORT_C:
        GET_REG(GPIO_C_AHB_PERI_BASE_ADDRESS, GPIODATA_OFFSET) = Level;
        break;

    case PORT_D:
        GET_REG(GPIO_D_AHB_PERI_BASE_ADDRESS, GPIODATA_OFFSET) = Level;
        break;

    case PORT_E:
        GET_REG(GPIO_E_AHB_PERI_BASE_ADDRESS, GPIODATA_OFFSET) = Level;
        break;

    case PORT_F:
        GET_REG(GPIO_F_AHB_PERI_BASE_ADDRESS, GPIODATA_OFFSET) = Level;
        break;

    default:
        /* Error In Port Number Configuration */
        break;
    }
}

/******************************************************************************
 * \Syntax          : Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId)
 * \Description     : Function to flip the level of a channel and return the level of the channel after flip.
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Reentrant
 * \Parameters (in) : ChannelId - ID of DIO channel.
 * \Parameters (out): None
 * \Return value:   : Dio_LevelType - Level of the specified channel after toggle .
 *******************************************************************************/
Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId)
{

    /* Intial Value for Output Level*/
    Dio_LevelType outputLevel = DIO_LEVEL_ERROR;

    /* Check if the used channel is within the valid range */
    if (DIO_CONFIGURED_CHANNLES <= ChannelId)
    {

        return DIO_LEVEL_ERROR;
    }
    else
    {
        /* No Action Required */
    }

    /* Check if the used channel is within the valid Port range and toggle the requied channel*/
    switch (Dio_Configuration.Channels[ChannelId].Port_Number)
    {
    case PORT_A:
        if (BIT_IS_SET(GET_REG(GPIO_A_AHB_PERI_BASE_ADDRESS, GPIODATA_OFFSET), Dio_Configuration.Channels[ChannelId].Channel_Number))
        {
            /* Write Logic Low */
            CLEAR_BIT(GET_REG(GPIO_A_AHB_PERI_BASE_ADDRESS, GPIODATA_OFFSET), Dio_Configuration.Channels[ChannelId].Channel_Number);
            outputLevel = DIO_LEVEL_LOW;
        }

        else
        {
            /* Write Logic High */
            SET_BIT(GET_REG(GPIO_A_AHB_PERI_BASE_ADDRESS, GPIODATA_OFFSET), Dio_Configuration.Channels[ChannelId].Channel_Number);
            outputLevel = DIO_LEVEL_HIGH;
        }

        break;

    case PORT_B:
        if (BIT_IS_SET(GET_REG(GPIO_B_AHB_PERI_BASE_ADDRESS, GPIODATA_OFFSET), Dio_Configuration.Channels[ChannelId].Channel_Number))
        {
            /* Write Logic Low */
            CLEAR_BIT(GET_REG(GPIO_B_AHB_PERI_BASE_ADDRESS, GPIODATA_OFFSET), Dio_Configuration.Channels[ChannelId].Channel_Number);
            outputLevel = DIO_LEVEL_LOW;
        }

        else
        {
            /* Write Logic High */
            SET_BIT(GET_REG(GPIO_B_AHB_PERI_BASE_ADDRESS, GPIODATA_OFFSET), Dio_Configuration.Channels[ChannelId].Channel_Number);
            outputLevel = DIO_LEVEL_HIGH;
        }

        break;
    case PORT_C:
        if (BIT_IS_SET(GET_REG(GPIO_C_AHB_PERI_BASE_ADDRESS, GPIODATA_OFFSET), Dio_Configuration.Channels[ChannelId].Channel_Number))
        {
            /* Write Logic Low */
            CLEAR_BIT(GET_REG(GPIO_C_AHB_PERI_BASE_ADDRESS, GPIODATA_OFFSET), Dio_Configuration.Channels[ChannelId].Channel_Number);
            outputLevel = DIO_LEVEL_LOW;
        }

        else
        {
            /* Write Logic High */
            SET_BIT(GET_REG(GPIO_C_AHB_PERI_BASE_ADDRESS, GPIODATA_OFFSET), Dio_Configuration.Channels[ChannelId].Channel_Number);
            outputLevel = DIO_LEVEL_HIGH;
        }

        break;

    case PORT_D:
        if (BIT_IS_SET(GET_REG(GPIO_D_AHB_PERI_BASE_ADDRESS, GPIODATA_OFFSET), Dio_Configuration.Channels[ChannelId].Channel_Number))
        {
            /* Write Logic Low */
            CLEAR_BIT(GET_REG(GPIO_D_AHB_PERI_BASE_ADDRESS, GPIODATA_OFFSET), Dio_Configuration.Channels[ChannelId].Channel_Number);
            outputLevel = DIO_LEVEL_LOW;
        }

        else
        {
            /* Write Logic High */
            SET_BIT(GET_REG(GPIO_D_AHB_PERI_BASE_ADDRESS, GPIODATA_OFFSET), Dio_Configuration.Channels[ChannelId].Channel_Number);
            outputLevel = DIO_LEVEL_HIGH;
        }

        break;

    case PORT_E:
        if (BIT_IS_SET(GET_REG(GPIO_E_AHB_PERI_BASE_ADDRESS, GPIODATA_OFFSET), Dio_Configuration.Channels[ChannelId].Channel_Number))
        {
            /* Write Logic Low */
            CLEAR_BIT(GET_REG(GPIO_E_AHB_PERI_BASE_ADDRESS, GPIODATA_OFFSET), Dio_Configuration.Channels[ChannelId].Channel_Number);
            outputLevel = DIO_LEVEL_LOW;
        }

        else
        {
            /* Write Logic High */
            SET_BIT(GET_REG(GPIO_E_AHB_PERI_BASE_ADDRESS, GPIODATA_OFFSET), Dio_Configuration.Channels[ChannelId].Channel_Number);
            outputLevel = DIO_LEVEL_HIGH;
        }
        break;

    case PORT_F:
        if (BIT_IS_SET(GET_REG(GPIO_F_AHB_PERI_BASE_ADDRESS, GPIODATA_OFFSET), Dio_Configuration.Channels[ChannelId].Channel_Number))
        {
            /* Write Logic Low */
            CLEAR_BIT(GET_REG(GPIO_F_AHB_PERI_BASE_ADDRESS, GPIODATA_OFFSET), Dio_Configuration.Channels[ChannelId].Channel_Number);
            outputLevel = DIO_LEVEL_LOW;
        }

        else
        {
            /* Write Logic High */
            SET_BIT(GET_REG(GPIO_F_AHB_PERI_BASE_ADDRESS, GPIODATA_OFFSET), Dio_Configuration.Channels[ChannelId].Channel_Number);
            outputLevel = DIO_LEVEL_HIGH;
        }
        break;

    default:
        /* Error In Port Number Configuration */
        outputLevel = DIO_LEVEL_ERROR;
        break;
    }

    /* return the output level after toggle */

    return outputLevel;
}

/**********************************************************************************************************************
 *  END OF FILE: Dio.c
 *********************************************************************************************************************/

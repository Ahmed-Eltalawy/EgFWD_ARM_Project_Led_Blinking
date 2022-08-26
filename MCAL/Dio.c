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
    case PORTNUMBER_A:
        if (BIT_IS_SET(GET_REG(GPIO_A_APB_PERI_BASE_ADDRESS, GPIODATA_OFFSET), Dio_Configuration.Channels[ChannelId].Channel_Number))
        {
            outputLevel = DIO_LEVEL_HIGH;
        }

        else
        {
            outputLevel = DIO_LEVEL_LOW;
        }

        break;

    case PORTNUMBER_B:
        if (BIT_IS_SET(GET_REG(GPIO_B_APB_PERI_BASE_ADDRESS, GPIODATA_OFFSET), Dio_Configuration.Channels[ChannelId].Channel_Number))
        {
            outputLevel = DIO_LEVEL_HIGH;
        }

        else
        {
            outputLevel = DIO_LEVEL_LOW;
        }

        break;
    case PORTNUMBER_C:
        if (BIT_IS_SET(GET_REG(GPIO_C_APB_PERI_BASE_ADDRESS, GPIODATA_OFFSET), Dio_Configuration.Channels[ChannelId].Channel_Number))
        {
            outputLevel = DIO_LEVEL_HIGH;
        }

        else
        {
            outputLevel = DIO_LEVEL_LOW;
        }

        break;

    case PORTNUMBER_D:
        if (BIT_IS_SET(GET_REG(GPIO_D_APB_PERI_BASE_ADDRESS, GPIODATA_OFFSET), Dio_Configuration.Channels[ChannelId].Channel_Number))
        {
            outputLevel = DIO_LEVEL_HIGH;
        }

        else
        {
            outputLevel = DIO_LEVEL_LOW;
        }

        break;

    case PORTNUMBER_E:
        if (BIT_IS_SET(GET_REG(GPIO_E_APB_PERI_BASE_ADDRESS, GPIODATA_OFFSET), Dio_Configuration.Channels[ChannelId].Channel_Number))
        {
            outputLevel = DIO_LEVEL_HIGH;
        }

        else
        {
            outputLevel = DIO_LEVEL_LOW;
        }

        break;

    case PORTNUMBER_F:
        if (BIT_IS_SET(GET_REG(GPIO_F_APB_PERI_BASE_ADDRESS, GPIODATA_OFFSET), Dio_Configuration.Channels[ChannelId].Channel_Number))
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
        outputLevel=  DIO_LEVEL_ERROR;
        break;
    }

    /* return the value of the specified DIO channel. */
    return outputLevel;
}

/******************************************************************************
 * \Syntax          : void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level)
 * \Description     : Function to set a level of a channel .
 *
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

    /* Check if the used channel is within the valid Port range and Write the requied level on the requied channel*/
    switch (Dio_Configuration.Channels[ChannelId].Port_Number)
    {
    case PORTNUMBER_A:
        if (Level == DIO_LEVEL_HIGH)
        {
            /* Write Logic High */
            SET_BIT(GET_REG(GPIO_A_AHB_PERI_BASE_ADDRESS, GPIODATA_OFFSET), Dio_Configuration.Channels[ChannelId].Channel_Number);
        }
        else
        {
            /* Write Logic Low */
            CLEAR_BIT(GET_REG(GPIO_A_AHB_PERI_BASE_ADDRESS, GPIODATA_OFFSET), Dio_Configuration.Channels[ChannelId].Channel_Number);
        }

        break;

    case PORTNUMBER_B:
        if (Level == DIO_LEVEL_HIGH)
        {
            /* Write Logic High */
            SET_BIT(GET_REG(GPIO_B_APB_PERI_BASE_ADDRESS, GPIODATA_OFFSET), Dio_Configuration.Channels[ChannelId].Channel_Number);
        }
        else
        {
            /* Write Logic Low */
            CLEAR_BIT(GET_REG(GPIO_B_APB_PERI_BASE_ADDRESS, GPIODATA_OFFSET), Dio_Configuration.Channels[ChannelId].Channel_Number);
        }

        break;
    case PORTNUMBER_C:
        if (Level == DIO_LEVEL_HIGH)
        {
            /* Write Logic High */
            SET_BIT(GET_REG(GPIO_C_APB_PERI_BASE_ADDRESS, GPIODATA_OFFSET), Dio_Configuration.Channels[ChannelId].Channel_Number);
        }
        else
        {
            /* Write Logic Low */
            CLEAR_BIT(GET_REG(GPIO_C_APB_PERI_BASE_ADDRESS, GPIODATA_OFFSET), Dio_Configuration.Channels[ChannelId].Channel_Number);
        }

        break;

    case PORTNUMBER_D:
        if (Level == DIO_LEVEL_HIGH)
        {
            /* Write Logic High */
            SET_BIT(GET_REG(GPIO_D_APB_PERI_BASE_ADDRESS, GPIODATA_OFFSET), Dio_Configuration.Channels[ChannelId].Channel_Number);
        }
        else
        {
            /* Write Logic Low */
            CLEAR_BIT(GET_REG(GPIO_D_APB_PERI_BASE_ADDRESS, GPIODATA_OFFSET), Dio_Configuration.Channels[ChannelId].Channel_Number);
        }

        break;

    case PORTNUMBER_E:
        if (Level == DIO_LEVEL_HIGH)
        {
            /* Write Logic High */
            SET_BIT(GET_REG(GPIO_E_APB_PERI_BASE_ADDRESS, GPIODATA_OFFSET), Dio_Configuration.Channels[ChannelId].Channel_Number);
        }
        else
        {
            /* Write Logic Low */
            CLEAR_BIT(GET_REG(GPIO_E_APB_PERI_BASE_ADDRESS, GPIODATA_OFFSET), Dio_Configuration.Channels[ChannelId].Channel_Number);
        }

        break;

    case PORTNUMBER_F:
        if (Level == DIO_LEVEL_HIGH)
        {
            /* Write Logic High */
            SET_BIT(GET_REG(GPIO_F_APB_PERI_BASE_ADDRESS, GPIODATA_OFFSET), Dio_Configuration.Channels[ChannelId].Channel_Number);
        }
        else
        {
            /* Write Logic Low */
            CLEAR_BIT(GET_REG(GPIO_F_APB_PERI_BASE_ADDRESS, GPIODATA_OFFSET), Dio_Configuration.Channels[ChannelId].Channel_Number);
        }

        break;

    default:
        /* Error In Port Number Configuration */
        break;
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
    case PORTNUMBER_A:
        outputPort = (Dio_PortLevelType)GET_REG(GPIO_A_AHB_PERI_BASE_ADDRESS, GPIODATA_OFFSET);
        break;

    case PORTNUMBER_B:
        outputPort = (Dio_PortLevelType)GET_REG(GPIO_B_APB_PERI_BASE_ADDRESS, GPIODATA_OFFSET);
        break;

    case PORTNUMBER_C:
        outputPort = (Dio_PortLevelType)GET_REG(GPIO_C_APB_PERI_BASE_ADDRESS, GPIODATA_OFFSET);
        break;

    case PORTNUMBER_D:
        outputPort = (Dio_PortLevelType)GET_REG(GPIO_D_APB_PERI_BASE_ADDRESS, GPIODATA_OFFSET);
        break;

    case PORTNUMBER_E:
        outputPort = (Dio_PortLevelType)GET_REG(GPIO_E_APB_PERI_BASE_ADDRESS, GPIODATA_OFFSET);
        break;

    case PORTNUMBER_F:
        outputPort = (Dio_PortLevelType)GET_REG(GPIO_F_APB_PERI_BASE_ADDRESS, GPIODATA_OFFSET);
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
    case PORTNUMBER_A:
        GET_REG(GPIO_A_AHB_PERI_BASE_ADDRESS, GPIODATA_OFFSET) = Level;
        break;

    case PORTNUMBER_B:
        GET_REG(GPIO_B_APB_PERI_BASE_ADDRESS, GPIODATA_OFFSET) = Level;
        break;

    case PORTNUMBER_C:
        GET_REG(GPIO_C_APB_PERI_BASE_ADDRESS, GPIODATA_OFFSET) = Level;
        break;

    case PORTNUMBER_D:
        GET_REG(GPIO_D_APB_PERI_BASE_ADDRESS, GPIODATA_OFFSET) = Level;
        break;

    case PORTNUMBER_E:
        GET_REG(GPIO_E_APB_PERI_BASE_ADDRESS, GPIODATA_OFFSET) = Level;
        break;

    case PORTNUMBER_F:
        GET_REG(GPIO_F_APB_PERI_BASE_ADDRESS, GPIODATA_OFFSET) = Level;
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
    case PORTNUMBER_A:
        if (BIT_IS_SET(GET_REG(GPIO_A_APB_PERI_BASE_ADDRESS, GPIODATA_OFFSET), Dio_Configuration.Channels[ChannelId].Channel_Number))
        {
            /* Write Logic Low */
            CLEAR_BIT(GET_REG(GPIO_A_APB_PERI_BASE_ADDRESS, GPIODATA_OFFSET), Dio_Configuration.Channels[ChannelId].Channel_Number);
            outputLevel = DIO_LEVEL_LOW;
        }

        else
        {
            /* Write Logic High */
            SET_BIT(GET_REG(GPIO_A_APB_PERI_BASE_ADDRESS, GPIODATA_OFFSET), Dio_Configuration.Channels[ChannelId].Channel_Number);
            outputLevel = DIO_LEVEL_HIGH;
        }

        break;

    case PORTNUMBER_B:
        if (BIT_IS_SET(GET_REG(GPIO_B_APB_PERI_BASE_ADDRESS, GPIODATA_OFFSET), Dio_Configuration.Channels[ChannelId].Channel_Number))
        {
            /* Write Logic Low */
            CLEAR_BIT(GET_REG(GPIO_B_APB_PERI_BASE_ADDRESS, GPIODATA_OFFSET), Dio_Configuration.Channels[ChannelId].Channel_Number);
            outputLevel = DIO_LEVEL_LOW;
        }

        else
        {
            /* Write Logic High */
            SET_BIT(GET_REG(GPIO_B_APB_PERI_BASE_ADDRESS, GPIODATA_OFFSET), Dio_Configuration.Channels[ChannelId].Channel_Number);
            outputLevel = DIO_LEVEL_HIGH;
        }

        break;
    case PORTNUMBER_C:
        if (BIT_IS_SET(GET_REG(GPIO_C_APB_PERI_BASE_ADDRESS, GPIODATA_OFFSET), Dio_Configuration.Channels[ChannelId].Channel_Number))
        {
            /* Write Logic Low */
            CLEAR_BIT(GET_REG(GPIO_C_APB_PERI_BASE_ADDRESS, GPIODATA_OFFSET), Dio_Configuration.Channels[ChannelId].Channel_Number);
            outputLevel = DIO_LEVEL_LOW;
        }

        else
        {
            /* Write Logic High */
            SET_BIT(GET_REG(GPIO_C_APB_PERI_BASE_ADDRESS, GPIODATA_OFFSET), Dio_Configuration.Channels[ChannelId].Channel_Number);
            outputLevel = DIO_LEVEL_HIGH;
        }

        break;

    case PORTNUMBER_D:
        if (BIT_IS_SET(GET_REG(GPIO_D_APB_PERI_BASE_ADDRESS, GPIODATA_OFFSET), Dio_Configuration.Channels[ChannelId].Channel_Number))
        {
            /* Write Logic Low */
            CLEAR_BIT(GET_REG(GPIO_D_APB_PERI_BASE_ADDRESS, GPIODATA_OFFSET), Dio_Configuration.Channels[ChannelId].Channel_Number);
            outputLevel = DIO_LEVEL_LOW;
        }

        else
        {
            /* Write Logic High */
            SET_BIT(GET_REG(GPIO_D_APB_PERI_BASE_ADDRESS, GPIODATA_OFFSET), Dio_Configuration.Channels[ChannelId].Channel_Number);
            outputLevel = DIO_LEVEL_HIGH;
        }

        break;

    case PORTNUMBER_E:
        if (BIT_IS_SET(GET_REG(GPIO_E_APB_PERI_BASE_ADDRESS, GPIODATA_OFFSET), Dio_Configuration.Channels[ChannelId].Channel_Number))
        {
            /* Write Logic Low */
            CLEAR_BIT(GET_REG(GPIO_E_APB_PERI_BASE_ADDRESS, GPIODATA_OFFSET), Dio_Configuration.Channels[ChannelId].Channel_Number);
            outputLevel = DIO_LEVEL_LOW;
        }

        else
        {
            /* Write Logic High */
            SET_BIT(GET_REG(GPIO_E_APB_PERI_BASE_ADDRESS, GPIODATA_OFFSET), Dio_Configuration.Channels[ChannelId].Channel_Number);
            outputLevel = DIO_LEVEL_HIGH;
        }
        break;

    case PORTNUMBER_F:
        if (BIT_IS_SET(GET_REG(GPIO_F_APB_PERI_BASE_ADDRESS, GPIODATA_OFFSET), Dio_Configuration.Channels[ChannelId].Channel_Number))
        {
            /* Write Logic Low */
            CLEAR_BIT(GET_REG(GPIO_F_APB_PERI_BASE_ADDRESS, GPIODATA_OFFSET), Dio_Configuration.Channels[ChannelId].Channel_Number);
            outputLevel = DIO_LEVEL_LOW;
        }

        else
        {
            /* Write Logic High */
            SET_BIT(GET_REG(GPIO_F_APB_PERI_BASE_ADDRESS, GPIODATA_OFFSET), Dio_Configuration.Channels[ChannelId].Channel_Number);
            outputLevel = DIO_LEVEL_HIGH;
        }
        break;

    default:
    /* Error In Port Number Configuration */
        outputLevel =  DIO_LEVEL_ERROR;
        break;
    }

    /* return the output level after toggle */

    return outputLevel;
}

/**********************************************************************************************************************
 *  END OF FILE: Dio.c
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Gpt.c
 *        \brief
 *
 *      \details Source File for Gpt Module's driver .
 *               Note : The Module Support only timer_0 (16/32-Bit).
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Gpt.h"
/**********************************************************************************************************************
 *  LOCAL MACROS CONSTANT\FUNCTION
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/
/* Global pointer to function used to point upper layer functions
 * to be used in Call Back */
static volatile void (*g_Timer0_Call_Back_Ptr)(void) = NULL_PTR;

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
 * \Syntax             : void Gpt_Init(const Gpt_ConfigType* ConfigPtr)
 * \Description        : Function to Intialize the Gpt Module.
 * \Sync\Async         : Synchronous.
 * \Reentrancy         : NonReentrant.
 * \Parameters (in)    : ConfigPtr - Configuration of Timer module.
 * \Parameters (inout) : None.
 * \Parameters (out)   : None.
 * \Return value:      : None.
 *******************************************************************************/
void Gpt_Init(const Gpt_ConfigType *ConfigPtr)
{
    /* Iterator Counter used to iterate on the array of the configuration strucrtues of all configures timers */
    uint8 counter = 0;

    /* Base Address of GPT Peripheral*/
    volatile uint32 *gptBaseAddress = NULL_PTR;

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

    /* Loop on the array of the configuration strucrtues of all configures timers */
    for (counter = 0; counter < CONGIGURED_TIMER_NUMBER; counter++)
    {

        switch (ConfigPtr->Channel[counter].ChannelId)
        {
        case TIMER_0_16_32_BIT:

            /*
           GPT module clock must be enabled before the registers can be programmed.
            There must be a delay of 3 system clocks after the GPT module clock is enabled before
           any GPT module registers are accessed .
           */

            /* Enable Timer 0 Clock*/
            SYSTEM_CONTROL_REG_RCGCTIMER.R0 = ENABLE;

            /* Get the Base Address of Timer 0 Module*/
            gptBaseAddress = (volatile uint32 *)GPT_TIMER0_PERI_BASE_ADDRESS;

            break;
        default:
            /* Configurations Error */
            /* No Action Required */
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

        /********************************Set GPT Timer Operation Type **************************/
        if (ConfigPtr->Channel[counter].OperationType == GPT_OPERATION_CONCATENATED)
        {
            GET_REGISTER((volatile uint8 *)gptBaseAddress, GPTMCFG_BF, GPTMCFG_OFFSET).GPTMCFG = GPT_OPERATION_CONCATENATED;
        }
        else if (ConfigPtr->Channel[counter].OperationType == GPT_OPERATION_CONCATENATED_RTC)
        {
            GET_REGISTER((volatile uint8 *)gptBaseAddress, GPTMCFG_BF, GPTMCFG_OFFSET).GPTMCFG = GPT_OPERATION_CONCATENATED_RTC;
        }
        else if (ConfigPtr->Channel[counter].OperationType == GPT_OPERATION_INDIVIDUAL)
        {
            GET_REGISTER((volatile uint8 *)gptBaseAddress, GPTMCFG_BF, GPTMCFG_OFFSET).GPTMCFG = GPT_OPERATION_INDIVIDUAL;
        }
        else
        {
            /* Configurations Error */
            /* No Action Required */
        }

        /********************************Set GPT Timer Mode Type **************************/
        if (ConfigPtr->Channel[counter].ChannelMode == GPT_MODE_ONE_SHOOT)
        {
            GET_REGISTER((volatile uint8 *)gptBaseAddress, GPTMTAMR_BF, GPTMTAMR_OFFSET).TAMR = GPT_MODE_ONE_SHOOT;
        }
        else if (ConfigPtr->Channel[counter].ChannelMode == GPT_MODE_PERIODIC)
        {
            GET_REGISTER((volatile uint8 *)gptBaseAddress, GPTMTAMR_BF, GPTMTAMR_OFFSET).TAMR = GPT_MODE_PERIODIC;
        }
        else if (ConfigPtr->Channel[counter].ChannelMode == GPT_MODE_CAPTURE)
        {
            GET_REGISTER((volatile uint8 *)gptBaseAddress, GPTMTAMR_BF, GPTMTAMR_OFFSET).TAMR = GPT_MODE_CAPTURE;
        }
        else
        {
            /* Configurations Error */
            /* No Action Required */
        }

        /***********************Set GPT Timer Counting Direction **********************/
        if (ConfigPtr->Channel[counter].ChannelCountDirection == GPT_COUNT_DOWN)
        {
            GET_REGISTER((volatile uint8 *)gptBaseAddress, GPTMTAMR_BF, GPTMTAMR_OFFSET).TACDIR = GPT_COUNT_DOWN;
        }
        else if (ConfigPtr->Channel[counter].ChannelCountDirection == GPT_COUNT_UP)
        {
            GET_REGISTER((volatile uint8 *)gptBaseAddress, GPTMTAMR_BF, GPTMTAMR_OFFSET).TACDIR = GPT_COUNT_UP;
        }
        else
        {
            /* Configurations Error */
            /* No Action Required */
        }
    }

    /* Enable all the interrupts after initializations of Gpt Module  */
    INTERRUPTS_ENABLE();
}
/******************************************************************************
 * \Syntax             : void Gpt_EnableNotification(Gpt_ChannelType ChannelId)
 * \Description        : Function to enable call back notofication .
 * \Sync\Async         : Synchronous
 * \Reentrancy         : Reentrant
 * \Parameters (in)    : ChannelId - ID of Timer Module.
 * \Parameters (inout) : None
 * \Parameters (out)   : None
 * \Return value:      : None
 *******************************************************************************/
void Gpt_EnableNotification(Gpt_ChannelType ChannelId)
{
    /* Base Address of GPT Peripheral*/
    volatile uint32 *gptBaseAddress = NULL_PTR;

    switch (ChannelId)
    {
    case TIMER_0_16_32_BIT:
        /* Get the Base Address of Timer 0 Module*/
        gptBaseAddress = (volatile uint32 *)GPT_TIMER0_PERI_BASE_ADDRESS;
        break;
    default:
        /* Configurations Error */
        /* No Action Required */
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
    /* Enable GPTM Timer A Time-Out Interrupt */
    GET_REGISTER((volatile uint8 *)gptBaseAddress, GPTMIMR_BF, GPTMTAMR_OFFSET).TATOIM = ENABLE;

    /* Enable GPTM Timer A Match Interrupt  */
    GET_REGISTER((volatile uint8 *)gptBaseAddress, GPTMIMR_BF, GPTMTAMR_OFFSET).TAMIM = ENABLE;
}

/******************************************************************************
 * \Syntax             : void Gpt_DisableNotification(Gpt_ChannelType ChannelId)
 * \Description        : Function to disable call back notofication .
 * \Sync\Async         : Synchronous
 * \Reentrancy         : Reentrant
 * \Parameters (in)    : ChannelId - ID of Timer Module.
 * \Parameters (inout) : None
 * \Parameters (out)   : None
 * \Return value:      : None
 *******************************************************************************/
void Gpt_DisableNotification(Gpt_ChannelType ChannelId)
{

    /* Base Address of GPT Peripheral*/
    volatile uint32 *gptBaseAddress = NULL_PTR;

    switch (ChannelId)
    {
    case TIMER_0_16_32_BIT:
        /* Get the Base Address of Timer 0 Module*/
        gptBaseAddress = (volatile uint32 *)GPT_TIMER0_PERI_BASE_ADDRESS;
        break;
    default:
        /* Configurations Error */
        /* No Action Required */
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
    /* Disable GPTM Timer A Time-Out Interrupt */
    GET_REGISTER((volatile uint8 *)gptBaseAddress, GPTMIMR_BF, GPTMTAMR_OFFSET).TATOIM = DISABLE;

    /* Disable GPTM Timer A Match Interrupt  */
    GET_REGISTER((volatile uint8 *)gptBaseAddress, GPTMIMR_BF, GPTMTAMR_OFFSET).TAMIM = DISABLE;
}

/******************************************************************************
 * \Syntax             : Gpt_ValueType Gpt_GetTimeElapsed(Gpt_ChannelType ChannelId)
 * \Description        : Function to get elapsed time .
 * \Sync\Async         : Synchronous
 * \Reentrancy         : Reentrant
 * \Parameters (in)    : ChannelId - ID of Timer Module.
 * \Parameters (inout) : None
 * \Parameters (out)   : None
 * \Return value:      : Gpt_ValueType
 *******************************************************************************/
Gpt_ValueType Gpt_GetTimeElapsed(Gpt_ChannelType ChannelId)
{

    /* Base Address of GPT Peripheral*/
    volatile uint32 *gptBaseAddress = NULL_PTR;

    /* Elapsed time value*/
    uint32 timeElapsed;

    switch (ChannelId)
    {
    case TIMER_0_16_32_BIT:
        /* Get the Base Address of Timer 0 Module*/
        gptBaseAddress = (volatile uint32 *)GPT_TIMER0_PERI_BASE_ADDRESS;
        break;
    default:
        /* Configurations Error */
        /* No Action Required */
        break;
    }

    /* Check of the user filled the configuration Successfully*/
    if (NULL_PTR == gptBaseAddress)
    {
        /* Configurations Error */
        return 0;
    }

    else
    {
        /* Configurations Successfully */
        /* No Action Required */
    }

    /* Get the tle elapsed time */
    timeElapsed = GET_REGISTER((volatile uint8 *)gptBaseAddress, uint32, GPTMTAV_OFFSET);

    return timeElapsed;
}

/******************************************************************************
 * \Syntax               : Std_ReturnType Gpt_GetPredefTimerValue(Gpt_PredefTimerType PredefTimer , uint32* TimeValuePtr)
 * \Description          : Function to return the current value of the Gpt predefined timer value  passed by predef timer.
 * \Sync\Async           : Synchronous
 * \Reentrancy           : Reentrant
 * \Parameters (in)      : PredefTimer  - Pre Defined TImer Value.
 *                         TimeValuePtr -  The current value of predefinied timer
 * * \Parameters (inout) : None
 * \Parameters (out)     : None
 * \Return value:        : Std_ReturnType
 *******************************************************************************/
// Std_ReturnType Gpt_GetPredefTimerValue(Gpt_PredefTimerType PredefTimer, uint32 *TimeValuePtr)
// {
// }

/******************************************************************************
 * \Syntax             : Gpt_ValueType Gpt_GetTimeRemaining(Gpt_ChannelType ChannelId)
 * \Description        : Function to get Remaining time .
 * \Sync\Async         : Synchronous
 * \Reentrancy         : Reentrant
 * \Parameters (in)    : ChannelId - ID of Timer Module.
 * \Parameters (inout) : None
 * \Parameters (out)   : None
 * \Return value:      : Gpt_ValueType
 *******************************************************************************/
Gpt_ValueType Gpt_GetTimeRemaining(Gpt_ChannelType ChannelId)
{

    /* Base Address of GPT Peripheral*/
    volatile uint32 *gptBaseAddress = NULL_PTR;

    /* Elapsed time value*/
    uint32 timeRemaining;

    switch (ChannelId)
    {
    case TIMER_0_16_32_BIT:
        /* Get the Base Address of Timer 0 Module*/
        gptBaseAddress = (volatile uint32 *)GPT_TIMER0_PERI_BASE_ADDRESS;
        break;
    default:
        /* Configurations Error */
        /* No Action Required */
        break;
    }

    /* Check of the user filled the configuration Successfully*/
    if (NULL_PTR == gptBaseAddress)
    {
        /* Configurations Error */
        return 0;
    }

    else
    {
        /* Configurations Successfully */
        /* No Action Required */
    }

    /* Get the tle elapsed time */
    timeRemaining = GET_REGISTER((volatile uint8 *)gptBaseAddress, uint32, GPTMTAILR_OFFSET);

    return timeRemaining;
}

/******************************************************************************
 * \Syntax             : void Gpt_StartTimer(Gpt_ChannelType ChannelId, Gpt_ValueType Value)
 * \Description        : Function to start the selected timer channel with a defined target time .
 * \Sync\Async         : Synchronous
 * \Reentrancy         : Reentrant
 * \Parameters (in)    : ChannelId - ID of Timer Module.
 *                       Value     - The defined target time .
 * \Parameters (inout) : None
 * \Parameters (out)   : None
 * \Return value:      : None
 *******************************************************************************/
void Gpt_StartTimer(Gpt_ChannelType ChannelId, Gpt_ValueType Value)
{

    /* Base Address of GPT Peripheral*/
    volatile uint32 *gptBaseAddress = NULL_PTR;

    switch (ChannelId)
    {
    case TIMER_0_16_32_BIT:
        /* Get the Base Address of Timer 0 Module*/
        gptBaseAddress = (volatile uint32 *)GPT_TIMER0_PERI_BASE_ADDRESS;
        break;
    default:
        /* Configurations Error */
        /* No Action Required */
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

    /* Set the timer Value*/
    GET_REGISTER((volatile uint8 *)gptBaseAddress, uint32, GPTMTAILR_OFFSET) = Value;

    /* Start the timer */
    GET_REGISTER((volatile uint8 *)gptBaseAddress, GPTMCTL_BF, GPTMTAILR_OFFSET).TAEN = ENABLE;
}

/******************************************************************************
 * \Syntax             : void Gpt_StopTimer(Gpt_ChannelType ChannelId)
 * \Description        : Function to stop the selected timer channel .
 * \Sync\Async         : Synchronous
 * \Reentrancy         : Reentrant
 * \Parameters (in)    : ChannelId - ID of Timer Module.
 * \Parameters (inout) : None
 * \Parameters (out)   : None
 * \Return value:      : None
 *******************************************************************************/
void Gpt_StopTimer(Gpt_ChannelType ChannelId)
{
    /* Base Address of GPT Peripheral*/
    volatile uint32 *gptBaseAddress = NULL_PTR;

    switch (ChannelId)
    {
    case TIMER_0_16_32_BIT:
        /* Get the Base Address of Timer 0 Module*/
        gptBaseAddress = (volatile uint32 *)GPT_TIMER0_PERI_BASE_ADDRESS;
        break;
    default:
        /* Configurations Error */
        /* No Action Required */
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

    /* Stop the timer */
    GET_REGISTER((volatile uint8 *)gptBaseAddress, GPTMCTL_BF, GPTMTAILR_OFFSET).TAEN = DISABLE;
}

/******************************************************************************
 * \Syntax             : void Gpt_Notification_Timer(Gpt_ChannelType ChannelId)
 * \Description        : Function to Set the callback notification .
 * \Sync\Async         : Synchronous
 * \Reentrancy         : Reentrant
 * \Parameters (in)    : ChannelId - ID of Timer Module.
 * \Parameters (inout) : None
 * \Parameters (out)   : None
 * \Return value       : None
 *******************************************************************************/
void Gpt_Notification_Timer(Gpt_ChannelType ChannelId)
{

    /* Check of the user filled the configuration Successfully*/
    if (NULL_PTR == Gpt_Config.Channel[ChannelId].ChannelNotification)
    {
        /* Configurations Error */
        return;
    }

    else
    {
        /* Configurations Successfully */
        /* No Action Required */
    }

    switch (ChannelId)
    {
    case TIMER_0_16_32_BIT:
        /* Set the Call back Function*/
        g_Timer0_Call_Back_Ptr = Gpt_Config.Channel[ChannelId].ChannelNotification;
        break;
    default:
        /* Configurations Error */
        /* No Action Required */
        break;
    }
}

/******************************************************************************
 * \Syntax             : void TIMER0A_Handler(void)
 * \Description        : Interrupt Service Routine for Timer0 .
 * \Sync\Async         : Synchronous
 * \Reentrancy         : Reentrant
 * \Parameters (in)    : None.
 * \Parameters (inout) : None
 * \Parameters (out)   : None
 * \Return value       : None
 *******************************************************************************/
void TIMER0A_Handler (void)
{
    /* Check if the Timer0_setCallBack is already called */
	if(NULL_PTR != g_Timer0_Call_Back_Ptr )
	{
        /* call the functionusing call-back concept */
		(*g_Timer0_Call_Back_Ptr)(); 
	}

        else
    {
        /* Configurations Successfully */
        /* No Action Required */
    }


}
/**********************************************************************************************************************
 *  END OF FILE: Gpt.c
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  IntCrtl.c
 *        \brief
 *
 *      \details  IntCrtl Module's driver
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "IntCtrl.h"

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
 * \Syntax          : void IntCrtl_Init(void)
 * \Description     : initialize IntCrtl Module .
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : None
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/
void IntCrtl_Init(void)
{
    uint8 counter = 0;

    uint8 offsetRegister = 0;
    uint8 IntLocation    = 0;
		volatile NVIC_PRIx_BF *PRIx ;

    /* TODO	: Configure Grouping/SubGrouping System in APINT register in SCB */
    /* 8 Group Priority and 1 Sungroup */
    SCB_APINT = 0x05FA0000;

    /* TODO : Assign Group/Subgroup priority in NVIC_PRIx Nvic and SCB_SYSPRIx registers */
    /* TODO : Enable/Disable based on user configurations in NVIC_ENx and SCB_SYSHNDCTRL registers */

    for (counter = 0; counter < CONFIGURED_EXCEPTIONS_NUM; counter++)
    {
        /* Check if Exception enabled or disabled */
        if (IntCtrl_Config.exceptions[counter].mode == EXC_DISABLED)
        {
            switch (IntCtrl_Config.exceptions[counter].exceptionId)
            {
            case RESET:
            case NMI:
            case HARD_FAULT:
                break; /* Can not disable this exceptions*/
            case MEMORY_MANAGE_FAULT:
                SCB_SYSHNDCTRL.MEM = 0;
                break;
            case BUS_FAULT:
                SCB_SYSPRI1.BUS = IntCtrl_Config.exceptions[counter].priority;
                SCB_SYSHNDCTRL.BUS = 1;
                break;
            case USAGE_FAULT:
                SCB_SYSPRI1.USAGE = IntCtrl_Config.exceptions[counter].priority;
                SCB_SYSHNDCTRL.USAGE = 1;
                break;
            case SVCALL:
                SCB_SYSPRI2.SVC = IntCtrl_Config.exceptions[counter].priority;
                break;
            case DEBUG_MONITOR:
                SCB_SYSPRI3.DEBUG = IntCtrl_Config.exceptions[counter].priority;
                break;
            case PENDSV:
                SCB_SYSPRI3.PENDSV = IntCtrl_Config.exceptions[counter].priority;
                break;
            case SYSTICK:
                SCB_SYSPRI3.TICK = IntCtrl_Config.exceptions[counter].priority;
                SYSTICK_STCTRL.INTEN = 1;
                break;
            }
        }
        else if (IntCtrl_Config.exceptions[counter].mode == EXC_ENABLED)
        {

            switch (IntCtrl_Config.exceptions[counter].exceptionId)
            {
            case RESET:
            case NMI:
            case HARD_FAULT:
                break;
            case MEMORY_MANAGE_FAULT:
                SCB_SYSPRI1.MEM = IntCtrl_Config.exceptions[counter].priority;
                SCB_SYSHNDCTRL.MEM = 1;
                break;
            case BUS_FAULT:
                SCB_SYSHNDCTRL.BUS = 0;
                break;
            case USAGE_FAULT:
                SCB_SYSHNDCTRL.USAGE = 0;
                break;
            case SVCALL:
                break;
            case DEBUG_MONITOR:
                break;
            case PENDSV:
                break;
            case SYSTICK:
                SYSTICK_STCTRL.INTEN = 0;
                break;
            }
        }
    }

    for (counter = 0; counter < CONFIGURED_INTERRUPTS_NUM; counter++)
    {
        /* Check if Interrupt enabled or disabled */
        if (IntCtrl_Config.interrupts[counter].mode == INT_DISABLED)
        {
            if ((IntCtrl_Config.interrupts[counter].interruptId >= 0) && (IntCtrl_Config.interrupts[counter].interruptId < 32))
            {
                SET_BIT(NVIC_DIS0, IntCtrl_Config.interrupts[counter].interruptId);
            }

            else if ((IntCtrl_Config.interrupts[counter].interruptId > 31) && (IntCtrl_Config.interrupts[counter].interruptId < 64))
            {
                SET_BIT(NVIC_DIS1, IntCtrl_Config.interrupts[counter].interruptId);
            }

            else if ((IntCtrl_Config.interrupts[counter].interruptId > 63) && (IntCtrl_Config.interrupts[counter].interruptId < 96))
            {
                SET_BIT(NVIC_DIS2, IntCtrl_Config.interrupts[counter].interruptId);
            }

            else if ((IntCtrl_Config.interrupts[counter].interruptId > 95) && (IntCtrl_Config.interrupts[counter].interruptId < 128))
            {
                SET_BIT(NVIC_DIS3, IntCtrl_Config.interrupts[counter].interruptId);
            }

            else if ((IntCtrl_Config.interrupts[counter].interruptId > 127) && (IntCtrl_Config.interrupts[counter].interruptId < 139))
            {
                SET_BIT(NVIC_DIS4, IntCtrl_Config.interrupts[counter].interruptId);
            }

            else
            {
                /* Interrupt Id error. */
            }
        }
        else if (IntCtrl_Config.interrupts[counter].mode == INT_ENABLED)
        {
            /* Calculate the offset of priority register */

            offsetRegister = IntCtrl_Config.interrupts[counter].interruptId / 4;
            IntLocation = IntCtrl_Config.interrupts[counter].interruptId % 4;
            PRIx = (volatile NVIC_PRIx_BF *)(CORTEXM4_PERI_BASE_ADDRESS + NVIC_PRIx_BASE + (offsetRegister * 4));

            /* Assign the priority to the  interrupt */
            switch (IntLocation)
            {
            case 0:
                PRIx->INTA = IntCtrl_Config.interrupts[counter].priority;
                break;
            case 1:
                PRIx->INTB = IntCtrl_Config.interrupts[counter].priority;
                break;
            case 2:
                PRIx->INTC = IntCtrl_Config.interrupts[counter].priority;
                break;
            case 3:
                PRIx->INTD = IntCtrl_Config.interrupts[counter].priority;
                break;
            }

            /* Enable the interrupt, by setting the corresponding bit in ENx */
            if ((IntCtrl_Config.interrupts[counter].priority >= 0) && (IntCtrl_Config.interrupts[counter].priority < 32))
            {
                SET_BIT(NVIC_EN0, IntCtrl_Config.interrupts[counter].priority);
            }

            else if ((IntCtrl_Config.interrupts[counter].priority > 31) && (IntCtrl_Config.interrupts[counter].priority < 64))
            {
                SET_BIT(NVIC_EN1, IntCtrl_Config.interrupts[counter].priority);
            }

            else if ((IntCtrl_Config.interrupts[counter].priority > 63) && (IntCtrl_Config.interrupts[counter].priority < 96))
            {
                SET_BIT(NVIC_EN2, IntCtrl_Config.interrupts[counter].priority);
            }

            else if ((IntCtrl_Config.interrupts[counter].priority > 95) && (IntCtrl_Config.interrupts[counter].priority < 128))
            {
                SET_BIT(NVIC_EN3, IntCtrl_Config.interrupts[counter].priority);
            }

            else if ((IntCtrl_Config.interrupts[counter].priority > 127) && (IntCtrl_Config.interrupts[counter].priority < 139))
            {
                SET_BIT(NVIC_EN4, IntCtrl_Config.interrupts[counter].priority);
            }

            else
            {
                /* Interrupt Id error. */
            }
        }
    }
}

/******************************************************************************
 * \Syntax          : void IntCtrl_EnableInterrupt(IntCtrl_InterruptType InterruptId, IntCtrl_PriorityLevel Priority)
 * \Description     : Enable the specified interrupt and assign prriority to it .
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : InterruptId -  the specified interrupt Id to be enabled .
 *                    Priority    -  the specified interrupt Priority .
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/
void IntCtrl_EnableInterrupt(IntCtrl_InterruptID InterruptId, IntCtrl_InterruptPriorityLevel Priority)
{

    /* Calculate the offset of priority register */

    uint8 offsetRegister = InterruptId / 4;
    uint8 IntLocation = InterruptId % 4;
    volatile NVIC_PRIx_BF *PRIx = (volatile NVIC_PRIx_BF *)(CORTEXM4_PERI_BASE_ADDRESS + NVIC_PRIx_BASE + (offsetRegister * 4));

    /* Assign the priority to the  interrupt */
    switch (IntLocation)
    {
    case 0:
        PRIx->INTA = Priority;
        break;
    case 1:
        PRIx->INTB = Priority;
        break;
    case 2:
        PRIx->INTC = Priority;
        break;
    case 3:
        PRIx->INTD = Priority;
        break;
    }

    /* Enable the interrupt, by setting the corresponding bit in ENx */
    if ((InterruptId >= 0) && (InterruptId < 32))
    {
        SET_BIT(NVIC_EN0, InterruptId);
    }

    else if ((InterruptId > 31) && (InterruptId < 64))
    {
        SET_BIT(NVIC_EN1, InterruptId);
    }

    else if ((InterruptId > 63) && (InterruptId < 96))
    {
        SET_BIT(NVIC_EN2, InterruptId);
    }

    else if ((InterruptId > 95) && (InterruptId < 128))
    {
        SET_BIT(NVIC_EN3, InterruptId);
    }

    else if ((InterruptId > 127) && (InterruptId < 139))
    {
        SET_BIT(NVIC_EN4, InterruptId);
    }

    else
    {
        /* Interrupt Id error. */
    }
}

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
void IntCtrl_DisableInterrupt(IntCtrl_InterruptID InterruptId)
{
    /* Disable the interrupt, by setting the corresponding bit in DISx */
    if ((InterruptId >= 0) && (InterruptId < 32))
    {
        SET_BIT(NVIC_DIS0, InterruptId);
    }

    else if ((InterruptId > 31) && (InterruptId < 64))
    {
        SET_BIT(NVIC_DIS1, InterruptId);
    }

    else if ((InterruptId > 63) && (InterruptId < 96))
    {
        SET_BIT(NVIC_DIS2, InterruptId);
    }

    else if ((InterruptId > 95) && (InterruptId < 128))
    {
        SET_BIT(NVIC_DIS3, InterruptId);
    }

    else if ((InterruptId > 127) && (InterruptId < 139))
    {
        SET_BIT(NVIC_DIS4, InterruptId);
    }

    else
    {
        /* Interrupt Id error. */
    }
}

/**********************************************************************************************************************
 *  END OF FILE: IntCrtl.c
 *********************************************************************************************************************/

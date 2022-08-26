/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Mcu_Hw.h
 *       Module:  Mcu_Hw
 *
 *  Description:  header file for Registers definition    
 *  
 *********************************************************************************************************************/
#ifndef MCU_HW_H
#define MCU_HW_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

 /* Structure to define Bit Fields of SysTick Control and Status Register*/
typedef struct SYSTICK_STCTRL_BF
{
	uint32 ENABLES		:1;
	uint32 INTEN		:1;
	uint32 CLK_SRC		:1;
	uint32 				:13;
	uint32 COUNT		:1;
	uint32 				:15;
} SYSTICK_STCTRL_BF;

/* Structure to define Bit Fields of Software Trigger Interrupt  Register*/
typedef struct SWTRIG_BF
{
    uint32 INTID        :8;
    uint32              :24;

}SWTRIG_BF;

/* Structure to define Bit Fields of Interrupt Control and State Register*/
typedef struct INTCTRL_BF
{
    uint32 VECACT   :8;
    uint32          :3;
    uint32 RETBASE  :1;
    uint32 VECPEND  :8;
    uint32          :2;
    uint32 ISRPEND  :1;
    uint32 ISRPRE   :1;
    uint32          :1;
    uint32 PENDSTCLR:1;
    uint32 PENDSTSET:1;
    uint32 UNPENDSV :1;
    uint32 PENDSV   :1;
    uint32          :2;
    uint32 NMISET   :1; 
}INTCTRL_BF;

/* Structure to define Bit Fields of NVIC_PRIn Register*/
typedef struct
{
	uint32				:5;
	uint32 INTA			:3;
	uint32				:5;
	uint32 INTB			:3;
	uint32				:5;
	uint32 INTC			:3;
	uint32				:5;
	uint32 INTD			:3;
} NVIC_PRIx_BF;

/* Structure to define Bit Fields of System Handler Priority 1 Register*/
typedef struct SCB_SYSPRI1_BF
{
	uint32 				:5;
	uint32 MEM			:3;
	uint32				:5;
	uint32 BUS			:3;
	uint32				:5;
	uint32 USAGE		:3;
	uint32				:8;
} SCB_SYSPRI1_BF;	

/* Structure to define Bit Fields of System Handler Priority 2 Register*/
typedef struct SCB_SYSPRI2_BF
{
	uint32 				:29;
	uint32 SVC			:3;
} SCB_SYSPRI2_BF;	

/* Structure to define Bit Fields of System Handler Priority 3 Register*/
typedef struct SCB_SYSPRI3_BF
{
	uint32 				:5;
	uint32 DEBUG		:3;
	uint32				:13;
	uint32 PENDSV		:3;
	uint32				:5;
	uint32 TICK			:3;
} SCB_SYSPRI3_BF;	

/* Structure to define Bit Fields of System Handler Control and State Register*/
typedef struct SCB_SYSHNDCTRL_BF
{
	uint32 MEMA			:1;
	uint32 BUSA			:1;
	uint32 				:1;
	uint32 USGA			:1;
	uint32 				:3;
	uint32 SVCA			:1;
	uint32 MON			:1;
	uint32 				:1;
	uint32 PNDSV		:1;
	uint32 TICK			:1;
	uint32 USAGEP		:1;
	uint32 MEMP			:1;
	uint32 BUSP			:1;
	uint32 SVC			:1;
	uint32 MEM			:1;
	uint32 BUS			:1;
	uint32 USAGE		:1;
	uint32 				:13;
} SCB_SYSHNDCTRL_BF;



/*   32/64-Bit Wide General-Purpose Timer Software Reset (SRWTIMER), offset 0x55C  */
typedef struct SRWTIMER_BF
{
    uint32 R0       :1;  /* 32/64-Bit Wide General-Purpose Timer 5 Software Reset */
    uint32 R1       :1;  /* 32/64-Bit Wide General-Purpose Timer 4 Software Reset */
    uint32 R2       :1;  /* 32/64-Bit Wide General-Purpose Timer 3 Software Reset */
    uint32 R3       :1;  /* 32/64-Bit Wide General-Purpose Timer 2 Software Reset */
    uint32 R4       :1;  /* 32/64-Bit Wide General-Purpose Timer 1 Software Reset */
    uint32 R5       :1;  /* 32/64-Bit Wide General-Purpose Timer 0 Software Reset */
    uint32          :27; /* ********************Reserved Bits******************** */
}SRWTIMER_BF;


/*   Watchdog Timer Run Mode Clock Gating Control (RCGCWD), offset 0x600  */
typedef struct RCGCWD_BF
{
    uint32 R0       :1;  /* Watchdog Timer 1 Run Mode Clock Gating Control */
    uint32 R1       :1;  /* Watchdog Timer 0 Run Mode Clock Gating Control */
    uint32          :30; /* ****************Reserved Bits***************** */
}RCGCWD_BF;


/*   16/32-Bit General-Purpose Timer Run Mode Clock Gating Control (RCGCTIMER), offset 0x604  */
typedef struct RCGCTIMER_BF
{
    uint32 R0       :1;  /* 16/32-Bit General-Purpose Timer 5 Run Mode Clock Gating Control */
    uint32 R1       :1;  /* 16/32-Bit General-Purpose Timer 4 Run Mode Clock Gating Control */
    uint32 R2       :1;  /* 16/32-Bit General-Purpose Timer 3 Run Mode Clock Gating Control */
    uint32 R3       :1;  /* 16/32-Bit General-Purpose Timer 2 Run Mode Clock Gating Control */
    uint32 R4       :1;  /* 16/32-Bit General-Purpose Timer 1 Run Mode Clock Gating Control */
    uint32 R5       :1;  /* 16/32-Bit General-Purpose Timer 0 Run Mode Clock Gating Control */
    uint32          :27; /* ********************Reserved Bits******************** */
}RCGCTIMER_BF;

/* General-Purpose Input/Output Run Mode Clock Gating Control */
typedef struct RCGCGPIO_BF
{
	uint32 R0       :1;  /* GPIO Port A Run Mode Clock Gating Control */
    uint32 R1       :1;  /* GPIO Port B Run Mode Clock Gating Control */
    uint32 R2       :1;  /* GPIO Port C Run Mode Clock Gating Control */
    uint32 R3       :1;  /* GPIO Port D Run Mode Clock Gating Control */
    uint32 R4       :1;  /* GPIO Port E Run Mode Clock Gating Control */
    uint32 R5       :1;  /* GPIO Port F Run Mode Clock Gating Control */
    uint32          :27; /* ********************Reserved Bits******************** */

}RCGCGPIO_BF;


/* General-Purpose Input/Output Run Mode Clock Gating Control */
typedef struct GPIOHBCTL_BF
{
	uint32 PORTA       :1;  /* GPIO Port A Run Mode Clock Gating Control */
    uint32 PORTB       :1;  /* GPIO Port B Run Mode Clock Gating Control */
    uint32 PORTC       :1;  /* GPIO Port C Run Mode Clock Gating Control */
    uint32 PORTD       :1;  /* GPIO Port D Run Mode Clock Gating Control */
    uint32 PORTE       :1;  /* GPIO Port E Run Mode Clock Gating Control */
    uint32 PORTF       :1;  /* GPIO Port F Run Mode Clock Gating Control */
    uint32             :27; /* ********************Reserved Bits******************** */

}GPIOHBCTL_BF;

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
 
 /* Define CPU Clock with 16 MHz*/
#define F_CPU																	(16000000U)


/* Base address of ARM Cortex M4 Core Peripherals SysTick, NVIC, MPU, FPU and SCB registers */
#define CORTEXM4_PERI_BASE_ADDRESS             (0xE000E000)


/*===========================================================*
 *                   System Timer (SysTick) REGISTERS        *
 *========================================================== */
 /* SysTick Control and Status Register */
#define SYSTICK_STCTRL                           (*((volatile SYSTICK_STCTRL_BF*)(CORTEXM4_PERI_BASE_ADDRESS+0x010)))
/* SysTick Reload Value Register */
#define SYSTICK_STRELOAD                         (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x014)))
/* SysTick Current Value Register */
#define SYSTICK_STCURRENT                        (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x018)))


/*===========================================================*
 *  Nested Vectored Interrupt Controller (NVIC) REGISTERS    *
 *========================================================== */
 
/* Interrupt 0-31 Set Enable */
#define NVIC_EN0							   (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x100)))
/* Interrupt 32-63 Set Enable */
#define NVIC_EN1							   (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x104)))
/* Interrupt 64-95 Set Enable */
#define NVIC_EN2							   (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x108)))
/* Interrupt 96-127 Set Enable */
#define NVIC_EN3							   (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x10C)))
/* Interrupt 128-138 Set Enable */
#define NVIC_EN4							   (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x110)))

/* Interrupt 0-31 Clear Enable */
#define NVIC_DIS0							   (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x180)))
/* Interrupt 32-63 Clear Enable */
#define NVIC_DIS1							   (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x184)))
/* Interrupt 64-95 Clear Enable */
#define NVIC_DIS2							   (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x188)))
/* Interrupt 96-127 Clear Enable */
#define NVIC_DIS3							   (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x18C)))
/* Interrupt 128-138 Clear Enable */
#define NVIC_DIS4                              (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x190)))

/* Interrupt 0-31 Set Pending */
#define NVIC_PEND0							   (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x200)))
/* Interrupt 32-63 Set Pending */
#define NVIC_PEND1							   (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x204)))
/* Interrupt 64-95 Set Pending */
#define NVIC_PEND2							   (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x208)))
/* Interrupt 96-127 Set Pending */
#define NVIC_PEND3							   (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x20C)))
/* Interrupt 128-138 Set Pending */
#define NVIC_PEND4                             (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x210)))

/* Interrupt 0-31 Clear Pending */
#define NVIC_UNPEND0					       (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x280)))
/* Interrupt 32-63 Clear Pending */
#define NVIC_UNPEND1				     	   (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x284)))
/* Interrupt 64-95 Clear Pending */
#define NVIC_UNPEND2						   (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x288)))
/* Interrupt 96-127 Clear Pending */
#define NVIC_UNPEND3						   (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x28C)))
/* Interrupt 128-138 Clear Pending */
#define NVIC_UNPEND4                           (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x290)))

/* Interrupt 0-31 Active Bit */
#define NVIC_ACTIVE0					       (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x300)))
/* Interrupt 32-63 Active Bit */
#define NVIC_ACTIVE1				     	   (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x304)))
/* Interrupt 64-95 Active Bit */
#define NVIC_ACTIVE2						   (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x308)))
/* Interrupt 96-127 Active Bit */
#define NVIC_ACTIVE3						   (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x30C)))
/* Interrupt 128-138 Active Bit */
#define NVIC_ACTIVE4                           (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x310)))

/* Base address of NVIC Priority registers */
#define NVIC_PRIx_BASE						   (0x400)

/* Interrupt 0-3 Priority */
#define NVIC_PRI_0                             (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x400)))
/* Interrupt 4-7 Priority */
#define NVIC_PRI_1                             (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x404)))
/* Interrupt 8-11 Priority */
#define NVIC_PRI_2                             (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x408)))
/* Interrupt 12-15 Priority */
#define NVIC_PRI_3                             (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x40C)))
/* Interrupt 16-19 Priority */
#define NVIC_PRI_4                             (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x410)))
/* Interrupt 20-23 Priority */
#define NVIC_PRI_5                             (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x414)))
/* Interrupt 24-27 Priority */
#define NVIC_PRI_6                             (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x418)))
/* Interrupt 28-31 Priority */
#define NVIC_PRI_7                             (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x41C)))
/* Interrupt 32-35 Priority */
#define NVIC_PRI_8                             (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x420)))
/* Interrupt 36-39 Priority */
#define NVIC_PRI_9                             (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x424)))
/* Interrupt 40-43 Priority */
#define NVIC_PRI_10                            (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x428)))
/* Interrupt 44-47 Priority */
#define NVIC_PRI_11                            (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x42C)))
/* Interrupt 48-51 Priority */
#define NVIC_PRI_12                            (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x430)))
/* Interrupt 52-55 Priority */
#define NVIC_PRI_13                            (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x434)))
/* Interrupt 56-59 Priority */
#define NVIC_PRI_14                            (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x438)))
/* Interrupt 60-63 Priority */
#define NVIC_PRI_15                            (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x43C)))
/* Interrupt 64-67 Priority */
#define NVIC_PRI_16                            (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x440)))
/* Interrupt 68-71 Priority */
#define NVIC_PRI_17                            (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x444)))
/* Interrupt 72-75 Priority */
#define NVIC_PRI_18                            (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x448)))
/* Interrupt 76-79 Priority */
#define NVIC_PRI_19                            (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x44C)))
/* Interrupt 80-83 Priority */
#define NVIC_PRI_20                            (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x450)))
/* Interrupt 84-87 Priority */
#define NVIC_PRI_21                            (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x454)))
/* Interrupt 88-91 Priority */
#define NVIC_PRI_22                            (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x458)))
/* Interrupt 92-95 Priority */
#define NVIC_PRI_23                            (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x45C)))
/* Interrupt 96-99 Priority */
#define NVIC_PRI_24                            (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x460)))
/* Interrupt 100-103 Priority */
#define NVIC_PRI_25                            (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x464)))
/* Interrupt 104-107 Priority */
#define NVIC_PRI_26                            (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x468)))
/* Interrupt 108-111 Priority */
#define NVIC_PRI_27                            (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x46C)))
/* Interrupt 112-115 Priority */
#define NVIC_PRI_28                            (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x470)))
/* Interrupt 116-119 Priority */
#define NVIC_PRI_29                            (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x474)))
/* Interrupt 120-123 Priority */
#define NVIC_PRI_30                            (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x478)))
/* Interrupt 124-127 Priority */
#define NVIC_PRI_31                            (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x47C)))
/* Interrupt 128-131 Priority */
#define NVIC_PRI_32                            (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x480)))
/* Interrupt 132-135 Priority */
#define NVIC_PRI_33                            (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x484)))
/* Interrupt 136-138 Priority */
#define NVIC_PRI_34                            (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x488)))

/* Software Trigger Interrupt Register*/
#define  NVIC_SWTRIG                           (*((volatile SWTRIG_BF*)(CORTEXM4_PERI_BASE_ADDRESS+0xF00)))



/*===========================================================*
 *            System Control Block (SCB) REGISTERS           *
 *========================================================== */

/* Auxiliary Control Register */ 
#define SCB_ACTLR                           (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x008)))
/* CPU ID Base Register */ 
#define SCB_CPUID                           (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD00)))
/* Interrupt Control and State Register */
#define SCB_INTCTRL                         (*((volatile INTCTRL_BF*)(CORTEXM4_PERI_BASE_ADDRESS+0xD04)))
/*  Vector Table Offset Register */
#define SCB_VTABLE                          (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD08)))
/*  Application Interrupt and Reset Control Register */
#define SCB_APINT                           (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD0C)))
/* System Control Register */
#define SCB_SYSCTRL                         (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD10)))
/* Configuration and Control Register */
#define SCB_CFGCTRL                         (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD14)))
/* System Handler Priority 1 Register */
#define SCB_SYSPRI1                         (*((volatile SCB_SYSPRI1_BF*)(CORTEXM4_PERI_BASE_ADDRESS+0xD18)))
/* System Handler Priority 2 Register */
#define SCB_SYSPRI2                         (*((volatile SCB_SYSPRI2_BF*)(CORTEXM4_PERI_BASE_ADDRESS+0xD1C)))
/* System Handler Priority 3 Register */
#define SCB_SYSPRI3                         (*((volatile SCB_SYSPRI3_BF*)(CORTEXM4_PERI_BASE_ADDRESS+0xD20)))
/*  System Handler Control and State Register */
#define SCB_SYSHNDCTRL                      (*((volatile SCB_SYSHNDCTRL_BF*)(CORTEXM4_PERI_BASE_ADDRESS+0xD24)))
/*  Configurable Fault Status Register */
#define SCB_FAULTSTAT                       (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD28)))
/*  Hard Fault Status Register */
#define SCB_HFAULTSTAT                      (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD2C)))
/* Memory Management Fault Address Register */
#define SCB_MMADDR                          (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD34)))
/* Bus Fault Address Register */
#define SCB_FAULTADDR                       (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD38)))
 
 /*===========================================================*
 *            System Control REGISTERS                        *
 *========================================================== */
/* Base address of System Control registers */
#define SYSTEM_CONTROL_PERI_BASE_ADDRESS          (0x400FE000)

#define SYSTEM_CONTROL_REG_SRWTIMER                         (*((volatile SRWTIMER_BF*)(SYSTEM_CONTROL_PERI_BASE_ADDRESS+0x55C)))
#define SYSTEM_CONTROL_REG_RCGCWD                           (*((volatile RCGCWD_BF*)(SYSTEM_CONTROL_PERI_BASE_ADDRESS+0x600)))
#define SYSTEM_CONTROL_REG_RCGCTIMER                        (*((volatile RCGCTIMER_BF*)(SYSTEM_CONTROL_PERI_BASE_ADDRESS+0x604)))
#define SYSTEM_CONTROL_REG_RCGCGPIO                         (*((volatile RCGCGPIO_BF*)(SYSTEM_CONTROL_PERI_BASE_ADDRESS+0x608)))
#define SYSTEM_CONTROL_REG_GPIOHBCTL                        (*((volatile GPIOHBCTL_BF*)(SYSTEM_CONTROL_PERI_BASE_ADDRESS+0x06C)))
/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 

 
#endif  /* MCU_HW_H */

/**********************************************************************************************************************
 *  END OF FILE: Mcu_Hw.h
 *********************************************************************************************************************/

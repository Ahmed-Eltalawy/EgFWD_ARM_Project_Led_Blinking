/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Port_registers.h
 *       Module:  -
 *
 *  Description:  Header file for Port Module Registers.     
 *  
 *********************************************************************************************************************/
#ifndef PORT_REGISTERS_H
#define PORT_REGISTERS_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/*===========================================================*
 *                   Port REGISTERS                          *
 *========================================================== */
/* Base address of GPIO Port A (APB) */
#define GPIO_A_APB_PERI_BASE_ADDRESS             (0x40004000)

/* Base address of GPIO Port A (AHB) */
#define GPIO_A_AHB_PERI_BASE_ADDRESS             (0x40058000)

/* Base address of GPIO Port B (APB) */
#define GPIO_B_APB_PERI_BASE_ADDRESS             (0x40005000)

/* Base address of GPIO Port B (AHB) */
#define GPIO_B_AHB_PERI_BASE_ADDRESS             (0x40059000)

/* Base address of GPIO Port C (APB) */
#define GPIO_C_APB_PERI_BASE_ADDRESS             (0x40006000)

/* Base address of GPIO Port C (AHB) */
#define GPIO_C_AHB_PERI_BASE_ADDRESS             (0x4005A000)

/* Base address of GPIO Port D (APB) */
#define GPIO_D_APB_PERI_BASE_ADDRESS             (0x40007000)

/* Base address of GPIO Port D (AHB) */
#define GPIO_D_AHB_PERI_BASE_ADDRESS             (0x4005B000)

/* Base address of GPIO Port E (APB) */
#define GPIO_E_APB_PERI_BASE_ADDRESS             (0x40024000)

/* Base address of GPIO Port E (AHB) */
#define GPIO_E_AHB_PERI_BASE_ADDRESS             (0x4005C000)

/* Base address of GPIO Port F (APB) */
#define GPIO_F_APB_PERI_BASE_ADDRESS             (0x40025000)

/* Base address of GPIO Port F (AHB) */
#define GPIO_F_AHB_PERI_BASE_ADDRESS             (0x4005D000)




#define GPIODATA_OFFSET                          (0x3FC)         //GPIO Data Register
#define GPIODIR_OFFSET                           (0x400)         //GPIO Direction Register
#define GPIOIS_OFFSET                            (0x404)         //GPIO Interrupt Sense Register
#define GPIOIBE_OFFSET                           (0x408)         //GPIO Interrupt Both Edges Register
#define GPIOIEV_OFFSET                           (0x40C)         //GPIO Interrupt Event Register
#define GPIOIM_OFFSET                            (0x410)         //GPIO Interrupt Mask Register
#define GPIORIS_OFFSET                           (0x414)         //GPIO Raw Interrupt Status Register
#define GPIOMIS_OFFSET                           (0x418)         //GPIO Masked Interrupt Status Register
#define GPIOICR_OFFSET                           (0x41C)         //GPIO Interrupt Clear Register
#define GPIOAFSEL_OFFSET                         (0x420)         //GPIO Alternate Function Select Register
#define GPIODR2R_OFFSET                          (0x500)         //GPIO 2-mA Drive Select Register
#define GPIODR4R_OFFSET                          (0x504)         //GPIO 4-mA Drive Select Register
#define GPIODR8R_OFFSET                          (0x508)         //GPIO 8-mA Drive Selec Register
#define GPIOODR_OFFSET                           (0x50C)         //GPIO Open Drain Select Register
#define GPIOPUR_OFFSET                           (0x510)         //GPIO Pull-Up Select Register
#define GPIOPDR_OFFSET                           (0x514)         //GPIO Pull-Down Select Register
#define GPIOSLR_OFFSET                           (0x518)         //GPIO Slew Rate Control Select Register
#define GPIODEN_OFFSET                           (0x51C)         //GPIO Digital Enable Register
#define GPIOLOCK_OFFSET                          (0x520)         //GPIO Lock Register
#define GPIOCR_OFFSET                            (0x524)         //GPIO Commit Register
#define GPIOAMSEL_OFFSET                         (0x528)         //GPIO Analog Mode Select Register
#define GPIOPCTL_OFFSET                          (0x52C)         //GPIO Port Control Register
#define GPIOADCCTL_OFFSET                        (0x530)         //GPIO ADC Control Register
#define GPIODMACTL_OFFSET                        (0x534)         //GPIO DMA Control Register
#define GPIOPeriphID4_OFFSET                     (0xFD0)         //GPIO Peripheral Identification 4 Register
#define GPIOPeriphID5_OFFSET                     (0xFD4)         //GPIO Peripheral Identification 5 Register
#define GPIOPeriphID6_OFFSET                     (0xFD8)         //GPIO Peripheral Identification 6 Register
#define GPIOPeriphID7_OFFSET                     (0xFDC)         //GPIO Peripheral Identification 47 Register
#define GPIOPeriphID0_OFFSET                     (0xFE0)         //GPIO Peripheral Identification 0 Register
#define GPIOPeriphID1_OFFSET                     (0xFE4)         //GPIO Peripheral Identification 1 Register
#define GPIOPeriphID2_OFFSET                     (0xFE8)         //GPIO Peripheral Identification 2 Register
#define GPIOPeriphID3_OFFSET                     (0xFEC)         //GPIO Peripheral Identification 3 Register
#define GPIOPCellID0_OFFSET                      (0xFF0)         //GPIO PrimeCell Identification 0 Register
#define GPIOPCellID1_OFFSET                      (0xFF4)         //GPIO PrimeCell Identification 1 Register
#define GPIOPCellID2_OFFSET                      (0xFF8)         //GPIO PrimeCell Identification 2 Register
#define GPIOPCellID3_OFFSET                      (0xFFC)         //GPIO PrimeCell Identification 3 Register

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


 
#endif  /* PORT_REGISTERS_H */

/**********************************************************************************************************************
 *  END OF FILE: Port_Registers.h
 *********************************************************************************************************************/

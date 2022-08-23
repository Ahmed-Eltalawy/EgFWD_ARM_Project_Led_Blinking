/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Gpt_registers.h
 *       Module:  -
 *
 *  Description:  Header file for Gpt Module Registers.     
 *  
 *********************************************************************************************************************/
#ifndef GPT_REGISTERS_H
#define GPT_REGISTERS_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
 
/* GPT Register Configuration Bit Fields */
typedef struct GPTMCFG_BF
{
    uint32 GPTMCFG     :3;
    uint32             :29;
 
}GPTMCFG_BF;


/* GPT Register Timer A Mode Bit Fields */
typedef struct GPTMTAMR_BF
{
    uint32 TAMR      :2;
    uint32 TACMR     :1;
    uint32 TAAMS     :1;
    uint32 TACDIR    :1;
    uint32 TAMIE     :1;
    uint32 TAWOT     :1;
    uint32 TASNAP    :1;
    uint32 TAILD     :1;
    uint32 TAPWMIE   :1;
    uint32 TAMRSU    :1;
    uint32 TAPLO     :1;
    uint32           :20;
 
}GPTMTAMR_BF;


/* GPT Register Interrupt Mask Bit Fields */
typedef struct GPTMIMR_BF
{
    uint32 TATOIM    :1;
    uint32 CAMIM     :1;
    uint32 CAEIM     :1;
    uint32 RTCIM     :1;
    uint32 TAMIM     :1;
    uint32           :3;
    uint32 TBTOIM    :1;
    uint32 CBMIM     :1;
    uint32 CBEIM     :1;
    uint32 TBMIM     :1;
    uint32           :4;
    uint32 WUEIM     :1;
    uint32           :15;
 
}GPTMIMR_BF;


typedef struct
{
	uint32 TAEN		:1;
	uint32 TASTALL	:1;
	uint32 TAEVENT	:2;
	uint32 RTCEN	:1;
	uint32 TAOTE	:1;
	uint32 TAPWML	:1;
	uint32 			:1;
	uint32 TBEN		:1;
	uint32 TBSTALL	:1;
	uint32 TBEVENT	:2;
	uint32 			:1;
	uint32 TBOTE	:1;
	uint32 TBPWML	:1;
	uint32 			:17;
} GPTMCTL_BF;

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/*===========================================================*
 *                   General Purpose Timer REGISTERS         *
 *========================================================== */

/* Base address of General Purpose Timer 0 */
#define GPT_TIMER0_PERI_BASE_ADDRESS                  (0x40030000)

/* Base address of General Purpose Timer 1 */
#define GPT_TIMER1_PERI_BASE_ADDRESS                  (0x40031000)

/* Base address of General Purpose Timer 2 */
#define GPT_TIMER2_PERI_BASE_ADDRESS                  (0x40032000)

/* Base address of General Purpose Timer 3 */
#define GPT_TIMER3_PERI_BASE_ADDRESS                  (0x40033000)

/* Base address of General Purpose Timer 4 */
#define GPT_TIMER4_PERI_BASE_ADDRESS                  (0x40034000)

/* Base address of General Purpose Timer 5 */
#define GPT_TIMER5_PERI_BASE_ADDRESS                  (0x40035000)

/* Base address of Wide General Purpose Timer 0 */
#define GPT_WIDE_TIMER0_PERI_BASE_ADDRESS             (0x40036000)

/* Base address of Wide General Purpose Timer 1 */
#define GPT_WIDE_TIMER1_PERI_BASE_ADDRESS             (0x40037000)

/* Base address of Wide General Purpose Timer 2 */
#define GPT_WIDE_TIMER2_PERI_BASE_ADDRESS             (0x4004C000)

/* Base address of Wide General Purpose Timer 3 */
#define GPT_WIDE_TIMER3_PERI_BASE_ADDRESS             (0x4004D000)

/* Base address of Wide General Purpose Timer 4 */
#define GPT_WIDE_TIMER4_PERI_BASE_ADDRESS             (0x4004E000)

/* Base address of Wide General Purpose Timer 5 */
#define GPT_WIDE_TIMER5_PERI_BASE_ADDRESS             (0x4004F000)



#define GPTMCFG_OFFSET                                (0x000)          //GPTM Configuration Register
#define GPTMTAMR_OFFSET                               (0x004)          //GPTM Timer A Mode Register
#define GPTMTBMR_OFFSET                               (0x008)          //GPTM Timer B Mode Register
#define GPTMCTL_OFFSET                                (0x00C)          //GPTM Control Register
#define GPTMSYNC_OFFSET                               (0x010)          //GPTM Synchronize Register
#define GPTMIMR_OFFSET                                (0x018)          //GPTM Interrupt Mask Register
#define GPTMRIS_OFFSET                                (0x01C)          //GPTM Raw Interrupt Status Register
#define GPTMMIS_OFFSET                                (0x020)          //GPTM Masked Interrupt Status Register
#define GPTMICR_OFFSET                                (0x024)          //GPTM Interrupt Clear Register
#define GPTMTAILR_OFFSET                              (0x028)          //GPTM Timer A Interval Load Register
#define GPTMTBILR_OFFSET                              (0x02C)          //GPTM Timer B Interval Load Register
#define GPTMTAMATCHR_OFFSET                           (0x030)          //GPTM Timer A Match Register
#define GPTMTBMATCHR_OFFSET                           (0x034)          //GPTM Timer B Match Register
#define GPTMTAPR_OFFSET                               (0x038)          //GPTM Timer A Prescale Register
#define GPTMTBPR_OFFSET                               (0x03C)          //GPTM Timer B Prescale Register
#define GPTMTAPMR_OFFSET                              (0x040)          //GPTM TimerA Prescale Match Register
#define GPTMTBPMR_OFFSET                              (0x044)          //GPTM TimerB Prescale Match Register
#define GPTMTAR_OFFSET                                (0x048)          //GPTM Timer A Register
#define GPTMTBR_OFFSET                                (0x04C)          //GPTM Timer B Register
#define GPTMTAV_OFFSET                                (0x050)          //GPTM Timer A Value Register
#define GPTMTBV_OFFSET                                (0x054)          //GPTM Timer B Value Register
#define GPTMRTCPD_OFFSET                              (0x058)          //GPTM RTC Predivide Register
#define GPTMTAPS_OFFSET                               (0x05C)          //GPTM Timer A Prescale Snapshot Register
#define GPTMTBPS_OFFSET                               (0x060)          //GPTM Timer B Prescale Snapshot Register
#define GPTMTAPV_OFFSET                               (0x064)          //GPTM Timer A Prescale Value Register
#define GPTMTBPV_OFFSET                               (0x068)          //GPTM Timer B Prescale Value Register
#define GPTMPP_OFFSET                                 (0xFC0)          //GPTM Peripheral Properties Register


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


 
#endif  /* GPT_REGISTERS_H */

/**********************************************************************************************************************
 *  END OF FILE: Gpt_Registers.h
 *********************************************************************************************************************/

/******************************************************************************
 *		    AceXtreme 'C' Run Time Software Library
 *
 * FILE:          ddccommon.h
 *
 * DESCRIPTION:   Common definitions and types used in the 69092 and 42992
 *                libraries.
 *
 * Data Device Corporation
 * 105 Wilbur Place
 * Bohemia N.Y. 11716
 * (631) 567-5600
 *
 * Copyright (c) 2011 by Data Device Corporation
 * All Rights Reserved.
 *
 ******************************************************************************/
#ifndef __DDC_COMMON_H__
#define __DDC_COMMON_H__

/*============================================================================*/
/*                               D E F I N E S                                */
/*============================================================================*/

/*----------------------------------------------------------------------------*/
/* DDC Vendor ID */
/*----------------------------------------------------------------------------*/
#define DDC_VENDOR_ID                   0x4DDC

/*----------------------------------------------------------------------------*/
/* DDC Device IDs */
/*----------------------------------------------------------------------------*/

/* Legacy Cards */
#define DDC_DEV_ID_BU65565C1            0x0901  /* 1 channel  PMC card                      */
#define DDC_DEV_ID_BU65565C2            0x0902  /* 2 channel  PMC card                      */
#define DDC_DEV_ID_BU65565C3            0x0903  /* 3 channel  PMC card                      */
#define DDC_DEV_ID_BU65565C4            0x0904  /* 4 channel  PMC card                      */
#define DDC_DEV_ID_BU65569I1            0x0B01  /* 1 channel  PCI card                      */
#define DDC_DEV_ID_BU65569I2            0x0B02  /* 2 channel  PCI card                      */
#define DDC_DEV_ID_BU65569I3            0x0B03  /* 3 channel  PCI card                      */
#define DDC_DEV_ID_BU65569I4            0x0B04  /* 4 channel  PCI card                      */
#define DDC_DEV_ID_BU65569T1            0x0C01  /* 1 channel CPCI card                      */
#define DDC_DEV_ID_BU65569T2            0x0C02  /* 2 channel CPCI card                      */
#define DDC_DEV_ID_BU65569T3            0x0C03  /* 3 channel CPCI card                      */
#define DDC_DEV_ID_BU65569T4            0x0C04  /* 4 channel CPCI card                      */
#define DDC_DEV_ID_BU65569B1            0x0C05  /* 1 channel CPCI card                      */
#define DDC_DEV_ID_BU65569B2            0x0C06  /* 2 channel CPCI card                      */
#define DDC_DEV_ID_BU65569B3            0x0C07  /* 3 channel CPCI card                      */
#define DDC_DEV_ID_BU65569B4            0x0C08  /* 4 channel CPCI card                      */
#define DDC_DEV_ID_BU65566XX            0x0E06  /* 1 - 4 channel 66MHz PCI card             */
#define DDC_DEV_ID_BU65566RX            0x1100  /* 1 - 4 channel 66MHz cPCI card            */
#define DDC_DEV_ID_BU65843              0x0400  /* BC/RT/MT WITH 4K OF RAM                  */
#define DDC_DEV_ID_BU65586N2            0x0401  /* BC/RT/MT WITH 64K OF RAM                 */
#define DDC_DEV_ID_BU65864              0x0402  /* BC/RT/MT WITH 64K OF RAM                 */
#define DDC_DEV_ID_BU65743              0x0404  /* RT ONLY WITH 4K OF RAM                   */
#define DDC_DEV_ID_BU65764              0x0406  /* RT ONLY WITH 64K OF RAM                  */

/* Legacy Cards - High-Reliable */
#define DDC_DEV_ID_BU65596F1            0x2400  /* 1 channel PMC card, Front                */
#define DDC_DEV_ID_BU65596F2            0x2401  /* 2 channel PMC card, Front                */
#define DDC_DEV_ID_BU65596F4            0x2402  /* 4 channel PMC card, Front                */
#define DDC_DEV_ID_BU65596M1            0x2403  /* 1 channel PMC card, Rear                 */
#define DDC_DEV_ID_BU65596M2            0x2404  /* 2 channel PMC card, Rear                 */
#define DDC_DEV_ID_BU65596M4            0x2405  /* 4 channel PMC card, Rear                 */

/* Flexcore Cards */
#define DDC_DEV_ID_BU65578CX            0x1200  /* 1 - 4 channel PC-104+ card               */
#define DDC_DEV_ID_BU65590FMX           0x1300  /* 1 - 4 channel MultiIO card               */
#define DDC_DEV_ID_BU65578FMX           0x1600  /* 1 - 8 channel PMC card                   */
#define DDC_DEV_ID_BU65590CX            0x1700  /* 1 - 4 channel MultiIO PC104P card        */
#define DDC_DEV_ID_BU65590UX            0x5590  /* 1 - 4 channel MultiIO USB card           */

/* ACEX Cards */
#define DDC_DEV_ID_QPRM                 0x1A00  /* 1 channel Q-PRIME Evaluation card        */

#define DDC_DEV_ID_BU67101QX            0x1B00  /* 1 - 4 channel Express card               */
#define DDC_DEV_ID_BU67102UX            0x7102
#define DDC_DEV_ID_BU67103UX            0x7103
#define DDC_DEV_ID_BU67105CX            0x1D00  /* 1 - 4 channel PC-104P card               */
#define DDC_DEV_ID_BU67106KX            0x1C00  /* 1 - 4 channel PCIe Type A card           */
#define DDC_DEV_ID_BU67106BKX           0x1C80  /* 1 - 4 channel PCIe type B card           */
#define DDC_DEV_ID_BU67107FM            0x2000  /* 1 - 2 channel PMC Front/Rear card        */
#define DDC_DEV_ID_BU67108C             0x1F00  /* 1 - 2 channel PMC Front/Rear card        */
#define DDC_DEV_ID_BU67110FM            0x1E00  /* 1 - 8 channel High-Density PMC card      */
#define DDC_DEV_ID_BU67112Xx            0x2500  /* 1 - 8 channel PCIe Tacex based card      */
#define DDC_DEV_ID_BU67113UX            0x0300

#define DDC_DEV_ID_BU67202UX            0x0200

#define DDC_DEV_ID_BU67206KX            0x2100  /* 1 - 4 channel MF PCIe type A card (Obsoleted)  */
#define DDC_DEV_ID_BU67206BKX           0x2180  /* 1 - 4 channel MF PCIe type B card        */
#define DDC_DEV_ID_BU67210FMX           0x2200  /* 1 - 4 channel MF PCI B card              */

#define DDC_DEV_ID_BU67211UX            0x0100

/*----------------------------------------------------------------------------*/
/*                               W I N D O W S                                */
/*----------------------------------------------------------------------------*/
#ifdef WIN32

typedef HANDLE				  DDC_HANDLE;
typedef unsigned char         U8BIT;
typedef unsigned short        U16BIT;
typedef unsigned long         U32BIT;
typedef ULONG64               U64BIT;

typedef char                  S8BIT;
typedef short                 S16BIT;
typedef long                  S32BIT;
typedef LONG64                S64BIT;

#define  U64 U64BIT
#define  S64 S64BIT
#define  U32 U32BIT
#define  S32 S32BIT
#define  U16 U16BIT
#define  S16 S16BIT
#define  U8  U8BIT
#define  S8  S8BIT

/* Mutex Definitions */
#define DDC_MUTEX		           DDC_HANDLE
#define DDC_MUTEX_DESTROY(x)       CloseHandle(x)
#define DDC_MUTEX_CREATE(x,y,z)    CreateMutex(x,y,z)
#define DDC_MUTEX_WAIT_FOREVER(x)  WaitForSingleObject(x,INFINITE)
#define DDC_MUTEX_RELEASE(x)       ReleaseMutex(x)

/* RTL malloc/free macro */
#ifndef STATIC
   #define DDC_MALLOC(size) malloc(size)
   #define DDC_FREE(ptr) free(ptr)
#else
   #define DDC_MALLOC(size) DDC_Malloc(size)
   #define DDC_FREE(ptr) DDC_Free(ptr)
#endif /* STATIC */

#endif /* WIN32 */

/*----------------------------------------------------------------------------*/
/*                                 L I N U X                                  */
/*----------------------------------------------------------------------------*/
#ifdef linux

typedef unsigned char         U8BIT;
typedef unsigned short        U16BIT;
typedef unsigned int          U32BIT;
typedef unsigned long long    U64BIT;

typedef signed char           S8BIT;
typedef short                 S16BIT;
typedef int                   S32BIT;
typedef long long             S64BIT;

typedef unsigned short        USHORT;
typedef unsigned short        WORD;
typedef unsigned long         ULONG;

typedef char                  CHAR;
typedef unsigned char         UCHAR;
typedef short                 SHORT;
typedef long                  LONG;
typedef unsigned int          DWORD;

#define LPVOID                void*
#define PVOID                 void*
#define VOID                  void

typedef unsigned char         BOOL;
typedef unsigned char         BOOLEAN;

#define  U64 U64BIT
#define  S64 S64BIT
#define  U32 U32BIT
#define  S32 S32BIT
#define  U16 U16BIT
#define  S16 S16BIT
#define  U8  U8BIT
#define  S8  S8BIT

/* Mutex Definitions */
#define DDC_MUTEX                   pthread_mutex_t *
#define DDC_MUTEX_DESTROY(x)        {pthread_mutex_destroy(x);free(x);x=NULL;}
#define DDC_MUTEX_CREATE(x,y,z)     _dvxMutexCreate(x)
#define DDC_MUTEX_WAIT_FOREVER(x)   pthread_mutex_lock(x)
#define DDC_MUTEX_RELEASE(x)        pthread_mutex_unlock(x)

/* RTL malloc/free macro */
#ifndef STATIC
   #define DDC_MALLOC(size) malloc(size)
   #define DDC_FREE(ptr) free(ptr)
#else
   #define DDC_MALLOC(size) DDC_Malloc(size)
   #define DDC_FREE(ptr) DDC_Free(ptr)
#endif /* STATIC */

#endif /* linux */

/*----------------------------------------------------------------------------*/
/*                               V X W O R K S                                */
/*----------------------------------------------------------------------------*/
#ifdef VX_WORKS

#include <vxworks.h>

#define HANDLE                void *
#define DDC_HANDLE            void *

typedef UINT8                 U8BIT;
typedef UINT16                U16BIT;
typedef UINT32                U32BIT;
typedef UINT64                U64BIT;

typedef INT8                  S8BIT;
typedef INT16                 S16BIT;
typedef INT32                 S32BIT;
typedef INT64                 S64BIT;

typedef UINT32                DWORD;

#define LPVOID                void*
#define PVOID                 void*
#define VOID                  void

#ifndef VME_184  /* SVME 184 BSP has BOOLEAN typedef */
typedef unsigned char         BOOLEAN;
#endif

typedef unsigned short        WORD;

typedef short                 SHORT;
typedef long                  LONG;
typedef unsigned long *       PULONG;
typedef unsigned short *      PUSHORT;

#define  U64 U64BIT
#define  S64 S64BIT
#define  U32 U32BIT
#define  S32 S32BIT
#define  U16 U16BIT
#define  S16 S16BIT
#define  U8  U8BIT
#define  S8  S8BIT

/* Mutex Definitions */
#define DDC_MUTEX                   SEM_ID
#define DDC_MUTEX_DESTROY(x)        {semDelete(x); x=NULL;}
#define DDC_MUTEX_CREATE(x,y,z)     semBCreate(SEM_Q_FIFO,SEM_FULL)
#define DDC_MUTEX_WAIT_FOREVER(x)   semTake(x, WAIT_FOREVER)
#define DDC_MUTEX_RELEASE(x)        semGive(x)

/* RTL malloc/free macro */
#ifndef STATIC
   #define DDC_MALLOC(size) malloc(size)
   #define DDC_FREE(ptr) free(ptr)
#else
   #define DDC_MALLOC(size) DDC_Malloc(size)
   #define DDC_FREE(ptr) DDC_Free(ptr)
#endif /* STATIC */

#define INVALID_FAMILY              0xFF

#endif /* VX_WORKS */

/*----------------------------------------------------------------------------*/
/*                             I N T E G R I T Y                              */
/*----------------------------------------------------------------------------*/
#ifdef INTEGRITY

typedef unsigned char         U8BIT;
typedef unsigned short        U16BIT;
typedef unsigned long         U32BIT;
typedef unsigned long long    U64BIT;

typedef char                  S8BIT;
typedef short                 S16BIT;
typedef long                  S32BIT;
typedef signed long long      S64BIT;

typedef unsigned short        WORD;

typedef unsigned long         DWORD;

typedef unsigned char         BOOL;
typedef unsigned char         BOOLEAN;
typedef void		          VOID;

/* Mutex Definitions */
#define DDC_MUTEX
#define DDC_MUTEX_DESTROY(x)
#define DDC_MUTEX_CREATE(x,y,z)
#define DDC_MUTEX_WAIT_FOREVER(x)
#define DDC_MUTEX_RELEASE(x)

/* RTL malloc/free macro */
#ifndef STATIC
   #define DDC_MALLOC(size) malloc(size)
   #define DDC_FREE(ptr) free(ptr)
#else
   #define DDC_MALLOC(size) DDC_Malloc(size)
   #define DDC_FREE(ptr) DDC_Free(ptr)
#endif /* STATIC */

#endif /* INTEGRITY */

/*----------------------------------------------------------------------------*/
/*                              A L L   O S ' S                               */
/*----------------------------------------------------------------------------*/
#ifndef FALSE
#define FALSE                 0
#endif

#ifndef TRUE
#define TRUE                  1
#endif

#include "ddcos.h"

/* Device Family Name Enumeration */
typedef enum _FAMILY
{
   EMACE = 0,
   E2MACE,
   ACEX,
   SYNCHRO
} FAMILY;

typedef enum
{
   DISC_INPUT  = 0,
   DISC_OUTPUT = 1
} DISC_DIR;

enum
{
    ARINC429_TX_CHANNEL = 0,
    ARINC429_RX_CHANNEL,
    ARINC429_UNDEFINED_CHANNEL
};

enum
{
    ARINC717_TX_CHANNEL = 0,
    ARINC717_RX_CHANNEL,
    ARINC717_UNDEFINED_CHANNEL
};

 /* Capability Defines to be used with the HWVERSIONINFO structure member dwCapabilities */

                                                            /* BIT Description              */
#define HWVER_CAPABILITY_MF                     0x00000001  /* 0   Multi-Function Capable   */
#define HWVER_CAPABILITY_VAR_VOLT_OUT           0x00000002  /* 1   Variable Voltage Output  */
#define HWVER_CAPABILITY_COUPLING               0x00000004  /* 2   Coupling                 */
#define HWVER_CAPABILITY_TERMINATION            0x00000008  /* 3   Termination              */
#define HWVER_CAPABILITY_REPLAY                 0x00000010  /* 4   Replay                   */
#define HWVER_CAPABILITY_MTI                    0x00000020  /* 5   MTI                      */
#define HWVER_CAPABILITY_MTIE_MEC               0x00000040  /* 6   MTIe (MEC)               */
#define HWVER_CAPABILITY_MTIR_AES               0x00000080  /* 7   MTIr (AES)               */
#define HWVER_CAPABILITY_EXTERNAL_CLOCK_IN      0x00000100  /* 8   External Clock In        */
#define HWVER_CAPABILITY_EXTERNAL_CLOCK_OUT     0x00000200  /* 9   External Clock Out       */
#define HWVER_CAPABILITY_IRIG_IN_ANALOG         0x00000400  /* 10  Analog IRIG Rx (In)      */
#define HWVER_CAPABILITY_IRIG_IN_DIGITAL        0x00000800  /* 11  Digital IRIG Rx (In)     */
#define HWVER_CAPABILITY_IRIG_OUT_DIGITAL       0x00001000  /* 12  Digital IRIG Tx (Out)    */
#define HWVER_CAPABILITY_IRIG_RANGE             0x00002000  /* 13  IRIG Range               */
#define HWVER_CAPABILITY_TX_INHIBIT_BC_DISABLE  0x00004000  /* 14  Tx Inhibit / BC Disable  */
#define HWVER_CAPABILITY_CAN                    0x00008000  /* 15  CAN                      */
#define HWVER_CAPABILITY_PPS                    0x00010000  /* 16  PPS                      */
#define HWVER_CAPABILITY_PROG_ARINC_429         0x00020000  /* 17  Programmable ARINC 429   */
#define HWVER_CAPABILITY_PROG_ARINC_717         0x00040000  /* 18  Programmable ARINC 429   */
#define HWVER_CAPABILITY_PROG_SERIAL            0x00080000  /* 19  Programmable ARINC 429   */
#define HWVER_CAPABILITY_MSI                    0x00100000  /* 20  PPS                      */
#define HWVER_CAPABILITY_BC_DISABLE             0x00200000  /* 22  BC disable               */
#define HWVER_CAPABILITY_BC_EXT_TRIGGER         0x00400000  /* 21  BC external trigger      */
#define HWVER_CAPABILITY_MRT_DISABLE            0x00800000  /* 23  MRT disable              */
#define HWVER_CAPABILITY_RT_AUTO_BOOT           0x01000000  /* 24  RT Auto Boot             */
#define HWVER_CAPABILITY_TX_INHIBIT             0x02000000  /* 25  TX Inhibit               */
                                                            /* 26 - 29 (Unused)             */
#define HWVER_CAPABILITY_MPRM                   0x40000000  /* 30  M-Prime device           */
#define HWVER_CAPABILITY_QPRM                   0x80000000  /* 31  Q-Prime device           */

/* ARINC 429 programmable configuration options place holders, common between RTL and Driver */
#define ARINC_429_PROGRMMABLE_ENABLE_OPT        0x00000001
#define ARINC_429_PROGRMMABLE_TYPE_OPT          0x00000002
#define ARINC_429_PROGRMMABLE_SPEED_OPT         0x00000008
#define ARINC_429_PROGRMMABLE_PARITY_OPT        0x00000008
#define ARINC_429_PROGRMMABLE_BIT_FORMAT_OPT    0x00000010
#define ARINC_429_PROGRMMABLE_MODE_OPT          0x00000020
#define ARINC_429_PROGRMMABLE_RESET_OPT         0x00000040
#define ARINC_429_PROGRMMABLE_ENABLE_TX_PASSIVE_OPT 0x00000080


/* Option parameters for API function ModifyRepeatedData. */
#define ARINC_429_MODIFY_REPEATED_VIA_LABEL     0x0000001
#define ARINC_429_MODIFY_REPEATED_VIA_SDI_LABEL 0x0000002

/* ARINC 717 programmable configuration options place holders, common between RTL and Driver */
#define ARINC_717_PROGRMMABLE_SLOPE_OPT         0x00000001
#define ARINC_717_PROGRMMABLE_WRAP_AROUND_OPT   0x00000002
#define ARINC_717_PROGRMMABLE_STOP_OPT          0x00000004
#define ARINC_717_PROGRMMABLE_AUTO_DETECT_OPT   0x00000008
#define ARINC_717_PROGRMMABLE_RESET_OPT         0x00000010
#define ARINC_717_PROGRMMABLE_BUFFER_MODE_OPT   0x00000020
#define ARINC_717_PROGRMMABLE_PROTOCOL_OPT      0x00000040
#define ARINC_717_PROGRMMABLE_TYPE_OPT          0x00000080
#define ARINC_717_PROGRMMABLE_SPEED_OPT         0x00000200
#define ARINC_717_PROGRMMABLE_FRAME_COUNT_OPT   0x00000400

/* ARINC 717 programmable Tx load options. */
#define ARINC_717_TX_DATA_PRIMARY_BUFFER_OPT    0x00000001
#define ARINC_717_TX_DATA_SECONDARY_BUFFER_OPT  0x00000002

/* Slope control, bits [15:14] of configuration register */
#define ARINC_717_PROG_TX_SLOPE_CONTROL_MASK        0x3
#define ARINC_717_PROG_TX_SLOPE_CONTROL_68PF        0x0
#define ARINC_717_PROG_TX_SLOPE_CONTROL_398PF       0x1
#define ARINC_717_PROG_TX_SLOPE_CONTROL_538PF       0x2
#define ARINC_717_PROG_TX_SLOPE_CONTROL_868PF       0x3

#define ARINC_717_PROG_BUF_MODE_SINGLE              0x0
#define ARINC_717_PROG_BUF_MODE_DOUBLE              0x1
#define ARINC_717_PROG_BUF_MODE_CIRCULAR            0x2 /* Only valid in receiver mode */
#define ARINC_717_PROG_BUF_MODE_INVALID             0x3

/* Interrupt place holders */
#define ARINC_717_CH1_INT                           0x00000001
#define ARINC_717_CH2_INT                           0x00000002
#define ARINC_717_PROG_INT_TX_MARKER0_ENA           0x00000001  /* 1st location of of 1st buffer read */
#define ARINC_717_PROG_INT_TX_MARKER1_ENA           0x00000002  /* 1st location of of 2nd buffer read */
#define ARINC_717_PROG_INT_RX_HALF_SUB_FRAME_ENA    0x00010000  /* mid subframe word read */
#define ARINC_717_PROG_INT_RX_SUB_FRAME_ENA         0x00020000  /* next subframe word read */
#define ARINC_717_PROG_INT_RX_50_PC_MEM_ENA         0x00040000  /* 50% of memory written */
#define ARINC_717_PROG_INT_RX_100_PC_MEM_ENA        0x00080000  /* next word at beggining of memory written */
#define ARINC_717_PROG_INT_RX_REC_SYNCED_ENA        0x00100000  /* valid sync word detected when not synced */
#define ARINC_717_PROG_INT_RX_REC_SYNCED_ERR_ENA    0x00200000  /* valid sync word not detected at beginning of frame */
#define ARINC_717_PROG_INT_RX_AUTO_DETECT_LOCK_ENA  0x00400000  /* receiver detected correct speed */
#define ARINC_717_PROG_INT_RX_AUTO_DETECT_LOST_ENA  0x00800000  /* receiver lost lock on correct speed due to bit errors */
#define ARINC_717_PROG_INT_RX_BIT_ERR_DETECTED_ENA  0x01000000  /* Reserved bits */
#define ARINC_717_PROG_INT_NOT_USED_ENA             0x01FF0003  /* Reserved bits */

#define ARINC_717_PROG_EXT_WRAP_AROUND_MASK         0x00002000  /* Enables exteranl transmitter/receiver wraparound mode. */
#define ARINC_717_PROG_TX_STOP_MASK                 0x00001000  /* Enables exteranl transmitter/receiver wraparound mode. */
#define ARINC_717_PROG_RX_AUTO_DETECT_MASK          0x00000800  /* Receiver auto detect transmit speed. */
#define ARINC_717_PROG_INT_WRAP_AROUND_MASK         0x00000400  /* Transmitter will transmit data interanally to receiver. */
#define ARINC_717_PROG_RESET_MASK                   0x00000200  /* Resets all registers and protocol engines. */

#define ARINC_717_PROG_SPEED_SHIFT                  0
#define ARINC_717_PROG_SPEED_32_WPS                 0x0     /* 384   bps */
#define ARINC_717_PROG_SPEED_64_WPS                 0x1     /* 768   bps */
#define ARINC_717_PROG_SPEED_128_WPS                0x2     /* 1536  bps */
#define ARINC_717_PROG_SPEED_256_WPS                0x3     /* 3072  bps */
#define ARINC_717_PROG_SPEED_512_WPS                0x4     /* 6144  bps */
#define ARINC_717_PROG_SPEED_1024_WPS               0x5     /* 12288 bps */
#define ARINC_717_PROG_SPEED_2048_WPS               0x6     /* 24576 bps */
#define ARINC_717_PROG_SPEED_4096_WPS               0x7     /* 49152 bps */
#define ARINC_717_PROG_SPEED_8192_WPS               0x8     /* 98304 bps */
#define ARINC_717_PROG_SPEED_INVALID_WPS            0xFF

#define ARINC_717_SYNC_WORD_MASK                    0x00000FFF
#define ARINC_717_SYNC_WORD_ONE                     0x00000247 /* Octal 1107 */
#define ARINC_717_SYNC_WORD_TWO                     0x000005B8 /* Octal 2670 */
#define ARINC_717_SYNC_WORD_THREE                   0x00000A47 /* Octal 5107 */
#define ARINC_717_SYNC_WORD_FOUR                    0x00000DB8 /* Octal 6670 */

/* Bi Polar Return to Zero (1) or Harvard Bi Phase (0) mode select, bit [6] of configuration register. */
#define ARINC_717_PROG_BPRZ_MASK                    0x0
#define ARINC_717_PROG_HBP_MASK                     0x1

/*============================================================================*/
/*                               S T R U C T S                                */
/*============================================================================*/

/*-----------------------------------------------------------------------
Struct:  ARINC_429_PROGRAMBLE_CONFIG

Description:
   This structure describes ARINC 429 Programmable Channel Configuration.
------------------------------------------------------------------------*/
typedef struct ACEX_CONFIG_ID
{
   U16BIT   u16Type;
   U16BIT   u16Channel;
} ACEX_CONFIG_ID;

typedef struct _ARINC_429_PROGRMMABLE_CONFIG
{
    ACEX_CONFIG_ID    sConfigID;
    U32BIT          u32ConfigOption;
    U8BIT           u8Channel;
    U8BIT           bEnable;
    U8BIT           bType;
    U8BIT           u8Speed;
    U8BIT           u8Parity;
    U8BIT           u8BitFormat;
    U8BIT           u8Mode;
    U8BIT           bReset;
} ARINC_429_PROGRMMABLE_CONFIG, *PARINC_429_PROGRMMABLE_CONFIG;

typedef enum _ARINC_717_STATE
{
    ARINC_717_RESET,
    ARINC_717_READY,
    ARINC_717_RUN,
    ARINC_717_PAUSE
} ARINC_717_STATE;

typedef struct _ARINC_717_PROGRMMABLE_CONFIG
{
    ACEX_CONFIG_ID  sConfigID;
    U32BIT          u32ConfigOption;
    U8BIT           u8Channel;
    U8BIT           u8SlopeControl;
    U8BIT           u8WrapAroundMode;
    U8BIT           bStopTx;
    U8BIT           bRxAutoDetect;
    U8BIT           bReset;
    U8BIT           u8BufferMode;
    U8BIT           u8ProtocolType;
    U8BIT           u8Type;
    U8BIT           u8Speed;
    ARINC_717_STATE eState;         /* Used only during RUN state setting */
    U16BIT          u16FrameCount;  /* Frame count for transmitter mode only. */
    U8BIT           bGetInterrupt;
    U8BIT           bEnableInterrupt;
    U32BIT          u32Interrupts;
} ARINC_717_PROGRMMABLE_CONFIG, *PARINC_717_PROGRMMABLE_CONFIG;

typedef struct _CAN_FIRMWARE_VERSION
{
    U8BIT             u8Reserved;
    U8BIT             u8VerMajor;
    U8BIT             u8VerMinora;
    U8BIT             u8VerMinorb;
} CAN_FIRMWARE_VERSION, *PCAN_FIRMWARE_VERSION;

/* CAN Bus configuration options place holders, common between RTL and Driver */
#define CAN_BUS_SPEED_OPT                       0x00000001
#define CAN_BUS_RESET_OPT                       0x00000002
#define CAN_BUS_RX_FILTER_OPT                   0x00000004
#define CAN_BUS_RUN_STATE_OPT                   0x00000008
#define CAN_BUS_FIRWARE_VERSION_OPT             0x00000010
#define CAN_BUS_RX_INTERRUPT_OPT                0x00000020
#define CAN_BUS_TIMER_OPT                       0x00000040
#define CAN_BUS_MESSAGE_COUNT_INT_OPT           0x00000080
#define CAN_BUS_MONITOR_ONLY_OPT                0x00000100
#define CAN_BUS_INTERNAL_LOOP_BACK_OPT          0x00000200
#define CAN_BUS_DEBUG_UART_OPT                  0x08000000
#define CAN_BUS_TX_ONE_MSG_CH1                  0x04000000
#define CAN_BUS_TX_ONE_MSG_CH2                  0x02000000
#define CAN_BUS_CONFIG_PENDING                  0x80000000  /* MSB bit reserved for config word pending */

#define CAN_BUS_ID_MASK                         0x1FFFFFFF
#define CAN_BUS_EXT_ID_MASK                     0x0003FFFF
#define CAN_BUS_STD_ID_MASK                     0x1FFC0000
#define CAN_BUS_ID_MASK                         0x1FFFFFFF
#define CAN_BUS_ID_EXTENDED_ENABLE              0x80000000

#define CAN_BUS_RX_FILTER_ENABLE                0x40000000
#define CAN_BUS_RX_FILTER_RESERVED_B29          0x20000000

#define CAN_BUS_SPEED_MASK                      0xFF  /* Speed settings */
#define CAN_BUS_SPEED_1_MBS                         0x01
#define CAN_BUS_SPEED_800_KBS                       0x02
#define CAN_BUS_SPEED_500_KBS                       0x03
#define CAN_BUS_SPEED_250_KBS                       0x04
#define CAN_BUS_SPEED_125_KBS                       0x05
#define CAN_BUS_SPEED_100_KBS                       0x06
#define CAN_BUS_SPEED_50_KBS                        0x07
#define CAN_BUS_SPEED_40_KBS                        0x08
#define CAN_BUS_SPEED_20_KBS                        0x09
#define CAN_BUS_SPEED_10_KBS                        0x0A
#define CAN_BUS_SPEED_5_KBS                         0x0B

#define CAN_MSG_PENDING_MASK    0xFFFF0000
#define CAN_MESSAGE_PENDING     0x4DDC0000
#define CAN_ERROR_TX_QUEUED_MASK    0x00004000
#define CAN_ERROR_TX_OVERFLOW_MASK  0x00002000
#define CAN_ERROR_INT_MASK      0x00001000
#define CAN_EXT_ID_ENABLE_MASK  0x00000400
#define CAN_SUB_REMOTE_REQ_MASK 0x00000200
#define CAN_REMOTE_REQ_MASK     0x00000100
#define CAN_CH_NUM_MASK         0x000000FF
#define CAN_MSG_LEN_MASK        0x0000000F
#define CAN_MSG_TIME_MASK       0x0000FFFF

#define CAN_MSG_ERROR_RECESSIVE_MASK    0x00008000
#define CAN_MSG_ERROR_DOMINANT_MASK     0x00004000
#define CAN_MSG_ERROR_ACK_MASK          0x00002000
#define CAN_MSG_ERROR_CRC_MASK          0x00001000
#define CAN_MSG_ERROR_FORM_MASK         0x00000800
#define CAN_MSG_ERROR_STUFFING_MASK     0x00000400
#define CAN_MSG_ERROR_TX_COUNTER_MASK   0x00000200
#define CAN_MSG_ERROR_RX_COUNTER_MASK   0x00000100
#define CAN_MSG_ERROR_BOFFINT_MASK      0x00000004
#define CAN_MSG_ERROR_GENERAL_MASK      0x00000002
#define CAN_MSG_TX_ERROR_CTR_MASK       0x000000FF
#define CAN_MSG_RX_ERROR_CTR_MASK       0x0000FF00


typedef enum _CAN_BUS_RUN_STATE
{
    CAN_BUS_RESET,
    CAN_BUS_READY,
    CAN_BUS_RUN,
    CAN_BUS_PAUSE
} CAN_BUS_RUN_STATE;

#define CAN_BUS_MAX_MSG_COUNT_INT               500
#define CAN_BUS_MAX_TIMER_MS_INT                1000
#define CAN_BUS_RX_FILTER_MAX                   32
typedef struct _CAN_BUS_CONFIG
{
    ACEX_CONFIG_ID    sConfigID;
    U32BIT            u32ConfigOption;
    U8BIT             u8Channel;
    U8BIT             u8Speed;
    U8BIT             bInterrupt;
    U16BIT            u16TimerValue;
    U16BIT            u16MessageCountInt;
    U8BIT             u8EnableMonitor;
    U8BIT             u8EnableLoopback;
    CAN_BUS_RUN_STATE eState;         /* Used only during RUN state setting */
    U32BIT            u32FilterValues[CAN_BUS_RX_FILTER_MAX];
} CAN_BUS_CONFIG, *PCAN_BUS_CONFIG;

#define CAN_BUS_DWORDS_PER_MSG                  6 /* number of DWords in a CAN message. */


/* Software Version Information struct */
typedef struct _SWVERSIONINFO
{
   U32BIT dwRtlVersion;
   U32BIT dwCoreVersion;
   U8BIT  szRtlVersion[32];
   U32BIT dwReserved1;
   U32BIT dwReserved2;
   U32BIT dwReserved3;
   U32BIT dwReserved4;
} SWVERSIONINFO, *PSWVERSIONINFO;


#ifndef __DEV_INFO__
#define __DEV_INFO__

/* Generic device ID and location info */
typedef struct _HWVERSIONINFO
{
    U32BIT  dwFwVersion;
    U32BIT  dwHdlVersion;
    U32BIT  dwDriverVersion;
    U32BIT  dwSerialNumber;
    FAMILY  dwFamilyNumber;
    U32BIT  dwModelNumber;
    char    szModelName[32];
    char    szDriverVersion[16];
    U32BIT  dwHdlNumber;
    U32BIT  dwCapabilities;
    U32BIT  dwReserved3;
    U32BIT  dwReserved4;
    char    szReserved[32];

} HWVERSIONINFO, *PHWVERSIONINFO;

/* Channel count struct */
typedef struct _CHANCOUNT
{
   U8BIT bTx;
   U8BIT bRx;
   U8BIT bGroup;
   U8BIT bDiscrete;
   U8BIT bAvionic;
   U8BIT bBoardModel;
   U8BIT b1553;
   U8BIT a429Prog;
   U8BIT bUart;
   U8BIT RS232;
   U8BIT RS485;
   U8BIT CanBus;
   U8BIT a717Rx;
   U8BIT a717Tx;
   U8BIT a717Prog;
} CHANCOUNT_t, *CHANCOUNT_p;

typedef struct _ENHANCED_CAPABILITY_INFO
{
     U8BIT modelNumber;
     U8BIT channelCount1553;
     U8BIT channelCount429Rx;
     U8BIT channelCount429Tx;
     U8BIT channelCount429Prog;
     U8BIT channelCountAIO;
     U8BIT channelCountDIO;
     U8BIT channelCountRS232;
     U8BIT channelCountRS485;
     U8BIT channelCountUart;
     U8BIT channelCountCanBus;
     U8BIT channelCount717Rx;
     U8BIT channelCount717Tx;
     U8BIT channelCount717Prog;
     U8BIT u8Reserved1;
     U8BIT u8Reserved2;
     U8BIT u8Reserved3;
     U8BIT u8Reserved4;
     U8BIT u8Reserved5;
     U8BIT u8Reserved6;
     U8BIT u8Reserved7;
     U8BIT u8Reserved8;
} ENHANCED_CAPABILITY_INFO, *PENHANCED_CAPABILITY_INFO;

typedef struct _OSCONTEXT
{
   HANDLE hDriverApp;
   HANDLE hDriverIrq;
   HANDLE hBlockEvent;
   HANDLE hExitEvent;
   HANDLE hThread[2];
   U32    dwThreadID[2];
} OSCONTEXT;

typedef struct _IOINFO
{
    U16BIT     bInitialized;        /* Initialization status.   */
	OSCONTEXT *pContext;                     /* OS specific information.          */
    U32BIT     dwCardType;          /* The card being accessed */
    HANDLE     hDriverLib;          /* Driver handle for library */
    CHANCOUNT_t  strChanCount;        /* structure that holds number of IO's. */

}IOINFO_t, *IOINFO_p;

/* Generic device ID and location info */
typedef struct _DEV_INFO
{
    unsigned long dwVendorID;
    unsigned long dwDeviceID;
    unsigned long dwBusHub;
    unsigned long dwSlotPort;
    unsigned long dwChanMemBA;
    unsigned long dwChanMemLen;
    unsigned long u32Capability;

	HWVERSIONINFO sHwVersionInfo;

} DEV_INFO, *PDEV_INFO;

/* Rx host buffer message structure */
typedef struct _RX_HBUF_MESSAGE
{
	U32BIT u32Data;
	U32BIT u32StampHigh;
	U32BIT u32StampLow;
} RX_HBUF_MESSAGE, *PRX_HBUF_MESSAGE;

typedef struct _ARINC_HOST_BUF_METRICS
{
    U32  u32429HbufPercentFull;
    U32  u32429HbufPercentHigh;
    U32  u32429HbufOverflowCount;
} ARINC_HOST_BUF_METRICS, *PARINC_HOST_BUF_METRICS;

#endif


#endif /* __DDC_COMMON_H__ */

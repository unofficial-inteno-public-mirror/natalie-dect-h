#ifndef DSPPCMBUFCTRL_H
#define DSPPCMBUFCTRL_H
/****************************************************************************
*  Program/file: dsppcmbufctrl.h
*   
*  Copyright (C) by RTX TELECOM A/S, Denmark.
*  These computer program listings and specifications, are the property of 
*  RTX TELECOM A/S, Denmark and shall not be reproduced or copied or used in 
*  whole or in part without written permission from RTX TELECOM A/S, Denmark.
*
*  Programmer: MSJ
*
*  MODULE: 
*  CONTROLLING DOCUMENT:
*  SYSTEM DEPENDENCIES:
*   
*  DESCRIPTION: PCMBUFCTRL and SYNCFBUF definitions.
*   
****************************************************************************/

/****************************************************************************
*                                  PVCS info                                  
*****************************************************************************

$Author:   MSJ  $
$Date:   06 Jan 2011 12:42:44  $
$Revision:   1.1  $
$Modtime:   06 Jan 2011 12:07:42  $
$Archive:   J:/sw/Projects/NatalieV3/FpCvm/Config/Bcm6362/vcs/dsppcmbufctrl.h_v  $

*/

/****************************************************************************
* Macro Definitions
****************************************************************************/

// pointer-array addresses 
#define GDSP_PCMBUFCTRL_SYNCFBUF_RX0_PTR_ADDR  (SHARED_RAM_START|0x0820)
#define GDSP_PCMBUFCTRL_SYNCFBUF_RX1_PTR_ADDR  (SHARED_RAM_START|0x0824) 
#define GDSP_PCMBUFCTRL_SYNCFBUF_RX2_PTR_ADDR  (SHARED_RAM_START|0x0828) 
#define GDSP_PCMBUFCTRL_SYNCFBUF_RX3_PTR_ADDR  (SHARED_RAM_START|0x082c) 
#define GDSP_PCMBUFCTRL_SYNCFBUF_TX0_PTR_ADDR  (SHARED_RAM_START|0x0830) 
#define GDSP_PCMBUFCTRL_SYNCFBUF_TX1_PTR_ADDR  (SHARED_RAM_START|0x0834) 
#define GDSP_PCMBUFCTRL_SYNCFBUF_TX2_PTR_ADDR  (SHARED_RAM_START|0x0838) 
#define GDSP_PCMBUFCTRL_SYNCFBUF_TX3_PTR_ADDR  (SHARED_RAM_START|0x083c) 

// PCMBUFCTRL control-data
#define GDSP_PCMBUFCTRL_STARTCTRL_ADDR         (SHARED_RAM_START|0x0818)
#define GDSP_PCMBUFCTRL_TESTCTRL_ADDR          (SHARED_RAM_START|0x081c)

// PCMBUFCTRL channel-data addresses
#define GDSP_PCMBUFCTRL_CH0_TX_DATA_ADDR       (SHARED_RAM_START|0x0840)
#define GDSP_PCMBUFCTRL_CH0_RX_DATA_ADDR       (SHARED_RAM_START|0x0a20)
#define GDSP_PCMBUFCTRL_CH1_TX_DATA_ADDR       (SHARED_RAM_START|0x0c00)
#define GDSP_PCMBUFCTRL_CH1_RX_DATA_ADDR       (SHARED_RAM_START|0x0de0)
#define GDSP_PCMBUFCTRL_CH2_TX_DATA_ADDR       (SHARED_RAM_START|0x0fc0)
#define GDSP_PCMBUFCTRL_CH2_RX_DATA_ADDR       (SHARED_RAM_START|0x11a0)
#define GDSP_PCMBUFCTRL_CH3_TX_DATA_ADDR       (SHARED_RAM_START|0x1380)
#define GDSP_PCMBUFCTRL_CH3_RX_DATA_ADDR       (SHARED_RAM_START|0x1560)

// macro's for retrieving the  gDspSyncFBufData_t pointers
// not tested->
#define GET_PCMBUFCTRL_SYNCFBUF_RX(ch)  ((gDspSyncFBufData_t *)*((unsigned long *)(GDSP_PCMBUFCTRL_SYNCFBUF_RX0_PTR_ADDR+(ch*4))))
#define GET_PCMBUFCTRL_SYNCFBUF_TX(ch)  ((gDspSyncFBufData_t *)*((unsigned long *)(GDSP_PCMBUFCTRL_SYNCFBUF_TX0_PTR_ADDR+(ch*4))))
//<--

/****************************************************************************
* Type Definitions
****************************************************************************/

typedef struct  
{
   unsigned short   in_ptr;         // loc 1
   unsigned short   start_ptr;      // loc 2
   unsigned short   buffer_ptr;     // loc 3

   unsigned short   mode;           // loc 4
   unsigned short   buffer_size;    // loc 5
   unsigned short   page_size;      // loc 6 
   unsigned short   int_vector;     // loc 7

   unsigned short   trf_trig_ofs;     // loc 8  
   unsigned short   trf_ctrl_out_ptr; // loc 9
   unsigned short   trf_ctrl_on;      // loc 10
   unsigned short   trf_ctrl_off;     // loc 11
   unsigned short   trf_ctrl_state;   // loc 12 

   unsigned short   idx;            // loc 13
   unsigned short   page_ofs;       // loc 14

   unsigned short   start_sync_out;     // loc 15
   unsigned short   x16;            // loc 16
   unsigned short   x17;            // loc 17
   unsigned short   x18;            // loc 18
   unsigned short   x19;            // loc 19
   unsigned short   x20;            // loc 20
   unsigned short   x21;            // loc 21
   unsigned short   trf_cnt;        // loc 22
 
   unsigned short   output;         // loc 23  

} gDspSyncFBufData_t;


#endif // DSPPCMBUFCTRL_H
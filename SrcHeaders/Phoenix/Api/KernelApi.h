/****************************************************************************
*  Program/file: KernelApi.h
*   
*  Copyright (C) by RTX TELECOM A/S, Denmark.
*  These computer program listings and specifications, are the property of 
*  RTX TELECOM A/S, Denmark and shall not be reproduced or copied or used in 
*  whole or in part without written permission from RTX TELECOM A/S, Denmark.
*
*  Programmer: MLA
*
*  MODULE:
*  CONTROLLING DOCUMENT:
*  SYSTEM DEPENDENCIES:
*   
*   
*  DESCRIPTION: Function for in-kernel access to send and receive API
*  mails. This should not be used simultaniously with the user space device
*  node (typically /dev/dect). These functions are exported by the dect
*  kernel module.
*
*  
*   
*   
*   
*   
****************************************************************************/

/****************************************************************************
*                                  PVCS info                                  
*****************************************************************************

$Author:   MLA  $
$Date:   28 Oct 2009 14:59:46  $
$Revision:   1.1  $
$Modtime:   28 Oct 2009 14:59:26  $
$Archive:   J:/sw/Include/uClinux/DevDect/vcs/KernelApi.h_v  $

*/


/****************************************************************************
*                               Include files                                 
****************************************************************************/

/****************************************************************************
*                              Macro definitions                              
****************************************************************************/

// kapi_read() flags
#define KRF_BLOCK 0x1 // Blocking operation

/****************************************************************************
*                     Enumerations/Type definitions/Structs                   
****************************************************************************/


/****************************************************************************
*                            Global variables/const                           
****************************************************************************/


/****************************************************************************
*                            Local variables/const                            
****************************************************************************/


/****************************************************************************
*                          Local Function prototypes                          
****************************************************************************/


/****************************************************************************
*                                Implementation                               
****************************************************************************/

/****************************************************************************
*  FUNCTION: kapi_write
*
*  INPUTS  : buf: Buffer containing one complete API mails
*            count: Size of API mail
*  OUTPUTS : none
*  RETURNS : Negative in case of error, otherwise count
*
* DESCRIPTION: Send an API mail to the driver. buf must contain a complete
* API mail of count bytes. See API for description of maximum allowed mail
* lengths. Non-blocking.
****************************************************************************/
int kapi_write(const void* buf, size_t count);

/****************************************************************************
*  FUNCTION: kapi_read
*
*  INPUTS  : buf: Buffer of size at least size API_FP_LINUX_MAX_MAIL_SIZE
*            flags: See KRF_* above
*  OUTPUTS : none
*  RETURNS : Negative in case of error. 0 if no mail was copied to
*            buf. Otherwise length of mailcopied to buf.
*
* DESCRIPTION: Receive one complete API mail from the driver. buf must have
* room for a complete API mail of up to API_FP_LINUX_MAX_MAIL_SIZE
* bytes. See API for description of maximum allowed mail lengths. Default
* operations is non-blocking.
****************************************************************************/
int kapi_read(void *buf, int flags);

/****************************************************************************
*  FUNCTION: kapi_read
*
*  INPUTS  : wq: Pointer to wait queue to be signalled when there are API
*            mails ready to be read from the driver. NULL to deregister.
*  OUTPUTS : none
*  RETURNS : Negative in case of error.
*
* DESCRIPTION: Register a wait queue to be woken using
* wake_up_interruptible in case of data ready to be read using
* kapi_read(). Only one wait queue can be registered. To change the
* registered wait queue, first deregister the old.
****************************************************************************/
int kapi_register_wq(wait_queue_head_t *wq);


#if 0 // Example code
{
   wait_queue_head_t wq;
   init_waitqueue_head(&wq);
   kapi_register_wq(&wq);
   while (1)
   {
      DEFINE_WAIT(wait);
      prepare_to_wait(&wq, &wait, TASK_INTERRUPTIBLE);
      if ((count = kapi_read(buf,0)) <= 0 /*&& process probably waits for other stuff also */)
         schedule();
      finish_wait(&wq, &wait);
   }
   kapi_register_wq(NULL);
}
#endif

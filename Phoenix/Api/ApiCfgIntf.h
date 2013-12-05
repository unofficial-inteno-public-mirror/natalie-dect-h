/****************************************************************************
*  Program/file: ApiCfg.h
*
*  Copyright (C) by RTX TELECOM A/S, Denmark.
*  These computer program listings and specifications, are the property of
*  RTX TELECOM A/S, Denmark and shall not be reproduced or copied or used in
*  whole or in part without written permission from RTX TELECOM A/S, Denmark.
*
*  Programmer: SS
*
*  MODULE:
*  CONTROLLING DOCUMENT:
*  SYSTEM DEPENDENCIES:
*
*
*  DESCRIPTION:
*
*
*
*
*
****************************************************************************/

#ifndef APIINTFCFG_H
#define APIINTFCFG_H

/****************************************************************************
*                              Macro definitions
****************************************************************************/

#define NUMBER_OF_CODEC_LIST_ENTRIES 2

#ifndef COLA_SYSTEM
  #define COLA_SYSTEM 0
#endif

#if (COLA_SYSTEM == 1)
  #undef API_FORWARD_MAIL_TO_RTX_EAI
  void ClSysTask(const RosMailType* Mail);
  #define API_PROJECT_FORWARD_MAIL(_m_) ClSysTask(_m_)
#endif

#define APIIMAGECONTROL_TASK API_TASK
#define APIHAL_TASK API_TASK

#define API_HAL_MAX_LEDS 3

#endif


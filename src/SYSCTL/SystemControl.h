/**
 * @file SystemControl.h
 * @author ryhoh
 * @brief システム制御としてのデータ整理ロジック
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef __SYSTEMCONTROL_H__
#define __SYSTEMCONTROL_H__

/* include *******************************************************************************************/
#include <Arduino.h>

#include "../common.h"
#include "../configure.h"
#include "../DIP/DIP.h"
#include "../Cover/Cover.h"
/* define ********************************************************************************************/
#define Y_SYSCTL_CONTROL_STATE_BOOT         (0)         /* 初期状態 */
#define Y_SYSCTL_CONTROL_STATE_SLEEP        (1)         /* スリープ状態 */
#define Y_SYSCTL_CONTROL_STATE_ACTIVE       (2)         /* 稼働状態 */
/* function ******************************************************************************************/
void SYSCTL_Main(void);
uint8_t SYSCTL_GetControlState(void);
uint32_t SYSCTL_GetSelectedScoreIdx(void);
/* ***************************************************************************************************/

#endif /* __SYSTEMCONTROL_H__ */

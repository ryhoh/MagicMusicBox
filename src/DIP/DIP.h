/**
 * @file DIP.h
 * @author ryhoh
 * @brief DIPスイッチ入力の処理を行う
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef __DIP_H__
#define __DIP_H__

/* include *******************************************************************************************/
#include <Arduino.h>

#include "../common.h"
#include "../configure.h"
/* function ******************************************************************************************/
void DIP_Main(void);
uint32_t DIP_GetSwitchState(void);
/* ***************************************************************************************************/

#endif /* __DIP_H__ */

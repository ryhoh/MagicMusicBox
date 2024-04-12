/**
 * @file Cover.h
 * @author ryhoh
 * @brief フタの開閉検出ロジック
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef __COVER_H__
#define __COVER_H__

/* include *******************************************************************************************/
#include <Arduino.h>

#include "../common.h"
#include "../configure.h"
/* function ******************************************************************************************/
void COVER_Main(void);
uint8_t COVER_GetOpenedFlag(void);
/* ***************************************************************************************************/

#endif /* __COVER_H__ */

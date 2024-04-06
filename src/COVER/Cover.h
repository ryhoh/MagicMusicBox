/**
 * @file CoverControl.h
 * @author ryhoh
 * @brief フタの開閉検出ロジック
 * 
 * @copyright Copyright (c) 2024
 * 
 */

/* include *******************************************************************************************/
#include <Arduino.h>

#include "../common.h"
#include "../configure.h"
/* function ******************************************************************************************/
void COVER_Main(void);
uint8_t COVER_GetOpenedFlag(void);
/* ***************************************************************************************************/

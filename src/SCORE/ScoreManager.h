/**
 * @file ScoreManager.h
 * @author ryhoh
 * @brief 楽譜情報の管理を行う
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef __SCORE_MANAGER_H__
#define __SCORE_MANAGER_H__

/* include *******************************************************************************************/
#include <Arduino.h>

#include "../common.h"
#include "../configure.h"
#include "Note.h"
#include "../SYSCTL/SystemControl.h"

#include "scores/Score_TwinkleStar.h"
/* define ********************************************************************************************/
#define Y_SCORE_SCORE_NUM       (4)     /* 楽譜数 */
/* function ******************************************************************************************/
void SCORE_Main(void);
uint8_t SCORE_GetSelectScoreSuccessFlag(void);
const score_score_t *SCORE_GetSelectedScore(void);
const char *SCORE_GetSelectedArtistName(void);
const char *SCORE_GetSelectedScoreName(void);
uint32_t SCORE_GetScoreFullTime(void);
/********************************************************************************************************/

#endif /* __SCORE_MANAGER_H__ */

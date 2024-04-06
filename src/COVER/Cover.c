/**
 * @file Cover.c
 * @author ryhoh
 * @brief フタの開閉検出ロジック
 * 
 * @copyright Copyright (c) 2024
 * 
 */

/* include *******************************************************************************************/
#include "Cover.h"
/* variable ******************************************************************************************/
static u_int8_t zuc_COVER_OpenedFlag = Y_OFF;   /* [-,-] COVER_フタ開放フラグ */
/* prototype *****************************************************************************************/
static void COVER_Init(void);
static void COVER_JudgeOpened(void);
/* function ******************************************************************************************/
/**
 * @brief フタの開閉検出処理メイン
 * 
 */
void COVER_Main(void) {
    static uint8_t zuc_InitDoneFlag = Y_ON;     /* 初期化完了フラグ */

    if (zuc_InitDoneFlag == Y_OFF) {            /* 初期化未完了時のみ実行 */
        COVER_Init();                           /* 初期化処理 */
        zuc_InitDoneFlag = Y_ON;                /* 初期化完了フラグをON */
    }

    /* フタの開閉検出処理 */
    COVER_JudgeOpened();
}

/**
 * @brief フタの開閉検出初期化処理
 * 
 */
static void COVER_Init(void) {
    /* センサにつながっているピンをセットアップする */
    pinMode(PIN_COVER_SW_0, INPUT);             /* フタ開閉センサ0 */

#if SW_COVER_SW_REDUNDANT == 1                  /* 冗長構成の場合 */
    pinMode(PIN_COVER_SW_1, INPUT);             /* フタ開閉センサ1 */
#endif
}

/**
 * @brief フタの開閉検出処理
 * 
 */
static void COVER_JudgeOpened(void) {
    uint8_t uc_cover_sw_0;
#if SW_COVER_SW_REDUNDANT == 1                  /* 冗長構成の場合 */
    uint8_t uc_cover_sw_1;
#endif

    /* フタ開閉センサ0の状態を取得 */
    uc_cover_sw_0 = digitalRead(PIN_COVER_SW_0);

#if SW_COVER_SW_REDUNDANT == 1                  /* 冗長構成の場合 */
    /* フタ開閉センサ1の状態を取得 */
    uc_cover_sw_1 = digitalRead(PIN_COVER_SW_1);

    /* 冗長構成の場合、どちらかが閉まっている（センサが通電しLOWとなる）とき、閉まっていると判定する */
    if ((uc_cover_sw_0 == LOW) || (uc_cover_sw_1 == LOW)) {
        uc_cover_sw_0 = Y_OFF;                  /* 閉まっている */
    } else {
        uc_cover_sw_0 = Y_ON;                   /* 開いている */
    }
#endif

    /* 出力 */
    zuc_COVER_OpenedFlag = uc_cover_sw_0;
}

/* Interface *****************************************************************************************/
/**
 * @brief COVER_フタ開放フラグ取得
 * 
 * @return COVER_フタ開放フラグ
 */
uint8_t COVER_GetOpenedFlag(void) {
    return zuc_COVER_OpenedFlag;
}

/* ***************************************************************************************************/

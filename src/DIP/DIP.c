/**
 * @file DIP.c
 * @author ryhoh
 * @brief DIPスイッチ入力の処理を行う
 * 
 * @copyright Copyright (c) 2024
 * 
 */

/* include *******************************************************************************************/
#include "DIP.h"
/* variable ******************************************************************************************/
static uint8_t zuc_DIP_SwitchState = 0;   /* [-,-] DIP_DIPスイッチ状態 */
/* prototype *****************************************************************************************/
static void DIP_Init(void);
static void DIP_Input_2Bits(void);
/* function ******************************************************************************************/
/**
 * @brief DIPスイッチ入力処理メイン
 * 
 */
void DIP_Main(void) {
    static uint8_t zuc_InitDoneFlag = Y_OFF;    /* 初期化完了フラグ */

    if (zuc_InitDoneFlag == Y_OFF) {            /* 初期化未完了時のみ実行 */
        DIP_Init();                             /* 初期化処理 */
        zuc_InitDoneFlag = Y_ON;                /* 初期化完了フラグをON */
    }

    /* DIPスイッチ入力処理 */
#if SW_DIP_SW_NUM == 2
    DIP_Input_2Bits();
#else
    #error "SW_DIP_SW_NUM != 2 は未実装"
#endif
}

/**
 * @brief DIPスイッチ入力初期化処理
 * 
 */
static void DIP_Init(void) {
    /* センサにつながっているピンをセットアップする */
#if SW_DIP_SW_NUM == 2
    pinMode(PIN_DIP_SW_BIT0, INPUT);             /* DIPスイッチビット0 */
    pinMode(PIN_DIP_SW_BIT1, INPUT);             /* DIPスイッチビット1 */
#else
    #error "SW_DIP_SW_NUM != 2 は未実装"
#endif
}

/**
 * @brief DIPスイッチ入力処理 (2Bit版)
 * 
 */
static void DIP_Input_2Bits(void) {
    uint8_t uc_DIP_Switch_Bit0;
    uint8_t uc_DIP_Switch_Bit1;

    /* DIPスイッチビット0の状態を取得 */
    uc_DIP_Switch_Bit0 = digitalRead(PIN_DIP_SW_BIT0);

    /* DIPスイッチビット1の状態を取得 */
    uc_DIP_Switch_Bit1 = digitalRead(PIN_DIP_SW_BIT1);

    /* DIPスイッチ状態を更新 */
    zuc_DIP_SwitchState = (uc_DIP_Switch_Bit1 << 1) | uc_DIP_Switch_Bit0;
}

/* Interface *****************************************************************************************/
/**
 * @brief DIP_DIPスイッチ状態取得
 * 
 */
uint8_t DIP_GetSwitchState(void) {
    return zuc_DIP_SwitchState;
}

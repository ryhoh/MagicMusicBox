/**
 * @file SystemControl.c
 * @author ryhoh
 * @brief システム制御としてのデータ整理ロジック
 * 
 * @copyright Copyright (c) 2024
 * 
 */

/* include *******************************************************************************************/
#include "SystemControl.h"
/* variable ******************************************************************************************/
static uint8_t zuc_SYSCTL_Control_State = Y_SYSCTL_CONTROL_STATE_BOOT;   /* [-,-] SYSCTL_制御状態 */
static uint32_t zul_SYSCTL_SelectedScoreIdx = 0;                         /* [-,-] SYSCTL_選択曲インデックス */
/* prototype *****************************************************************************************/
static void SYSCTL_Input(uint8_t *const puc_cover_opened_flag);
static void SYSCTL_JudgeControlState(const uint8_t uc_cover_opened_flag);
/* function ******************************************************************************************/
/**
 * @brief SYSCTLメイン処理
 * 
 */
void SYSCTL_Main(void) {
    uint8_t uc_COVER_OpenedFlag;                /* [-,-] フタ開放フラグ */

    /* SYSCTL入力処理 */
    SYSCTL_Input(&uc_COVER_OpenedFlag);

    /* SYSCTL_制御状態判定処理 */
    SYSCTL_JudgeControlState(uc_COVER_OpenedFlag);
}

/**
 * @brief SYSCTL入力処理
 * 
 */
static void SYSCTL_Input(
    uint8_t *const puc_cover_opened_flag        /* [-,-] フタ開放フラグ */
) {
    *puc_cover_opened_flag = COVER_GetOpenedFlag();                 /* フタ開放フラグ */
    zul_SYSCTL_SelectedScoreIdx = DIP_GetSwitchState();             /* DIPスイッチ状態を選択曲インデックスにラッチ */
}

/**
 * @brief SYSCTL_制御状態判定処理
 * 
 */
static void SYSCTL_JudgeControlState(
    const uint8_t uc_cover_opened_flag     /* [-,-] フタ開放フラグ */
) {
    uint8_t uc_control_state = zuc_SYSCTL_Control_State;        /* [-,-] SYSCTL_制御状態 */

    switch (uc_control_state) {
    case Y_SYSCTL_CONTROL_STATE_BOOT:                           /* 初期状態 */
        if (uc_cover_opened_flag == Y_OFF) {                    /* フタが閉じている場合 */
            uc_control_state = Y_SYSCTL_CONTROL_STATE_SLEEP;    /* スリープ状態へ遷移 */
        }
        break;
    case Y_SYSCTL_CONTROL_STATE_SLEEP:                          /* スリープ状態 */
        if (uc_cover_opened_flag == Y_ON) {                     /* フタが開いている場合 */
            uc_control_state = Y_SYSCTL_CONTROL_STATE_ACTIVE;   /* 稼動状態へ遷移 */
        }
        break;
    case Y_SYSCTL_CONTROL_STATE_ACTIVE:                         /* 稼動状態 */
        if (uc_cover_opened_flag == Y_OFF) {                    /* フタが閉じている場合 */
            uc_control_state = Y_SYSCTL_CONTROL_STATE_SLEEP;    /* スリープ状態へ遷移 */
        }
        break;
    default:
        break;
    }

    zuc_SYSCTL_Control_State = uc_control_state;                /* SYSCTL_制御状態を更新 */
}

/* Interface *****************************************************************************************/
/**
 * @brief SYSCTL_制御状態取得
 * 
 */
uint8_t SYSCTL_GetControlState(void) {
    return zuc_SYSCTL_Control_State;
}

/**
 * @brief SYSCTL_選択曲インデックス取得
 * 
 */
uint32_t SYSCTL_GetSelectedScoreIdx(void) {
    return zul_SYSCTL_SelectedScoreIdx;
}

/**********************************************************************************************************/

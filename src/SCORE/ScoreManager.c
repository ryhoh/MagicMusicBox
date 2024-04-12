/**
 * @file ScoreManager.c
 * @author ryhoh
 * @brief 楽譜情報の管理を行う
 * 
 * @copyright Copyright (c) 2024
 * 
 */

/* include *******************************************************************************************/
#include "ScoreManager.h"
/* variable ******************************************************************************************/
const static score_score_t *Xst_SCORE_ScoreList[Y_SCORE_SCORE_NUM] = {  /* 楽譜リスト */
    &Xst_SCORE_Twinkle_Star,                /* きらきら星 */
    NULL,                                   /* 未使用 */
    NULL,                                   /* 未使用 */
    NULL,                                   /* 未使用 */
};

static uint8_t zuc_SCORE_SelectScoreSuccessFlag = Y_OFF;    /* [-,-] SCORE_曲選択成功フラグ */
static uint8_t zuc_SCORE_SelectedScoreIdx = 0;              /* [-,-] SCORE_選択曲インデックス */
static uint32_t zul_SCORE_FullTime = 0;                     /* [ms,-] SCORE_曲の長さ */

/* prototype *****************************************************************************************/
static void SCORE_SelectScore(void);

/* function ******************************************************************************************/
/**
 * @brief SCOREメイン処理
 * 
 */
void SCORE_Main(void) {
    uint8_t uc_control_state = SYSCTL_GetControlState();    /* [-,-] 制御状態 */
    static uint8_t zuc_control_state_old;                    /* [-,-] 制御状態(前回値) */

    /* スリープ以外の状態からスリープに移行したときのみ実行 */
    if ((zuc_control_state_old != Y_SYSCTL_CONTROL_STATE_SLEEP)
     && (uc_control_state == Y_SYSCTL_CONTROL_STATE_SLEEP)) {
        /* 楽譜選択処理 */
        SCORE_SelectScore();

        /* 曲の長さ算出処理 */
        SCORE_CalcScoreFullTime();
    }

    zuc_control_state_old = uc_control_state;    /* 制御状態(前回値)を更新 */
}

/**
 * @brief SCORE_楽譜選択処理
 * 
 */
static void SCORE_SelectScore(void) {
    uint8_t uc_DIP_SwitchState = DIP_GetSwitchState();              /* [-,-] DIPスイッチ状態 */
    static uint8_t zuc_DIP_SwitchState_Old = 0;                     /* [-,-] DIPスイッチ状態(前回値) */

    if (uc_DIP_SwitchState != zuc_DIP_SwitchState_Old) {            /* 選択曲が変更された場合 */
        if (uc_DIP_SwitchState < Y_SCORE_SCORE_NUM) {               /* 選択曲が有効範囲内の場合 */
            if (Xst_SCORE_ScoreList[uc_DIP_SwitchState] != NULL) {  /* 選択曲が有効な楽譜の場合 */
                zuc_SCORE_SelectedScoreIdx = uc_DIP_SwitchState;    /* 選択曲インデックスを更新 */
                zuc_SCORE_SelectScoreSuccessFlag = Y_ON;            /* 曲選択成功フラグをON */
            } else {
                zuc_SCORE_SelectScoreSuccessFlag = Y_OFF;           /* 曲選択成功フラグをOFF */
            }
        }
    }

    zuc_DIP_SwitchState_Old = uc_DIP_SwitchState;                  /* DIPスイッチ状態(前回値)を更新 */
}

/**
 * @brief 曲の長さ算出処理
 * 
 */
uint32_t SCORE_CalcScoreFullTime(void) {
    uint32_t ul_score_full_time = 0;                                                            /* [ms,-]曲の長さ(ms) */
    uint32_t ul_score_full_ticks = 0;                                                           /* [tick,-]曲の長さ(周期) */     
    const score_score_t *const pst_score = Xst_SCORE_ScoreList[zuc_SCORE_SelectedScoreIdx];     /* [-,-]選択された楽譜 */
    uint32_t ul_track_len;                                                                      /* [-,-]トラックの長さ */
    score_note_t *pst_note;                                                                     /* [-,-]音符 */
    uint32_t ul_a;

    if (zuc_SCORE_SelectScoreSuccessFlag == Y_OFF) {    /* 曲選択成功フラグがOFFの場合 */
        ul_score_full_time = 0;
    } else {
        /* 曲の長さを計算して返す */
        for (int32_t i = 0; i < pst_score->uc_track_num; i++) {
            /* 各トラックの最終音符に注目 */
            ul_track_len = pst_score->pst_tracks[i].ul_track_len;           /* 注目するトラックの長さ */
            pst_note = &pst_score->pst_tracks[i].pst_notes[ul_track_len-1]; /* 注目するトラックの最終音符 */
            ul_a = pst_note->ul_offset + pst_note->us_length;               /* 音符の開始時刻+音符の長さ */

            /* 各トラック間のセレクトハイ */
            ul_score_full_ticks = M_MAX(ul_score_full_time, ul_a);
        }
        
        /* 周期からミリ秒に変換 */
        ul_score_full_time = ul_score_full_ticks * Y_TASK_PERIOD;
    }

    zul_SCORE_FullTime = ul_score_full_time;    /* 曲の長さを更新 */
}


/**
 * @brief 曲選択成功フラグを取得
 * 
 * @return uint8_t 曲選択成功フラグ
 */
uint8_t SCORE_GetSelectScoreSuccessFlag(void) {
    return zuc_SCORE_SelectScoreSuccessFlag;
}

/**
 * @brief 選択された音源情報を取得
 * 
 * @return const score_score_t * 選択された音源情報
 */
const score_score_t *SCORE_GetSelectedScore(void) {
    if (zuc_SCORE_SelectScoreSuccessFlag == Y_OFF) {    /* 曲選択成功フラグがOFFの場合 */
        return NULL;
    }

    return &Xst_SCORE_ScoreList[zuc_SCORE_SelectedScoreIdx];
}

/**
 * @brief 選択されたアーティスト名を取得
 * 
 * @return char *選択されたアーティスト名
 */
const char *SCORE_GetSelectedArtistName(void) {
    if (zuc_SCORE_SelectScoreSuccessFlag == Y_OFF) {    /* 曲選択成功フラグがOFFの場合 */
        return "不正なアーティスト";
    }
    
    return Xst_SCORE_ScoreList[zuc_SCORE_SelectedScoreIdx]->pc_artist_name;
}

/**
 * @brief 選択された曲名を取得
 * 
 * @return char *選択された曲名
 */
const char *SCORE_GetSelectedScoreName(void) {
    if (zuc_SCORE_SelectScoreSuccessFlag == Y_OFF) {    /* 曲選択成功フラグがOFFの場合 */
        return "不正な曲名";
    }
    
    return Xst_SCORE_ScoreList[zuc_SCORE_SelectedScoreIdx]->pc_score_name;
}

/**
 * @brief 曲の長さを取得
 * 
 * @return uint32_t [ms,-]曲の長さ
 */
uint32_t SCORE_GetFullTime(void) {
    if (zuc_SCORE_SelectScoreSuccessFlag == Y_OFF) {    /* 曲選択成功フラグがOFFの場合 */
        return 0;
    }

    return zul_SCORE_FullTime;
}


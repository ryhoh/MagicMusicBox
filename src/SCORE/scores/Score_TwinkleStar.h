/**
 * @file Score_TwinkleStar.h
 * @author ryhoh
 * @brief Twinkle Twinkle Little Starの楽譜情報
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef __SCORE_TWINKLE_STAR_H__
#define __SCORE_TWINKLE_STAR_H__

/* include *******************************************************************************************/
#include "../Note.h"

/* define ********************************************************************************************/
#define Y_SCORE_TWINKLE_STAR_TRACK_0_SIZE       (42)    /* トラック長 */
#define Y_SCORE_TWINKLE_STAR_TRACK_1_SIZE       (24)    /* トラック長 */
#define Y_SCORE_TWINKLE_STAR_TRACK_2_SIZE       (24)    /* トラック長 */
#define Y_SCORE_TWINKLE_STAR_TRACK_MAX_SIZE     (42)    /* 上記の最大数とすること */

#define Y_SCORE_TWINKLE_STAR_TRACK_NUM          (3)     /* トラック数 */

/* 配列長最大値チェック */
#if    (Y_SCORE_TWINKLE_STAR_TRACK_MAX_SIZE < Y_SCORE_TWINKLE_STAR_TRACK_0_SIZE) \
    || (Y_SCORE_TWINKLE_STAR_TRACK_MAX_SIZE < Y_SCORE_TWINKLE_STAR_TRACK_1_SIZE) \
    || (Y_SCORE_TWINKLE_STAR_TRACK_MAX_SIZE < Y_SCORE_TWINKLE_STAR_TRACK_2_SIZE)
    #error "Y_SCORE_TWINKLE_STAR_TRACK_MAX_SIZE が不正"
#endif

/* params ********************************************************************************************/
const static score_note_t Xst_SCORE_Notes_Twinkle_Star_0[Y_SCORE_TWINKLE_STAR_TRACK_0_SIZE] = {
    {Y_SCORE_NOTE_C5, 64, 0},
    {Y_SCORE_NOTE_C5, 64, 64},
    {Y_SCORE_NOTE_G5, 64, 128},
    {Y_SCORE_NOTE_G5, 64, 192},
    {Y_SCORE_NOTE_A5, 64, 256},
    {Y_SCORE_NOTE_A5, 64, 320},
    {Y_SCORE_NOTE_G5, 128, 384},
    {Y_SCORE_NOTE_F5, 64, 512},
    {Y_SCORE_NOTE_F5, 64, 576},
    {Y_SCORE_NOTE_E5, 64, 640},
    {Y_SCORE_NOTE_E5, 64, 704},
    {Y_SCORE_NOTE_D5, 64, 768},
    {Y_SCORE_NOTE_D5, 64, 832},
    {Y_SCORE_NOTE_C5, 128, 896},
    {Y_SCORE_NOTE_G5, 64, 1024},
    {Y_SCORE_NOTE_G5, 64, 1088},
    {Y_SCORE_NOTE_F5, 64, 1152},
    {Y_SCORE_NOTE_F5, 64, 1216},
    {Y_SCORE_NOTE_E5, 64, 1280},
    {Y_SCORE_NOTE_E5, 64, 1344},
    {Y_SCORE_NOTE_D5, 128, 1408},
    {Y_SCORE_NOTE_G5, 64, 1536},
    {Y_SCORE_NOTE_G5, 64, 1600},
    {Y_SCORE_NOTE_F5, 64, 1664},
    {Y_SCORE_NOTE_F5, 64, 1728},
    {Y_SCORE_NOTE_E5, 64, 1792},
    {Y_SCORE_NOTE_E5, 64, 1856},
    {Y_SCORE_NOTE_D5, 128, 1920},
    {Y_SCORE_NOTE_C5, 64, 2048},
    {Y_SCORE_NOTE_C5, 64, 2112},
    {Y_SCORE_NOTE_G5, 64, 2176},
    {Y_SCORE_NOTE_G5, 64, 2240},
    {Y_SCORE_NOTE_A5, 64, 2304},
    {Y_SCORE_NOTE_A5, 64, 2368},
    {Y_SCORE_NOTE_G5, 128, 2432},
    {Y_SCORE_NOTE_F5, 64, 2560},
    {Y_SCORE_NOTE_F5, 64, 2624},
    {Y_SCORE_NOTE_E5, 64, 2688},
    {Y_SCORE_NOTE_E5, 64, 2752},
    {Y_SCORE_NOTE_D5, 64, 2816},
    {Y_SCORE_NOTE_D5, 64, 2880},
    {Y_SCORE_NOTE_C5, 128, 2944}
};

const static score_note_t Xst_SCORE_Notes_Twinkle_Star_1[Y_SCORE_TWINKLE_STAR_TRACK_1_SIZE] = {
    {Y_SCORE_NOTE_E4, 128, 0},
    {Y_SCORE_NOTE_C5, 128, 128},
    {Y_SCORE_NOTE_C5, 128, 256},
    {Y_SCORE_NOTE_C5, 128, 384},
    {Y_SCORE_NOTE_A4, 128, 512},
    {Y_SCORE_NOTE_G4, 128, 640},
    {Y_SCORE_NOTE_G4, 128, 768},
    {Y_SCORE_NOTE_E4, 128, 896},
    {Y_SCORE_NOTE_C5, 128, 1024},
    {Y_SCORE_NOTE_A4, 128, 1152},
    {Y_SCORE_NOTE_G4, 128, 1280},
    {Y_SCORE_NOTE_G4, 128, 1408},
    {Y_SCORE_NOTE_C5, 128, 1536},
    {Y_SCORE_NOTE_A4, 128, 1664},
    {Y_SCORE_NOTE_G4, 128, 1792},
    {Y_SCORE_NOTE_G4, 128, 1920},
    {Y_SCORE_NOTE_E4, 128, 2048},
    {Y_SCORE_NOTE_C5, 128, 2176},
    {Y_SCORE_NOTE_C5, 128, 2304},
    {Y_SCORE_NOTE_C5, 128, 2432},
    {Y_SCORE_NOTE_A4, 128, 2560},
    {Y_SCORE_NOTE_G4, 128, 2688},
    {Y_SCORE_NOTE_G4, 128, 2816},
    {Y_SCORE_NOTE_E4, 128, 2944}
};

const static score_note_t Xst_SCORE_Notes_Twinkle_Star_2[Y_SCORE_TWINKLE_STAR_TRACK_2_SIZE] = {
    {Y_SCORE_NOTE_C4, 128, 0},
    {Y_SCORE_NOTE_C4, 128, 128},
    {Y_SCORE_NOTE_F3, 128, 256},
    {Y_SCORE_NOTE_C4, 128, 384},
    {Y_SCORE_NOTE_F3, 128, 512},
    {Y_SCORE_NOTE_C4, 128, 640},
    {Y_SCORE_NOTE_G3, 128, 768},
    {Y_SCORE_NOTE_C4, 128, 896},
    {Y_SCORE_NOTE_C4, 128, 1024},
    {Y_SCORE_NOTE_F3, 128, 1152},
    {Y_SCORE_NOTE_G3, 128, 1280},
    {Y_SCORE_NOTE_G3, 128, 1408},
    {Y_SCORE_NOTE_C4, 128, 1536},
    {Y_SCORE_NOTE_F3, 128, 1664},
    {Y_SCORE_NOTE_G3, 128, 1792},
    {Y_SCORE_NOTE_G3, 128, 1920},
    {Y_SCORE_NOTE_C4, 128, 2048},
    {Y_SCORE_NOTE_C4, 128, 2176},
    {Y_SCORE_NOTE_F3, 128, 2304},
    {Y_SCORE_NOTE_C4, 128, 2432},
    {Y_SCORE_NOTE_F3, 128, 2560},
    {Y_SCORE_NOTE_C4, 128, 2688},
    {Y_SCORE_NOTE_G3, 128, 2816},
    {Y_SCORE_NOTE_C4, 128, 2944}
};

const static score_track_t Xst_SCORE_Tracks_Twinkle_Star[Y_SCORE_TWINKLE_STAR_TRACK_NUM] = {
    {
        Y_SCORE_TWINKLE_STAR_TRACK_0_SIZE,
        &Xst_SCORE_Notes_Twinkle_Star_0[0],
    },
    {
        Y_SCORE_TWINKLE_STAR_TRACK_1_SIZE,
        &Xst_SCORE_Notes_Twinkle_Star_1[0],
    },
    {
        Y_SCORE_TWINKLE_STAR_TRACK_2_SIZE,
        &Xst_SCORE_Notes_Twinkle_Star_2[0],
    },
};

const static char Xst_SCORE_Artist_Twinkle_Star[] = "-";             /* 作曲者 */
const static char Xst_SCORE_ScoreName_Twinkle_Star[] = "きらきら星";   /* 楽曲名 */

const score_score_t Xst_SCORE_Twinkle_Star = {
    Y_SCORE_TWINKLE_STAR_TRACK_MAX_SIZE,
    &Xst_SCORE_Artist_Twinkle_Star[0],
    &Xst_SCORE_ScoreName_Twinkle_Star[0],
    Y_SCORE_TWINKLE_STAR_TRACK_NUM,
    0,
    &Xst_SCORE_Tracks_Twinkle_Star[0],
};

#endif /* __SCORE_TWINKLE_STAR_H__ */

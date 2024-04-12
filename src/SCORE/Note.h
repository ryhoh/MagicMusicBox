/**
 * @file Note.h
 * @author ryhoh
 * @brief 音階の情報を管理する
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef __NOTE_H__
#define __NOTE_H__

/* include *******************************************************************************************/
#include <Arduino.h>
/* define ********************************************************************************************/
#define Y_SCORE_NOTE_A0  (28)
#define Y_SCORE_NOTE_AS0 (29)
#define Y_SCORE_NOTE_B0  (31)
#define Y_SCORE_NOTE_C1  (32)
#define Y_SCORE_NOTE_CS1 (35)
#define Y_SCORE_NOTE_D1  (37)
#define Y_SCORE_NOTE_D1S (39)
#define Y_SCORE_NOTE_E1  (41)
#define Y_SCORE_NOTE_F1  (44)
#define Y_SCORE_NOTE_FS1 (46)
#define Y_SCORE_NOTE_G1  (49)
#define Y_SCORE_NOTE_GS1 (52)
#define Y_SCORE_NOTE_A1  (55)
#define Y_SCORE_NOTE_AS1 (58)
#define Y_SCORE_NOTE_B1  (62)
#define Y_SCORE_NOTE_C2  (65)
#define Y_SCORE_NOTE_CS2 (69)
#define Y_SCORE_NOTE_D2  (73)
#define Y_SCORE_NOTE_DS2 (78)
#define Y_SCORE_NOTE_E2  (82)
#define Y_SCORE_NOTE_F2  (87)
#define Y_SCORE_NOTE_FS2 (92)
#define Y_SCORE_NOTE_G2  (98)
#define Y_SCORE_NOTE_GS2 (104)
#define Y_SCORE_NOTE_A2  (110)
#define Y_SCORE_NOTE_AS2 (117)
#define Y_SCORE_NOTE_B2  (123)
#define Y_SCORE_NOTE_C3  (131)
#define Y_SCORE_NOTE_CS3 (139)
#define Y_SCORE_NOTE_D3  (147)
#define Y_SCORE_NOTE_DS3 (156)
#define Y_SCORE_NOTE_E3  (165)
#define Y_SCORE_NOTE_F3  (175)
#define Y_SCORE_NOTE_FS3 (185)
#define Y_SCORE_NOTE_G3  (196)
#define Y_SCORE_NOTE_GS3 (208)
#define Y_SCORE_NOTE_A3  (220)
#define Y_SCORE_NOTE_AS3 (233)
#define Y_SCORE_NOTE_B3  (247)
#define Y_SCORE_NOTE_C4  (262)
#define Y_SCORE_NOTE_CS4 (277)
#define Y_SCORE_NOTE_D4  (294)
#define Y_SCORE_NOTE_DS4 (311)
#define Y_SCORE_NOTE_E4  (330)
#define Y_SCORE_NOTE_F4  (349)
#define Y_SCORE_NOTE_FS4 (370)
#define Y_SCORE_NOTE_G4  (392)
#define Y_SCORE_NOTE_GS4 (415)
#define Y_SCORE_NOTE_A4  (440)
#define Y_SCORE_NOTE_AS4 (466)
#define Y_SCORE_NOTE_B4  (494)
#define Y_SCORE_NOTE_C5  (523)
#define Y_SCORE_NOTE_CS5 (554)
#define Y_SCORE_NOTE_D5  (587)
#define Y_SCORE_NOTE_DS5 (622)
#define Y_SCORE_NOTE_E5  (659)
#define Y_SCORE_NOTE_F5  (698)
#define Y_SCORE_NOTE_FS5 (740)
#define Y_SCORE_NOTE_G5  (784)
#define Y_SCORE_NOTE_GS5 (831)
#define Y_SCORE_NOTE_A5  (880)
#define Y_SCORE_NOTE_AS5 (932)
#define Y_SCORE_NOTE_B5  (988)
#define Y_SCORE_NOTE_C6  (1047)
#define Y_SCORE_NOTE_CS6 (1109)
#define Y_SCORE_NOTE_D6  (1175)
#define Y_SCORE_NOTE_DS6 (1245)
#define Y_SCORE_NOTE_E6  (1319)
#define Y_SCORE_NOTE_F6  (1397)
#define Y_SCORE_NOTE_FS6 (1480)
#define Y_SCORE_NOTE_G6  (1568)
#define Y_SCORE_NOTE_GS6 (1661)
#define Y_SCORE_NOTE_A6  (1760)
#define Y_SCORE_NOTE_AS6 (1865)
#define Y_SCORE_NOTE_B6  (1976)
#define Y_SCORE_NOTE_C7  (2093)
#define Y_SCORE_NOTE_CS7 (2217)
#define Y_SCORE_NOTE_D7  (2349)
#define Y_SCORE_NOTE_DS7 (2489)
#define Y_SCORE_NOTE_E7  (2637)
#define Y_SCORE_NOTE_F7  (2794)
#define Y_SCORE_NOTE_FS7 (2960)
#define Y_SCORE_NOTE_G7  (3136)
#define Y_SCORE_NOTE_GS7 (3322)
#define Y_SCORE_NOTE_A7  (3520)
#define Y_SCORE_NOTE_AS7 (3729)
#define Y_SCORE_NOTE_B7  (3951)
#define Y_SCORE_NOTE_C8  (4186)

/* Structure *****************************************************************************************/
typedef struct _score_note_t {  /* 音符の情報 */
  uint16_t us_note;    /* 音階 */
  uint16_t us_length;  /* 音符の長さ */
  uint32_t ul_offset;  /* 音符の再生タイミング(0秒からのオフセット) */
} score_note_t;

typedef struct _score_track_t { /* トラックの情報 */
        uint32_t      ul_track_len;   /* トラックの長さ */
  const score_note_t *pst_notes;      /* 音符の情報 */
} score_track_t;

typedef struct _score_score_t {
        uint32_t        ul_track_max_len;   /* トラックの最大長 */
  const char           *pc_artist_name;     /* アーティスト名 */
  const char           *pc_score_name;      /* 曲名 */
        uint8_t         uc_track_num;       /* トラック数 */
        uint8_t         uc_dummy;           /* ダミー領域 */
  const score_track_t  *pst_tracks;         /* トラックデータ */
} score_score_t;

/* ***************************************************************************************************/

#endif /* __NOTE_H__ */

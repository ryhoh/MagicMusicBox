/**
 * @file configure.c
 * @author ryhoh
 * @brief H/W Configurations
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef __CONFIGURE_H__
#define __CONFIGURE_H__

/* Compile Switch ***********************************************************************************/
#define SW_COVER_SW_REDUNDANT           (1)         /* 0:No Redundunt 1:Redundunt                   */
#define SW_BUZZER_NUM                   (4)         /* Number of buzzers installed                  */
#define SW_DIP_SW_NUM                   (2)         /* Number of DIP switches installed             */
/* H/W Pin Assign ***********************************************************************************/
#define PIN_COVER_SW_0                  (D9)         /* Cover Switch 0                              */
#define PIN_COVER_SW_1                  (D10)        /* Cover Switch 1                              */
#define PIN_BUZZER_0                    (D0)         /* Buzzer 0                                    */
#define PIN_BUZZER_1                    (D1)         /* Buzzer 1                                    */
#define PIN_BUZZER_2                    (D2)         /* Buzzer 2                                    */
#define PIN_BUZZER_3                    (D3)         /* Buzzer 3                                    */
#define PIN_DIP_SW_BIT0                 (D8)         /* DIP Switch Bit0                             */
#define PIN_DIP_SW_BIT1                 (D7)         /* DIP Switch Bit1                             */
/* **************************************************************************************************/

#endif /* __CONFIGURE_H__ */

/***************************************************************************
 *             __________               __   ___.
 *   Open      \______   \ ____   ____ |  | _\_ |__   _______  ___
 *   Source     |       _//  _ \_/ ___\|  |/ /| __ \ /  _ \  \/  /
 *   Jukebox    |    |   (  <_> )  \___|    < | \_\ (  <_> > <  <
 *   Firmware   |____|_  /\____/ \___  >__|_ \|___  /\____/__/\_ \
 *                     \/            \/     \/    \/            \/
 * $Id$
 *
 * Copyright (C) 2005 Dave Chapman
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This software is distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY
 * KIND, either express or implied.
 *
 ****************************************************************************/

#ifndef _SUDOKU_H
#define _SUDOKU_H

#include "plugin.h"

#define GAME_FILE         PLUGIN_GAMES_DIR "/sudoku.ss"

/* variable button definitions */
#if (CONFIG_KEYPAD == IRIVER_H100_PAD) || \
    (CONFIG_KEYPAD == IRIVER_H300_PAD)
#define SUDOKU_BUTTON_QUIT BUTTON_OFF
#define SUDOKU_BUTTON_UP BUTTON_UP
#define SUDOKU_BUTTON_DOWN BUTTON_DOWN
#define SUDOKU_BUTTON_LEFT BUTTON_LEFT
#define SUDOKU_BUTTON_RIGHT BUTTON_RIGHT
#define SUDOKU_BUTTON_ALTTOGGLE BUTTON_ON
#define SUDOKU_BUTTON_TOGGLE BUTTON_SELECT
#define SUDOKU_BUTTON_MENU BUTTON_MODE
#define SUDOKU_BUTTON_POSSIBLE BUTTON_REC

#elif (CONFIG_KEYPAD == IPOD_4G_PAD) || \
      (CONFIG_KEYPAD == IPOD_3G_PAD) || \
      (CONFIG_KEYPAD == IPOD_1G2G_PAD)
#define SUDOKU_BUTTON_MENU       BUTTON_MENU
#define SUDOKU_BUTTON_LEFT       BUTTON_SCROLL_BACK
#define SUDOKU_BUTTON_RIGHT      BUTTON_SCROLL_FWD
#define SUDOKU_BUTTON_CHANGEDIR  BUTTON_SELECT
#define SUDOKU_BUTTON_TOGGLE     BUTTON_RIGHT
#define SUDOKU_BUTTON_TOGGLEBACK BUTTON_LEFT
#define SUDOKU_BUTTON_POSSIBLE   BUTTON_PLAY

#elif (CONFIG_KEYPAD == IAUDIO_X5M5_PAD)
#define SUDOKU_BUTTON_QUIT BUTTON_POWER
#define SUDOKU_BUTTON_UP BUTTON_UP
#define SUDOKU_BUTTON_DOWN BUTTON_DOWN
#define SUDOKU_BUTTON_LEFT BUTTON_LEFT
#define SUDOKU_BUTTON_RIGHT BUTTON_RIGHT
#define SUDOKU_BUTTON_TOGGLE BUTTON_SELECT
#define SUDOKU_BUTTON_MENU BUTTON_PLAY
#define SUDOKU_BUTTON_POSSIBLE BUTTON_REC

#elif (CONFIG_KEYPAD == GIGABEAT_PAD)
#define SUDOKU_BUTTON_QUIT BUTTON_POWER
#define SUDOKU_BUTTON_UP BUTTON_UP
#define SUDOKU_BUTTON_DOWN BUTTON_DOWN
#define SUDOKU_BUTTON_LEFT BUTTON_LEFT
#define SUDOKU_BUTTON_RIGHT BUTTON_RIGHT
#define SUDOKU_BUTTON_TOGGLE BUTTON_SELECT
#define SUDOKU_BUTTON_MENU BUTTON_MENU
#define SUDOKU_BUTTON_POSSIBLE BUTTON_A

#elif (CONFIG_KEYPAD == GIGABEAT_S_PAD)
#define SUDOKU_BUTTON_QUIT BUTTON_POWER
#define SUDOKU_BUTTON_UP BUTTON_UP
#define SUDOKU_BUTTON_DOWN BUTTON_DOWN
#define SUDOKU_BUTTON_LEFT BUTTON_LEFT
#define SUDOKU_BUTTON_RIGHT BUTTON_RIGHT
#define SUDOKU_BUTTON_TOGGLE BUTTON_SELECT
#define SUDOKU_BUTTON_MENU BUTTON_MENU
#define SUDOKU_BUTTON_POSSIBLE BUTTON_PLAY

#elif (CONFIG_KEYPAD == IRIVER_H10_PAD)
#define SUDOKU_BUTTON_QUIT BUTTON_POWER
#define SUDOKU_BUTTON_UP BUTTON_SCROLL_UP
#define SUDOKU_BUTTON_DOWN BUTTON_SCROLL_DOWN
#define SUDOKU_BUTTON_LEFT BUTTON_LEFT
#define SUDOKU_BUTTON_RIGHT BUTTON_RIGHT
#define SUDOKU_BUTTON_TOGGLE BUTTON_REW
#define SUDOKU_BUTTON_MENU BUTTON_PLAY
#define SUDOKU_BUTTON_POSSIBLE BUTTON_FF

#elif (CONFIG_KEYPAD == SANSA_E200_PAD)
#define SUDOKU_BUTTON_QUIT BUTTON_POWER
#define SUDOKU_BUTTON_UP BUTTON_UP
#define SUDOKU_BUTTON_DOWN BUTTON_DOWN
#define SUDOKU_BUTTON_LEFT BUTTON_LEFT
#define SUDOKU_BUTTON_RIGHT BUTTON_RIGHT
#define SUDOKU_BUTTON_TOGGLEBACK BUTTON_SCROLL_BACK
#define SUDOKU_BUTTON_TOGGLE BUTTON_SCROLL_FWD
#define SUDOKU_BUTTON_MENU BUTTON_SELECT
#define SUDOKU_BUTTON_POSSIBLE BUTTON_REC

#elif (CONFIG_KEYPAD == SANSA_FUZE_PAD)
#define SUDOKU_BUTTON_QUIT      (BUTTON_HOME|BUTTON_REPEAT)
#define SUDOKU_BUTTON_UP        BUTTON_UP
#define SUDOKU_BUTTON_DOWN      BUTTON_DOWN
#define SUDOKU_BUTTON_LEFT      BUTTON_LEFT
#define SUDOKU_BUTTON_RIGHT     BUTTON_RIGHT
#define SUDOKU_BUTTON_TOGGLEBACK BUTTON_SCROLL_BACK
#define SUDOKU_BUTTON_TOGGLE    BUTTON_SCROLL_FWD
#define SUDOKU_BUTTON_MENU      (BUTTON_HOME | BUTTON_REL)
#define SUDOKU_BUTTON_POSSIBLE  BUTTON_SELECT

#elif (CONFIG_KEYPAD == SANSA_C200_PAD)
#define SUDOKU_BUTTON_QUIT_PRE   BUTTON_POWER
#define SUDOKU_BUTTON_QUIT       (BUTTON_POWER | BUTTON_REPEAT)
#define SUDOKU_BUTTON_UP         BUTTON_UP
#define SUDOKU_BUTTON_DOWN       BUTTON_DOWN
#define SUDOKU_BUTTON_LEFT       BUTTON_LEFT
#define SUDOKU_BUTTON_RIGHT      BUTTON_RIGHT
#define SUDOKU_BUTTON_TOGGLEBACK BUTTON_VOL_DOWN
#define SUDOKU_BUTTON_TOGGLE     BUTTON_VOL_UP
#define SUDOKU_BUTTON_ALTTOGGLE  BUTTON_SELECT
#define SUDOKU_BUTTON_MENU_PRE   BUTTON_POWER
#define SUDOKU_BUTTON_MENU       (BUTTON_POWER | BUTTON_REL)
#define SUDOKU_BUTTON_POSSIBLE   BUTTON_REC

#elif (CONFIG_KEYPAD == SANSA_CLIP_PAD)
#define SUDOKU_BUTTON_QUIT_PRE   BUTTON_POWER
#define SUDOKU_BUTTON_QUIT       (BUTTON_POWER | BUTTON_REPEAT)
#define SUDOKU_BUTTON_UP         BUTTON_UP
#define SUDOKU_BUTTON_DOWN       BUTTON_DOWN
#define SUDOKU_BUTTON_LEFT       BUTTON_LEFT
#define SUDOKU_BUTTON_RIGHT      BUTTON_RIGHT
#define SUDOKU_BUTTON_TOGGLEBACK BUTTON_VOL_DOWN
#define SUDOKU_BUTTON_TOGGLE     BUTTON_VOL_UP
#define SUDOKU_BUTTON_ALTTOGGLE  BUTTON_SELECT
#define SUDOKU_BUTTON_MENU_PRE   BUTTON_POWER
#define SUDOKU_BUTTON_MENU       (BUTTON_POWER | BUTTON_REL)
#define SUDOKU_BUTTON_POSSIBLE   BUTTON_HOME

#elif (CONFIG_KEYPAD == SANSA_M200_PAD)
#define SUDOKU_BUTTON_QUIT_PRE   BUTTON_POWER
#define SUDOKU_BUTTON_QUIT       (BUTTON_POWER | BUTTON_REPEAT)
#define SUDOKU_BUTTON_UP         BUTTON_UP
#define SUDOKU_BUTTON_DOWN       BUTTON_DOWN
#define SUDOKU_BUTTON_LEFT       BUTTON_LEFT
#define SUDOKU_BUTTON_RIGHT      BUTTON_RIGHT
#define SUDOKU_BUTTON_TOGGLEBACK BUTTON_VOL_DOWN
#define SUDOKU_BUTTON_TOGGLE     BUTTON_VOL_UP
#define SUDOKU_BUTTON_ALTTOGGLE  (BUTTON_SELECT | BUTTON_REL)
#define SUDOKU_BUTTON_MENU_PRE   BUTTON_POWER
#define SUDOKU_BUTTON_MENU       (BUTTON_POWER | BUTTON_REL)
#define SUDOKU_BUTTON_POSSIBLE   (BUTTON_SELECT | BUTTON_UP)

#elif CONFIG_KEYPAD == MROBE500_PAD
#define SUDOKU_BUTTON_QUIT       BUTTON_POWER

#elif (CONFIG_KEYPAD == MROBE100_PAD)
#define SUDOKU_BUTTON_QUIT BUTTON_POWER
#define SUDOKU_BUTTON_UP BUTTON_UP
#define SUDOKU_BUTTON_DOWN BUTTON_DOWN
#define SUDOKU_BUTTON_LEFT BUTTON_LEFT
#define SUDOKU_BUTTON_RIGHT BUTTON_RIGHT
#define SUDOKU_BUTTON_TOGGLE BUTTON_SELECT
#define SUDOKU_BUTTON_MENU BUTTON_MENU
#define SUDOKU_BUTTON_POSSIBLE BUTTON_DISPLAY

#elif CONFIG_KEYPAD == IAUDIO_M3_PAD
#define SUDOKU_BUTTON_QUIT BUTTON_RC_REC
#define SUDOKU_BUTTON_UP BUTTON_RC_VOL_UP
#define SUDOKU_BUTTON_DOWN BUTTON_RC_VOL_DOWN
#define SUDOKU_BUTTON_LEFT BUTTON_RC_REW
#define SUDOKU_BUTTON_RIGHT BUTTON_RC_FF
#define SUDOKU_BUTTON_TOGGLE BUTTON_RC_MODE
#define SUDOKU_BUTTON_MENU BUTTON_RC_MENU
#define SUDOKU_BUTTON_POSSIBLE BUTTON_RC_PLAY

#elif (CONFIG_KEYPAD == COWON_D2_PAD)
#define SUDOKU_BUTTON_QUIT BUTTON_POWER
#define SUDOKU_BUTTON_MENU BUTTON_MENU

#elif CONFIG_KEYPAD == IAUDIO67_PAD
#define SUDOKU_BUTTON_QUIT BUTTON_POWER
#define SUDOKU_BUTTON_UP BUTTON_STOP
#define SUDOKU_BUTTON_DOWN BUTTON_PLAY
#define SUDOKU_BUTTON_LEFT BUTTON_LEFT
#define SUDOKU_BUTTON_RIGHT BUTTON_RIGHT
#define SUDOKU_BUTTON_TOGGLE BUTTON_VOLUP
#define SUDOKU_BUTTON_MENU BUTTON_MENU
#define SUDOKU_BUTTON_POSSIBLE BUTTON_VOLDOWN

#elif CONFIG_KEYPAD == CREATIVEZVM_PAD
#define SUDOKU_BUTTON_QUIT BUTTON_BACK
#define SUDOKU_BUTTON_UP BUTTON_UP
#define SUDOKU_BUTTON_DOWN BUTTON_DOWN
#define SUDOKU_BUTTON_LEFT BUTTON_LEFT
#define SUDOKU_BUTTON_RIGHT BUTTON_RIGHT
#define SUDOKU_BUTTON_TOGGLE BUTTON_SELECT
#define SUDOKU_BUTTON_MENU BUTTON_MENU
#define SUDOKU_BUTTON_POSSIBLE BUTTON_PLAY

#elif CONFIG_KEYPAD == CREATIVE_ZENXFI3_PAD
#define SUDOKU_BUTTON_QUIT       BUTTON_POWER
#define SUDOKU_BUTTON_UP         BUTTON_UP
#define SUDOKU_BUTTON_DOWN       BUTTON_DOWN
#define SUDOKU_BUTTON_LEFT       BUTTON_BACK
#define SUDOKU_BUTTON_RIGHT      BUTTON_MENU
#define SUDOKU_BUTTON_TOGGLEBACK BUTTON_VOL_DOWN
#define SUDOKU_BUTTON_TOGGLE     BUTTON_VOL_UP
#define SUDOKU_BUTTON_MENU      (BUTTON_PLAY|BUTTON_REPEAT)
#define SUDOKU_BUTTON_POSSIBLE  (BUTTON_PLAY|BUTTON_REL)

#elif CONFIG_KEYPAD == PHILIPS_HDD1630_PAD
#define SUDOKU_BUTTON_QUIT BUTTON_POWER
#define SUDOKU_BUTTON_UP BUTTON_UP
#define SUDOKU_BUTTON_DOWN BUTTON_DOWN
#define SUDOKU_BUTTON_LEFT BUTTON_LEFT
#define SUDOKU_BUTTON_RIGHT BUTTON_RIGHT
#define SUDOKU_BUTTON_TOGGLE BUTTON_SELECT
#define SUDOKU_BUTTON_MENU BUTTON_MENU
#define SUDOKU_BUTTON_POSSIBLE BUTTON_VIEW

#elif CONFIG_KEYPAD == PHILIPS_HDD6330_PAD
#define SUDOKU_BUTTON_QUIT BUTTON_POWER
#define SUDOKU_BUTTON_UP BUTTON_UP
#define SUDOKU_BUTTON_DOWN BUTTON_DOWN
#define SUDOKU_BUTTON_LEFT BUTTON_LEFT
#define SUDOKU_BUTTON_RIGHT BUTTON_RIGHT
#define SUDOKU_BUTTON_TOGGLE BUTTON_PLAY
#define SUDOKU_BUTTON_MENU BUTTON_MENU
#define SUDOKU_BUTTON_POSSIBLE BUTTON_NEXT

#elif CONFIG_KEYPAD == PHILIPS_SA9200_PAD
#define SUDOKU_BUTTON_QUIT BUTTON_POWER
#define SUDOKU_BUTTON_UP BUTTON_UP
#define SUDOKU_BUTTON_DOWN BUTTON_DOWN
#define SUDOKU_BUTTON_LEFT BUTTON_PREV
#define SUDOKU_BUTTON_RIGHT BUTTON_NEXT
#define SUDOKU_BUTTON_TOGGLE BUTTON_PLAY
#define SUDOKU_BUTTON_MENU BUTTON_MENU
#define SUDOKU_BUTTON_POSSIBLE BUTTON_RIGHT

#elif (CONFIG_KEYPAD == ONDAVX747_PAD)
#define SUDOKU_BUTTON_QUIT BUTTON_POWER
#define SUDOKU_BUTTON_MENU BUTTON_MENU

#elif (CONFIG_KEYPAD == ONDAVX777_PAD)
#define SUDOKU_BUTTON_QUIT BUTTON_POWER

#elif (CONFIG_KEYPAD == SAMSUNG_YH92X_PAD)
#define SUDOKU_BUTTON_UP       BUTTON_UP
#define SUDOKU_BUTTON_DOWN     BUTTON_DOWN
#define SUDOKU_BUTTON_LEFT     BUTTON_LEFT
#define SUDOKU_BUTTON_RIGHT    BUTTON_RIGHT
#define SUDOKU_BUTTON_TOGGLE   BUTTON_FFWD
#define SUDOKU_BUTTON_TOGGLEBACK BUTTON_REW
#define SUDOKU_BUTTON_MENU     (BUTTON_PLAY|BUTTON_REPEAT)
#define SUDOKU_BUTTON_POSSIBLE (BUTTON_PLAY|BUTTON_REL)

#elif (CONFIG_KEYPAD == SAMSUNG_YH820_PAD)
#define SUDOKU_BUTTON_UP       BUTTON_UP
#define SUDOKU_BUTTON_DOWN     BUTTON_DOWN
#define SUDOKU_BUTTON_LEFT     BUTTON_LEFT
#define SUDOKU_BUTTON_RIGHT    BUTTON_RIGHT
#define SUDOKU_BUTTON_TOGGLE   BUTTON_FFWD
#define SUDOKU_BUTTON_TOGGLEBACK BUTTON_REW
#define SUDOKU_BUTTON_MENU     BUTTON_REC
#define SUDOKU_BUTTON_POSSIBLE BUTTON_PLAY

#elif CONFIG_KEYPAD == PBELL_VIBE500_PAD
#define SUDOKU_BUTTON_QUIT     BUTTON_REC
#define SUDOKU_BUTTON_UP       BUTTON_UP
#define SUDOKU_BUTTON_DOWN     BUTTON_DOWN
#define SUDOKU_BUTTON_LEFT     BUTTON_PREV
#define SUDOKU_BUTTON_RIGHT    BUTTON_NEXT
#define SUDOKU_BUTTON_TOGGLE   BUTTON_OK
#define SUDOKU_BUTTON_MENU     BUTTON_MENU
#define SUDOKU_BUTTON_POSSIBLE BUTTON_PLAY

#elif CONFIG_KEYPAD == MPIO_HD200_PAD
#define SUDOKU_BUTTON_QUIT       (BUTTON_REC | BUTTON_PLAY)
#define SUDOKU_BUTTON_MENU       BUTTON_REC
#define SUDOKU_BUTTON_UP         BUTTON_FF
#define SUDOKU_BUTTON_DOWN       BUTTON_REW
#define SUDOKU_BUTTON_LEFT       BUTTON_VOL_DOWN
#define SUDOKU_BUTTON_RIGHT      BUTTON_VOL_UP
#define SUDOKU_BUTTON_TOGGLE     BUTTON_FUNC
#define SUDOKU_BUTTON_POSSIBLE   BUTTON_PLAY

#elif CONFIG_KEYPAD == MPIO_HD300_PAD
#define SUDOKU_BUTTON_QUIT       (BUTTON_MENU | BUTTON_REPEAT)
#define SUDOKU_BUTTON_MENU       (BUTTON_MENU | BUTTON_REL)
#define SUDOKU_BUTTON_UP         BUTTON_UP
#define SUDOKU_BUTTON_DOWN       BUTTON_DOWN
#define SUDOKU_BUTTON_LEFT       BUTTON_REW
#define SUDOKU_BUTTON_RIGHT      BUTTON_FF
#define SUDOKU_BUTTON_TOGGLE     BUTTON_ENTER
#define SUDOKU_BUTTON_POSSIBLE   BUTTON_PLAY

#elif CONFIG_KEYPAD == SANSA_FUZEPLUS_PAD
#define SUDOKU_BUTTON_QUIT       BUTTON_POWER
#define SUDOKU_BUTTON_MENU       BUTTON_BACK
#define SUDOKU_BUTTON_LEFT       BUTTON_LEFT
#define SUDOKU_BUTTON_RIGHT      BUTTON_RIGHT
#define SUDOKU_BUTTON_UP         BUTTON_UP
#define SUDOKU_BUTTON_DOWN       BUTTON_DOWN
#define SUDOKU_BUTTON_TOGGLE     BUTTON_SELECT
#define SUDOKU_BUTTON_TOGGLEBACK BUTTON_BOTTOMLEFT
#define SUDOKU_BUTTON_POSSIBLE   BUTTON_PLAYPAUSE
#define SUDOKU_BUTTON_ALTTOGGLE  BUTTON_BOTTOMRIGHT

#elif (CONFIG_KEYPAD == SANSA_CONNECT_PAD)
#define SUDOKU_BUTTON_QUIT BUTTON_POWER
#define SUDOKU_BUTTON_UP BUTTON_UP
#define SUDOKU_BUTTON_DOWN BUTTON_DOWN
#define SUDOKU_BUTTON_LEFT BUTTON_LEFT
#define SUDOKU_BUTTON_RIGHT BUTTON_RIGHT
#define SUDOKU_BUTTON_TOGGLEBACK BUTTON_PREV
#define SUDOKU_BUTTON_TOGGLE BUTTON_NEXT
#define SUDOKU_BUTTON_MENU BUTTON_SELECT
#define SUDOKU_BUTTON_POSSIBLE BUTTON_VOL_DOWN

#elif CONFIG_KEYPAD == SAMSUNG_YPR0_PAD
#define SUDOKU_BUTTON_QUIT       BUTTON_BACK
#define SUDOKU_BUTTON_UP         BUTTON_UP
#define SUDOKU_BUTTON_DOWN       BUTTON_DOWN
#define SUDOKU_BUTTON_LEFT       BUTTON_LEFT
#define SUDOKU_BUTTON_RIGHT      BUTTON_RIGHT
#define SUDOKU_BUTTON_MENU       BUTTON_MENU
#define SUDOKU_BUTTON_TOGGLE     BUTTON_SELECT
#define SUDOKU_BUTTON_POSSIBLE   BUTTON_USER

#elif CONFIG_KEYPAD == HM60X_PAD
#define SUDOKU_BUTTON_QUIT       BUTTON_POWER
#define SUDOKU_BUTTON_MENU       (BUTTON_POWER | BUTTON_LEFT)
#define SUDOKU_BUTTON_LEFT       BUTTON_LEFT
#define SUDOKU_BUTTON_RIGHT      BUTTON_RIGHT
#define SUDOKU_BUTTON_UP         BUTTON_UP
#define SUDOKU_BUTTON_DOWN       BUTTON_DOWN
#define SUDOKU_BUTTON_TOGGLE     BUTTON_SELECT
#define SUDOKU_BUTTON_TOGGLEBACK (BUTTON_POWER | BUTTON_RIGHT)
#define SUDOKU_BUTTON_POSSIBLE   (BUTTON_POWER | BUTTON_SELECT)
#define SUDOKU_BUTTON_ALTTOGGLE  (BUTTON_POWER | BUTTON_UP)

#elif CONFIG_KEYPAD == HM801_PAD
#define SUDOKU_BUTTON_QUIT       BUTTON_POWER
#define SUDOKU_BUTTON_MENU       BUTTON_PLAY
#define SUDOKU_BUTTON_LEFT       BUTTON_LEFT
#define SUDOKU_BUTTON_RIGHT      BUTTON_RIGHT
#define SUDOKU_BUTTON_UP         BUTTON_UP
#define SUDOKU_BUTTON_DOWN       BUTTON_DOWN
#define SUDOKU_BUTTON_TOGGLE     BUTTON_NEXT
#define SUDOKU_BUTTON_TOGGLEBACK BUTTON_PREV
#define SUDOKU_BUTTON_POSSIBLE   (BUTTON_POWER | BUTTON_SELECT)
#define SUDOKU_BUTTON_ALTTOGGLE  BUTTON_SELECT

#elif CONFIG_KEYPAD == SONY_NWZ_PAD
#define SUDOKU_BUTTON_MENU       BUTTON_BACK
#define SUDOKU_BUTTON_UP         BUTTON_UP
#define SUDOKU_BUTTON_DOWN       BUTTON_DOWN
#define SUDOKU_BUTTON_LEFT       BUTTON_LEFT
#define SUDOKU_BUTTON_RIGHT      BUTTON_RIGHT
#define SUDOKU_BUTTON_TOGGLE     BUTTON_PLAY
#define SUDOKU_BUTTON_POSSIBLE   BUTTON_POWER

#elif CONFIG_KEYPAD == CREATIVE_ZEN_PAD
#define SUDOKU_BUTTON_MENU       BUTTON_MENU
#define SUDOKU_BUTTON_UP         BUTTON_UP
#define SUDOKU_BUTTON_DOWN       BUTTON_DOWN
#define SUDOKU_BUTTON_LEFT       BUTTON_LEFT
#define SUDOKU_BUTTON_RIGHT      BUTTON_RIGHT
#define SUDOKU_BUTTON_TOGGLE     BUTTON_SELECT
#define SUDOKU_BUTTON_POSSIBLE   BUTTON_SHORTCUT

#elif CONFIG_KEYPAD == DX50_PAD
#define SUDOKU_BUTTON_QUIT       (BUTTON_POWER|BUTTON_REL)

#elif CONFIG_KEYPAD == CREATIVE_ZENXFI2_PAD
#define SUDOKU_BUTTON_QUIT      BUTTON_POWER
#define SUDOKU_BUTTON_MENU      BUTTON_MENU

#elif CONFIG_KEYPAD == AGPTEK_ROCKER_PAD
#define SUDOKU_BUTTON_MENU       BUTTON_POWER
#define SUDOKU_BUTTON_UP         BUTTON_UP
#define SUDOKU_BUTTON_DOWN       BUTTON_DOWN
#define SUDOKU_BUTTON_LEFT       BUTTON_LEFT
#define SUDOKU_BUTTON_RIGHT      BUTTON_RIGHT
#define SUDOKU_BUTTON_TOGGLE     BUTTON_SELECT
#define SUDOKU_BUTTON_POSSIBLE   BUTTON_VOLUP

#elif CONFIG_KEYPAD == XDUOO_X3_PAD
#define SUDOKU_BUTTON_QUIT_PRE   BUTTON_POWER
#define SUDOKU_BUTTON_QUIT       (BUTTON_POWER | BUTTON_REPEAT)
#define SUDOKU_BUTTON_UP         BUTTON_HOME
#define SUDOKU_BUTTON_DOWN       BUTTON_OPTION
#define SUDOKU_BUTTON_LEFT       BUTTON_PREV
#define SUDOKU_BUTTON_RIGHT      BUTTON_NEXT
#define SUDOKU_BUTTON_TOGGLEBACK BUTTON_VOL_DOWN
#define SUDOKU_BUTTON_TOGGLE     BUTTON_VOL_UP
#define SUDOKU_BUTTON_ALTTOGGLE  BUTTON_PLAY
#define SUDOKU_BUTTON_MENU_PRE   BUTTON_POWER
#define SUDOKU_BUTTON_MENU       (BUTTON_POWER | BUTTON_REL)
#define SUDOKU_BUTTON_POSSIBLE   (BUTTON_HOME | BUTTON_PWRALT)

#elif CONFIG_KEYPAD == XDUOO_X3II_PAD || CONFIG_KEYPAD == XDUOO_X20_PAD
#define SUDOKU_BUTTON_QUIT_PRE   BUTTON_POWER
#define SUDOKU_BUTTON_QUIT       (BUTTON_POWER | BUTTON_REPEAT)
#define SUDOKU_BUTTON_UP         BUTTON_HOME
#define SUDOKU_BUTTON_DOWN       BUTTON_OPTION
#define SUDOKU_BUTTON_LEFT       BUTTON_PREV
#define SUDOKU_BUTTON_RIGHT      BUTTON_NEXT
#define SUDOKU_BUTTON_TOGGLEBACK BUTTON_VOL_DOWN
#define SUDOKU_BUTTON_TOGGLE     BUTTON_VOL_UP
#define SUDOKU_BUTTON_ALTTOGGLE  BUTTON_PLAY
#define SUDOKU_BUTTON_MENU_PRE   BUTTON_POWER
#define SUDOKU_BUTTON_MENU       (BUTTON_POWER | BUTTON_REL)
#define SUDOKU_BUTTON_POSSIBLE   (BUTTON_HOME | BUTTON_POWER)

#elif CONFIG_KEYPAD == FIIO_M3K_PAD
#define SUDOKU_BUTTON_QUIT_PRE   BUTTON_POWER
#define SUDOKU_BUTTON_QUIT       (BUTTON_POWER | BUTTON_REPEAT)
#define SUDOKU_BUTTON_UP         BUTTON_HOME
#define SUDOKU_BUTTON_DOWN       BUTTON_OPTION
#define SUDOKU_BUTTON_LEFT       BUTTON_PREV
#define SUDOKU_BUTTON_RIGHT      BUTTON_NEXT
#define SUDOKU_BUTTON_TOGGLEBACK BUTTON_VOL_DOWN
#define SUDOKU_BUTTON_TOGGLE     BUTTON_VOL_UP
#define SUDOKU_BUTTON_ALTTOGGLE  BUTTON_PLAY
#define SUDOKU_BUTTON_MENU_PRE   BUTTON_POWER
#define SUDOKU_BUTTON_MENU       (BUTTON_POWER | BUTTON_REL)
#define SUDOKU_BUTTON_POSSIBLE   (BUTTON_HOME | BUTTON_POWER)

#elif CONFIG_KEYPAD == IHIFI_770_PAD || CONFIG_KEYPAD == IHIFI_800_PAD
#define SUDOKU_BUTTON_QUIT_PRE   BUTTON_POWER
#define SUDOKU_BUTTON_QUIT       (BUTTON_POWER | BUTTON_REPEAT)
#define SUDOKU_BUTTON_UP         BUTTON_PREV
#define SUDOKU_BUTTON_DOWN       BUTTON_NEXT
#define SUDOKU_BUTTON_LEFT       BUTTON_HOME
#define SUDOKU_BUTTON_RIGHT      BUTTON_VOL_DOWN
#define SUDOKU_BUTTON_TOGGLEBACK (BUTTON_POWER | BUTTON_VOL_DOWN)
#define SUDOKU_BUTTON_TOGGLE     (BUTTON_POWER | BUTTON_VOL_UP)
#define SUDOKU_BUTTON_ALTTOGGLE  BUTTON_PLAY
#define SUDOKU_BUTTON_MENU_PRE   BUTTON_POWER
#define SUDOKU_BUTTON_MENU       (BUTTON_POWER | BUTTON_REL)
#define SUDOKU_BUTTON_POSSIBLE   (BUTTON_POWER | BUTTON_HOME)

#elif CONFIG_KEYPAD == EROSQ_PAD
#define SUDOKU_BUTTON_QUIT_PRE   BUTTON_POWER
#define SUDOKU_BUTTON_QUIT       (BUTTON_POWER | BUTTON_REPEAT)
#define SUDOKU_BUTTON_UP         BUTTON_PREV
#define SUDOKU_BUTTON_DOWN       BUTTON_NEXT
#define SUDOKU_BUTTON_LEFT       BUTTON_SCROLL_BACK
#define SUDOKU_BUTTON_RIGHT      BUTTON_SCROLL_FWD
#define SUDOKU_BUTTON_TOGGLEBACK BUTTON_VOL_DOWN
#define SUDOKU_BUTTON_TOGGLE     BUTTON_VOL_UP
#define SUDOKU_BUTTON_MENU_PRE   BUTTON_MENU
#define SUDOKU_BUTTON_MENU       (BUTTON_MENU | BUTTON_REL)
#define SUDOKU_BUTTON_POSSIBLE   BUTTON_BACK

#else
#error No keymap defined!
#endif

#ifdef HAVE_TOUCHSCREEN
#ifndef SUDOKU_BUTTON_QUIT
#define SUDOKU_BUTTON_QUIT     BUTTON_TOPLEFT
#endif
#ifndef SUDOKU_BUTTON_UP
#define SUDOKU_BUTTON_UP       BUTTON_TOPMIDDLE
#endif
#ifndef SUDOKU_BUTTON_DOWN
#define SUDOKU_BUTTON_DOWN     BUTTON_BOTTOMMIDDLE
#endif
#ifndef SUDOKU_BUTTON_LEFT
#define SUDOKU_BUTTON_LEFT     BUTTON_MIDLEFT
#endif
#ifndef SUDOKU_BUTTON_RIGHT
#define SUDOKU_BUTTON_RIGHT    BUTTON_MIDRIGHT
#endif
#ifndef SUDOKU_BUTTON_TOGGLE
#define SUDOKU_BUTTON_TOGGLE   BUTTON_CENTER
#endif
#ifndef SUDOKU_BUTTON_MENU
#define SUDOKU_BUTTON_MENU     BUTTON_TOPRIGHT
#endif
#ifndef SUDOKU_BUTTON_POSSIBLE
#define SUDOKU_BUTTON_POSSIBLE BUTTON_BOTTOMLEFT
#endif
#endif

struct sudoku_state_t {
  char filename[MAX_PATH];  /* Filename */
  char startboard[9][9];    /* The initial state of the game */
  char currentboard[9][9];  /* The current state of the game */
  char savedboard[9][9];    /* Cached copy of saved state */
  int x,y;                  /* Cursor position */
  int editmode;             /* We are editing the start board */
#ifdef SUDOKU_BUTTON_POSSIBLE
  short possiblevals[9][9];  /* possible values a cell could be, user sets them */
  short savedpossible[9][9]; /* cached copy of possible cell values */
#endif
};


#endif

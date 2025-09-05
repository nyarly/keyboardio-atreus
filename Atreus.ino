/* -*- mode: c++ -*-
 * Atreus -- Chrysalis-enabled Sketch for the Keyboardio Atreus
 * Copyright (C) 2018, 2019  Keyboard.io, Inc
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef BUILD_INFORMATION
#define BUILD_INFORMATION "locally built"
#endif

#include "Kaleidoscope.h"
#include "Kaleidoscope-EEPROM-Settings.h"
#include "Kaleidoscope-EEPROM-Keymap.h"
#include "Kaleidoscope-FocusSerial.h"
#include "Kaleidoscope-Macros.h"
#include "Kaleidoscope-MouseKeys.h"
#include "Kaleidoscope-Qukeys.h"



#define MO(n) ShiftToLayer(n)
#define TG(n) LockLayer(n)

enum {
  MACRO_QWERTY,
  MACRO_VERSION_INFO,
  MACRO_NUMOUT
};

#define Key_Exclamation LSHIFT(Key_1)
#define Key_At LSHIFT(Key_2)
#define Key_Hash LSHIFT(Key_3)
#define Key_Dollar LSHIFT(Key_4)
#define Key_Percent LSHIFT(Key_5)
#define Key_Caret LSHIFT(Key_6)
#define Key_And LSHIFT(Key_7)
#define Key_Star LSHIFT(Key_8)
#define Key_Plus LSHIFT(Key_Equals)

#define Key_Under LSHIFT(Key_Minus)
#define Key_DoubleQuote LSHIFT(Key_Quote)
#define Key_LeftAngle LSHIFT(Key_Comma)
#define Key_RightAngle LSHIFT(Key_Period)
#define Key_Pipe LSHIFT(Key_Backslash)
#define Key_Colon LSHIFT(Key_Semicolon)
enum {
  QWERTY,
  SYM,
  NUM,
  SPC,
  MOUSE
};

/* *INDENT-OFF* */
KEYMAPS(
  [QWERTY] = KEYMAP_STACKED
  (
    Key_Q,             Key_W,          Key_E,          Key_R,           Key_T,
    Key_A,             Key_S,          Key_D,          Key_F,           Key_G,
    Key_Z,             Key_X,          Key_C,          Key_V,           Key_B,          Key_LeftGui,
    Key_Esc,           Key_Tab,        Key_LeftShift,  Key_LeftAlt,     Key_Space,      Key_LeftControl

      ,                  Key_Y,          Key_U,         Key_I,           Key_O,       Key_P
      ,                  Key_H,          Key_J,         Key_K,           Key_L,       Key_Semicolon,
      Key_RightGui,     Key_N,          Key_M,         Key_Comma,       Key_Period,  Key_Slash,
      Key_RightControl,  Key_Backspace,  Key_RightAlt,  Key_RightShift,  Key_Quote,   Key_Enter
  ),

  [SYM] = KEYMAP_STACKED
  (
    Key_Under,      Key_Plus,        Key_LeftCurlyBracket,  Key_RightCurlyBracket,  Key_DoubleQuote,
    Key_Minus,      Key_Equals,      Key_LeftParen,         Key_RightParen,         Key_Quote,
    Key_LeftAngle,  Key_RightAngle,  Key_LeftBracket,       Key_RightBracket,       Key_Pipe,         Key_Caret,
    TG(SYM),        Key_Insert,      Key_LeftGui,           ___,                    ___,              ___

      ,                         Key_Home,                    Key_PageDown,              Key_PageUp,   Key_End,         Key_Backspace
      ,                         Key_LeftArrow,               Key_DownArrow,             Key_UpArrow,  Key_RightArrow,  ___,
      Consumer_PlaySlashPause,  Consumer_ScanPreviousTrack,  Consumer_ScanNextTrack,
          Consumer_Mute,        Consumer_VolumeDecrement,    Consumer_VolumeIncrement,
      ___,                      ___,                         ___,                       Key_Period,   Key_0,           Key_Equals
   ),


  [NUM] = KEYMAP_STACKED
  (
    Key_Insert,             Key_LeftParen,  Key_Star,     Key_And,          ___,
    Key_Delete,             Key_Caret,      Key_Percent,  Key_Dollar,       Key_PageDown,
    M(MACRO_VERSION_INFO),  Key_Hash,       Key_At,       Key_Exclamation,  ___,           ___,
    TG(NUM),                ___,            ___,          ___,              ___,           ___

        ,                 Key_Colon,   Key_7,  Key_8,      Key_9,       Key_Minus
        ,                 Key_Equals,  Key_4,  Key_5,      Key_6,       Key_Plus,
        M(MACRO_NUMOUT),  Key_Tab,     Key_1,  Key_2,      Key_3,       Key_Star,
        ___,              ___,         Key_0,  Key_Comma,  Key_Period,  Key_Slash
   ),

  [SPC] = KEYMAP_STACKED
  (
    Key_Insert,             Key_ScrollLock,  Key_PrintScreen,           Key_Insert,                  LALT(Key_Sysreq),
    Key_Delete,             ___,             Consumer_VolumeIncrement,  Consumer_ScanPreviousTrack,  Consumer_PlaySlashPause,
    M(MACRO_VERSION_INFO),  ___,             Consumer_VolumeDecrement,  Consumer_ScanNextTrack,      Consumer_Mute,            ___,
    TG(SPC),                ___,             ___,                       ___,                         ___,                      ___

      ,     Key_UpArrow,    Key_F7,  Key_F8,  Key_F9,  Key_F10
      ,     Key_DownArrow,  Key_F4,  Key_F5,  Key_F6,  Key_F11,
      ___,  XXX,            Key_F1,  Key_F2,  Key_F3,  Key_F12,
      ___,  ___,            ___,     ___,     ___,     ___
   ),

  [MOUSE] = KEYMAP_STACKED
  (
   ___,         Key_mouseBtnR,  Key_mouseBtnM,  Key_mouseBtnL,  ___,
   Key_mouseL,  Key_mouseUp,    Key_mouseDn,   Key_mouseR,      ___,
   ___,         ___,            ___,           ___,             ___,  Key_mouseScrollUp,
   TG(MOUSE),   ___,            ___,           ___,             ___,  Key_mouseScrollDn

      ,     Key_mouseBtnL,  Key_mouseWarpNW,  Key_mouseWarpN,   Key_mouseWarpNE,  ___
      ,     Key_mouseBtnM,  Key_mouseWarpW,   Key_mouseWarpIn,  Key_mouseWarpE,   ___,
      ___,  Key_mouseBtnR,  Key_mouseWarpSW,  Key_mouseWarpS,   Key_mouseWarpSE,  ___,
      ___,  ___,            ___,              ___,              ___,              Key_mouseWarpEnd
   )
)
/* *INDENT-ON* */

KALEIDOSCOPE_INIT_PLUGINS(
  EEPROMSettings,
  EEPROMKeymap,
  Focus,
  FocusEEPROMCommand,
  FocusSettingsCommand,
  Qukeys,
  Macros,
  MouseKeys
);

static void numoutMacro(uint8_t keyState) {
  Macros.play(MACRODOWN(T(Enter), Tr(UnlockLayer(NUM))));
}

const macro_t *macroAction(uint8_t macroIndex, uint8_t keyState) {
  switch (macroIndex) {
  case MACRO_QWERTY:
    // This macro is currently unused, but is kept around for compatibility
    // reasons. We used to use it in place of `MoveToLayer(QWERTY)`, but no
    // longer do. We keep it so that if someone still has the old layout with
    // the macro in EEPROM, it will keep working after a firmware update.
    Layer.move(QWERTY);
    break;
  case MACRO_VERSION_INFO:
    if (keyToggledOn(keyState)) {
      Macros.type(PSTR("Keyboardio Atreus - Kaleidoscope "));
      Macros.type(PSTR(BUILD_INFORMATION));
    }
    break;

  case MACRO_NUMOUT:
    numoutMacro(keyState);
    break;

  default:
    break;
  }

  return MACRO_NONE;
}

void setup() {
  QUKEYS(
    kaleidoscope::plugin::Qukey(0,  KeyAddr(2,  5),   Key_Backtick),         //`
    kaleidoscope::plugin::Qukey(0,  KeyAddr(2,  6),   Key_Backslash),        //\ -
    kaleidoscope::plugin::Qukey(0,  KeyAddr(1,  0),   ShiftToLayer(MOUSE)),  //a
    kaleidoscope::plugin::Qukey(0,  KeyAddr(1,  1),   ShiftToLayer(SPC)),    //s
    kaleidoscope::plugin::Qukey(0,  KeyAddr(1,  2),   ShiftToLayer(NUM)),    //d
    kaleidoscope::plugin::Qukey(0,  KeyAddr(1,  3),   ShiftToLayer(SYM)),    //f
    kaleidoscope::plugin::Qukey(0,  KeyAddr(1,  8),   ShiftToLayer(SYM)),    //j
    kaleidoscope::plugin::Qukey(0,  KeyAddr(1,  9),   ShiftToLayer(NUM)),    //k
    kaleidoscope::plugin::Qukey(0,  KeyAddr(1,  10),  ShiftToLayer(SPC)),    //l
    kaleidoscope::plugin::Qukey(0,  KeyAddr(1,  11),  ShiftToLayer(MOUSE)),  //;
    kaleidoscope::plugin::Qukey(0,  KeyAddr(3,  4),  Key_LeftShift),  // space
    kaleidoscope::plugin::Qukey(0,  KeyAddr(3,  7),  Key_RightShift),  // backspace
  )
  MouseKeys.setWarpGridSize(MOUSE_WARP_GRID_3X3);
  Kaleidoscope.setup();
  EEPROMKeymap.setup(10);
}

void loop() {
  Kaleidoscope.loop();
}

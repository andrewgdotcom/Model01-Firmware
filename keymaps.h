/** The Model 01's key layouts are defined as 'keymaps'. By default, there are three
  * keymaps: The standard QWERTY keymap, the "Function layer" keymap and the "Numpad"
  * keymap.
  *
  * Each keymap is defined as a list using the 'KEYMAP_STACKED' macro, built
  * of first the left hand's layout, followed by the right hand's layout.
  *
  * Keymaps typically consist mostly of `Key_` definitions. There are many, many keys
  * defined as part of the USB HID Keyboard specification. You can find the names
  * (if not yet the explanations) for all the standard `Key_` defintions offered by
  * Kaleidoscope in these files:
  *    https://github.com/keyboardio/Kaleidoscope/blob/master/src/key_defs_keyboard.h
  *    https://github.com/keyboardio/Kaleidoscope/blob/master/src/key_defs_consumerctl.h
  *    https://github.com/keyboardio/Kaleidoscope/blob/master/src/key_defs_sysctl.h
  *    https://github.com/keyboardio/Kaleidoscope/blob/master/src/key_defs_keymaps.h
  *
  * Additional things that should be documented here include
  *   using ___ to let keypresses fall through to the previously active layer
  *   using XXX to mark a keyswitch as 'blocked' on this layer
  *   using ShiftToLayer() and LockLayer() keys to change the active keymap.
  *   keeping NUM and FN consistent and accessible on all layers
  *
  * The PROG key is special, since it is how you indicate to the board that you
  * want to flash the firmware. However, it can be remapped to a regular key.
  * When the keyboard boots, it first looks to see whether the PROG key is held
  * down; if it is, it simply awaits further flashing instructions. If it is
  * not, it continues loading the rest of the firmware and the keyboard
  * functions normally, with whatever binding you have set to PROG. More detail
  * here: https://community.keyboard.io/t/how-the-prog-key-gets-you-into-the-bootloader/506/8
  *
  * The "keymaps" data structure is a list of the keymaps compiled into the firmware.
  * The order of keymaps in the list is important, as the ShiftToLayer(#) and LockLayer(#)
  * macros switch to key layers based on this list.
  *
  *

  * A key defined as 'ShiftToLayer(FUNCTION)' will switch to FUNCTION while held.
  * Similarly, a key defined as 'LockLayer(NUMPAD)' will switch to NUMPAD when tapped.
  */

/**
  * Layers are "0-indexed" -- That is the first one is layer 0. The second one is layer 1.
  * The third one is layer 2.
  * This 'enum' lets us use names like QWERTY, FUNCTION, and NUMPAD in place of
  * the numbers 0, 1 and 2.
  */

/*
 * The following options control the parameterized keymaps.
 * Enable and disable features by editing the include directives below.
 * Only one option of each group should be uncommented at any time.
 * Note that these work by defining aliases and so the order is important.
 */

/*
 * Choose arrangement of modifier keys in PRIMARY_KEYMAP_INTERNATIONAL
 */

//#include "modifiers-std.h"
#include "modifiers-thumb-enter.h"
//#include "modifiers-thumb-enter-bepo.h"
//#include "modifiers-altgr.h"
//#include "modifiers-japan.h"

/*
 * Choose the arrangement of the orphan keys in PRIMARY_KEYMAP_INTERNATIONAL
 * If you enable class4j, you should also enable "modifiers-japan.h" above.
 */

//#include "orphans-std.h"
#include "orphans-class1.h"
//#include "orphans-class2.h"
//#include "orphans-class3.h"
//#include "orphans-class4.h"
//#include "orphans-class4j.h"
//#include "orphans-class5.h"

/*
 * Choose mouse scrolling behaviour in FUNCTION_KEYMAP_INVERTED_T
 */

// Use traditional mouse scrolling
#define SCROLL_UP Key_mouseScrollUp
#define SCROLL_DOWN Key_mouseScrollDn

// Use "natural" mouse scrolling
//#define SCROLL_UP Key_mouseScrollDn
//#define SCROLL_DOWN Key_mouseScrollUp

/*
 * Define our layer names. These must match the layer structure below.
 */

enum { PRIMARY, NUMPAD, FUNCTION }; // layers


/**
  * To change your keyboard's layout from QWERTY to DVORAK or COLEMAK, comment out the line
  *
  * #define PRIMARY_KEYMAP_QWERTY
  *
  * by changing it to
  *
  * // #define PRIMARY_KEYMAP_QWERTY
  *
  * Then uncomment the line corresponding to the layout you want to use.
  *
  */

// #define PRIMARY_KEYMAP_QWERTY
// #define PRIMARY_KEYMAP_COLEMAK
// #define PRIMARY_KEYMAP_DVORAK
#define PRIMARY_KEYMAP_INTERNATIONAL
// #define PRIMARY_KEYMAP_CUSTOM

/**
  * Comment this line out to use upstream's numpad keymap.
  */
#define NUMPAD_KEYMAP_PROPER

/**
  * Comment this line out to use upstream's function keymap. Beware that some
  * combinations of primary and function keymaps do not contain PgUp and PgDn.
  */
#define FUNCTION_KEYMAP_INVERTED_T

/* This comment temporarily turns off astyle's indent enforcement
 *   so we can make the keymaps actually resemble the physical key layout better
 */
// *INDENT-OFF*

KEYMAPS(

#if defined (PRIMARY_KEYMAP_QWERTY)

// Upstream QWERTY
  [PRIMARY] = KEYMAP_STACKED
  (___,          Key_1, Key_2, Key_3, Key_4, Key_5, Key_LEDEffectNext,
   Key_Backtick, Key_Q, Key_W, Key_E, Key_R, Key_T, Key_Tab,
   Key_PageUp,   Key_A, Key_S, Key_D, Key_F, Key_G,
   Key_PageDown, Key_Z, Key_X, Key_C, Key_V, Key_B, Key_Escape,
   Key_LeftControl, Key_Backspace, Key_LeftGui, Key_LeftShift,
   ShiftToLayer(FUNCTION),

   M(MACRO_ANY),  Key_6, Key_7, Key_8,     Key_9,         Key_0,         LockLayer(NUMPAD),
   Key_Enter,     Key_Y, Key_U, Key_I,     Key_O,         Key_P,         Key_Equals,
                  Key_H, Key_J, Key_K,     Key_L,         Key_Semicolon, Key_Quote,
   Key_RightAlt,  Key_N, Key_M, Key_Comma, Key_Period,    Key_Slash,     Key_Minus,
   Key_RightShift, Key_LeftAlt, Key_Spacebar, Key_RightControl,
   ShiftToLayer(FUNCTION)),

#elif defined (PRIMARY_KEYMAP_DVORAK)

// Upstream Dvorak
  [PRIMARY] = KEYMAP_STACKED
  (___,          Key_1,         Key_2,     Key_3,      Key_4, Key_5, Key_LEDEffectNext,
   Key_Backtick, Key_Quote,     Key_Comma, Key_Period, Key_P, Key_Y, Key_Tab,
   Key_PageUp,   Key_A,         Key_O,     Key_E,      Key_U, Key_I,
   Key_PageDown, Key_Semicolon, Key_Q,     Key_J,      Key_K, Key_X, Key_Escape,
   Key_LeftControl, Key_Backspace, Key_LeftGui, Key_LeftShift,
   ShiftToLayer(FUNCTION),

   M(MACRO_ANY),   Key_6, Key_7, Key_8, Key_9, Key_0, LockLayer(NUMPAD),
   Key_Enter,      Key_F, Key_G, Key_C, Key_R, Key_L, Key_Slash,
                   Key_D, Key_H, Key_T, Key_N, Key_S, Key_Minus,
   Key_RightAlt,   Key_B, Key_M, Key_W, Key_V, Key_Z, Key_Equals,
   Key_RightShift, Key_LeftAlt, Key_Spacebar, Key_RightControl,
   ShiftToLayer(FUNCTION)),

#elif defined (PRIMARY_KEYMAP_COLEMAK)

// Upstream Colemak
  [PRIMARY] = KEYMAP_STACKED
  (___,          Key_1, Key_2, Key_3, Key_4, Key_5, Key_LEDEffectNext,
   Key_Backtick, Key_Q, Key_W, Key_F, Key_P, Key_G, Key_Tab,
   Key_PageUp,   Key_A, Key_R, Key_S, Key_T, Key_D,
   Key_PageDown, Key_Z, Key_X, Key_C, Key_V, Key_B, Key_Escape,
   Key_LeftControl, Key_Backspace, Key_LeftGui, Key_LeftShift,
   ShiftToLayer(FUNCTION),

   M(MACRO_ANY),  Key_6, Key_7, Key_8,     Key_9,         Key_0,         LockLayer(NUMPAD),
   Key_Enter,     Key_J, Key_L, Key_U,     Key_Y,         Key_Semicolon, Key_Equals,
                  Key_H, Key_N, Key_E,     Key_I,         Key_O,         Key_Quote,
   Key_RightAlt,  Key_K, Key_M, Key_Comma, Key_Period,    Key_Slash,     Key_Minus,
   Key_RightShift, Key_LeftAlt, Key_Spacebar, Key_RightControl,
   ShiftToLayer(FUNCTION)),

#elif defined (PRIMARY_KEYMAP_INTERNATIONAL)

  [PRIMARY] = KEYMAP_STACKED
  (LEFT_OF_1,     Key_1, Key_2, Key_3, Key_4, Key_5, RIGHT_OF_5,
   LEFT_OF_Q,     Key_Q, Key_W, Key_E, Key_R, Key_T, MOD_L_MIDDLE,
   LEFT_OF_A,     Key_A, Key_S, Key_D, Key_F, Key_G,
   LEFT_OF_Z,     Key_Z, Key_X, Key_C, Key_V, Key_B, MOD_L_BOTTOM,
   MOD_L_THUMB_0, MOD_L_THUMB_1, MOD_L_THUMB_2, MOD_L_THUMB_3,
   MOD_L_PALM,

   LEFT_OF_6,     Key_6, Key_7, Key_8,     Key_9,      Key_0,         RIGHT_OF_0,
   MOD_R_MIDDLE,  Key_Y, Key_U, Key_I,     Key_O,      Key_P,         RIGHT_OF_P,
                  Key_H, Key_J, Key_K,     Key_L,      Key_Semicolon, RIGHT_OF_SEMICOLON,
   MOD_BUTTERFLY, Key_N, Key_M, Key_Comma, Key_Period, Key_Slash,     RIGHT_OF_SLASH,
   MOD_R_THUMB_3, MOD_R_THUMB_2, MOD_R_THUMB_1, MOD_R_THUMB_0,
   MOD_R_PALM),

#elif defined (PRIMARY_KEYMAP_CUSTOM)

  // Edit this keymap to make a custom layout
  [PRIMARY] = KEYMAP_STACKED
  (___,          Key_1, Key_2, Key_3, Key_4, Key_5, Key_LEDEffectNext,
   Key_Backtick, Key_Q, Key_W, Key_E, Key_R, Key_T, Key_Tab,
   Key_PageUp,   Key_A, Key_S, Key_D, Key_F, Key_G,
   Key_PageDown, Key_Z, Key_X, Key_C, Key_V, Key_B, Key_Escape,
   Key_LeftControl, Key_Backspace, Key_LeftGui, Key_LeftShift,
   ShiftToLayer(FUNCTION),

   M(MACRO_ANY),  Key_6, Key_7, Key_8,     Key_9,         Key_0,         LockLayer(NUMPAD),
   Key_Enter,     Key_Y, Key_U, Key_I,     Key_O,         Key_P,         Key_Equals,
                  Key_H, Key_J, Key_K,     Key_L,         Key_Semicolon, Key_Quote,
   Key_RightAlt,  Key_N, Key_M, Key_Comma, Key_Period,    Key_Slash,     Key_Minus,
   Key_RightShift, Key_LeftAlt, Key_Spacebar, Key_RightControl,
   ShiftToLayer(FUNCTION)),

#else

#error "No default keymap defined. You should make sure that you have a line like '#define PRIMARY_KEYMAP_QWERTY' in your sketch"

#endif

#if defined (NUMPAD_KEYMAP_PROPER)

  [NUMPAD] = KEYMAP_STACKED
  (___,      ___, ___,           ___,           ___,            ___,        ___,
   Key_Tab,  ___, ___,           Key_UpArrow,   ___,            ___,        Key_PageUp,
   Key_Home, ___, Key_LeftArrow, Key_DownArrow, Key_RightArrow, ___,
   Key_End,  ___, ___,           ___,           ___,            Key_Insert, Key_PageDown,
   ___, ___, ___, ___,
   ___,

   M(MACRO_VERSION_INFO),  ___,                 Key_KeypadClear, Key_KeypadEquals,   Key_KeypadDivide,   Key_KeypadMultiply, ___,
   ___,                    Key_Space,           Key_Keypad7,     Key_Keypad8,        Key_Keypad9,        Key_KeypadSubtract, ___,
                           Key_Backspace,       Key_Keypad4,     Key_Keypad5,        Key_Keypad6,        Key_KeypadAdd,      ___,
   ___,                    Key_KeypadComma,     Key_Keypad1,     Key_Keypad2,        Key_Keypad3,        Key_KeypadEnter,    ___,
   Key_Keypad000, Key_Keypad00, Key_Keypad0, Key_KeypadDot,
   ___),

#else

// Upstream numpad keymap
  [NUMPAD] =  KEYMAP_STACKED
  (___, ___, ___, ___, ___, ___, ___,
   ___, ___, ___, ___, ___, ___, ___,
   ___, ___, ___, ___, ___, ___,
   ___, ___, ___, ___, ___, ___, ___,
   ___, ___, ___, ___,
   ___,

   M(MACRO_VERSION_INFO),  ___, Key_7, Key_8,      Key_9,              Key_KeypadSubtract, ___,
   ___,                    ___, Key_4, Key_5,      Key_6,              Key_KeypadAdd,      ___,
                           ___, Key_1, Key_2,      Key_3,              Key_Equals,         ___,
   ___,                    ___, Key_0, Key_Period, Key_KeypadMultiply, Key_KeypadDivide,   Key_Enter,
   ___, ___, ___, ___,
   ___),

#endif

#if defined (FUNCTION_KEYMAP_INVERTED_T)

  [FUNCTION] = KEYMAP_STACKED
  (Key_Backtick, Key_F1,           Key_F2,           Key_F3,         Key_F4,            Key_F5,           Key_LEDEffectNext,
   Key_Tab,      SCROLL_UP,        Key_mouseWarpNW,  Key_mouseUp,    Key_mouseWarpNE,   Key_mouseWarpEnd, Key_PageUp,
   Key_Home,     Key_mouseBtnL,    Key_mouseL,       Key_mouseDn,    Key_mouseR,        Key_mouseBtnR,
   Key_End,      SCROLL_DOWN,      Key_mouseWarpSW,  Key_mouseBtnM,  Key_mouseWarpSE,   Key_Insert,       Key_PageDown,
   ___, Key_Delete, ___, ___,
   ___,

   Consumer_ScanPreviousTrack, Key_F6,                 Key_F7,                   Key_F8,                   Key_F9,          Key_F10,   Key_F11,
   Consumer_PlaySlashPause,    Consumer_ScanNextTrack, Key_CapsLock,             Key_UpArrow,              Key_ScrollLock,  Key_Pause, Key_F12,
                               Key_PrintScreen,        Key_LeftArrow,            Key_DownArrow,            Key_RightArrow,  ___,       Key_PcApplication,
   ___,                        Consumer_Mute,          Consumer_VolumeDecrement, Consumer_VolumeIncrement, ___,             ___,       Key_Sysreq,
   ___, ___, Key_Enter, ___,
   ___)
// no trailing comma!

#else

// Upstream function keymap
  [FUNCTION] =  KEYMAP_STACKED
  (___,      Key_F1,           Key_F2,      Key_F3,     Key_F4,        Key_F5,           Key_CapsLock,
   Key_Tab,  ___,              Key_mouseUp, ___,        Key_mouseBtnR, Key_mouseWarpEnd, Key_mouseWarpNE,
   Key_Home, Key_mouseL,       Key_mouseDn, Key_mouseR, Key_mouseBtnL, Key_mouseWarpNW,
   Key_End,  Key_PrintScreen,  Key_Insert,  ___,        Key_mouseBtnM, Key_mouseWarpSW,  Key_mouseWarpSE,
   ___, Key_Delete, ___, ___,
   ___,

   Consumer_ScanPreviousTrack, Key_F6,                 Key_F7,                   Key_F8,                   Key_F9,          Key_F10,          Key_F11,
   Consumer_PlaySlashPause,    Consumer_ScanNextTrack, Key_LeftCurlyBracket,     Key_RightCurlyBracket,    Key_LeftBracket, Key_RightBracket, Key_F12,
                               Key_LeftArrow,          Key_DownArrow,            Key_UpArrow,              Key_RightArrow,  ___,              ___,
   Key_PcApplication,          Consumer_Mute,          Consumer_VolumeDecrement, Consumer_VolumeIncrement, ___,             Key_Backslash,    Key_Pipe,
   ___, ___, Key_Enter, ___,
   ___)
// no trailing comma!

#endif

) // KEYMAPS(

/* Re-enable astyle's indent enforcement */
// *INDENT-ON*

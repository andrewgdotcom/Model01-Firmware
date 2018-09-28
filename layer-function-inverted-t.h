// Define the ABG inverted-T function layer

/* This layer contains extra PgUp, PgDn and Num keys, so is recommended for use
 * in combination with the ABG multilingual base layer.
 *
 * In this layer, we move mouse keys to a homed, inverted-T position under the
 * left hand, and arrange warp keys in a square around them. The left mouse
 * button is under the left pinky, so it can be held down easily for drag and
 * drop; the other mouse buttons are located by analogy. Insert is therefore
 * displaced, and moves to Fn-B, close to Delete.
 *
 * Similarly, on the right hand we move the arrow keys to a homed inverted-T.
 * This displaces the magic RightCurlyBracket.
 */

/* This comment temporarily turns off astyle's indent enforcement
 *   so we can make the keymaps actually resemble the physical key layout better
 */
// *INDENT-OFF*

  [FUNCTION] = KEYMAP_STACKED
  (Key_Backtick, Key_F1,           Key_F2,           Key_F3,         Key_F4,            Key_F5,           Key_LEDEffectNext,
   Key_Tab,      SCROLL_UP,        Key_mouseWarpNW,  Key_mouseUp,    Key_mouseWarpNE,   Key_mouseWarpEnd, Key_PageUp,
   Key_Home,     Key_mouseBtnL,    Key_mouseL,       Key_mouseDn,    Key_mouseR,        Key_mouseBtnR,
   Key_End,      SCROLL_DOWN,      Key_mouseWarpSW,  Key_mouseBtnM,  Key_mouseWarpSE,   Key_Insert,       Key_PageDown,
   ___, Key_Delete, ___, ___,
   ___,

   Consumer_ScanPreviousTrack, Key_F6,                 Key_F7,                   Key_F8,                   Key_F9,          Key_F10,               Key_F11,
   Consumer_PlaySlashPause,    Consumer_ScanNextTrack, Key_LeftCurlyBracket,     Key_UpArrow,              Key_LeftBracket, Key_RightBracket,      Key_F12,
                               Key_PrintScreen,        Key_LeftArrow,            Key_DownArrow,            Key_RightArrow,  Key_RightCurlyBracket, ___,
   Key_PcApplication,          Consumer_Mute,          Consumer_VolumeDecrement, Consumer_VolumeIncrement, ___,             Key_Backslash,         Key_Pipe,
   ___, ___, Key_Enter, ___,
   ___)

// *INDENT-ON*

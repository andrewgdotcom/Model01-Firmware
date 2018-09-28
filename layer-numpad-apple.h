/* The numpad is moved to be properly homed under the right hand. Zero is moved
 * to the thumb as per Kinesis. The usual non-numeric keys are arranged around
 * the tenkey in an Apple standard layout. This should be broadly compatible.
 *
 * Extra arrow keys are provided in an inverted-T under the left hand. The non-
 * mouse keys from the left hand of layer-function-inverted-t are also duplicated.
 */

/* This comment temporarily turns off astyle's indent enforcement
 *   so we can make the keymaps actually resemble the physical key layout better
 */
// *INDENT-OFF*

  [NUMPAD] = KEYMAP_STACKED
  (___,      ___, ___,           ___,           ___,            ___,        ___,
   Key_Tab,  ___, ___,           Key_UpArrow,   ___,            ___,        Key_PageUp,
   Key_Home, ___, Key_LeftArrow, Key_DownArrow, Key_RightArrow, ___,
   Key_End,  ___, ___,           ___,           ___,            Key_Insert, Key_PageDown,
   ___, ___, ___, ___,
   ___,

   M(MACRO_VERSION_INFO),  ___,                 Key_KeypadClear, Key_KeypadEquals,   Key_KeypadDivide,   Key_KeypadMultiply, ___,
   ___,                    ___,                 Key_Keypad7,     Key_Keypad8,        Key_Keypad9,        Key_KeypadSubtract, ___,
                           Key_Backspace,       Key_Keypad4,     Key_Keypad5,        Key_Keypad6,        Key_KeypadAdd,      ___,
   ___,                    Key_KeypadComma,     Key_Keypad1,     Key_Keypad2,        Key_Keypad3,        Key_KeypadEnter,    ___,
   Key_Keypad000, Key_Keypad00, Key_Keypad0, Key_KeypadDot,
   ___)

// *INDENT-ON*

/*
 * Define modifier aliases. This allows us to configure the modifiers
 * independently from the rest of the keymap layout.
 *
 * This layout moves Command to the Butterfly key and arranges the Japanese
 * thumb keys Kana, Henkan and Muhenkan (somewhat arbitrarily) on the spare thumb keys.
 *
 * The thumb buttons are numbered starting from 0 at the upper-outside to 3 on
 * the lower-inside on each hand (mirror image).
 */

#define MOD_L_THUMB_0 Key_International5	// Muhenkan
#define MOD_L_THUMB_1 Key_Backspace
#define MOD_L_THUMB_2 Key_LeftShift
#define MOD_L_THUMB_3 Key_LeftControl
#define MOD_L_PALM    ShiftToLayer(FUNCTION)

#define MOD_L_MIDDLE  Key_Tab
#define MOD_L_BOTTOM  Key_Escape

#define MOD_R_THUMB_0 Key_International4	// Henkan
#define MOD_R_THUMB_1 Key_Spacebar
#define MOD_R_THUMB_2 Key_International2	// Kana
#define MOD_R_THUMB_3 Key_RightAlt
#define MOD_R_PALM    ShiftToLayer(FUNCTION)

#define MOD_R_MIDDLE  Key_Enter
#define MOD_BUTTERFLY Key_RightGui


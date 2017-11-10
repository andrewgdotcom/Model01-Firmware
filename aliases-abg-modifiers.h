/* Define modifier aliases. This allows us to configure the modifiers
 * independently from the rest of the keymap layout.
 *
 * This layout moves Shift to the inside of Cmd/Alt for easier use, and
 * rotates Cmd and Alt so that L/R-Alt are on the thumbs and Cmd is on the
 * butterfly key.
 *
 * The thumb buttons are numbered starting from 0 at the upper-outside to 3 on
 * the lower-inside on each hand (mirror image).
 */

#define MOD_L_THUMB_0 Key_LeftControl
#define MOD_L_THUMB_1 Key_Backspace
#define MOD_L_THUMB_2 Key_LeftShift
#define MOD_L_THUMB_3 Key_LeftAlt
#define MOD_L_PALM    FN_SHIFT

#define MOD_L_MIDDLE  Key_Tab
#define MOD_L_BOTTOM  Key_Escape

#define MOD_R_THUMB_0 Key_RightControl
#define MOD_R_THUMB_1 Key_Spacebar
#define MOD_R_THUMB_2 Key_RightShift
#define MOD_R_THUMB_3 Key_RightAlt
#define MOD_R_PALM    FN_SHIFT

#define MOD_R_MIDDLE  Key_Enter
#define MOD_BUTTERFLY Key_RightGui


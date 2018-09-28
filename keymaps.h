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
  *   the special nature of the PROG key
  *   keeping NUM and FN consistent and accessible on all layers
  *
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
 * Enable and disable optional features by editing the include directives below.
 * In general, only one option of each group should be enabled at any time.
 * Note that these work by defining aliases and so the order of inclusion is important.
 */


/*
 * Choose modifier key layout
 */

//#include "modifiers-std.h"
#include "modifiers-thumb-enter.h"
//#include "modifiers-altgr.h"
//#include "modifiers-japan.h"

/*
 * Choose mouse scrolling behaviour
 * Note: mouse scrolling is only enabled in "layer-function-inverted-t.h"
 */

// Use traditional mouse scrolling
#define SCROLL_UP Key_mouseScrollUp
#define SCROLL_DOWN Key_mouseScrollDn

// Use "natural" mouse scrolling
//#define SCROLL_UP Key_mouseScrollDn
//#define SCROLL_DOWN Key_mouseScrollUp

/*
 * Choose the arrangement of the orphan keys
 * These are referred to by the primary-paramaterized layer
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
 * Define our layer names. These must match the layer structure below.
 */

enum { PRIMARY, NUMPAD, FUNCTION }; // layers

/*
 * Enable and disable layers by editing the various include directives below.
 * Beware that the include directives MUST be on a line by themselves.
 */

const Key keymaps[][ROWS][COLS] PROGMEM = {
#include "layer-primary-parameterized.h"
,
#include "layer-numpad-apple.h"
,
#include "layer-function-inverted-t.h"
};

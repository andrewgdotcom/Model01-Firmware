ABG firmware variant layout
===========================

This repository contains alternative layer files that vary the default 
keyboardio firmware layout to make multilingual typing more intuitive and
fix a selection of annoyances.

While the modifications can be applied individually, it is recommended
that aliases-abg-orphans-* not be used without also enabling one of
the abg-function-* layers, so that `PgUp`, `PgDn`, `LED` and `Num`
remain accessible.

How to use
----------

Follow the instructions in the [README.md] file, but instead of cloning
`keyboardio/Model01-Firmware`, clone `andrewgdotcom/Model01-Firmware`.
Otherwise the steps are identical.

To enable/disable the modifications, edit the include directives in 
`keymaps.h`.

The Changes
===========

The Numpad Layer
----------------

### layer-std-numpad.h

* The stock firmware numpad layer is implemented

### layer-abg-numpad-apple.h

* Numpad is properly homed as per e.g. Kinesis and implements the standard Apple
	keypad layout for the non-numeric keys. It also fixes a bug where
	the keypad generated `Equals` (which varies with OS keymap) rather than
	the more invariant code `KP_Equals`, and also adds an extra `Backspace` key.

The Function Layer
------------------

### layer-std-function.h

* The stock firmware function layer is implemented

### layer-abg-function-minimal-changes.h

* Duplicate keys are created on the Fn layer to free up space on the base layer:

	* Page Up/Down keys are duplicated on Fn-Tab and Fn-Escape.
	* Num is duplicated on Fn-C15R2 (the middle rightmost key).
	* LED is duplicated on Fn-LED

### layer-abg-function-inverted-t.h

* Duplicate keys are created on the Fn layer to free up space on the base layer:

	* Page Up/Down keys are duplicated on Fn-Tab and Fn-Escape.
	* Num is duplicated on Fn-C15R3 (the bottom rightmost key).
		(The magic pipe key is moved to C13R3).
	* LED is duplicated on Fn-LED

* Arrow keys are homed as an inverted-T under "IJKL", rather than in `vi` format.
	* Right-curlybrace is moved to C14R2

* Mousekeys are properly homed as an inverted-T under the first three fingers.
	The warp buttons are arranged in a square around the inverted-T.
	Left-button is under the left pinky so that it can be held down easily
	for drag and drop while the inverted-T and warp buttons are operated by
	the first three fingers. Right and middle buttons are placed by analogy.
	Insert is displaced, and is relocated under "B" to be close to Delete.

* Mouse scroll keys are added - traditional or "natural" scrolling is 
	configurable by the `aliases-abg-scroll-wheel-*` include files.

The Base Layer
==============

The base layer is parameterized and controlled by the inclusion of a
set of alias files. Currently the two supported alias classes are
`orphans` and `modifiers`. One include file from each class must be
enabled.

Orphans
-------

Most computer keyboards are highly asymmetrical. A column-based
keyboard such as the Model01 realigns the most commonly-used keys in a
symmetrical arrangement. These keys are the digits `1, 2, ... 0` and
the keys below and slightly to one side of them (`1QAZ`, `2WSX`,
... `0P;/` on a US keyboard; the labels vary according to language).
The Model01 arranges these 40 keys in a roughly rectangular layout, but
with the columns shifted up and down slightly to match the different
lengths of each finger.

Because an asymmetrical key layout can never be exactly mapped onto a
symmetrical layout, there are around ten keys that produce either
accented letters or symbols (depending on your language settings) but
do not fit this rectangular pattern. These are the 'orphaned keys' and
no one treatment of them will satisfy all languages. This is because
the language keymaps were designed (separately) based on various
assumptions about physical key locations that the Model01 cannot meet
simultaneously. Therefore, some language layouts require different
compromises to be made than others.

The `orphans` files control the arrangement of orphaned keys across the
outside columns at the very left and right of the Model01, and on the
`LED` and `Any` keys in the top middle. Since most keyboard layouts
require more scancodes than the default firmware layout provides, the
`LED`, `PgUp` and `PgDn` keys must be moved to the function layer. See
"The Function Layer" above.

The orphan key arrangements supported here are designed using the 
principle of least surprise. This means that any changes from a
standard keyboard should present the minimum amount of confusion to a
user familiar with a standard keyboard layout (of whatever language).

Each language layout is grouped into a class of layouts based upon where
the square brackets are normally found on a standard keyboard.
Since these bracket keys are usually
paired, they are moved to either between `5` and `6` on the top row (if
paired side by side, classes 1, 2 and 3) or the two keys directly
below `Prog` on the left hand side (classes 4 and 5).

* Class 1: brackets on the first (number) row or no paired brackets
* Class 2: brackets on the second row (to the right of `UIOP`)
* Class 3: brackets on the third row (to the right of `JKL<something>`)
* Class 4: opening and closing brackets above and below each other, immediately to the left of `Enter`
	* Class 4j: as above, with extra keys for Japanese language support
* Class 5: square and curly brackets on separate keys, one pair on the
	second row as per class 2 and one on the third as per class 3

In all layouts other than `std` and `japan`, the non-US extra key that
is normally found beside left-shift is retained in the analogous
location at the bottom left. In `japan` there is no such key, and
the bottom left position is used instead for `Yen`.

The remaining orphans are rearranged to keep them as close as
possible to their standard locations, but in almost all cases at least
one key must move from the top right to the far left due to symmetry
constraints.

### aliases-std-orphans.h

The stock firmware layout is implemented. This is the only orphans
option that works with the `layer-std-function.h` function layer. It is
recommended for use only with US-ASCII layouts.

### aliases-abg-orphans-merlin2.h

For class 1 language keymaps, e.g. Dvorak, AZERTY, QWERTZ, and those
QWERTY languages that normally have letters but no brackets on the keys
to the right of `UIOP` and `JKL<something>` (e.g. Canadian, Italian, Nordic).
This layout moves the two keys to the right of `0` (brackets in some
keymaps) to the keys between `5` and `6` (labelled `LED`, `Any`).
The key immediately above right-shift is swapped to the left hand,
on the same row.

This layout should also be usable (but not optimized) for class 2
language keymaps.

### aliases-abg-orphans-ngetal2.h

For class 2 language keymaps, such as Colemak, and those QWERTY
languages (US, Dutch, programmer Polish) that normally have square
brackets on the two keys to the right of `P`. This layout moves the
square brackets to the keys between `5` and `6`.
The key immediately above right-shift is swapped to the left hand,
on the same row.

### aliases-abg-orphans-latam.h

For class 3 language keymaps, such as Latin American Spanish, which have
square brackets on the two keys to the right of `JKL<something>`. This
layout moves the square brackets to the keys between `5` and `6`.
The key immediately to the left of `Backspace` is swapped to the left
hand.

### aliases-abg-orphans-brazil.h

For class 4 language keymaps, such as Brazilian Portugese, which have
square brackets on the two keys to the left of `Enter`, above and below.
This layout moves the square brackets to the two
keys directly below `Prog`, and backtick goes to the right of `5`.

### aliases-abg-orphans-japan.h

Brackets treated as per `brazil`, but also supports the Japanese keys
`Ro` and `Yen` at the expense of
moving backtick (used as `Zenkaku/Hankaku`) into the function layer.
The key `Yen` moves to the bottom left corner.
The two keys between `0` and `Yen` go to between `5` and `6`.

This option should be used in conjuction with the `japan` modifiers
option (see below).

### aliases-abg-orphans-merlin3.h

For class 5 language keymaps, such as European Spanish and Swiss
German/French, which have square and curly brackets separated on the
four keys to the left of `Enter`. This layout moves the opening brackets to
the keys below `Prog` and leaves the closing brackets on the keys below
`Num`. Backtick goes to the right of `5`.

### Obsolete keymaps

The following keymaps are no longer recommended, as they require the
`Num` key to be moved to the function layer. They are still usable, so
long as one of the nonstandard function layers above is enabled.

#### aliases-abg-orphans-abg.h

The original ABG/Celtic international layout for class 1 and 2 keymaps.
This is the same as `merlin2`, except that the top-right keys go to
`Any` and `Num` instead of `LED` and `Any`.

#### aliases-abg-orphans-spanish.h

For class 5 keymaps. This is similar to `orphans-abg` except that the
Spanish closing bracket keys are located on the top right and bottom
right corner keys. The key to the left of `Backspace` is swapped to the
left hand.

Modifiers
---------

The `modifiers` files control the arrangement of keys that do not
normally generate letters, numbers or symbols.

On a standard keyboard these are the spacebar, the keys on either side
of the spacebar, and the keys at the very left and right edges of the
main block of letters, numbers and symbols.

On the Model01, these are the two palm keys, the eight thumb keys, and
the bottom two keys in the extra columns in the middle.
The arrangement of these keys is largely a matter of personal taste,
although there are a few obvious choices such as placing the space
key under one of the thumbs. A small number of reasonable alternatives
are maintained here.

### aliases-std-modifiers.h

* The stock firmware layout is implemented

### aliases-abg-modifiers.h

* The thumb buttons and butterfly key are rearranged:

	* Butterfly is now Command/GUI
	* Command/GUI and Alt (L/R THUMB_2) become the Shift keys
	* The Shift keys (L/R THUMB_3) become Left-Alt and Right-Alt (=AltGr)
		This better facilitates touch-typing with AltGr

### aliases-abg-modifiers-thumb-enter.h

* As above, but right THUMB_2 is now Enter/Return, and Del is mapped
	where Enter was.

### aliases-abg-modifiers-japan.h

* As `abg-modifiers` above, but the Japanese input keys `Kana`,
	`Henkan` and `Muhenkan` are placed under the thumbs, at the expense of
	only having one key each for `Shift`, `Control` and `Alt`.

The layer definitions
=====================

Base layer with orphans-merlin2 and modifiers-abg (US-international)
-------------------------------------------------------------------

```
Prg 1!  2@  3#  4$  5%  -_     =+  6^  7&  8*  9(  0)  Num
`~  Q   W   E   R   T   Tab    Ret Y   U   I   O   P   [{
\|  A   S   D   F   G              H   J   K   L   ;:  '"
<>  Z   X   C   V   B   Esc    Cmd N   M   ,<  .>  /?  ]}
            Ctl Bs  Sh  Alt    Alt Sh  Sp  Ctl
```

ABG Numpad Apple
----------------

```
___ ___ ___ ___ ___ ___ ___    VER ___ Clr =   /   *   ___
Tab ___ ___ Up  ___ ___ PUp    ___ ___ 7   8   9   -   ___
Hom ___ Le  Dn  Ri  ___            Bs  4   5   6   +   ___
End ___ ___ ___ ___ Ins PDn    ___ ___ 1   2   3   Ent ___
            ___ ___ ___ ___    ___ ___ 0   .
```

ABG Function Inverted-T
-----------------------

```
___ F1  F2  F3  F4  F5  LED    Pre F6  F7  F8  F9  F10 F11
Tab ScU MNW MUp MNE MWE PUp    Pla Nxt {   Up  [   ]   F12
Hom LBu MLe MDn MRi RBu            PSc Le  Dn  Ri  }   ___
End ScD MSW MBu MSE Ins PDn    App Mut V+  V-  |   \   Num
            ___ Del ___ ___    ___ ___ Ret ___
```

ABG Function Minimal Changes
----------------------------

```
___ F1  F2  F3  F4  F5  LED    Pre F6  F7  F8  F9  F10 F11
Tab ___ MUp PUp RBu MWE MNE    Pla Nxt {   }   [   ]   F12
Hom MLe MDn MRi LBu MNW            Le  Dn  Up  Ri  ___ Num
End PSc Ins PDn MBu MSW MSE    App Mut V+  V-  ___ \   |
            ___ Del ___ ___    ___ ___ Ret ___
```


Extended Model01 firmware variant keymaps
=========================================

This repository contains alternative layer files that vary the default
keyboardio firmware keymap to make multilingual typing more intuitive and
fix a selection of annoyances.

While the modifications can be mixed and matched, it is recommended that
`layer-function-std.h` should only be used if `orphans-std.h` is enabled,
otherwise the keys `PgUp`, `PgDn` and `LED` may become inaccessible.

Terminology
-----------

When talking about computer keyboards, the word "layout" can mean either the
physical location of the key switches on the keyboard itself, the arrangement
of the printed keycaps attached to the key switches, the mapping of the switches
to PS/2 or USB scancodes, the mapping of those scancodes to OS-level keypress
events, or various combinations of the above. For the avoidance of confusion,
in this document we will use the following convention:

* "geometry" means the precise physical arrangement of key switches at the
    hardware level
* "(firmware) keymap" means the mapping of these key switches to USB scancodes
    at the firmware level - it is at this level that the Model01 pretends to
    be a standard keyboard, and so where most of its constraints are found
* "OS layout" or "software layout" means the mapping of the USB scancodes to
    software-level keypress events - this mapping (also confusingly called a
    "keymap" in Linux) is beyond the scope of the Model01 firmware.
* "layout" (without qualification) means a combination of the above, or the
    overall user experience of typing

Rationale
---------

Due to the constraints of the USB protocol, a keyboard does not generate
human-readable keypresses ("Capital A, small n, small d, etc.") directly, but
rather a sequence of low-level keyswitch reports along the lines of "first
row second column key down, first row second column key up, second row fourth
column key down, etc.". These are only meaningful after translation through a
software-level OS layout. Because of this, even a programmable keyboard like
the Model01 cannot generate arbitrary key events (accents, foreign scripts,
mathematical symbols) and have them understood by software - its firmware can
only generate the (much fewer) USB scancodes, and therefore only make the
software understand those key events that are allowed by the operating system's
currently-active (and language-dependent) software layout.

While it is possible to use the Model01's firmware to perform a one-to-one
rearrangement of supported keys (e.g. converting a QWERTY layout to a Colemak
or Dvorak layout) without making any changes at the OS level, this does not
help with language switching, because different language layouts must support
a different selection of accented characters, scripts etc. So for language
shifting, the OS must usually also be reconfigured.

So if we have no choice but to use software to switch languages, can we find a
firmware keymap for the Model01 that supports multiple languages simultaneously?
The stock firmware keymap does not, but can be made to do so with a few minor
modifications.

How to use
----------

Follow the instructions in the [README.md](README.md) file, but instead of cloning
`keyboardio/Model01-Firmware`, clone `andrewgdotcom/Model01-Firmware`.
Otherwise the steps are identical.

To manage the firmware keymap variants, edit the include directives in
`keymaps.h`. At the bottom of this file is the keymap definition, which by
default contains three include directives that load the parameterized primary
layer, the inverted-t function layer, and the Apple-compatible numpad layer.
Include files matching the stock firmware layers are also provided, and these
can be mixed and matched (with some caveats, see below).

Above the keymap definition are a series of alias files that control the
parameterized primary layer by redefining a small number of variable key
definitions. These control the arrangement of USB scancodes across two classes
of physical keys - "orphan keys" that usually generate printable characters and
are operated mostly by the little fingers, and modifier keys that are operated
mostly by the thumbs (these also include Return, Space, Backspace and Delete).

```
___ ___ ___ ___ ___ ___ ORP    ORP ___ ___ ___ ___ ___ ___
ORP ___ ___ ___ ___ ___ MOD    MOD ___ ___ ___ ___ ___ ORP
ORP ___ ___ ___ ___ ___            ___ ___ ___ ___ ___ ORP
ORP ___ ___ ___ ___ ___ MOD    MOD ___ ___ ___ ___ ___ ORP
            MOD MOD MOD MOD    MOD MOD MOD MOD
```

The orphan keys and modifier keys are treated separately because orphan key
definitions are usually language-limited, whereas modifier keys are a personal
taste. A library of orphan and modifier definition files is provided, and one
of each should be included in the keymaps.h file if using the parameterized
primary layout.


The Numpad Layer
================

### layer-numpad-std.h

* The stock firmware numpad layer is implemented

### layer-numpad-apple.h

* Numpad is properly homed as per e.g. Kinesis and implements the standard Apple
	keypad layout for the non-numeric keys. It also fixes a bug where
	the keypad generated `Equals` (which varies with OS keymap) rather than
	the more invariant code `KP_Equals`, and also adds an extra `Backspace` key.

```
___ ___ ___ ___ ___ ___ ___    VER ___ Clr =   /   *   ___
Tab ___ ___ Up  ___ ___ PUp    ___ ___ 7   8   9   -   ___
Hom ___ Le  Dn  Ri  ___            Bs  4   5   6   +   ___
End ___ ___ ___ ___ Ins PDn    ___ ___ 1   2   3   Ent ___
            ___ ___ ___ ___    ___ ___ 0   .
```

The Function Layer
==================

### layer-function-std.h

* The stock firmware function layer is implemented

### layer-function-with-duplicates.h

* Duplicate keys are created on the Fn layer to free up space on the base layer:

    * Page Up/Down keys are duplicated on Fn-E and Fn-C.
    * LED is duplicated on Fn-LED
    * Backtick (Zenkaku/Hankaku) is duplicated on Fn-Prog

```
`~  F1  F2  F3  F4  F5  LED    Pre F6  F7  F8  F9  F10 F11
Tab ___ MUp PUp RBu MWE MNE    Pla Nxt {   }   [   ]   F12
Hom MLe MDn MRi LBu MNW            Le  Dn  Up  Ri  ___ ___
End PSc Ins PDn MBu MSW MSE    App Mut V+  V-  ___ \   |
            ___ Del ___ ___    ___ ___ Ret ___
```

### layer-function-inverted-t.h

* Duplicate keys are created on the Fn layer to free up space on the base layer:

    * Page Up/Down keys are duplicated on Fn-Tab and Fn-Escape.
    * LED is duplicated on Fn-LED
    * Backtick (Zenkaku/Hankaku) is duplicated on Fn-Prog

* Arrow keys are homed as an inverted-T under "IJKL", rather than in `vi` format.
    * Magic symbol keys are no longer required, so we repurpose them.
    * CapsLock is under "U" (for "uppercase")
    * ScrollLock is under "O", Pause under "P" and SysRq under "="

* Mousekeys are properly homed as an inverted-T under "ESDF".
    * The warp buttons are arranged in a square around the inverted-T ("WRXV").
    * Left-button is under "A" for ease of dragging with the mousekeys.
    * Right and middle buttons are placed by analogy on "C" and "G".
    * Insert is displaced, and is relocated under "B" to be close to Delete.
    * PrintScreen is displaced, and relocated under "H"

* Mouse scroll keys under "Q" and "Z" - traditional or "natural" scrolling is
	configurable by defining the macros SCROLL_UP and SCROLL_DOWN in keymaps.h.

```
`~  F1  F2  F3  F4  F5  LED    Pre F6  F7  F8  F9  F10 F11
Tab ScU MNW MUp MNE MWE PUp    Pla Nxt CLk Up  SLk Pse F12
Hom LBu MLe MDn MRi RBu            PSc Le  Dn  Ri  ___ ___
End ScD MSW MBu MSE Ins PDn    App Mut V+  V-  ___ ___ Sys
            ___ Del ___ ___    ___ ___ Ret ___
```

The Primary Layer
=================

The primary layer is parameterized and controlled by the inclusion of a
set of alias files. Currently the two supported alias classes are
`orphans` and `modifiers`. One include file from each class must be
enabled.

Orphans
-------

Most computer keyboards are highly asymmetrical. A column-based
keyboard such as the Model01 realigns the most commonly-used keys in a
symmetrical geometry. These keys are the digits `1, 2, ... 0` and
the keys below and slightly to one side of them (`1QAZ`, `2WSX`,
... `0P;/` on a US keyboard; the labels vary according to language).
The Model01 arranges these 40 keys in a roughly rectangular geometry, but
with the columns shifted up and down slightly to match the different
lengths of each finger.

Because an asymmetrical key geometry can never be exactly mapped onto a
symmetrical geometry, there are around ten keys that produce either
accented letters or symbols (depending on your language settings) but
do not fit this rectangular pattern. These are the 'orphaned keys' and
no one treatment of them will satisfy all languages. This is because the
industry-standard language layouts were designed (separately) based on various
assumptions about physical key geometry that the Model01 cannot meet
simultaneously. Therefore, some languages require different compromises to be
made than others.

The `orphans` files control the arrangement of orphaned keys across the
outside columns at the very left and right of the Model01, and on the
`LED` and `Any` keys in the top middle. Since most OS keyboard layouts
require more scancodes than the default firmware keymap provides, at
least three keys must be moved to the function layer. See
"The Function Layer" above.

The orphan key arrangements supported here are designed using the
principle of least surprise. This means that any changes from a
standard keyboard should present the minimum amount of confusion to a
user familiar with a standard keyboard layout (of whatever language).

Each OS language layout is grouped into a class of firmware keymaps based
upon where the square brackets are normally found on a standard keyboard.
Since these bracket keys are usually
paired, they are moved to either between `5` and `6` on the top row (if
paired side by side, classes 1, 2 and 3) or the two keys directly
below `Prog` on the left hand side (classes 4 and 5).

* Class 1: brackets on the first (number) row or no paired brackets
	(Dvorak, AZERTY, BÉPO, QWERTZ, Canadian Multilingual, Italian alternative, Nordic, Turkish Q/F)
* Class 2: brackets on the second row, to the right of `UIOP`
	(English QWERTY, Colemak, Dutch, Italian, programmer Polish)
* Class 3: brackets on the third row, to the right of `JKL<something>`
	(Latin American Spanish)
* Class 4: opening and closing brackets above and below each other, immediately to the left of `Enter`
	(Brazilian Portugese)
	* Class 4j: as above, with extra keys for Japanese language support
* Class 5: square and curly brackets on separate keys, one pair on the
	second row as per class 2 and one on the third as per class 3
	(European Spanish, Swiss French/German, Canadian French)

In all firmware keymaps other than `std` and `class4j`, the non-US extra key
that is normally found beside left-shift is retained in the analogous
location at the bottom left. In `class4j` there is no such key, and
the bottom left position is used instead for `Yen`.

The remaining orphans are rearranged to keep them as close as
possible to their standard locations, but in almost all cases at least
one key must move from the top right to the far left due to geometry
constraints.

### orphans-std.h

The stock firmware keymap is implemented. This is the only orphans option that
works with the `layer-function-std.h` function layer. It is recommended for
use only with the US-ASCII OS layout, as it does not have a non-US backslash
key (the "international key" normally to the right of left-shift).

### orphans-class1.h

For class 1 language layouts, e.g. Dvorak, AZERTY, BÉPO, QWERTZ, Turkish F, and
those QWERTY language layouts that normally have letters but no brackets on the
keys to the right of `UIOP` and `JKL<something>` (e.g. Canadian CSA
Multilingual, Italian, Nordic, Turkish Q).
This firmware keymap moves the two keys to the right of `0` (brackets in some
keymaps) to the keys between `5` and `6` (labelled `LED`, `Any`).
The key immediately above right-shift is swapped to the left hand,
on the same row.

#### Behaviour under an AZERTY OS layout, with modifiers-altgr:

```
Prg &1  é2  '3  "4{ (5[ )°]    =+} -6  è7  _8  ç9  à0  Num
`~  '"  ,<  .>  P   Y   Tab    Ret F   G   C   R   L   /?
\|  A   O   E   U   I              D   H   T   N   S   -_
<>  ;:  Q   J   K   X   Esc    Cmd B   M   W   V   Z   =+
            Ctl Bs  Sh  Alt    Alt Sh  Sp  Ctl
```

#### Behaviour under a Dvorak OS layout, with modifiers-altgr:

```
Prg 1!  2@  3#  4$  5%  -_     =+  6^  7&  8*  9(  0)  Num
²   A   Z   E   R   T   Tab    Ret Y   U   I   O   P   ^¨
*µ  Q   S   D   F   G              H   J   K   L   M   ù%
<>  W   X   C   V   B   Esc    Cmd N   ,?  ;.  :/  !§  $£
            Ctl Bs  Sh  Alt    Alt Sh  Sp  Ctl
```

This class 1 firmware keymap should also be usable (but not optimized) for class 2
language keymaps. In this usage, the open and close bracket keys will be above
and below the home row respectively, in the rightmost column.

#### Behaviour under a US-international OS layout, with modifiers-altgr:

```
Prg 1!  2@  3#  4$  5%  -_     =+  6^  7&  8*  9(  0)  Num
`~  Q   W   E   R   T   Tab    Ret Y   U   I   O   P   [{
\|  A   S   D   F   G              H   J   K   L   ;:  '"
<>  Z   X   C   V   B   Esc    Cmd N   M   ,<  .>  /?  ]}
            Ctl Bs  Sh  Alt    Alt Sh  Sp  Ctl
```

### orphans-class2.h

For class 2 language keymaps, such as Colemak, and those QWERTY
layouts (English, Dutch, programmer Polish) that normally have square
brackets on the two keys to the right of `P`. This firmware keymap moves the
square brackets to the keys between `5` and `6`.
The key immediately above right-shift is swapped to the left hand,
on the same row.

#### Behaviour under a US-international OS layout, with modifiers-altgr:

```
Prg 1!  2@  3#  4$  5%  [{     }]  6^  7&  8*  9(  0)  Num
`~  Q   W   E   R   T   Tab    Ret Y   U   I   O   P   -_
\|  A   S   D   F   G              H   J   K   L   ;:  '"
<>  Z   X   C   V   B   Esc    Cmd N   M   ,<  .>  /?  =+
            Ctl Bs  Sh  Alt    Alt Sh  Sp  Ctl
```

### orphans-class3.h

For class 3 language keymaps, such as Latin American Spanish, which have
square brackets on the two keys to the right of `JKL<something>`. This
keymap moves the square brackets to the keys between `5` and `6`. The key
immediately below and to the left of `Backspace` is swapped to the left hand.

#### Behaviour under a Latin American OS layout, with modifiers-altgr:

```
Prg 1!  2"  3#  4$  5%  {[     ]}  6&  7/  8(  9)  0=  Num
|°  Q   W   E   R   T   Tab    Ret Y   U   I   O   P   ´¨
+*  A   S   D   F   G              H   J   K   L   ;:  '?
<>  Z   X   C   V   B   Esc    Cmd N   M   ,<  .>  /?  ¿¡
            Ctl Bs  Sh  Alt    Alt Sh  Sp  Ctl
```

### orphans-class4.h

For class 4 language keymaps, such as Brazilian Portugese, which have
square brackets on the two keys to the left of `Enter`, above and below.
This keymap moves the square brackets to the two keys directly below `Prog`,
and the top left key (backtick in US_ASCII) goes to the right of `5`.

#### Behaviour under a Brazilian Portugese OS layout, with modifiers-altgr:

```
Prg 1!  2@  3#  4$  5%  '"     -_  6¨  7&  8*  9(  0)  Num
[{  Q   W   E   R   T   Tab    Ret Y   U   I   O   P   ´`
}]  A   S   D   F   G              H   J   K   L   Ç   ~^
\|  Z   X   C   V   B   Esc    Cmd N   M   ,<  .>  /?  =+
            Ctl Bs  Sh  Alt    Alt Sh  Sp  Ctl
```

### orphans-class4j.h

Brackets treated as per `class4`, but also supports the Japanese keys
`Ro` and `Yen` at the expense of moving `Zenkaku/Hankaku` (backtick in US_ASCII)
into the function layer. The key `Yen` moves to the bottom left corner.
The two keys between `0` and `Yen` go to between `5` and `6`.

This option should be used in conjuction with the `japan` modifiers
option (see below).

#### Behaviour under a Japanese OS layout, with modifiers-japan:

```
Prg 1!  2?  3#  4$  5%  -=     ^¯  6&  7'  8(  9)  0~  Num
[{  Q   W   E   R   T   Tab    Ret Y   U   I   O   P   @`
}]  A   S   D   F   G              H   J   K   L   ;+  :*
¥|  Z   X   C   V   B   Esc    Cmd N   M   ,<  .>  /?  \_
            Ctl Bs  Sh  MuH    Alt Kna Sp  Hen
```

### orphans-class5.h

For class 5 language keymaps (e.g. European Spanish, Swiss German/French,
Canadian French), which have square and curly brackets separated on the four
keys to the left of `Enter`. This firmware keymap moves the opening brackets to
the keys below `Prog` and leaves the closing brackets on the keys below
`Num`. `ºª` (backtick in US_ASCII) goes to the right of `5`.

#### Behaviour under a European Spanish OS layout, with modifiers-altgr:

```
Prg 1!  2"  3·  4$  5%  ºª     '?  6&  7/  8(  9)  0=  Num
`^[ Q   W   E   R   T   Tab    Ret Y   U   I   O   P   +*]
´¨{ A   S   D   F   G              H   J   K   L   Ñ   Ç }
<>  Z   X   C   V   B   Esc    Cmd N   M   ,;  .:  -_  ¡¿
            Ctl Bs  Sh  Alt    Alt Sh  Sp  Ctl
```


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

### modifiers.h

* The stock firmware keymap is implemented

### modifiers-altgr.h

* Thumb and butterfly keys are permuted to make Shift+AltGr more comfortable:

	* Butterfly is now Command/GUI
	* Command/GUI and Alt (L/R THUMB_2) become the Shift keys
	* The Shift keys (L/R THUMB_3) become Left-Alt and Right-Alt (=AltGr)

### modifiers-thumb-enter.h

* As `modifiers-altgr` above, but right THUMB_2 is now Enter/Return, and Del is
    mapped to the left of H instead.

### modifiers-japan.h

* As `modifiers-altgr` above, but the Japanese input keys `Kana`,
	`Henkan` and `Muhenkan` are placed under the thumbs, at the expense of
	only having one key each for `Shift`, `Control` and `Alt`.


Contributors
============

* Andrew Gallagher (abg)
* Yoann Brosseau (celtic)
* Michael Richters (merlin)
* Imre Kószó (ngetal)

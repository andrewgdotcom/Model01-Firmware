ABG/Celtic firmware variant layout
==================================

This repository contains a small number of commits that vary the default 
keyboardio firmware layout to make multilingual typing more intuitive and
fix a selection of annoyances.

The commits are mostly atomic and can be applied individually, however the
base layer changes require that three keys be moved from the base layer to
the Fn layer, so failing to apply the Fn layer commits will result in loss of
functionality.

How to use
----------

Follow the instructions in the README.md file, but instead of cloning
`keyboardio/Model01-Firmware`, clone `andrewgdotcom/Model01-Firmware`.
Otherwise the steps are identical.

The Changes
===========

* Arrow keys are homed as an inverted-T under "IJKL", rather than in `vi` format.

* Numpad is properly homed as per e.g. Kinesis and implements the standard Apple
	keypad layout for the non-numeric keys. It also fixes a bug where
	the keypad generated Equals (which varies with OS keymap) rather than
	the more invariant code KP_Equals. It also adds an extra Backspace key.

* Mousekeys are properly homed as an inverted-T under the first three fingers.
	The warp buttons are arranged in a square around the inverted-T.
	Left-button is under the left pinky so that it can be held down easily
	for drag and drop while the inverted-T and warp buttons are operated by
	the first three fingers. Right and middle buttons are placed by analogy.
	Insert is displaced, and is relocated under "B" to be close to Delete.

* Duplicate keys are created on the Fn layer to free up space on the base layer:

	* Page Up/Down keys are duplicated on Fn-Tab and Fn-Escape.
	* Num is duplicated on Fn-C15R3 (the bottom rightmost key).
		The magic pipe key is moved to C13R3 (but isn't needed).

* The ABG/Celtic international layout is implemented:

	* Page Up/Down become "\|" and "<>" (the "international key")
	* Any and Num become "-_" and "=+"
	* "-_" and "=+" become "[{" and "]}"

* The thumb buttons and butterfly key are rearranged:

	* Butterfly is now Command/GUI
	* Command/GUI and Alt become the Shift keys
	* The old Shift keys become Left-Alt and Right-Alt (=AltGr)

Base layer
----------

```
Prg 1!  2@  3#  4$  5%  LED    -_  6^  7&  8*  9(  0)  =+
`~  Q   W   E   R   T   Tab    Ret Y   U   I   O   P   [{
\|  A   S   D   F   G              H   J   K   L   ;:  '"
<>  Z   X   C   V   B   Esc    Cmd N   M   ,<  .>  /?  ]}
            Ctl Bs  Sh  Alt    Alt Sh  Sp  Ctl
```

Fn layer
--------

```
___ F1  F2  F3  F4  F5  XXX    Pre F6  F7  F8  F9  F10 F11
Tab ___ MNW MUp MNE MWE PUp    Pla Nxt {   }   [   ]   F12
Hom LBu MLe MDn MRi RBu            ___ Le  Dn  Up  Ri  ___
End PSc MSW MBu MSE Ins PDn    App Mut V+  V-  |   \   Num
            ___ Del ___ ___    ___ ___ Ret  ___
```

Numpad layer
------------

```
                               VER ___ Clr =   /   *   ___
                               ___ ___ 7   8   9   -   ___
                                   Bs  4   5   6   +   ___
                               ___ ___ 1   2   3   Ent ___
                               ___ ___ 0   .
```


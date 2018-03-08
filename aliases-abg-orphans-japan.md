japan orphans
===============

`japan` is a firmware layout optimised for class 4j OS keymaps,
which have square and curly brackets on both the second row and home row,
and which have the extra keys Ro and Yen.

In clockwise order from the bottom left, the orphan keys are mapped
according to each of the class 4j keymaps:

Keymap	| L(Z)	| L(A)	| L(Q)	| R(5)	| L(6)	| R(P)	| R(;)	| R(/)
--------|-------|-------|-------|-------|-------|-------|-------|-------
ja_JP	|¥&#124;| ]}(Mu)| [{(°)	| -=(Ha)| ^~(He)| @`(")	| :*(Ke)| \_(Ro)

Orphan key locations
--------------------

The orphan keys are found in these physical locations on the Model01:

LH column 0	|...|LH column 6|RH column 7|...|RH column 15	
------------|---|-----------|-----------|---|--------------
PROG		|...|RIGHT_OF_5 | LEFT_OF_6	|...| NUM
LEFT_OF_Q	|...|...		|...		|...| RIGHT_OF_P
LEFT_OF_A	|...|...		|...		|...| RIGHT_OF_SEMICOLON
LEFT_OF_Z	|...|...		|...		|...| RIGHT_OF_SLASH

`RIGHT_OF_5` and `LEFT_OF_6` are labelled `LED` and `ANY` on the
default keycap set.

Note that these labels refer to the relative positions of the keys in a
US-QWERTY layout, but otherwise have no significance. These key labels
always refer to the same physical keys on the Model01, no matter which
language keymap is in use.

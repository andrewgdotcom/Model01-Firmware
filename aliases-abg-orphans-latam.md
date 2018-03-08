latam orphans
===============

`latam` is a firmware layout optimised for class 3 OS keymaps,
which have square and curly brackets on the home row.

In clockwise order from the bottom left, the orphan keys are mapped
according to each of the class 3 keymaps:

Keymap	| L(Z)	| L(A)	| L(Q)	| R(5)	| L(6)	| R(P)	| R(;)	| R(/)
--------|-------|-------|-------|-------|-------|-------|-------|-------
es_MX	| <>	| +*~	|&#124;°¬| {[^	| }]`	| ´¨	| ¿¡	| '?\

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

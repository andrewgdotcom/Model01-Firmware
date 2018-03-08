merlin2 orphans
===============

`merlin2` is a firmware layout optimised for class 1 OS keymaps,
which have square and curly brackets on the number row.

Class 1 keymaps often have accented letters on R(P) and R(;) that must
remain in the same relative locations for touch typists.

In clockwise order from the bottom left, the orphan keys are mapped
according to each of the class 1 keymaps:

Keymap	| L(Z)	| L(A)	| L(Q)	| R(5)	| L(6)	| R(P)	| R(;)	| R(/)
--------|-------|-------|-------|-------|-------|-------|-------|-------
fr_FR	| <>	| *µ	| ²		| )°]	| =+}	| ^¨	| ù%	| $£¤
fr_FR@bepo| èÈ	| çÇ	| $#	| =°	| %`	| zZ	| mM	| wW
de_DE	| <>	| #'	| ^°	| ß?\	| ´`	| üÜ	| äÄ	| +*~
en_US@dvorak| <>|\&#124;| `~	| [{	| ]}	| /?	| -_	| =+
it_IT@alt| <>	| ù§	|\&#124;| '?	| ì^	| èé	| à°`	| +*~
se_SE	|<>&#124;| '*	| §½	| +?\	| ´`	| åÅ	| äÄ	| ¨^~

`merlin2` is also usable with some class 2 OS keymaps, 
which have square and curly brackets on the first letter row.

Keymap	| L(Z)	| L(A)	| L(Q)	| R(5)	| L(6)	| R(P)	| R(;)	| R(/)
--------|-------|-------|-------|-------|-------|-------|-------|-------
en_US	| <>	|\&#124;| `~	| -_	| =+	| [{	| '"	| ]}
it_IT	| <>	| ù§	|\&#124;| '?	| ì^	| èé[{	| à°#	| +*]}

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

/*
 * Arrange orphaned keys according to ABG QWERTY/Dvorak/AZERTY optimization
 * With @merlin's 2nd suggestion, using LED as a printable instead of NUM
 */

/* Since this DOES NOT contain PgUp or PgDn keys, it is recommended to
 * use one of the ABG Fn layers so that PgUp and PgDn can be accessed.
 */

#define LEFT_OF_1               ___
#define RIGHT_OF_5		Key_Minus
#define LEFT_OF_Q		Key_Backtick
#define LEFT_OF_A		Key_Backslash
#define LEFT_OF_Z		Key_NonUsBackslashAndPipe

#define LEFT_OF_6		Key_Equals
#define RIGHT_OF_0		LockLayer(NUMPAD)
#define RIGHT_OF_P		Key_LeftBracket
#define RIGHT_OF_SEMICOLON 	Key_Quote
#define RIGHT_OF_SLASH		Key_RightBracket

/*
 * Arrange orphaned keys according to ABG Spanish language optimization
 * With @merlin's 2nd and 3rd proposals, to use LED instead of NUM as a
 * printable, and nest spanish brackets between C0/C15 on rows 1 and 2,
 */

/* Since this DOES NOT contain PgUp or PgDn keys, it is recommended to
 * use one of the alternative Fn layers so that PgUp and PgDn can be accessed.
 */

#define LEFT_OF_1               ___
#define LEFT_OF_Q               Key_LeftBracket
#define LEFT_OF_A               Key_Quote
#define LEFT_OF_Z               Key_NonUsBackslashAndPipe

#define RIGHT_OF_5              Key_Backtick
#define LEFT_OF_6               Key_Equals

#define RIGHT_OF_0              LockLayer(NUMPAD)
#define RIGHT_OF_P              Key_RightBracket
#define RIGHT_OF_SEMICOLON      Key_Backslash
#define RIGHT_OF_SLASH          Key_Minus

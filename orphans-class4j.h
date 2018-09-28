/*
 * Arrange orphaned keys according to ABG's class-4j (Japanese) proposal
 * With @merlin's 2nd suggestion, using LED as a printable instead of NUM
 */

/* Since this DOES NOT contain PgUp PgDn or Backtick keys, it is recommended to
 * use one of the alternative Fn layers so that PgUp, PgDn and Backtick
 * (Zenkaku/Hankaku) can be accessed.
 */

#define LEFT_OF_1               ___
#define LEFT_OF_Q               Key_RightBracket
#define LEFT_OF_A               Key_Backslash
#define LEFT_OF_Z               Key_International3	// Key_Yen

#define RIGHT_OF_5              Key_Minus
#define LEFT_OF_6               Key_Equals

#define RIGHT_OF_0              LockLayer(NUMPAD)
#define RIGHT_OF_P              Key_LeftBracket
#define RIGHT_OF_SEMICOLON      Key_Quote
#define RIGHT_OF_SLASH          Key_International1	// Key_Ro

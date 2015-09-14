
#ifndef _INCLUDE_ESCSEQUENCES_
#define _INCLUDE_ESCSEQUENCES_

#define ESC 0x1B

typedef enum {
	TEXT_DEFAULT   = 0,
	TEXT_BOLD      = 1,
	TEXT_UNDERLINE = 4,
	TEXT_FLIP      = 7
} tstyle;

typedef enum {
	COLOR_BLACK = 30,
    COLOR_RED,
    COLOR_GREEN,
    COLOR_YELLOW,
    COLOR_BLUE,
    COLOR_PURPLE,
    COLOR_LIGHTBLUE,
    COLOR_WHITE,
    COLOR_ORIGINAL = 39
} tcolor;

typedef enum {
    BGCOLOR_BLACK = 40,
    BGCOLOR_RED,
    BGCOLOR_GREEN,
    BGCOLOR_YELLOW,
    BGCOLOR_BLUE,
    BGCOLOR_PURPLE,
    BGCOLOR_LIGHTBLUE,
    BGCOLOR_WHITE,
    BGCOLOR_ORIGINAL = 49
} tbgcolor;

#endif

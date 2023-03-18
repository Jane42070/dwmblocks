/* macro for conveniently specifying pathu and pathc below */
#define PATH(name)                      "/home/qilin/Github/dwmblocks/blocks/" name

/* buffer size for capturing output of the programs used for updating blocks */
#define CMDOUTLENGTH                    50

/* buffer size for status text */
#define STATUSLENGTH                    256

/* DELIMITERENDCHAR must be less than 32.
 * At max, DELIMITERENDCHAR - 1 number of clickable blocks will be allowed.
 * Raw characters larger than DELIMITERENDCHAR and smaller than ' ' in ASCII
   character set can be used for signaling color change in status.
 * The character corresponding to DELIMITERENDCHAR + 1 ('\x0b' when
   DELIMITERENDCHAR is 10) will switch the active colorscheme to the first one
   defined in colors array in dwm's config.h and so on.
 * If you wish to change DELIMITERENDCHAR, don't forget to update its value in
   dwm.c and color codes in your pathu programs. */
#define DELIMITERENDCHAR                10

/* delimiter specified as an array of characters
 * don't remove DELIMITERENDCHAR at the end */
static const char delimiter[] = {' ', DELIMITERENDCHAR };

#include "block.h"

/* If interval of a block is set to 0, the block will only be updated once at
   startup.
 * If interval is set to a negative value, the block will never be updated in
   the main loop.
 * Set pathc to NULL if clickability is not required for the block.
 * Set signal to 0 if both clickability and signaling are not required for the
   block.
 * Signal must be less than DELIMITERENDCHAR for clickable blocks.
 * If multiple signals are pending, then the lowest numbered one will be
   delivered first. */

/* pathu - path of the program whose output is used as status text of the block
           (output of the program should be a single line of text with at most
            one newline character at the end)
 * pathc - path of the program used for handling clicks on the block */

/* 1 interval = INTERVALs seconds, INTERVALn nanoseconds */
#define INTERVALs                       1
#define INTERVALn                       0

static Block blocks[] = {
/*      pathu                        pathc    interval        signal */
		{ PATH("songs"),             PATH("songs"),        10,           2},
		{ PATH("weather"),           PATH("weather"),       0,           8},
        { PATH("packages"),          PATH("packages"),      0,           9},
		{ PATH("cpu"),               PATH("cpu"),           5,           3},
		{ PATH("meminfo"),           PATH("meminfo"),      10,           3},
        { PATH("disk"),              PATH("disk"),         10,           4},
        { PATH("sound"),             PATH("sound"),         0,           1},
        { PATH("battery"),           PATH("battery"),      30,           5},
        { PATH("calendar"),          PATH("calendar"),     60,           6},
		{ PATH("internet"),          PATH("internet"),      5,           7},
		{ PATH("wallpaper"),         PATH("wallpaper"),   600,           0},
        // { PATH("cpu_temp.sh"),          PATH("cpu_temp_button.sh"),     1,              4},
        { NULL } /* just to mark the end of the array */
};

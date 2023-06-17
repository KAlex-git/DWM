
/*
 * ~/.local/src/dwm-master/theme/gruvbox-dark.h
 *
 */
static char normfgcolor[]           = "#ebdbb2"; /* color unfocused font */
static char normbgcolor[]           = "#282828"; /* background color of bar */
static char normbordercolor[]       = "#282a38"; /* border color unfocused windows */

static char selfgcolor[]            = "#282a38"; // color focused font
static char selbordercolor[]        = "#b16286"; /* border color focused windows */
static char selbgcolor[]            = "#b16286"; /* color focused tags */

static char *colors[][3] = {
       /*               fg           bg           border   */
       [SchemeNorm] = { normfgcolor, normbgcolor, normbordercolor },
       [SchemeSel]  = { selfgcolor,  selbgcolor,  selbordercolor  },
};


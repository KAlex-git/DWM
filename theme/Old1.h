/*
 * ~/.local/src/dwm-master/theme/Old1.h
 *
 */
static char normfgcolor[]           = "#eeeeee"; /* color unfocused font */
static char normbgcolor[]           = "#000000"; /* background color of bar */
static char normbordercolor[]       = "#000000"; /* border color unfocused windows */

static char selfgcolor[]            = "#0b4199"; // color focused font
static char selbordercolor[]        = "#afff2f"; /* border color focused windows */
static char selbgcolor[]            = "#afff2f"; /* color focused tags */

static char *colors[][3] = {
       /*               fg           bg           border   */
       [SchemeNorm] = { normfgcolor, normbgcolor, normbordercolor },
       [SchemeSel]  = { selfgcolor,  selbgcolor,  selbordercolor  },
};


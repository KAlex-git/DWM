/*
 * ~/.local/src/dwm-master/theme/doom-one.h
 *
 */
static char normfgcolor[]           = "#cccccc"; /* color unfocused font */
static char normbgcolor[]           = "#1c1f24"; /* background color of bar */
static char normbordercolor[]       = "#282a34"; /* border color unfocused windows */

static char selfgcolor[]            = "#000000"; // color focused font
static char selbordercolor[]        = "#98be65"; /* border color focused windows */
static char selbgcolor[]            = "#c678dd"; /* color focused tags */

static char *colors[][3] = {
       /*               fg           bg           border   */
       [SchemeNorm] = { normfgcolor, normbgcolor, normbordercolor },
       [SchemeSel]  = { selfgcolor,  selbgcolor,  selbordercolor  },
};


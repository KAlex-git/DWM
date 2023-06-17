/*
 * ~/.local/src/dwm-master/theme/tomorrow-night.h
 *
 */
static char normfgcolor[]           = "#c5c8c6"; /* color unfocused font */
static char normbgcolor[]           = "#1d1f21"; /* background color of bar */
static char normbordercolor[]       = "#1d1f21"; /* border color unfocused windows */

static char selfgcolor[]            = "#000000"; // color focused font
static char selbordercolor[]        = "#b77ee0"; /* border color focused windows */
static char selbgcolor[]            = "#b77ee0"; /* color focused tags */

static char *colors[][3] = {
       /*               fg           bg           border   */
       [SchemeNorm] = { normfgcolor, normbgcolor, normbordercolor },
       [SchemeSel]  = { selfgcolor,  selbgcolor,  selbordercolor  },
};


/*
 * ~/.local/src/dwm-master/theme/palenight.h
 *
 */
static char normfgcolor[]           = "#d0d0d0"; /* color unfocused font */
static char normbgcolor[]           = "#292d3e"; /* background color of bar */
static char normbordercolor[]       = "#292d3e"; /* border color unfocused windows */

static char selfgcolor[]            = "#1c1f24"; // color focused font
static char selbordercolor[]        = "#c792ea"; /* border color focused windows */
static char selbgcolor[]            = "#c792ea"; /* color focused tags */

static char *colors[][3] = {
       /*               fg           bg           border   */
       [SchemeNorm] = { normfgcolor, normbgcolor, normbordercolor },
       [SchemeSel]  = { selfgcolor,  selbgcolor,  selbordercolor  },
};


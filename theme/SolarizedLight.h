/*
 * ~/.local/src/dwm-master/theme/solarized-dark.h
 *
 */
static char normfgcolor[]           = "#eee8d5"; /* color unfocused font */
static char normbgcolor[]           = "#002b36"; /* background color of bar */
static char normbordercolor[]       = "#002b36"; /* border color unfocused windows */

static char selfgcolor[]            = "#ffffff"; // color focused font
static char selbordercolor[]        = "#d33682"; /* border color focused windows */
static char selbgcolor[]            = "#d33682"; /* color focused tags */

static char *colors[][3] = {
       /*               fg           bg           border   */
       [SchemeNorm] = { normfgcolor, normbgcolor, normbordercolor },
       [SchemeSel]  = { selfgcolor,  selbgcolor,  selbordercolor  },
};


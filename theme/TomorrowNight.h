/*
 * ~/.local/src/dwm-master/theme/solarized-light.h
 *
 */
static char normfgcolor[]           = "#657b83"; /* color unfocused font */
static char normbgcolor[]           = "#fdf6e3"; /* background color of bar */
static char normbordercolor[]       = "#fdf6e3"; /* border color unfocused windows */

static char selfgcolor[]            = "#ffffff"; // color focused font
static char selbordercolor[]        = "#d33682"; /* border color focused windows */
static char selbgcolor[]            = "#d33682"; /* color focused tags */

static char *colors[][3] = {
       /*               fg           bg           border   */
       [SchemeNorm] = { normfgcolor, normbgcolor, normbordercolor },
       [SchemeSel]  = { selfgcolor,  selbgcolor,  selbordercolor  },
};

/*
 * ~/.local/src/dwm-master/theme/dracula.h
 *
 */
static char normfgcolor[]           = "#ff79c6"; /* color unfocused font */
static char normbgcolor[]           = "#282a36"; /* background color of bar */
static char normbordercolor[]       = "#282a36"; /* border color unfocused windows */

static char selfgcolor[]            = "#000000"; // color focused font
static char selbordercolor[]        = "#282a36"; /* border color focused windows */
static char selbgcolor[]            = "#ffb86c"; /* color focused tags */

static char *colors[][3] = {
       /*               fg           bg           border   */
       [SchemeNorm] = { normfgcolor, normbgcolor, normbordercolor },
       [SchemeSel]  = { selfgcolor,  selbgcolor,  selbordercolor  },
};


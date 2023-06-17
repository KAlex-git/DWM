/*
 * ~/.local/src/dwm-master/theme/oceanic-next.h
 *
 */
static char normfgcolor[]           = "#d8dee9"; /* color unfocused font */
static char normbgcolor[]           = "#1b2b34"; /* background color of bar */
static char normbordercolor[]       = "#1b2b34"; /* border color unfocused windows */

static char selfgcolor[]            = "#000000"; // color focused font
static char selbordercolor[]        = "#c594c5"; /* border color focused windows */
static char selbgcolor[]            = "#c594c5"; /* color focused tags */

static char *colors[][3] = {
       /*               fg           bg           border   */
       [SchemeNorm] = { normfgcolor, normbgcolor, normbordercolor },
       [SchemeSel]  = { selfgcolor,  selbgcolor,  selbordercolor  },
};


/*
 * ~/.local/src/dwm-master/theme/monokai-pro.h
 */
static char normfgcolor[]           = "#FCFCFA"; /* color unfocused font */
static char normbgcolor[]           = "#2D2A2E"; /* background color of bar */
static char normbordercolor[]       = "#2D2A2E"; /* border color unfocused windows */

static char selfgcolor[]            = "#000000"; // color focused font
static char selbordercolor[]        = "#AB9DF2"; /* border color focused windows */
static char selbgcolor[]            = "#AB9DF2"; /* color focused tags */

static char *colors[][3] = {
       /*               fg           bg           border   */
       [SchemeNorm] = { normfgcolor, normbgcolor, normbordercolor },
       [SchemeSel]  = { selfgcolor,  selbgcolor,  selbordercolor  },
};


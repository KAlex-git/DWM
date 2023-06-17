
/*
 * ~/.local/src/dwm-master/theme/nord.h
 *
 */
static char normfgcolor[]           = "#D8DEE9"; /* color unfocused font */
static char normbgcolor[]           = "#2E3440"; /* background color of bar */
static char normbordercolor[]       = "#2E3440"; /* border color unfocused windows */

static char selfgcolor[]            = "#000000"; // color focused font
static char selbordercolor[]        = "#B48EAD"; /* border color focused windows */
static char selbgcolor[]            = "#B48EAD"; /* color focused tags */

static char *colors[][3] = {
       /*               fg           bg           border   */
       [SchemeNorm] = { normfgcolor, normbgcolor, normbordercolor },
       [SchemeSel]  = { selfgcolor,  selbgcolor,  selbordercolor  },
};


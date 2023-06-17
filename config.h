/* See LICENSE file for copyright and license details. */


/* TODO themes */
#include "theme/Old1.h"



/* appearance */
static const unsigned int borderpx  = 3;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int systraypinning = 1;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray        = 1;     /* 0 means no systray */
static const unsigned int gappih    = 20;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 5;       /* vert inner gap between windows */
static const unsigned int gappoh    = 5;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 20;       /* vert outer gap between windows and screen edge */
static const int swallowfloating    = 0;        /* 1 means swallow floating windows by default */
static const int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 0;        /* 0 means bottom bar */
static const char *fonts[]          = { 
	"monospace:size=10",
	"kalexsTTF:style=Regular:pixelsize=18",
	"JoyPixels:pixelsize=14:antialias=true:autohint=true"  
};
static char dmenufont[]             = "monospace:size=10";


//static char normfgcolor[]           = "#bbbbbb";
//static char normbgcolor[]           = "#222222";
//static char normbordercolor[]       = "#444444";
//
//static char selfgcolor[]            = "#eeeeee";
//static char selbordercolor[]        = "#777000";
//static char selbgcolor[]            = "#005577";
//
//static char *colors[][3] = {
//       /*               fg           bg           border   */
//       [SchemeNorm] = { normfgcolor, normbgcolor, normbordercolor },
//       [SchemeSel]  = { selfgcolor,  selbgcolor,  selbordercolor  },
//};


typedef struct {
	const char *name;
	const void *cmd;
} Sp;
const char *spcmd1[] = {"st", "-n", "spterm", "-g", "120x34", NULL };
const char *spcmd2[] = {"st", "-n", "spcalc", "-f", "monospace:size=16", "-g", "50x20", "-e", "bc", "-lq", NULL };
const char *spcmd3[] = {"st", "-n", "spmusic", "-g", "120x34", "-e", "ncmpcpp", NULL };
const char *spcmd4[] = {"st", "-n", "spcdown", "-f", "roboto mono nerd font:pixelsize=27:antialias=true:autohint=true", "-g", "10x3", "-e", "countdown.sh", "5", NULL };
static Sp scratchpads[] = {
	/* name          cmd  */
	{"spterm",      spcmd1},
	{"spcalc",			spcmd2},
	{"spmusic",     spcmd3},
	{"spcdown",     spcmd4},
};

/* tagging               */
static const char *tags[] = {
	"1 ", // ws 0
	"2 ", // ws 1
	"3 ", // ws 2
	"3 ", // ws 3
	"4 ", // ws 4
	"5 ", // ws 5
	"6 ", // ws 6
	"7 ", // ws 7
	"8 ", // ws 8
	"9 "  // ws 9
};


static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   isterminal noswallow monitor */
	{ "Gimp",     NULL,       NULL,       1 << 8,       0,           0,         0,        -1 },
	{ "mpv",      "RADIO",    NULL,       1 << 9,       0,           0,         0,        -1 },
	{ "St",       NULL,       NULL,       0,            0,           1,         0,        -1 },
	{
		NULL,								// class
		"brave-browser",    // instance
		NULL,								// title
		1 << 1,						  // tag mask
		0,							    // isfloating
		1,							    // isterminal
		0,							    // noswallow
		-1									// monitor
	},
	{
		"Opera",				// class
		NULL,               // instance
		NULL,								// title
		1 << 1,						  // tag mask
		0,							    // isfloating
		1,							    // isterminal
		0,							    // noswallow
		-1									// monitor
	},
	{
		"LibreWolf",				// class
		NULL,               // instance
		NULL,								// title
		1 << 1,						  // tag mask
		0,							    // isfloating
		1,							    // isterminal
		0,							    // noswallow
		-1									// monitor
	},
	{ "zoom",     "zoom",       NULL,       1 << 7,            0,           1,         0,        -1 },
	{ "mytetra",     "mytetra",       NULL,       1 << 8,            0,           1,         0,        -1 },
	{ "wtlibrary.exe",     NULL,       NULL,       1 << 3,            0,           1,         0,        -1 },
	{ "TelegramDesktop",     NULL,       NULL,       1 << 5,            0,           1,         0,        -1 },
	{ NULL,       NULL,       "Event Tester", 0,        0,           0,         1,        -1 },
	{ NULL,      "spterm",    NULL,       SPTAG(0),     1,           1,         0,        -1 },
	{ NULL,      "spcalc",      NULL,       SPTAG(1),     1,           1,         0,        -1 },
	{ NULL,      "spmusic",    NULL,       SPTAG(2),     1,           1,         0,        -1 },
	{ NULL,      "spcdown",    NULL,       SPTAG(3),     1,           1,         0,        -1 },
	{ "mpv",      "xv",    "camera",       0,     1,           1,         0,        -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */

#include "vanitygaps.c"

static const Layout layouts[] = {
	/* symbol     arrange function */
 	{ "[]=",	tile },			/* Master on left, slaves on right */
 	{ "[M]",	monocle },		/* All windows on top of eachother */
	{ "TTT",	NULL },		/* Master on top, slaves on bottom [bstack] */
	{ "[\\]",	dwindle },		/* Decreasing in size right and leftward [dwindle] */
	{ "H[]",	NULL },			/* Master on left, slaves in monocle-like mode on right [deck] */
	{ "[@]",	NULL },		/* Fibonacci spiral [spiral] */
	{ "|M|",	centeredmaster },		/* Master in middle, slaves on sides */
	{ "[CF]",	centeredfloatingmaster },	/* Same but master floats */
	{ "[F]",	NULL },			/* no layout function means floating behavior */
	{ NULL,		NULL },
};


/* key definitions */
#define MODKEY Mod4Mask

#define TAGKEYS(KEY,TAG)												\
{1, {{MODKEY, KEY}},								view,           {.ui = 1 << TAG} },	\
{1, {{MODKEY|ControlMask, KEY}},					toggleview,     {.ui = 1 << TAG} }, \
{1, {{MODKEY|ShiftMask, KEY}},						tag,            {.ui = 1 << TAG} }, \
{1, {{MODKEY|ControlMask|ShiftMask, KEY}},			toggletag,      {.ui = 1 << TAG} },

#define STACKKEYS(MOD,ACTION) \
	{1, {{MOD,	XK_j}},	ACTION##stack,	{.i = INC(+1) } }, \
	{1, {{MOD,	XK_k}},	ACTION##stack,	{.i = INC(-1) } }, \


#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* Constants */
#define TERMINAL "st"
#define TERMCLASS "St"

#define TUTOR "st -T __Edit -e nvim ~/.config/nvim/lua/tutor.ru"
#define EDIT "st -T __Edit -e nvim "
#define BROWSER "notify-send -i '~/.local/share/icons/opera.png' ' ';$BROWSER"
#define SKE "st -T ' study' -e wt -s"
#define screencastPhone "notify-send '' ' '; scrcpy --lock-video-orientation"

/*
 * AlsaAudio
 * add config see: ~/.local/bin/statusbar/sb-volume
 */
// #define upvol		"amixer set Master 10+ ; kill -44 $(pidof dwmblocks)"
// #define downvol "amixer set Master 10- ; kill -44 $(pidof dwmblocks)"
#define upvol		"wpctl set-volume @DEFAULT_AUDIO_SINK@ 10%+; kill -44 $(pidof dwmblocks)"
#define downvol "wpctl set-volume @DEFAULT_AUDIO_SINK@ 10%-; kill -44 $(pidof dwmblocks)"
#define mutevol "wpctl set-mute @DEFAULT_AUDIO_SINK@ toggle; kill -44 $(pidof dwmblocks)"

#define MicPlus "amixer set 'Internal Mic Boost' 1+ ; kill -44 $(pidof dwmblocks)"
#define MicMinus "amixer set 'Internal Mic Boost' 1- ; kill -44 $(pidof dwmblocks)"



/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { 
	"dmrun",
	 "-m", dmenumon, 
	 "-fn", dmenufont, 
	 "-l", "5", 
	//"-nb", normbgcolor, // Фон не активнного бара
	//"-nf", normfgcolor, // Цвет не активного текста
	//"-sb", selbgcolor,  // Фон переднего плана
	//"-sf", selfgcolor, // определяет выбранный цвет переднего плана (font)
	NULL 
};
static const char *termcmd[]  = { "st", NULL };
static const char *LFUB[]  = { "st", "-T", "🗄️lfub", "-e", "lfub", NULL };

static const char *bookmedia[] = { 
	"bookmenu", "-p", ">>", "-l", "5", "-fn", "jetbrains mono-10", "-s", ":", "-b", "/home/kalex/.config/bookmenu/media", "-co", "open", NULL };
static const char *bookbrowser[] = { 
	"bookmenu", "-p", ">>", "-l", "5", "-fn", "jetbrains mono-10", "-s", ":", "-b", "/home/kalex/.config/bookmenu/browser", "-co", "opera", NULL };
static const char *bookconfigs[] = { 
	"bookmenu", "-p", ">>", "-l", "5",  "-fn", "jetbrains mono-10", "-s", ":", "-b", "/home/kalex/.config/bookmenu/configs", "-co", EDIT, NULL};

//
//
// static const char *volume[3][4] = {
// 	{"/bin/sh", "-c", "wpctl set-volume @DEFAULT_AUDIO_SINK@ 5%+; pkill -RTMIN+10 dwmblocks", NULL},
// 	{"/bin/sh", "-c", "wpctl set-volume @DEFAULT_AUDIO_SINK@ 5%-; pkill -RTMIN+10 dwmblocks", NULL},
// 	{"/bin/sh", "-c", "wpctl set-mute @DEFAULT_AUDIO_SINK@ toggle; pkill -RTMIN+10 dwmblocks", NULL},
// };
// 	{0,       			XF86XK_AudioRaiseVolume, 	spawn,   {.v= volume[0]}},
//  	{0,       			XF86XK_AudioLowerVolume, 	spawn,   {.v= volume[1]}},
//  	{0,       			XF86XK_AudioMute,        	spawn,   {.v= volume[2]}},
//static const char *addressbook[] = {TERMINAL, "-e", "abook", "-C", "~/.config/abook/abookrc", "--datafile", "~/.config/abook/addressbook", NULL};


//static const char *moveLeft[]  = { "xdo", "move", "-x", "-20",NULL };	   //Super+Shift+h
//static const char *moveDown[]  = { "xdo", "move", "-y", "+20",NULL };	   //Super+Shift+j
//static const char *moveUp[]	   = { "xdo", "move", "-y", "-20",NULL };	   //Super+Shift+k
//static const char *moveRight[] = { "xdo", "move", "-x", "+20",NULL };	   //Super+Shift+l
//
//static const char *growLeft[]    = { "xdo", "resize", "-w", "+20",NULL };  //Super+Control+h
//static const char *shrinkDown[]  = { "xdo", "resize", "-h", "-20",NULL };  //Super+Control+j
//static const char *growUp[]      = { "xdo", "resize", "-h", "+20",NULL };  //Super+Control+k
//static const char *shrinkRight[] = { "xdo", "resize", "-w", "-20",NULL };  //Super+Control+l



#include <X11/XF86keysym.h>
#include "shiftview.c"


static Keychord keychords[] = {
	/* modifier                     key        function        argument */
	STACKKEYS( MODKEY,                          focus)
	STACKKEYS( MODKEY|ShiftMask,											push)

	{1, {{MODKEY,							XK_t}},		setlayout,		{.v = &layouts[0]} }, // tile
	{1, {{MODKEY,							XK_i}},		setlayout,		{.v = &layouts[1]} }, // centeredmaster
	{1, {{MODKEY|ShiftMask,		XK_t}},		setlayout,		{.v = &layouts[6]} }, // monocle
	{1, {{MODKEY|ShiftMask,		XK_y}},		setlayout,		{.v = &layouts[3]} }, // dwindle
	{1, {{MODKEY|ShiftMask,		XK_i}},		setlayout,		{.v = &layouts[7]} }, // centeredfloatingmaster
	// {1, {{MODKEY|ShiftMask,		XK_t}},		setlayout,		{.v = &layouts[2]} },
	// {1, {{MODKEY,							XK_u}},		setlayout,		{.v = &layouts[4]} },
	// {1, {{MODKEY,							XK_y}},		setlayout,		{.v = &layouts[5]} },

	TAGKEYS(			XK_1,		0)
	TAGKEYS(			XK_2,		1)
	TAGKEYS(			XK_3,		2)
	TAGKEYS(			XK_4,		3)
	TAGKEYS(			XK_5,		4)
	TAGKEYS(			XK_6,		5)
	TAGKEYS(			XK_7,		6)
	TAGKEYS(			XK_8,		7)
	TAGKEYS(			XK_9,		8)

    /* Restart or quit dwm */
	{1, {{MODKEY|ShiftMask,		XK_q}},							quit,           {0} },
	{1, {{Mod1Mask,						XK_q}},							killclient,			{0} },
	{1, {{MODKEY,							XK_q}},		spawn,		SHCMD("kill_window") },

    // BROWSER ; Browser bookmarks and history
	{2, {{MODKEY,		XK_w},		{0, XK_a}},							spawn,		SHCMD("dm-bookman") },
	{2, {{MODKEY,		XK_w},		{0, XK_e}},							spawn,	{.v = (const char*[]){ "copylinkBrowser", NULL } } },
	{2, {{MODKEY,		XK_w},		{0, XK_n}},							spawn,		SHCMD("st -e sudo nmtui") },
	{2, {{MODKEY,		XK_w},		{0, XK_w}},							spawn,		SHCMD(BROWSER) },
		// Translate online;offline
	{2, {{Mod1Mask,		XK_t},		{0, XK_o}},							spawn,		SHCMD("transl-dict") },
	{2, {{Mod1Mask,		XK_t},		{0, XK_f}},							spawn,		SHCMD("transl-sdcv-rofi") },



	{1, {{MODKEY,											XK_d}},			spawn,    {.v = dmenucmd } },
	{1, {{MODKEY,							XK_BackSpace}},			spawn,		SHCMD("clearMemory_Update") },
	{1, {{Mod1Mask,						XK_BackSpace}},			spawn,		SHCMD("dmMenu") },

	{1, {{Mod1Mask,						XK_grave}},					spawn,		SHCMD("dmenuunicode") },
	{2, {{Mod1Mask,						XK_m},		{0,XK_m}},							spawn,		SHCMD("fixsocialweb") },
	{2, {{Mod1Mask,						XK_m},		{0,XK_n}},							spawn,		SHCMD("mounter") },

// BOOK
	{1, {{Mod1Mask,						XK_o}},  spawn,  {.v = bookconfigs }},   // Alt + o
	{1, {{Mod1Mask,						XK_b}},  spawn,  {.v = bookmedia   }},   // Alt + b
	{1, {{Mod1Mask,						XK_w}},  spawn,  {.v = bookbrowser }},   // Alt + w

// MAIL
//{ MODKEY,							XK_e,							spawn,		SHCMD("st -e neomutt ; pkill -RTMIN+12 dwmblocks; rmdir ~/.abook") },
//{ MODKEY,							XK_e,  spawn,  SHCMD(TERMINAL " -e neomutt ; pkill -RTMIN+12 dwmblocks; rmdir ~/.abook") },
//{ MODKEY|ShiftMask,		XK_e,							spawn,		SHCMD("st -e abook -C ~/.config/abook/abookrc --datafile ~/.config/abook/addressbook") },
//{ MODKEY|ShiftMask,		XK_e,  spawn,  {.v = addressbook }},   // Meta + Shift + e



	{2, {{Mod1Mask, XK_p},							{0, XK_a}},						spawn,  SHCMD("dm-alias")},
	{2, {{Mod1Mask, XK_p},							{0, XK_e}},						spawn,  SHCMD("electroFast")},
	{2, {{Mod1Mask, XK_p},							{0, XK_c}},						spawn,  SHCMD("dtos-colorscheme")},
	{2, {{Mod1Mask, XK_p},							{0, XK_h}},						spawn,  SHCMD("apps_man")},
	{2, {{Mod1Mask, XK_p},							{0, XK_k}},						spawn,  SHCMD("dm-kill")},
	{2, {{Mod1Mask, XK_p},							{0, XK_r}},						spawn,  SHCMD("dm-radio")},
	{2, {{Mod1Mask, XK_p},							{0, XK_s}},						spawn,  SHCMD("passmenu")},
	{2, {{Mod1Mask, XK_p},							{0, XK_u}},						spawn,  SHCMD(TUTOR)},
	{2, {{Mod1Mask, XK_p},							{0, XK_y}},						spawn,  SHCMD("st -e sb-popupgrade")},
	{2, {{Mod1Mask, XK_p},							{0, XK_p}},						spawn,  SHCMD("sh ~/Documents/MYSECRETDOC/fixcopiedPass.sh")},
	{2, {{Mod1Mask, XK_apostrophe},			{0, XK_apostrophe}},  spawn,  SHCMD("wt -w")},
	{2, {{Mod1Mask, XK_apostrophe},			{0, XK_i}},						spawn,  SHCMD("wt -i")},
	{2, {{Mod1Mask, XK_apostrophe},			{0, XK_s}},						spawn,  SHCMD(SKE)},


/*{{{ TODO Sound & Volume */
	{1, {{MODKEY,							XK_m}},							spawn,		SHCMD("st -e ncmpcpp") },
	{1, {{MODKEY,						XK_p}},							spawn,		SHCMD("mpc toggle") },
	{1, {{MODKEY|ShiftMask,		XK_p}},							spawn,		SHCMD("mpc pause ; pauseallmpv") },
	{1, {{MODKEY,							XK_bracketleft}},		spawn,		SHCMD(downvol)},
	{1, {{MODKEY,							XK_bracketright}},	spawn,		SHCMD(upvol)},
	{1, {{MODKEY,            XK_equal}},          spawn,		SHCMD(upvol)},   // Meta + +
	{1, {{MODKEY,							XK_minus}},					spawn,		SHCMD(downvol)},
	{1, {{MODKEY|ShiftMask,  XK_m}},              spawn,		SHCMD(mutevol)},   // Meta + Shift + m
	{1, {{MODKEY,							XK_comma}},					spawn,		SHCMD("mpc prev") },
	{1, {{MODKEY|ShiftMask,		XK_comma}},					spawn,		SHCMD("mpc seek 0%") },
	{1, {{MODKEY,							XK_period}},				spawn,		SHCMD("mpc next") },
	{1, {{MODKEY|ShiftMask,		XK_period}},				spawn,		SHCMD("mpc repeat") },

	{1, {{MODKEY|ControlMask,  XK_equal}},          spawn,		SHCMD(MicPlus)},   // Meta + +
	{1, {{MODKEY|ControlMask,  XK_minus}},          spawn,		SHCMD(MicMinus)},   // Meta + +

	{2, {{Mod1Mask,	XK_s}, {0, XK_Return}},	togglescratch,	{.ui = 0} }, // Terminal
	{2, {{Mod1Mask,	XK_s}, {0, XK_c}},	togglescratch,	{.ui = 1} }, // Calculator (bc)
	{2, {{Mod1Mask,	XK_s}, {0, XK_m}},	togglescratch,	{.ui = 2} }, // ncmpcpp (spmusic)
	{2, {{Mod1Mask,	XK_s}, {0, XK_k}},	togglescratch,	{.ui = 3} }, // cdown

	{1, {{MODKEY,							XK_Return}},	spawn,					{.v = termcmd } },

	{1, {{MODKEY,							XK_r}},				spawn,          {.v = LFUB } },


	{1, {{MODKEY,							XK_0}},		view,		{.ui = ~0 } },
	{1, {{MODKEY|ShiftMask,		XK_0}},		tag,		{.ui = ~0 } },


	{1, {{MODKEY,							XK_o}},		incnmaster,     {.i = +1 } },
	{1, {{MODKEY|ShiftMask,		XK_o}},		incnmaster,     {.i = -1 } },


	{1, {{MODKEY,			XK_s}},		togglesticky,	{0} },
	{1, {{MODKEY,			XK_f}},		togglefullscr,	{0} },
	{1, {{MODKEY|ShiftMask,		XK_f}},		setlayout,	{.v = &layouts[8]} },

// Переключение между 2-мя последними вкладками
	{1, {{MODKEY,							XK_Tab}},		view,		{0} },
	{1, {{MODKEY,							XK_backslash}},		view,		{0} },
// current window jimp in next/prev no empty tag
	{1, {{MODKEY,							XK_g}},		shiftview,	{ .i = -1 } },
	{1, {{MODKEY,							XK_semicolon}},	shiftview,	{ .i = 1 } },
	{1, {{MODKEY,							XK_a}},		shiftview,	{ .i = -1 } },
	{1, {{MODKEY,							XK_s}},	shiftview,	{ .i = 1 } },
// move current window in next no empty tag
	{1, {{MODKEY|ShiftMask,		XK_a}},					shifttag,	{ .i = -1 } },
	{1, {{MODKEY|ShiftMask,		XK_s}},					shifttag,	{ .i = -1 } },
	{1, {{MODKEY|ShiftMask,		XK_Page_Up}},		shifttag,	{ .i = -1 } },
	{1, {{MODKEY|ShiftMask,		XK_Page_Down}},	shifttag,	{ .i = +1 } },


// {1, {{Mod1Mask|ShiftMask,     XK_h}},  spawn,  {.v = moveLeft}   }, // Meta + Shift + h
// {1, {{Mod1Mask|ShiftMask,	   XK_j}},  spawn,  {.v = moveDown}   }, // Meta + Shift + j
// {1, {{Mod1Mask|ShiftMask,	   XK_k}},  spawn,  {.v = moveUp}     }, // Meta + Shift + k
// {1, {{Mod1Mask|ShiftMask,	   XK_l}},  spawn,  {.v = moveRight}  }, // Meta + Shift + l


	/* J and K are automatically bound above in STACKEYS */
	{1, {{MODKEY,			XK_l}},		setmfact,				{.f = +0.05} },
	{1, {{MODKEY,			XK_h}},		setmfact,				{.f = -0.05} },

/* GAPS */
	{1, {{MODKEY,							XK_z}},		incrgaps,			{.i = +3 } },
	{1, {{MODKEY|ShiftMask,		XK_z}},		incrgaps,			{.i = -3 } },
	{1, {{MODKEY,							XK_x}},		togglegaps,		{0			 } },
	{1, {{MODKEY|ShiftMask,		XK_x}},		defaultgaps,	{0			 } },
	{1, {{Mod1Mask,						XK_z}},		spawn,        SHCMD("FixMyTetra.sh")},


	/* V is automatically bound above in STACKKEYS */
	{1, {{MODKEY,			XK_b}},		togglebar,	{0} },

	{1, {{MODKEY|ShiftMask,		XK_n}},				spawn,		SHCMD("st -e newsboat; pkill -RTMIN+6 dwmblocks") },

	{1, {{MODKEY,							XK_Left}},	focusmon,	{.i = -1 } },
	{1, {{MODKEY|ShiftMask,		XK_Left}},	tagmon,		{.i = -1 } },
	{1, {{MODKEY,							XK_Right}},	focusmon,	{.i = +1 } },
	{1, {{MODKEY|ShiftMask,		XK_Right}},	tagmon,		{.i = +1 } },

	{1, {{MODKEY,							XK_Page_Up}},	shiftview,	{ .i = -1 } },
	{1, {{MODKEY,							XK_Page_Down}},	shiftview,	{ .i = +1 } },
	{1, {{MODKEY,							XK_Insert}},	spawn,		SHCMD("notify-send \"📋 Clipboard contents:\" \"$(xclip -o -selection clipboard)\"") },

	{1, {{MODKEY,			XK_F1}},		spawn,		SHCMD("groff -mom /usr/local/share/dwm/larbs.mom -Tpdf | zathura -") },
	{1, {{MODKEY,			XK_F2}},		spawn,		SHCMD("tutorialvids") },
	{1, {{MODKEY,			XK_F3}},		spawn,		SHCMD("displayselect") },
	{1, {{MODKEY,			XK_F4}},		spawn,		SHCMD("st -e pulsemixer; kill -44 $(pidof dwmblocks)") },
	{1, {{MODKEY,			XK_F5}},		xrdb,		{.v = NULL } },
	{1, {{MODKEY,			XK_F6}},		spawn,		SHCMD("torwrap")},
	{1, {{MODKEY,			XK_F7}},		spawn,		SHCMD("td-toggle") },
	{1, {{MODKEY,			XK_F8}},		spawn,		SHCMD("mailsync") },
	{1, {{0,					XK_F9}},		spawn,		SHCMD("mounter") },
	{1, {{ShiftMask,	XK_F9}},		spawn,		SHCMD("unmounter") },
	{1, {{0,					XK_F11}},		spawn,		SHCMD("camtoggle") },
	{1, {{Mod1Mask,   XK_F12}},	  spawn,		SHCMD("remaps") },
	//{1, {{MODKEY,			XK_F12}},		xrdb,		{.v = NULL } },
	//{ MODKEY,			XK_space,	zoom,		{0} },
	{1, {{MODKEY|ShiftMask,		XK_space}},	togglefloating,	{0} },

	{1, {{0,									XK_Print}},				spawn,		SHCMD("maimpick screen") },
	{1, {{ShiftMask,					XK_Print}},				spawn,		SHCMD("maimpick choice") },
	{1, {{MODKEY,							XK_Print}},				spawn,		SHCMD("dm-record") },
	{1, {{MODKEY,							XK_Delete}},			spawn,		SHCMD("record kill") },
	{1, {{Mod1Mask,							XK_Delete}},			spawn,		SHCMD("killall screenkey || screenkey &") },

	{1, {{0, XF86XK_AudioMute}},				spawn,		SHCMD(mutevol)},
	{1, {{0, XF86XK_AudioRaiseVolume}},	spawn,		SHCMD(upvol)},
	{1, {{0, XF86XK_AudioLowerVolume}},	spawn,		SHCMD(downvol)},
	{1, {{0, XF86XK_AudioPrev}},				spawn,		SHCMD("mpc prev") },
	{1, {{0, XF86XK_AudioNext}},				spawn,		SHCMD("mpc next") },
	{1, {{0, XF86XK_AudioPause}},				spawn,		SHCMD("mpc pause") },
	{1, {{0, XF86XK_AudioPlay}},				spawn,		SHCMD("mpc play") },
	{1, {{0, XF86XK_AudioStop}},				spawn,		SHCMD("mpc stop") },
	{1, {{0, XF86XK_AudioRewind}},			spawn,		SHCMD("mpc seek -10") },
	{1, {{0, XF86XK_AudioForward}},			spawn,		SHCMD("mpc seek +10") },
	{1, {{0, XF86XK_AudioMedia}},				spawn,		SHCMD("st -e ncmpcpp") },
	{1, {{0, XF86XK_PowerOff}},					spawn,		SHCMD("sysact") },
	{1, {{0, XF86XK_Calculator}},				spawn,		SHCMD("st -e bc -l") },
	{1, {{0, XF86XK_Sleep}},						spawn,		SHCMD("sudo -A zzz") },
	{1, {{0, XF86XK_WWW}},							spawn,		SHCMD("$BROWSER") },
	{1, {{0, XF86XK_DOS}},							spawn,		SHCMD("st") },
	{1, {{0, XF86XK_ScreenSaver}},			spawn,		SHCMD("slock & xset dpms force off; mpc pause; pauseallmpv") },
	{1, {{0, XF86XK_TaskPane}},					spawn,		SHCMD("st -e htop") },
	{1, {{0, XF86XK_Mail}},							spawn,		SHCMD("st -e neomutt ; pkill -RTMIN+12 dwmblocks") },
	{1, {{0, XF86XK_MyComputer}},				spawn,		SHCMD("st -e lf /") },
/*{ 0, XF86XK_Battery,					spawn,		SHCMD("") }, */
	{1, {{0, XF86XK_Launch1}},					spawn,		SHCMD("xset dpms force off") },
	{1, {{0, XF86XK_TouchpadToggle}},		spawn,		SHCMD("(synclient | grep 'touchpadoff.*1' && synclient TouchpadOff=0) || synclient TouchpadOff=1") },
	{1, {{0, XF86XK_TouchpadOff}},			spawn,		SHCMD("synclient TouchpadOff=1") },
	{1, {{0, XF86XK_TouchpadOn}},		    spawn,		SHCMD("synclient TouchpadOff=0") },
	{1, {{0, XF86XK_MonBrightnessUp}},	spawn,		SHCMD("xbacklight -inc 15") },
	{1, {{0, XF86XK_MonBrightnessDown}},	spawn,		SHCMD("xbacklight -dec 15") },
	{1, {{Mod1Mask, XF86XK_MonBrightnessUp}},	spawn,		SHCMD("remaps") },
	{1, {{0, XF86XK_RFKill}},							spawn,		SHCMD("slock & xset dpms force off; mpc pause; pauseallmpv") },


};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button1,        sigdwmblocks,   {.i = 1} },
	{ ClkStatusText,        0,              Button2,        sigdwmblocks,   {.i = 2} },
	{ ClkStatusText,        0,              Button3,        sigdwmblocks,   {.i = 3} },
	{ ClkStatusText,        0,              Button4,        sigdwmblocks,   {.i = 4} },
	{ ClkStatusText,        0,              Button5,        sigdwmblocks,   {.i = 5} },
	{ ClkStatusText,        ShiftMask,      Button1,        sigdwmblocks,   {.i = 6} },
	{ ClkStatusText,        ShiftMask,      Button3,        spawn,          SHCMD("st -e nvim ~/.local/src/dwmblocks/config.h") },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        defaultgaps,	{0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkClientWin,		MODKEY,		Button4,	incrgaps,	{.i = +1} },
	{ ClkClientWin,		MODKEY,		Button5,	incrgaps,	{.i = -1} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
	{ ClkTagBar,		0,		Button4,	shiftview,	{.i = -1} },
	{ ClkTagBar,		0,		Button5,	shiftview,	{.i = 1} },
	{ ClkRootWin,		0,		Button2,	togglebar,	{0} },
};

// vim: foldmethod=marker 

#include <X11/XF86keysym.h>

/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx       = 2;   /* border pixel of windows */
static const unsigned int snap           = 32;  /* snap pixel */
static const int swallowfloating         = 1;   /* 1 means swallow floating windows by default */
static const int scalepreview            = 4;    /* Tag preview scaling */
static const unsigned int gappih         = 10;   /* horiz inner gap between windows */
static const unsigned int gappiv         = 10;   /* vert inner gap between windows */
static const unsigned int gappoh         = 10;   /* horiz outer gap between windows and screen edge */
static const unsigned int gappov         = 10;   /* vert outer gap between windows and screen edge */
static const int smartgaps_fact          = 1;   /* gap factor when there is only one client; 0 = no gaps, 3 = 3x outer gaps */
static const int showbar                 = 1;   /* 0 means no bar */
static const int topbar                  = 1;   /* 0 means bottom bar */
static const int vertpad                 = 0;   /* vertical padding of bar */
static const int sidepad                 = 0;   /* horizontal padding of bar */
/* Status is to be shown on: -1 (all monitors), 0 (a specific monitor by index), 'A' (active monitor) */
static const int statusmon               = -1;
static const unsigned int systrayspacing = 5;   /* systray spacing */
static const int showsystray             = 1;   /* 0 means no systray */

/* icons */
#define ICONSIZE 15    /* icon size */
#define ICONSPACING 5  /* space between icon and title */

/* Indicators: see patch/bar_indicators.h for options */
static int tagindicatortype              = INDICATOR_NONE;
static int tiledindicatortype            = INDICATOR_NONE;
static int floatindicatortype            = INDICATOR_TOP_LEFT_SQUARE;
static const char *fonts[]               = { "DejaVuSansMono:size=10", "FontAwesome5Brands:style=Solid:size=10:antialias:true", "FontAwesome5Free:style=Solid:size=10:antialias:true", "DejaVuSansMonoNerdFont:size=10" };
static const char dmenufont[]            = "DejaVuSansMono:size=10";

// dracula colors
#define DARK       "#282A36"
#define PINK       "#ff79c6"
#define GREEN      "#50fa7b"
#define PURPLE     "#bd93f9"
#define YELLOW     "#f1fa8c"
#define WHITE      "#f8f8f2"
#define RED        "#ff5555"
#define COMMENT    "#6272a4"

// window
static char normfgcolor[]                = PURPLE;
static char normbgcolor[]                = DARK;
static char normbordercolor[]            = COMMENT;
static char normfloatcolor[]             = COMMENT;

static char selfgcolor[]                 = DARK;
static char selbgcolor[]                 = PURPLE;
static char selbordercolor[]             = GREEN;
static char selfloatcolor[]              = GREEN;

// title
static char titlenormfgcolor[]           = COMMENT;
static char titlenormbgcolor[]           = DARK;
static char titlenormbordercolor[]       = PURPLE;
static char titlenormfloatcolor[]        = PURPLE;

static char titleselfgcolor[]            = GREEN;
static char titleselbgcolor[]            = DARK;
static char titleselbordercolor[]        = YELLOW;
static char titleselfloatcolor[]         = PURPLE;

// tags
static char tagsnormfgcolor[]            = PURPLE;
static char tagsnormbgcolor[]            = DARK;
static char tagsnormbordercolor[]        = PURPLE;
static char tagsnormfloatcolor[]         = PURPLE;

static char tagsselfgcolor[]             = DARK;
static char tagsselbgcolor[]             = PURPLE;
static char tagsselbordercolor[]         = GREEN;
static char tagsselfloatcolor[]          = GREEN;

// hidden
static char hidnormfgcolor[]             = COMMENT;
static char hidnormbgcolor[]             = DARK;
static char hidselfgcolor[]              = PURPLE;
static char hidselbgcolor[]              = DARK;

// urgent
static char urgfgcolor[]                 = DARK;
static char urgbgcolor[]                 = GREEN;
static char urgbordercolor[]             = RED;
static char urgfloatcolor[]              = RED;

static char transparent[]                = "#000000"; // placeholder value


static char *colors[][ColCount] = {
	/*                       fg                bg                border                float */
	[SchemeNorm]         = { normfgcolor,      normbgcolor,      normbordercolor,      normfloatcolor      },
	[SchemeSel]          = { selfgcolor,       selbgcolor,       selbordercolor,       selfloatcolor       },
	[SchemeTitleNorm]    = { titlenormfgcolor, titlenormbgcolor, titlenormbordercolor, titlenormfloatcolor },
	[SchemeTitleSel]     = { titleselfgcolor,  titleselbgcolor,  titleselbordercolor,  titleselfloatcolor  },
	[SchemeTagsNorm]     = { tagsnormfgcolor,  tagsnormbgcolor,  tagsnormbordercolor,  tagsnormfloatcolor  },
	[SchemeTagsSel]      = { tagsselfgcolor,   tagsselbgcolor,   tagsselbordercolor,   tagsselfloatcolor   },
	[SchemeHidNorm]      = { hidnormfgcolor,   hidnormbgcolor,   transparent,          transparent         },
	[SchemeHidSel]       = { hidselfgcolor,    hidselbgcolor,    transparent,          transparent         },
	[SchemeUrg]          = { urgfgcolor,       urgbgcolor,       urgbordercolor,       urgfloatcolor       },
};


// User apps
#define IMG_VIEWER "qimgv"
#define PDF_VIEWER "qpdfview"
#define EXPLORER "thunar"

const char *spcmd1[]  = {"alacritty",             "--class", "spterm,spterm", "--config-file", "/home/yr/.config/alacritty/alacritty-scrathcpad.yml", NULL };
const char *spcmd2[]  = {"keepassxc",             NULL };
const char *spcmd3[]  = {"audacious",             NULL };
const char *spcmd4[]  = {"galculator",            NULL };
const char *spcmd5[]  = {"orage",                 NULL };
const char *spcmd6[]  = {IMG_VIEWER,              NULL };
const char *spcmd7[]  = {"nm-connection-editor",  NULL };
const char *spcmd8[]  = {"blueman-manager",       NULL };
const char *spcmd9[]  = {PDF_VIEWER,              NULL };
const char *spcmd10[] = {"telegram-desktop",      NULL };
const char *spcmd11[] = {EXPLORER,                NULL };
const char *spcmd12[] = {"element-desktop",       NULL };
const char *spcmd13[] = {"pavucontrol-qt",        NULL };

static Sp scratchpads[] = {
   /* name                   cmd  */
   {"spterm",               spcmd1},
   {"keepassxc",            spcmd2},
   {"audacious",            spcmd3},
   {"galculator",           spcmd4},
   {"orage",                spcmd5},
   {IMG_VIEWER,             spcmd6},
   {"nm-connection-editor", spcmd7},
   {"blueman-manager",      spcmd8},
   {PDF_VIEWER,             spcmd9},
   {"telegram",             spcmd10},
   {EXPLORER,               spcmd11},
   {"element-desktop",      spcmd12},
   {"pavucontrol-qt",       spcmd13},
};

/* Tags
 * In a traditional dwm the number of tags in use can be changed simply by changing the number
 * of strings in the tags array. This build does things a bit different which has some added
 * benefits. If you need to change the number of tags here then change the NUMTAGS macro in dwm.c.
 *
 * Examples:
 *
 *  1) static char *tagicons[][NUMTAGS*2] = {
 *         [DEFAULT_TAGS] = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F", "G", "H", "I" },
 *     }
 *
 *  2) static char *tagicons[][1] = {
 *         [DEFAULT_TAGS] = { "•" },
 *     }
 *
 * The first example would result in the tags on the first monitor to be 1 through 9, while the
 * tags for the second monitor would be named A through I. A third monitor would start again at
 * 1 through 9 while the tags on a fourth monitor would also be named A through I. Note the tags
 * count of NUMTAGS*2 in the array initialiser which defines how many tag text / icon exists in
 * the array. This can be changed to *3 to add separate icons for a third monitor.
 *
 * For the second example each tag would be represented as a bullet point. Both cases work the
 * same from a technical standpoint - the icon index is derived from the tag index and the monitor
 * index. If the icon index is is greater than the number of tag icons then it will wrap around
 * until it an icon matches. Similarly if there are two tag icons then it would alternate between
 * them. This works seamlessly with alternative tags and alttagsdecoration patches.
 */
static char *tagicons[][NUMTAGS] =
{
	[DEFAULT_TAGS]        = { "1", "2", "3", "4", "5", "6", "7", "8", "9" },
	[ALTERNATIVE_TAGS]    = { "A", "B", "C", "D", "E", "F", "G", "H", "I" },
	[ALT_TAGS_DECORATION] = { "<1>", "<2>", "<3>", "<4>", "<5>", "<6>", "<7>", "<8>", "<9>" },
};


/* There are two options when it comes to per-client rules:
 *  - a typical struct table or
 *  - using the RULE macro
 *
 * A traditional struct table looks like this:
 *    // class      instance  title  wintype  tags mask  isfloating  monitor
 *    { "Gimp",     NULL,     NULL,  NULL,    1 << 4,    0,          -1 },
 *    { "Firefox",  NULL,     NULL,  NULL,    1 << 7,    0,          -1 },
 *
 * The RULE macro has the default values set for each field allowing you to only
 * specify the values that are relevant for your rule, e.g.
 *
 *    RULE(.class = "Gimp", .tags = 1 << 4)
 *    RULE(.class = "Firefox", .tags = 1 << 7)
 *
 * Refer to the Rule struct definition for the list of available fields depending on
 * the patches you enable.
 */

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 *	WM_WINDOW_ROLE(STRING) = role
	 *	_NET_WM_WINDOW_TYPE(ATOM) = wintype
	 */
	RULE(.wintype = WTYPE "DIALOG",              .isfloating = 1)
	RULE(.wintype = WTYPE "UTILITY",             .isfloating = 1)
	RULE(.wintype = WTYPE "TOOLBAR",             .isfloating = 1)
	RULE(.wintype = WTYPE "SPLASH",              .isfloating = 1)
    
  // scratchpads
	RULE(.class = "spterm",                      .tags = SPTAG(0),  .isfloating = 1)
	RULE(.class = "KeePassXC",                   .tags = SPTAG(1),  .isfloating = 1)
	RULE(.class = "Audacious",                   .tags = SPTAG(2),  .isfloating = 1)
	RULE(.class = "Galculator",                  .tags = SPTAG(3),  .isfloating = 1)
	RULE(.class = "Orage",                       .tags = SPTAG(4),  .isfloating = 1)
	RULE(.class = IMG_VIEWER,                    .tags = SPTAG(5),  .isfloating = 1)
	RULE(.class = "Nm-connection-editor",        .tags = SPTAG(6),  .isfloating = 1)
	RULE(.class = "blueman-manager",             .tags = SPTAG(7),  .isfloating = 1)
	RULE(.class = PDF_VIEWER,                    .tags = SPTAG(8),  .isfloating = 1)
	RULE(.class = "Telegram",                    .tags = SPTAG(9),  .isfloating = 1)
	RULE(.class = "Thunar",                      .tags = SPTAG(10), .isfloating = 1)
	RULE(.class = "pcmanfm-qt",                  .tags = SPTAG(10), .isfloating = 1)
	RULE(.class = "Element",                     .tags = SPTAG(11), .isfloating = 1)
	RULE(.class = "Pavucontrol-qt",              .tags = SPTAG(12), .isfloating = 1)

  // floating windows
	RULE(.class = "feh",                         .isfloating = 1)
	RULE(.class = "vlc",                         .isfloating = 1)
	RULE(.class = "mpv",                         .isfloating = 1)
	RULE(.class = "ffplay",                      .isfloating = 1)
	RULE(.class = "QjackCtl",                    .isfloating = 1)
	RULE(.class = "Blueman-manager",             .isfloating = 1)
	RULE(.class = "FeatherPad",                  .isfloating = 1)
	RULE(.class = "Nitrogen",                    .isfloating = 1)
	RULE(.class = "BleachBit",                   .isfloating = 1)
	RULE(.class = "universal-android-debloater", .isfloating = 1)

  // FIRST
	RULE(.class = "Chromium",                    .tags = 1)
	RULE(.class = "Thorium-browser-unstable",    .tags = 1)
	RULE(.class = "qutebrowser",                 .tags = 1)
	RULE(.class = "Firefox",                     .tags = 1)
	RULE(.class = "librewolf",                   .tags = 1)
	RULE(.class = "Vieb",                        .tags = 1)
  // SECOND
	RULE(.class = "Alacritty",                   .tags = 1 << 1)
	RULE(.class = "st",                          .tags = 1 << 1)
  // THIRD
	RULE(.class = "ranger",                      .tags = 1 << 2)
	RULE(.class = "Localsend_app",               .tags = 1 << 2)
	RULE(.class = "qBittorrent",                 .tags = 1 << 2)
  // FOURTH
	// RULE(.class = "Telegram",                    .tags = 1 << 3)
	RULE(.class = "Slack",                       .tags = 1 << 3)
  // FIFTH
	RULE(.class = "Code",                        .tags = 1 << 4)
	RULE(.class = "Emacs",                       .tags = 1 << 4)
	RULE(.class = "jetbrains-pycharm-ce",        .tags = 1 << 4)
	RULE(.class = "Lens",                        .tags = 1 << 4)
	RULE(.class = "Notesnook",                   .tags = 1 << 4)
	RULE(.class = "Joplin",                      .tags = 1 << 4)
	RULE(.class = "QOwnNotes",                   .tags = 1 << 4)
  // SIXTH
	RULE(.class = "guitarpro7.exe",              .tags = 1 << 5)
	RULE(.class = "transcribe.exe",              .tags = 1 << 5)
	RULE(.class = "TuxGuitar",                   .tags = 1 << 5)
	RULE(.class = "Picard",                      .tags = 1 << 5)
	RULE(.class = "Gtick",                       .tags = 1 << 5)
	RULE(.class = "Lingot",                      .tags = 1 << 5)
	RULE(.class = "Flowblade",                   .tags = 1 << 5)
	RULE(.class = "java",                        .tags = 1 << 5)
  // SEVENTH
	RULE(.class = "Soffice",                     .tags = 1 << 6)
	RULE(.class = "libreoffice",                 .tags = 1 << 6)
	RULE(.class = "kolourpaint",                 .tags = 1 << 6)
	RULE(.class = "Gimp",                        .tags = 1 << 6)
	RULE(.class = "DesktopEditors",              .tags = 1 << 6)
	RULE(.class = "Rustdesk",                    .tags = 1 << 6)
	RULE(.class = "Zathura",                     .tags = 1 << 6)
  // EIGHTH
	RULE(.class = "discord",                     .tags = 1 << 7)
	RULE(.class = "Skype",                       .tags = 1 << 7)
	RULE(.class = "zoom",                        .tags = 1 << 7)
	RULE(.class = "Jami",                        .tags = 1 << 7)
	RULE(.class = "obs",                         .tags = 1 << 7)
  // NINTH
	RULE(.class = "htop",                        .tags = 1 << 8)
};



/* Bar rules allow you to configure what is shown where on the bar, as well as
 * introducing your own bar modules.
 *
 *    monitor:
 *      -1  show on all monitors
 *       0  show on monitor 0
 *      'A' show on active monitor (i.e. focused / selected) (or just -1 for active?)
 *    bar - bar index, 0 is default, 1 is extrabar
 *    alignment - how the module is aligned compared to other modules
 *    widthfunc, drawfunc, clickfunc - providing bar module width, draw and click functions
 *    name - does nothing, intended for visual clue and for logging / debugging
 */
static const BarRule barrules[] = {
	/* monitor   bar    alignment         widthfunc          drawfunc          clickfunc          hoverfunc    name */
	{ -1,        0,     BAR_ALIGN_LEFT,   width_tags,        draw_tags,        click_tags,        hover_tags,  "tags"       },
	{  0,        0,     BAR_ALIGN_RIGHT,  width_systray,     draw_systray,     click_systray,     NULL,        "systray"    },
	{ -1,        0,     BAR_ALIGN_LEFT,   width_ltsymbol,    draw_ltsymbol,    click_ltsymbol,    NULL,        "layout"     },
	{ statusmon, 0,     BAR_ALIGN_RIGHT,  width_status2d,    draw_status2d,    click_statuscmd,   NULL,        "status2d"   },
	{ -1,        0,     BAR_ALIGN_NONE,   width_awesomebar,  draw_awesomebar,  click_awesomebar,  NULL,        "awesomebar" },
};

/* layout(s) */
static const float mfact          = 0.55; /* factor of master area size [0.05..0.95] */
static const int   nmaster        = 1;    /* number of clients in master area */
static const int   resizehints    = 0;    /* 1 means respect size hints in tiled resizals */
static const int   lockfullscreen = 1;    /* 1 will force focus on the fullscreen window */



static const Layout layouts[] = {
	/* symbol   arrange function */
	{ "[T]",    tile    },    /* first entry is default */
	{ "[F]",    NULL    },    /* no layout function means floating behavior */
 	{ "[M]",    monocle },
	{ NULL,     NULL    },
};


/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

#define STACKKEYS(MOD,ACTION) \
	{ MOD, XK_Up,    ACTION##stack, {.i = INC(+1) } }, \
	{ MOD, XK_Down,  ACTION##stack, {.i = INC(-1) } }, \
	{ MOD, XK_s,     ACTION##stack, {.i = PREVSEL } }, \
	{ MOD, XK_w,     ACTION##stack, {.i = 0       } }, \
	{ MOD, XK_e,     ACTION##stack, {.i = 1       } }, \
	{ MOD, XK_a,     ACTION##stack, {.i = 2       } }, \
	{ MOD, XK_z,     ACTION##stack, {.i = -1      } },


#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }
#define SCRIPTS "$HOME/.scripts/"
#define STATUSBAR "dwmblocks"

/* commands */
static const char *termcmd[]  = { "alacritty", NULL };

static const Key keys[] = {
	/* modifier                       key            function                argument */
	{ MODKEY,                         XK_Return,     spawn,                  {.v = termcmd } },
	{ MODKEY,                         XK_b,          togglebar,              {0}             },
	{ MODKEY,                         XK_i,          incnmaster,             {.i = +1 }      },
	{ MODKEY,                         XK_d,          incnmaster,             {.i = -1 }      },
    
  // resizing tiling windows
	{ MODKEY,                         XK_Left,       setmfact,               {.f = -0.05}    },
	{ MODKEY,                         XK_Right,      setmfact,               {.f = +0.05}    },
  // resizing floating windows
	{ MODKEY,                         XK_k,          exresize,               {.v = (int []){  25,  25 }}},  /* Begin, */
	{ MODKEY,                         XK_j,          exresize,               {.v = (int []){ -25, -25 }}},  /* Begin, */
	{ MODKEY,                         XK_l,          exresize,               {.v = (int []){  25,   0 }}},  /* Right, */
	{ MODKEY,                         XK_h,          exresize,               {.v = (int []){ -25,   0 }}},  /* Left,  */
	// { MODKEY|ControlMask,             XK_k,          exresize,               {.v = (int []){   0,  25 }}},  /* Up,    */
	// { MODKEY|ControlMask,             XK_j,          exresize,               {.v = (int []){   0, -25 }}},  /* Down,  */

  // changing focus
	STACKKEYS(MODKEY,                                focus)
  // moving windows
	STACKKEYS(MODKEY|ControlMask,                    push)

	{ Mod1Mask,                       XK_7,          explace,                {.ui = EX_NW }},   /* XK_KP_Home,  */
	{ Mod1Mask,                       XK_8,          explace,                {.ui = EX_N  }},   /* XK_KP_Up,    */
	{ Mod1Mask,                       XK_9,          explace,                {.ui = EX_NE }},   /* XK_KP_Prior, */
	{ Mod1Mask,                       XK_4,          explace,                {.ui = EX_W  }},   /* XK_KP_Left,  */
	{ Mod1Mask,                       XK_5,          explace,                {.ui = EX_C  }},   /* XK_KP_Begin, */
	{ Mod1Mask,                       XK_6,          explace,                {.ui = EX_E  }},   /* XK_KP_Right, */
	{ Mod1Mask,                       XK_1,          explace,                {.ui = EX_SW }},   /* XK_KP_End,   */
	{ Mod1Mask,                       XK_2,          explace,                {.ui = EX_S  }},   /* XK_KP_Down,  */
	{ Mod1Mask,                       XK_3,          explace,                {.ui = EX_SE }},   /* XK_KP_Next,  */

  // cycling tags
	{ MODKEY,                         XK_Next,       shiftviewclients,       { .i = +1 } },
	{ MODKEY,                         XK_Prior,      shiftviewclients,       { .i = -1 } },

  // kill app
	{ MODKEY,                         XK_x,          killclient,             {0} },

  // quit from dwm
	{ MODKEY|ShiftMask,               XK_q,          quit,                   {0} },

  // reload dwm
	{ MODKEY,                         XK_r,          quit,                   {1} },
	{ MODKEY|ShiftMask,               XK_F5,         xrdb,                   {.v = NULL } },

  // set tile layout
	{ MODKEY|Mod1Mask,                XK_t,          setlayout,              {.v = &layouts[0]} },
  // set float layout
	{ MODKEY|Mod1Mask,                XK_f,          setlayout,              {.v = &layouts[1]} },
  // set monocle layout
	{ MODKEY|Mod1Mask,                XK_m,          setlayout,              {.v = &layouts[2]} },
  // changing layouts
	{ Mod1Mask,                       XK_Tab,        setlayout,              {0} },

  // floating mode for window
	{ MODKEY,                         XK_Tab,        togglefloating,         {0} },

  // toggle fullscreen
	{ MODKEY,                       XK_f,          togglefullscreen,       {0} },

  // toggle sticky mode
	{ MODKEY,                         XK_s,          togglesticky,           {0} },

  // scratchpads
	{ MODKEY|ShiftMask,               XK_Return,     togglescratch,          {.ui = 0  } }, // terminal
	{ MODKEY|ShiftMask,               XK_p,          togglescratch,          {.ui = 1  } }, // keepass
	{ MODKEY|ShiftMask,               XK_m,          togglescratch,          {.ui = 2  } }, // music player
	{ MODKEY|ShiftMask,               XK_g,          togglescratch,          {.ui = 3  } }, // galculator
	{ MODKEY|ShiftMask,               XK_c,          togglescratch,          {.ui = 4  } }, // calendar
	{ MODKEY|ShiftMask,               XK_i,          togglescratch,          {.ui = 5  } }, // IMG_VIEWER
	{ MODKEY|ShiftMask,               XK_n,          togglescratch,          {.ui = 6  } }, // nmtui
	{ MODKEY|ShiftMask,               XK_b,          togglescratch,          {.ui = 7  } }, // btctl
	{ MODKEY|ShiftMask,               XK_d,          togglescratch,          {.ui = 8  } }, // PDF_VIEWER
	{ MODKEY|ShiftMask,               XK_t,          togglescratch,          {.ui = 9  } }, // telegram
	{ MODKEY|ShiftMask,               XK_f,          togglescratch,          {.ui = 10 } }, // pcmanfm-qt
	{ MODKEY|ShiftMask,               XK_e,          togglescratch,          {.ui = 11 } }, // Element
	{ MODKEY|ShiftMask,               XK_v,          togglescratch,          {.ui = 12 } }, // pavucontrol-qt

	{ MODKEY,                         XK_0,          view,                   {.ui = ~SPTAGMASK } },
	{ MODKEY|ShiftMask,               XK_0,          tag,                    {.ui = ~SPTAGMASK } },

  // switching between monitors
	{ MODKEY,                         XK_comma,      focusmon,               {.i = -1 } },
	{ MODKEY,                         XK_period,     focusmon,               {.i = +1 } },

  // moving window between monitors
	{ MODKEY|ShiftMask,               XK_comma,      tagmon,                 {.i = -1 } },
	{ MODKEY|ShiftMask,               XK_period,     tagmon,                 {.i = +1 } },

	TAGKEYS(                          XK_1,                                  0)
	TAGKEYS(                          XK_2,                                  1)
	TAGKEYS(                          XK_3,                                  2)
	TAGKEYS(                          XK_4,                                  3)
	TAGKEYS(                          XK_5,                                  4)
	TAGKEYS(                          XK_6,                                  5)
	TAGKEYS(                          XK_7,                                  6)
	TAGKEYS(                          XK_8,                                  7)
	TAGKEYS(                          XK_9,                                  8)


  // dmenu 
	{ MODKEY,               XK_space,                   spawn,  SHCMD(SCRIPTS "system/xorg/dmenu-scripts.sh apps")                              },
	{ Mod1Mask,             XK_x,                       spawn,	SHCMD(SCRIPTS "system/xorg/dmenu-scripts.sh powermenu")                         },
	{ Mod1Mask,             XK_space,                   spawn,	SHCMD(SCRIPTS "system/xorg/dmenu-scripts.sh clipmenu")                          },

  // console apps
  { MODKEY,               XK_Escape,                  spawn,	SHCMD("alacritty --class htop,htop -e htop")                               },

  // gui apps
  { MODKEY|ShiftMask,     XK_w,                       spawn,	SHCMD(SCRIPTS "system/xorg/find-app.sh chromium")                               },
	{ MODKEY|ShiftMask,     XK_j,                       spawn,	SHCMD(SCRIPTS "system/xorg/find-app.sh Joplin")                                 },

	

  // take screenshot
  { 0,                     XK_Print,                  spawn,	SHCMD(SCRIPTS "system/xorg/take-screenshot.sh --partial")                       },
  { MODKEY,                XK_Print,                  spawn,	SHCMD(SCRIPTS "system/xorg/take-screenshot.sh --full")                          },

	// audio controls
	{ 0,                     XF86XK_AudioRaiseVolume,   spawn,	SHCMD(SCRIPTS "system/control-volume.sh up   && pkill -RTMIN+1 dwmblocks") },
	{ 0,                     XF86XK_AudioLowerVolume,   spawn,	SHCMD(SCRIPTS "system/control-volume.sh down && pkill -RTMIN+1 dwmblocks") },
	{ 0,                     XF86XK_AudioMute,      	  spawn,	SHCMD(SCRIPTS "system/control-volume.sh mute && pkill -RTMIN+1 dwmblocks") },
	{ 0,                     XF86XK_AudioMicMute,      	spawn,	SHCMD(SCRIPTS "system/control-volume.sh mic  && pkill -RTMIN+2 dwmblocks") },

  // brightness controls
  { 0,                     XF86XK_MonBrightnessUp,    spawn,	SHCMD(SCRIPTS "system/xorg/get-brightness.sh      && pkill -RTMIN+3 dwmblocks") },
  { 0,                     XF86XK_MonBrightnessDown, 	spawn,	SHCMD(SCRIPTS "system/xorg/get-brightness.sh      && pkill -RTMIN+3 dwmblocks") },

  // changing keyboard layout
	{ Mod1Mask,              XK_Shift_L,               	spawn,	SHCMD("pkill -RTMIN+5 dwmblocks"                                         ) },
	{ ShiftMask,             XK_Alt_L,                 	spawn,	SHCMD("pkill -RTMIN+5 dwmblocks"                                         ) },
	{ 0,                     XK_Caps_Lock,             	spawn,	SHCMD("xdotool key Caps_Lock && pkill -RTMIN+5 dwmblocks"                ) },

	// bluetooth indicator
	// { 0,                     XF86XK_Bluetooth,         	spawn,	SHCMD("pkill -RTMIN+7 dwmblocks"                                         ) },
};


/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask           button          function        argument */
	{ ClkLtSymbol,          0,                   Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,                   Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,                   Button1,        togglewin,      {0} },
	{ ClkWinTitle,          0,                   Button3,        showhideclient, {0} },
	{ ClkWinTitle,          0,                   Button2,        zoom,           {0} },
	{ ClkStatusText,        0,                   Button1,        sigstatusbar,   {.i = 6 } },
	{ ClkStatusText,        0,                   Button2,        sigstatusbar,   {.i = 6 } },
	{ ClkStatusText,        0,                   Button3,        sigstatusbar,   {.i = 6 } },
  { ClkStatusText,        ShiftMask,           Button3,        spawn,          SHCMD("alacritty -e hx ~/.config/dwm/dwmblocks-async/config.h") },
	/* placemouse options, choose which feels more natural:
	 *    0 - tiled position is relative to mouse cursor
	 *    1 - tiled postiion is relative to window center
	 *    2 - mouse pointer warps to window center
	 *
	 * The moveorplace uses movemouse or placemouse depending on the floating state
	 * of the selected client. Set up individual keybindings for the two if you want
	 * to control these separately (i.e. to retain the feature to move a tiled window
	 * into a floating position).
	 */
	{ ClkClientWin,         MODKEY,              Button1,        moveorplace,    {.i = 1} },
	{ ClkClientWin,         MODKEY,              Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,              Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,                   Button1,        view,           {0} },
	{ ClkTagBar,            0,                   Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,              Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,              Button3,        toggletag,      {0} },
};



#include "/home/muratovas/.local/src/theme.h"

/* Taken from https://github.com/djpohly/dwl/issues/466 */
#define COLOR(hex)    { ((hex >> 24) & 0xFF) / 255.0f, \
                        ((hex >> 16) & 0xFF) / 255.0f, \
                        ((hex >> 8) & 0xFF) / 255.0f, \
                        (hex & 0xFF) / 255.0f }
/* appearance */
static const int sloppyfocus               = 1;  /* focus follows mouse */
static const int bypass_surface_visibility = 0;  /* 1 means idle inhibitors will disable idle tracking even if it's surface isn't visible  */
static const int smartborders              = 1;
static const unsigned int borderpx         = 2;  /* border pixel of windows */
static const float rootcolor[]             = COLOR(0x222222ff);
static const float focuscolor[]            = COLOR(_activeBgColor);
static const float bordercolor[]           = COLOR(_inactiveBgColor);
static const float urgentcolor[]           = COLOR(_urgentBgColor);
/* To conform the xdg-protocol, set the alpha to zero to restore the old behavior */
static const float fullscreen_bg[]         = {0.1f, 0.1f, 0.1f, 1.0f}; /* You can also use glsl colors */

#define CURSORTHEME "Breeze"
#define CURSORSIZE  24

/* tagging - TAGCOUNT must be no greater than 31 */
#define TAGCOUNT (9)

/* logging */
static int log_level = WLR_ERROR;

/* Autostart */
static const char *const autostart[] = {
        //"killall", "someblocks", "noticat", NULL,
        "wbg", "/home/muratovas/.config/wbg/bg.jpg", NULL,
        "dwlb", "-scale", "2", NULL,
        //"sh", "-c", "someblocks -p | dwlb -status-stdin all", NULL,
        //"sh", "-c", "noticat -dwlb | dwlb -status-stdin all", NULL,
        //"sh", "-c", "autostart.sh", NULL,
        NULL /* terminate */
};


static const Rule rules[] = {
	/* app_id     title       tags mask     isfloating   monitor */
	/* examples:
	{ "Gimp",     NULL,       0,            1,           -1 },
	*/
	{ NULL,  					"Picture-in-Picture",       0,       	  1,           -1},
	{ NULL,  					"Picture in picture",       0,       	  1,           -1},
	{ NULL,  					"Картинка в картинке",       0,       	  1,           -1},
	{ NULL,  					"Save File",       			0,       	  1,           -1},
	{ NULL,  					"Firefox — Sharing Indicator",       			0,       	  1,           -1},
	{ NULL,  					".* is sharing your screen.",       			0,       	  1,           -1},
	{ "gnome-calculator",		NULL,       				0,            1,           -1},
	{ "swappy",					NULL,       				0,            1,           -1},
	{ "xsensors",				NULL,       			0,       	  1,           -1},
	{ "wdisplays",				NULL,       			0,       	  1,           -1},
	{ "ulauncher",				NULL,       			0,       	  1,           -1},
	{ ".*gpg2.*",				NULL,       			0,       	  1,           -1},
};

/* layout(s) */
static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* monitors */
/* NOTE: ALWAYS add a fallback rule, even if you are completely sure it won't be used */
static const MonitorRule monrules[] = {
	/* name       mfact  nmaster scale layout       rotate/reflect                x    y */
	/* example of a HiDPI laptop monitor:
	{ "eDP-1",    0.5f,  1,      2,    &layouts[0], WL_OUTPUT_TRANSFORM_NORMAL,   -1,  -1 },
	*/
	/* defaults */
	//{ NULL,       0.55f, 1,      1,    &layouts[0], WL_OUTPUT_TRANSFORM_NORMAL,   -1,  -1 },
	{ "HDMI-A-1", 0.5,  1,      2,    &layouts[0], WL_OUTPUT_TRANSFORM_NORMAL,   0,  0 },
	{ "eDP-1",    0.5,  9,      1,    &layouts[0], WL_OUTPUT_TRANSFORM_NORMAL,   0,  1080 },
	{ NULL,       0.5,  1,      1,    &layouts[0], WL_OUTPUT_TRANSFORM_NORMAL,   -1,  -1 },
};

/* keyboard */
static const struct xkb_rule_names xkb_rules = {
	/* can specify fields: rules, model, layout, variant, options */
	/* example:
	.options = "ctrl:nocaps",
	*/
	.options = NULL,
	.layout = "us,ru",
    .options = "grp:win_space_toggle"
};

static const int repeat_rate = 25;
static const int repeat_delay = 600;

/* Trackpad */
static const int tap_to_click = 1;
static const int tap_and_drag = 1;
static const int drag_lock = 1;
static const int natural_scrolling = 0;
static const int disable_while_typing = 1;
static const int left_handed = 0;
static const int middle_button_emulation = 0;
/* You can choose between:
LIBINPUT_CONFIG_SCROLL_NO_SCROLL
LIBINPUT_CONFIG_SCROLL_2FG
LIBINPUT_CONFIG_SCROLL_EDGE
LIBINPUT_CONFIG_SCROLL_ON_BUTTON_DOWN
*/
static const enum libinput_config_scroll_method scroll_method = LIBINPUT_CONFIG_SCROLL_2FG;

/* You can choose between:
LIBINPUT_CONFIG_CLICK_METHOD_NONE
LIBINPUT_CONFIG_CLICK_METHOD_BUTTON_AREAS
LIBINPUT_CONFIG_CLICK_METHOD_CLICKFINGER
*/
static const enum libinput_config_click_method click_method = LIBINPUT_CONFIG_CLICK_METHOD_BUTTON_AREAS;

/* You can choose between:
LIBINPUT_CONFIG_SEND_EVENTS_ENABLED
LIBINPUT_CONFIG_SEND_EVENTS_DISABLED
LIBINPUT_CONFIG_SEND_EVENTS_DISABLED_ON_EXTERNAL_MOUSE
*/
static const uint32_t send_events_mode = LIBINPUT_CONFIG_SEND_EVENTS_ENABLED;

/* You can choose between:
LIBINPUT_CONFIG_ACCEL_PROFILE_FLAT
LIBINPUT_CONFIG_ACCEL_PROFILE_ADAPTIVE
*/
static const enum libinput_config_accel_profile accel_profile = LIBINPUT_CONFIG_ACCEL_PROFILE_ADAPTIVE;
static const double accel_speed = 0.0;
/* You can choose between:
LIBINPUT_CONFIG_TAP_MAP_LRM -- 1/2/3 finger tap maps to left/right/middle
LIBINPUT_CONFIG_TAP_MAP_LMR -- 1/2/3 finger tap maps to left/middle/right
*/
static const enum libinput_config_tap_button_map button_map = LIBINPUT_CONFIG_TAP_MAP_LRM;

/* If you want to use the windows key for MODKEY, use WLR_MODIFIER_LOGO */
#define MODKEY WLR_MODIFIER_ALT

#define TAGKEYS(KEY,SKEY,TAG) \
	{ MODKEY,                    -1, KEY,            view,            {.ui = 1 << TAG} }, \
	{ MODKEY|WLR_MODIFIER_CTRL,  -1, KEY,            toggleview,      {.ui = 1 << TAG} }, \
	{ MODKEY|WLR_MODIFIER_SHIFT, -1, SKEY,           tag,             {.ui = 1 << TAG} }, \
	{ MODKEY|WLR_MODIFIER_CTRL|WLR_MODIFIER_SHIFT,-1,SKEY,toggletag,  {.ui = 1 << TAG} }

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

#define MENUCMD "$TERMINAL_COMMAND sway-launcher-desktop.sh; exit"

#define SCREENSHOTSWAPPY "grim -g \"$(slurp -d)\" - | swappy -f -;"
#define SCREENSHOTFILE "grim $HOME/Media/screenshot-$(date +'%Y-%m-%d-%H%M%S').png; \
                        notify-send 'Screenshot save to file'"
#define RECORDERGIF "killall -s SIGINT wf-recorder; export area=$(slurp -d); pkill -RTMIN+8 someblocks && \
                     wf-recorder -F fps=12 -c gif -g \"$area\" -f $HOME/Media/recording--$(date +'%Y-%m-%d-%H%M%S').gif"

#define HIBERNATECMD "loginctl hibernate"
#define SHUTDOWNCMD "sudo openrc-shutdown -p 0"
#define REBOOTCMD "sudo openrc-shutdown -r 0"

#define RCdockerCMD "rc-status | grep 'docker' \
	 	&& sudo rc-service docker stop \
		|| sudo rc-service docker start"

#define RClibvirtdCMD "rc-status | grep 'libvirtd' \
	 	&& sudo rc-service libvirtd stop \
		|| sudo rc-service libvirtd start"

#define RCcupsdCMD "rc-status | grep 'cupsd' \
	 	&& sudo rc-service cupsd stop \
		|| sudo rc-service cupsd start"

static const Key keys[] = {
	/* Note that Shift changes certain key codes: c -> C, 2 -> at, etc. */
	/* modifier                  chain,  key                 function        argument */
	{ MODKEY|WLR_MODIFIER_CTRL,	 -1,XKB_KEY_Print,          spawn,          SHCMD(RECORDERGIF) },
	{ MODKEY,					 -1,XKB_KEY_Print,          spawn,          SHCMD(SCREENSHOTSWAPPY) },
	{ MODKEY|WLR_MODIFIER_SHIFT, -1,XKB_KEY_Print,          spawn,          SHCMD(SCREENSHOTFILE) },
	{ MODKEY|WLR_MODIFIER_SHIFT, XKB_KEY_E,XKB_KEY_S,          spawn,          SHCMD(SHUTDOWNCMD) },
	{ MODKEY|WLR_MODIFIER_SHIFT, XKB_KEY_E,XKB_KEY_R,          spawn,          SHCMD(REBOOTCMD) },
	{ MODKEY|WLR_MODIFIER_SHIFT, XKB_KEY_E,XKB_KEY_H,          spawn,          SHCMD(HIBERNATECMD) },
	{ MODKEY|WLR_MODIFIER_SHIFT, XKB_KEY_D,XKB_KEY_C,          spawn,          SHCMD(RCdockerCMD) },
	{ MODKEY|WLR_MODIFIER_SHIFT, XKB_KEY_D,XKB_KEY_V,          spawn,          SHCMD(RClibvirtdCMD) },
	{ MODKEY|WLR_MODIFIER_SHIFT, XKB_KEY_D,XKB_KEY_P,          spawn,          SHCMD(RCcupsdCMD) },
	{ MODKEY,                    -1,XKB_KEY_Return,     spawn,          SHCMD("$TERM") },
	{ MODKEY,                    -1,XKB_KEY_d,          spawn,          SHCMD(MENUCMD) },
	{ MODKEY|WLR_MODIFIER_SHIFT, -1,XKB_KEY_Q,          killclient,           {0} },
	{ MODKEY|WLR_MODIFIER_SHIFT, -1,XKB_KEY_C,          quit,     {0} },
	{ MODKEY,                    -1,XKB_KEY_Left,       focusdir,       {.ui = 0} },
	{ MODKEY,                    -1,XKB_KEY_Right,      focusdir,       {.ui = 1} },
	{ MODKEY,                    -1,XKB_KEY_Up,         focusdir,       {.ui = 2} },
	{ MODKEY,                    -1,XKB_KEY_Down,       focusdir,       {.ui = 3} },
	{ MODKEY|WLR_MODIFIER_SHIFT, -1,XKB_KEY_Left,       swapdir,        {.ui = 0} },
	{ MODKEY|WLR_MODIFIER_SHIFT, -1,XKB_KEY_Right,      swapdir,        {.ui = 1} },
	{ MODKEY|WLR_MODIFIER_SHIFT, -1,XKB_KEY_Up,         swapdir,        {.ui = 2} },
	{ MODKEY|WLR_MODIFIER_SHIFT, -1,XKB_KEY_Down,       swapdir,        {.ui = 3} },
	{ MODKEY|WLR_MODIFIER_CTRL,  -1,XKB_KEY_Down,       moveresizekb,   {.v = (int []){ 0, 40, 0, 0 }}},
	{ MODKEY|WLR_MODIFIER_CTRL,  -1,XKB_KEY_Up,         moveresizekb,   {.v = (int []){ 0, -40, 0, 0 }}},
	{ MODKEY|WLR_MODIFIER_CTRL,  -1,XKB_KEY_Right,      moveresizekb,   {.v = (int []){ 40, 0, 0, 0 }}},
	{ MODKEY|WLR_MODIFIER_CTRL,  -1,XKB_KEY_Left,       moveresizekb,   {.v = (int []){ -40, 0, 0, 0 }}},
	{ MODKEY|WLR_MODIFIER_SHIFT, -1,XKB_KEY_Down,       moveresizekb,   {.v = (int []){ 0, 0, 0, 40 }}},//NOTWORK
	{ MODKEY|WLR_MODIFIER_SHIFT, -1,XKB_KEY_Up,         moveresizekb,   {.v = (int []){ 0, 0, 0, -40 }}},//NOTWORK
	{ MODKEY|WLR_MODIFIER_SHIFT, -1,XKB_KEY_Right,      moveresizekb,   {.v = (int []){ 0, 0, 40, 0 }}},//NOTWORK
	{ MODKEY|WLR_MODIFIER_SHIFT, -1,XKB_KEY_Left,       moveresizekb,   {.v = (int []){ 0, 0, -40, 0 }}},//NOTWORK
	{ MODKEY,                    -1,XKB_KEY_j,          incnmaster,     {.i = +1} },
	{ MODKEY,                    -1,XKB_KEY_k,          incnmaster,     {.i = -1} },
	{ MODKEY,                    -1,XKB_KEY_h,          setmfact,       {.f = -0.05} },
	{ MODKEY,                    -1,XKB_KEY_l,          setmfact,       {.f = +0.05} },
	  // { MODKEY|WLR_MODIFIER_SHIFT, -1,XKB_KEY_j,          focusstack,     {.i = +1} },
	  // { MODKEY|WLR_MODIFIER_SHIFT, -1,XKB_KEY_k,          focusstack,     {.i = -1} },
	{ MODKEY,                    -1,XKB_KEY_y,          setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                    -1,XKB_KEY_u,          setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                    -1,XKB_KEY_i,          setlayout,      {.v = &layouts[2]} },
	//{ MODKEY,                    -1,XKB_KEY_o,          setlayout,      {.v = &layouts[3]} },
	// { MODKEY,                    -1,XKB_KEY_p,          setlayout,      {.v = &layouts[4]} },
	{ MODKEY,                    -1,XKB_KEY_Insert,      togglefloating, {0} },
	{ MODKEY|WLR_MODIFIER_SHIFT, -1,XKB_KEY_F,         togglefullscreen, {0} },
	{ MODKEY,                    -1,XKB_KEY_Tab,     view,           {0} },
	// { MODKEY|WLR_MODIFIER_CTRL, -1,XKB_KEY_Tab,       view,           {.ui = ~0} },
	{ MODKEY, 			     -1,XKB_KEY_z,       tag,            {.ui = ~0} },
	  // { MODKEY,				     -1,XKB_KEY_x,     zoom,           {0} },
	  // { MODKEY, 			     -1, XKB_KEY_v,       tagmon,         {.i = WLR_DIRECTION_LEFT} },
	  // { MODKEY, 			     -1, XKB_KEY_b,    tagmon,         {.i = WLR_DIRECTION_RIGHT} },
	  // { MODKEY,                  -1, XKB_KEY_n,      focusmon,       {.i = WLR_DIRECTION_LEFT} },
	  // { MODKEY,                  -1, XKB_KEY_m,     focusmon,       {.i = WLR_DIRECTION_RIGHT} },
	// { MODKEY|WLR_MODIFIER_CTRL,  -1,XKB_KEY_equal,          incgaps,       {.i = +1 } },
	// { MODKEY|WLR_MODIFIER_CTRL,  -1,XKB_KEY_minus,          incgaps,       {.i = -1 } },
	TAGKEYS(          XKB_KEY_1, XKB_KEY_exclam,                     0),
	TAGKEYS(          XKB_KEY_2, XKB_KEY_at,                         1),
	TAGKEYS(          XKB_KEY_3, XKB_KEY_numbersign,                 2),
	TAGKEYS(          XKB_KEY_4, XKB_KEY_dollar,                     3),
	TAGKEYS(          XKB_KEY_5, XKB_KEY_percent,                    4),
	TAGKEYS(          XKB_KEY_6, XKB_KEY_asciicircum,                5),
	TAGKEYS(          XKB_KEY_7, XKB_KEY_ampersand,                  6),
	TAGKEYS(          XKB_KEY_8, XKB_KEY_asterisk,                   7),
	TAGKEYS(          XKB_KEY_9, XKB_KEY_parenleft,                  8),

	/* Ctrl-Alt-Backspace and Ctrl-Alt-Fx used to be handled by X server */
	{ WLR_MODIFIER_CTRL|WLR_MODIFIER_ALT,-1,XKB_KEY_Terminate_Server, quit, {0} },
	/* Ctrl-Alt-Fx is used to switch to another VT, if you don't know what a VT is
	 * do not remove them.
	 */
#define CHVT(n) { WLR_MODIFIER_CTRL|WLR_MODIFIER_ALT,-1,XKB_KEY_XF86Switch_VT_##n, chvt, {.ui = (n)} }
	CHVT(1), CHVT(2), CHVT(3), CHVT(4), CHVT(5), CHVT(6),
	CHVT(7), CHVT(8), CHVT(9), CHVT(10), CHVT(11), CHVT(12),
};

static const Button buttons[] = {
	{ MODKEY, BTN_LEFT,   moveresize,     {.ui = CurMove} },
	{ MODKEY, BTN_MIDDLE, togglefloating, {0} },
	{ MODKEY, BTN_RIGHT,  moveresize,     {.ui = CurResize} },
};

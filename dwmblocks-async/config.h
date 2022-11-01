#define CMDLENGTH 45
#define DELIMITER "^c#ffffff^ | "
#define CLICKABLE_BLOCKS

const Block blocks[] = {
	BLOCK("~/.config/dwm/dwmblocks-async/scripts/vol_dwm",      0,     1),
	BLOCK("~/.config/dwm/dwmblocks-async/scripts/mic_dwm",      0,     2),
	BLOCK("~/.config/dwm/dwmblocks-async/scripts/backlight",    0,     3),
	BLOCK("~/.config/dwm/dwmblocks-async/scripts/cputemp",      5,     0),
	BLOCK("~/.config/dwm/dwmblocks-async/scripts/ram",          5,     0),
	BLOCK("~/.config/dwm/dwmblocks-async/scripts/disk -r",      10,    0),
	BLOCK("~/.config/dwm/dwmblocks-async/scripts/disk -u",      10,    0),
	BLOCK("~/.config/dwm/dwmblocks-async/scripts/bat_dwm",      5,     0),
	BLOCK("~/.config/dwm/dwmblocks-async/scripts/calendar",     10,    0),
	BLOCK("~/.config/dwm/dwmblocks-async/scripts/time",         5,     0),
	BLOCK("~/.config/dwm/dwmblocks-async/scripts/kbd",          0,     5),
};

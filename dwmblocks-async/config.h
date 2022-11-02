#define CMDLENGTH 50
#define DELIMITER "^c#ffffff^ | "
#define CLICKABLE_BLOCKS
#define scriptDir "~/.config/dwm/dwmblocks-async/scripts/"

const Block blocks[] = {
	BLOCK(scriptDir "vol_dwm",      0,     1),
	BLOCK(scriptDir "mic_dwm",      0,     2),
	BLOCK(scriptDir "backlight",    0,     3),
	BLOCK(scriptDir "cputemp",      5,     0),
	BLOCK(scriptDir "ram",          5,     0),
	BLOCK(scriptDir "disk -r",      10,    0),
	BLOCK(scriptDir "disk -u",      10,    0),
	BLOCK(scriptDir "bat_dwm",      5,     0),
	BLOCK(scriptDir "calendar",     10,    6),
	BLOCK(scriptDir "time",         5,     0),
	BLOCK(scriptDir "kbd",          0,     5),
};

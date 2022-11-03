#define CMDLENGTH 50
#define DELIMITER "^c#ffffff^ | "
#define CLICKABLE_BLOCKS
#define scriptDir "~/.config/dwm/dwmblocks-async/scripts/"

const Block blocks[] = {
	BLOCK(scriptDir "vol_dwm.sh",           0,       1),
	BLOCK(scriptDir "mic_dwm.sh",           0,       2),
	BLOCK(scriptDir "backlight.sh",         0,       3),
	BLOCK(scriptDir "cputemp.sh",           5,       0),
	BLOCK(scriptDir "ram.sh",               5,       0),
	BLOCK(scriptDir "disk.sh -r",           10,      0),
	BLOCK(scriptDir "disk.sh -u",           10,      0),
	BLOCK(scriptDir "xbps_updates.sh",      540,     0),
	BLOCK(scriptDir "bat_dwm.sh",           5,       0),
	BLOCK(scriptDir "calendar.sh",          10,      6),
	BLOCK(scriptDir "time.sh",              5,       0),
	BLOCK(scriptDir "kbd.sh",               0,       5),
};

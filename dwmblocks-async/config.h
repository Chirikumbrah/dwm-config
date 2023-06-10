#define CMDLENGTH 50
// #define DELIMITER "^c#ffffff^ | "
#define DELIMITER "  "
#define CLICKABLE_BLOCKS
#define SCRIPTS "$HOME/.scripts/dwmblocks/"

const Block blocks[] = {
	// BLOCK(scriptDir "xbps-updates.sh",      333,     0),
	BLOCK(SCRIPTS "vol-dwm.sh",           10,      1),
	// BLOCK(SCRIPTS "mic-dwm.sh",           10,      2),
	// BLOCK(SCRIPTS "backlight.sh",         0,       3),
	BLOCK(SCRIPTS "cputemp.sh",           5,       0),
	// BLOCK(SCRIPTS "ram.sh",               5,       0),
	// BLOCK(SCRIPTS "disk.sh -r",           10,      0),
	// BLOCK(SCRIPTS "disk.sh -u",           10,      0),
	BLOCK(SCRIPTS "bat-dwm.sh",           5,       0),
	BLOCK(SCRIPTS "datetime.sh",          5,       0),
	BLOCK(SCRIPTS "kbd.sh",               10,      5),
	// BLOCK(SCRIPTS "bluetooth.sh",         5,       7),
	// BLOCK(SCRIPTS "wifi.sh",              5,       7),
};

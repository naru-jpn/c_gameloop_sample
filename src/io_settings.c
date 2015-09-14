#include "io_settings.h"
#include <stdio.h>
#include <string.h>
#include <termios.h>

//--------------------------------------------------
static int is_setting = 0;
static struct termios init_tio;
//--------------------------------------------------

void setup_io() {
	if (is_setting!=0) {
		reset_io();
	}
	is_setting = 1;

	// 標準入力の設定
	struct termios tio;
	tcgetattr(0, &init_tio);
	memcpy(&tio, &init_tio, sizeof(struct termios));
	tio.c_lflag &= (IO_SETTINGS_VALID_ATTRIBUTES | ~IO_SETTINGS_INVALID_ATTRIBUTES);
	tcsetattr(0, TCSANOW, &tio);
}

void reset_io() {
	if (is_setting==0) {
		tcgetattr(0, &init_tio);
	}

	// 設定を戻す
	is_setting = 0;
	tcsetattr(0, TCSANOW, &init_tio);
}


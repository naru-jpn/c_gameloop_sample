#include "kbhit.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

int kbhit() {
	struct timeval tv;
	fd_set rfds;
	// 標準入力から取得できるものがあるかチェック
	FD_ZERO(&rfds);
	FD_SET(0, &rfds);
	tv.tv_usec = 0;
	tv.tv_sec = 0;
	select(1, &rfds, NULL, NULL, &tv);
	return FD_ISSET(0, &rfds) ? 1 : 0;
};

void readikey(int *ikeytype, char *ch, int flush) {
	read(0, ch, 1);
	// ESCと矢印キーは入力バッファの一文字目の文字コードが同じ。
	if (*ch == KEY_ESC) {
		if (kbhit()) {
			char input;
			// '[' は無視
			read(0, &input, 1);
			read(0, &input, 1);
			if (input == 'A') {
				// UP
				*ikeytype = IKEYTYPE_ARRUP;
			} else if (input == 'B') {
				// DOWN
                *ikeytype = IKEYTYPE_ARRDOWN;
			} else if (input == 'C') {
				// RIGHT
                *ikeytype = IKEYTYPE_ARRRIGHT;
            } else if (input == 'D') {
				// LEFT
                *ikeytype = IKEYTYPE_ARRLEFT;
            }
		} else {
			// ESC
			*ikeytype = IKEYTYPE_ESC;
		}
	} else {
		// 通常の文字
		*ikeytype = IKEYTYPE_CHAR;
	}
	if (flush) {
		char buf;
		while(kbhit()) {
			read(0, &buf, 1);
		}
	}
}

void read_key(char *ch) {
	read(0, ch, 1);
	return;
}


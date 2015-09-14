#include "timer.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/event.h>
#include <sys/time.h>

void createTimerEvent(int *kq, unsigned int ident, struct kevent *kev, unsigned int milliseconds) {

	// カーネルイベントキューの取得
	*kq = kqueue();
    if (*kq == -1) {
        perror("kqueue");
        exit(-1);
    }

    // イベントのパラメータ指定
    EV_SET(kev, ident, EVFILT_TIMER, EV_ADD, 0x02, milliseconds*1.0e+3, NULL);

    // イベントの追加
    int ret;
    ret = kevent(*kq, kev, 1, NULL, 0, NULL);
    if (ret == -1) {
        perror("kevent");
        exit(-1);
    }
}

void waitTimer(int kq, unsigned int ident, struct kevent *kev) {
	int ret;
	while (1) {
		// キューのイベント取得待ち
		ret = kevent(kq, NULL, 0, kev, 1, NULL);
		if (ret == -1) {
			perror("kevent");
			exit(-1);
		}
		// 目的のイベントなら戻る
		if (kev->ident == ident) return;
	}
}


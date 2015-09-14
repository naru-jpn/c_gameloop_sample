
#ifndef _INCLUDE_TIMER_
#define _INCLUDE_TIMER_

#include <sys/event.h>

/*
  タイマーイベントの作成
  @param kq カーネルイベントキュー
  @param ident イベントの識別番号
  @param kev イベント情報
  @param milliseconds 待ち時間
 */
void createTimerEvent(int *kq, unsigned int ident, struct kevent *kev, unsigned int milliseconds);

/*
  タイマー発火まで待機する
  @param kq カーネルイベントキュー 
  @param ident イベントの識別番号
  @param kev イベント情報
 */
void waitTimer(int kq, unsigned int ident, struct kevent *kev);

#endif

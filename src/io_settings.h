
#ifndef _INCLUDE_IO_SETTINGS_
#define _INCLUDE_IO_SETTINGS_

#define IO_SETTINGS_VALID_ATTRIBUTES (0)
#define IO_SETTINGS_INVALID_ATTRIBUTES (ECHO | ICANON)

// 入出力の設定をします。
void setup_io();

// 入出力の設定を初期値に戻します。
void reset_io();

#endif

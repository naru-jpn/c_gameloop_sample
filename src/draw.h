#include "esc_sequences.h"
#include "components.h"

#ifndef _INCLUDE_DISPLAY_
#define _INCLUDE_DISPLAY_

// 画面クリア
void clear();

// 座標 (x,y) へカーソルを移動
void move(unsigned int x, unsigned int y);

// 指定された座標への文字の描画
void draw(int x, int y, char *str);

// component の描画
void draw_component(int origin_x, int origin_y, component* comp);

// 文字の装飾
void set_style(unsigned int style);

// 文字色の変更
void set_color(unsigned int color);

// 背景色の変更
void set_bgcolor(unsigned int color);

#endif


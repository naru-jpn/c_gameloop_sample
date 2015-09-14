#include <stdio.h>
#include "io_settings.h"
#include "kbhit.h"
#include "timer.h"
#include "draw.h"
#include "scenes/scenes.h"
#include "scenes/scene_setting.h"

//----------------------------------------

// キーボード入力関連
static int ikeytype = 0;
static char input;

// タイマー関連
static int kq = 0;
static struct kevent kev;
static unsigned int ident = 1;

// ユーザーの位置
static component *hero = NULL;

// シーン
static int current_scene = 0;
static int is_setting = 0;

//----------------------------------------

int main(){

	// 標準入力の設定変更
	setup_io();

	// タイマーの作成
	createTimerEvent(&kq, ident, &kev, 100); /* 100ms */

	// 画面クリア&シーン設定
	clear();
	switch_scene(&current_scene, 1);

	// 主人公の初期化
	hero = new_component(0, 3, 3, TEXT_DEFAULT, COLOR_WHITE, BGCOLOR_ORIGINAL, R_SELF);

	while (ikeytype!=IKEYTYPE_ESC) {
		// タイマーイベント待機
		waitTimer(kq, ident, &kev);
		// キー取得
		if (kbhit()) {
			readikey(&ikeytype, &input, 1);
		} else {
			ikeytype = IKEYTYPE_NONE;
			input = ' ';
		}

		// 設定画面切り替え
		if (is_setting==0 && input=='i') {
			is_setting = 1;
			setup_setting();
		} else if (is_setting==1 && input=='i') {
			is_setting = 0;
			clean_setting();
		}

		// 操作用・出力用関数の取得
		FUNC_INPUT_CONTROL control_func = NULL;
		FUNC_OUTPUT_COMPONENTS output_func = NULL;
		if (is_setting==0) {
			control_func = get_icontrol_function(current_scene);
			output_func = get_ocomponent_function(current_scene);
		} else {
			control_func = input_control_setting;
			output_func = root_component_setting;
		}
		// 操作と出力
		control_func(hero, &current_scene, ikeytype, input);
		component *output = output_func();
		draw_component(0, 0, output);
		draw_component(0, 0, hero);
		move(0, 0);
	}
	clear();
	move(0, 0);
	printf("めのまえが まっくらに なった！\n");

	// 標準入力の設定を戻す
	reset_io();
	return 0;
}

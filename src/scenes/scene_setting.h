#include "../components.h"

#ifndef _INCLUDE_SETTING_
#define _INCLUDE_SETTING_

// 入力受け付け関数
void input_control_setting(component *hero, int *current_scene, int ikeytype, char input);

// 画面出力返却関数
component *root_component_setting();

// 準備
void setup_setting();

// 掃除
void clean_setting();

#endif


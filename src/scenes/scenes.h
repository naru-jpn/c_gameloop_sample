#include "../kbhit.h"
#include "../components.h"

#ifndef _INCLUDE_SCENES_
#define _INCLUDE_SCENES_

// 入力受け付け関数
typedef void (*FUNC_INPUT_CONTROL)(component *hero, int *current_scene, int ikeytype, char input);
FUNC_INPUT_CONTROL get_icontrol_function(int nscene);

// 画面出力返却関数
typedef component *(*FUNC_OUTPUT_COMPONENTS)();
FUNC_OUTPUT_COMPONENTS get_ocomponent_function(int nscene);

// シーン切り替え
void switch_scene(int *current_scene, int new_scene);

#endif

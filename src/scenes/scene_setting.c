#include "scene_setting.h"
#include "../kbhit.h"
#include "../resource/maps.h"
#include <stdlib.h>
#include <stdio.h>

static unsigned int count = 0;
static component *root = NULL;
static component *menu = NULL;
static component *arrow = NULL;

void input_control_setting(component *hero, int *current_scene, int ikeytype, char input) {
	// hide hero
	if (hero->hidden != 1) hero->hidden = 1;
	// move hero
	if (ikeytype==IKEYTYPE_ARRUP) {
		arrow->y--;
	} else if (ikeytype==IKEYTYPE_ARRDOWN) {
		arrow->y++;
	}
}

component *root_component_setting() {
	count++;
	if ((count/5)%2 == 0) {
		arrow->hidden = 0;
	} else {
		arrow->hidden = 1;
	}
	return root;
}

void setup_setting() {
	if (root == NULL) {
		root = new_component(0, 0, 0, TEXT_DEFAULT, COLOR_ORIGINAL, BGCOLOR_ORIGINAL, R_SETTING_FRAME);
		menu = new_component(0, 20, 3, TEXT_DEFAULT, COLOR_ORIGINAL, BGCOLOR_ORIGINAL, R_SETTING_MENU);
		root->child = menu;
		arrow = new_component(0, 18, 3, TEXT_DEFAULT, COLOR_ORIGINAL, BGCOLOR_ORIGINAL, R_SETTING_ARROW);
		menu->next = arrow;
	}
}

void clean_setting() {
	count = 0;
	if (root != NULL) {
		free_component(root);
		root = NULL;
		menu = NULL;
		arrow = NULL;
	}
}


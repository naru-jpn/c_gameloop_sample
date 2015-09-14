#include "scene_0001.h"
#include "../resource/maps.h"
#include "../kbhit.h"
#include <stdlib.h>
#include <stdio.h>

static unsigned int count = 0;
static component *root = NULL;
static component *sea1 = NULL;
static component *sea2 = NULL;

static int is_movable(int x, int y);

void input_control0001(component* hero, int *current_scene, int ikeytype, char input) {
	// show hero
	if (hero->hidden != 0) hero->hidden = 0;
	// move hero
	if (ikeytype==IKEYTYPE_ARRUP) {
		if (is_movable(hero->x, hero->y-1)) hero->y--;
	} else if (ikeytype==IKEYTYPE_ARRDOWN) {
		if (is_movable(hero->x, hero->y+1)) hero->y++;
	} else if (ikeytype==IKEYTYPE_ARRLEFT) {
		if (is_movable(hero->x-1, hero->y)) hero->x--;
	} else if (ikeytype==IKEYTYPE_ARRRIGHT) {
		if (is_movable(hero->x+1, hero->y))hero->x++;
	}
}

int is_movable(int x, int y) {
	char cell = MAP_0001[MAP_WIDTH*y + x];
	return (cell == ' ') ? 1 : 0;
}

component *root_component0001() {
	count++;
	if ((count/10)%2 == 0) {
		sea1->hidden = 0;
		sea2->hidden = 1;
	} else {
		sea1->hidden = 1;
        sea2->hidden = 0;
	}
	return root;
}

void setup0001() {
	if (root == NULL) {
		root = new_component(0, 0, 0, TEXT_DEFAULT, COLOR_ORIGINAL, BGCOLOR_ORIGINAL, MAP_0001);
		sea1 = new_component(0, 7, 12, TEXT_DEFAULT, COLOR_WHITE, BGCOLOR_LIGHTBLUE, MAP_0001_SEA1);
		root->child = sea1;
		sea2 = new_component(0, 7, 12, TEXT_DEFAULT, COLOR_WHITE, BGCOLOR_LIGHTBLUE, MAP_0001_SEA2);
		sea1->next = sea2;
	}
}

void clean0001() {
	count = 0;
	if (root != NULL) {
		free_component(root);
		root = NULL;
		sea1 = NULL;
		sea2 = NULL;
	}
}

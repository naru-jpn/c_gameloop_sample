#include "scene_0002.h"
#include "scenes.h"
#include "../resource/maps.h"
#include "../kbhit.h"
#include <stdlib.h>
#include <stdio.h>

static unsigned int count = 0;
static component *root = NULL;
static component *field1 = NULL;
static component *field2 = NULL;
static component *field3 = NULL;

static int is_movable(int x, int y);

void input_control0002(component* hero, int *current_scene, int ikeytype, char input) {
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
		if (is_movable(hero->x+1, hero->y)) hero->x++;
	}
	if (hero->y==14 && hero->x>=14 && hero->x<=17) {
        switch_scene(current_scene, 1);
        hero->y = 2;
    }
}

int is_movable(int x, int y) {
	char cell = MAP_0002[MAP_WIDTH*y + x];
	return (cell == ' ') ? 1 : 0;
}

component *root_component0002() {
	count++;
	return root;
}

void setup0002() {
	if (root == NULL) {
		root = new_component(0, 0, 0, TEXT_DEFAULT, COLOR_ORIGINAL, BGCOLOR_ORIGINAL, MAP_0002);
		field1 = new_component(1, 25, 6, TEXT_DEFAULT, COLOR_GREEN, BGCOLOR_ORIGINAL, MAP_0002_FIELD12);
        root->child = field1;
        field2 = new_component(2, 2, 2, TEXT_DEFAULT, COLOR_GREEN, BGCOLOR_ORIGINAL, MAP_0002_FIELD24);
        field1->next = field2;
		field3 = new_component(3, 20, 1, TEXT_DEFAULT, COLOR_GREEN, BGCOLOR_ORIGINAL, MAP_0002_FIELD4);
        field2->next = field3;
	}
}

void clean0002() {
	count = 0;
	if (root != NULL) {
		free_component(root);
		root = NULL;
	}
}

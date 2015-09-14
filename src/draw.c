#include "draw.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 子の component の描画
void draw_childcomponent(int parent_x, int parent_y, component *component);

void clear() {
	printf("\033[2J");
}

void move(unsigned int x, unsigned int y) {
	printf("\033[%d;%dH", y+1, x+1);
}

void draw(int x, int y, char *str) {
	// strtok の為、引数の文字列をコピーする。
	unsigned int length = strlen(str);
	char buf[length+1];
	strcpy(buf, str);
	// 受け取った文字列を改行コードで分割し、1行づつ描画する。
	unsigned int row = y;
	char *tok = strtok(buf, "\n");
	while (1) {
		if (tok == NULL) {
			break;
		} else {
    		move(x, row);
			printf("%s\n", tok);
			row++;
		}
		tok = strtok(NULL, "\n");
	}
}

void draw_component(int origin_x, int origin_y, component *comp) {
	int x = comp->x+origin_x;
	int y = comp->y+origin_y;
	if (comp->hidden == 0) {
		set_style(comp->style);
		set_color(comp->color);
		set_bgcolor(comp->bgcolor);
		draw(x, y, comp->resource);
	}
	if (comp->next != NULL) {
		draw_component(origin_x, origin_y, comp->next);
	}
	if (comp->child != NULL) {
		draw_component(x, y, comp->child);
	}
}

void set_style(unsigned int style) {
	printf("%c[%dm", ESC, style);
}

void set_color(unsigned int color) {
	printf("%c[%dm", ESC, color);
}

void set_bgcolor(unsigned int color) {
	printf("%c[%dm", ESC, color);
}


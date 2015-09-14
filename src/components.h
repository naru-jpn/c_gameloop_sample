#include "esc_sequences.h"
#include "resource/resources.h"

#ifndef _INCLUDE_COMPONENTS_
#define _INCLUDE_COMPONENTS_

typedef struct _component {
	int id;
	int x;
	int y;
	int hidden;
	tstyle style;
	tcolor color;
	tbgcolor bgcolor;
	char *resource;
	struct _component *next;
    struct _component *child;
} component;

// component の新規作成
component *new_component(int id, int x, int y, tstyle style, tcolor color, tbgcolor bgcolor, resource r);

// component の解放
void free_component(component *comp);

// id からの component の取得
component *get_component(component *parent, int id);

// next component の追加
void add_nextcomponent(component *parent, component *next);

#endif


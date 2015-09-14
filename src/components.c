#include "components.h"
#include <string.h>
#include <stdlib.h>

component *new_component(int id, int x, int y, tstyle style, tcolor color, tbgcolor bgcolor, resource r) {
	component *pnew;
	pnew = (component *)malloc(sizeof(component));
	pnew->id = id;
	pnew->x = x;
	pnew->y = y;
	pnew->hidden = 0;
    pnew->style = style;
    pnew->color = color;
    pnew->bgcolor = bgcolor;
	if (r != NULL) {
		// resource のコピー
		int len = strlen(r);
		char *cpy = malloc(sizeof(char)*(len+1));
		pnew->resource = cpy;
		strcpy(cpy, r);
	} else {
		pnew->resource = NULL;
	}
	pnew->next = NULL;
	pnew->child = NULL;
	return pnew;
}

void free_component(component *p) {
	if (p->child != NULL) {
		free_component(p->child);
	}
	component *pnext = p->next;
	while (1) {
		if (pnext == NULL) break;
		pnext = pnext->next;
		free(pnext);
	}
}

component *get_component(component *parent, int id) {
	component *p = parent;
	while (1) {
		p = p->next;
		if (p == NULL) return NULL;
		if (p->id == id) {
			return p;
		}
	}
	if (parent->child != NULL) {
		return get_component(parent->child, id);
	}
	return NULL;
}

void add_nextcomponent(component *parent, component *next) {
	component *p = parent;
	while (1) {
		if (p->next == NULL) {
			p->next = next;
			break;
		}
		p = p->next;
	}	
}


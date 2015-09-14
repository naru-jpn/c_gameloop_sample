#include "scenes.h"
#include "scene_0001.h"
#include <stdio.h>
#include <stdlib.h>

void (*get_setup_function(int nscene))(void);

void (*get_clean_function(int nscene))(void);

FUNC_INPUT_CONTROL get_icontrol_function(int nscene) {
	switch (nscene) {
        case 1:
            return input_control0001;
        default:
            return NULL;
    }
}

FUNC_OUTPUT_COMPONENTS get_ocomponent_function(int nscene) {
	switch (nscene) {
        case 1:
            return root_component0001;
        default:
            return NULL;
    }
}

void switch_scene(int *current_scene, int new_scene) {
	void (*setup)() = get_setup_function(new_scene);
	if (setup == NULL) {
		perror("setup scene");
		exit(-1);
	}
	void (*clean)() = get_clean_function(*current_scene);
	if (clean != NULL) clean();
	setup();
	*current_scene = new_scene;
}

void (*get_setup_function(int nscene))(void) {
	switch (nscene) {
		case 1:
			return setup0001;
		default:
			return NULL;
	}
}

void (*get_clean_function(int nscene))(void) {
	switch (nscene) {
        case 1:
            return clean0001;
        default:
            return NULL;
    }
}



TARGET = a.out
OUTPUT_DIR = out
BUILD_DIR = build
SRC_DIR = src

BASIC_FILES    = main.c io_settings.c kbhit.c timer.c draw.c components.c
RESOURCE_FILES = resource/resources.c resource/maps.c
SCENE_FILES    = scenes/scenes.c scenes/scene_0001.c scenes/scene_0002.c scenes/scene_setting.c

SRC_FILES = $(BASIC_FILES) $(RESOURCE_FILES) $(SCENE_FILES)

OUTPUT = $(addprefix $(OUTPUT_DIR)/,$(TARGET))
OBJS = $(addprefix $(BUILD_DIR)/,$(subst .c,.o, $(SRC_FILES)))
DEPS = $(subst .o,.d, $(OBJS))
SRCS = $(addprefix $(SRC_DIR)/,$(SRC_FILES))

CFLAGS = -Wall -O3
CC = gcc

all: $(BUILD_DIR) $(OUTPUT_DIR) $(OUTPUT)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(OUTPUT_DIR):
	mkdir -p $(OUTPUT_DIR)

$(OUTPUT): $(OBJS)
	$(CC) $(CFLAGS) -o $(OUTPUT) $^

$(BUILD_DIR)/%.o : $(SRC_DIR)/%.c
	@if [ ! -d $(dir $@) ]; then \
		mkdir -p $(dir $@); \
		echo "create directory $(dir $@)"; \
	fi
	$(CC) -c $(CFLAGS) -o $@ $<

$(BUILD_DIR)/%.d : $(SRC_DIR)/%.c
	@if [ ! -d $(dir $@) ]; then \
		mkdir -p $(dir $@); \
		echo "create directory $(dir $@)"; \
	fi
	@$(CC) -MM $(CFLAGS) $< \
	| sed 's/$(notdir $*).o/$(subst /,\/,$(patsubst %.d,%.o,$@) $@)/' > $@ ; \
	[ -s $@ ] || rm -f $@
	@if [ -f $@ ]; then \
		echo "create dependency file $@"; \
	fi

clean:
	rm -rf $(BUILD_DIR) $(OUTPUT_DIR) $(OUTPUT)

.PHONY: all clean

-include $(DEPS)


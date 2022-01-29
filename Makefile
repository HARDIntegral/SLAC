CC := gcc
FILE_TYPE := .c
DEBUG_FLAGS := -g -O0 -Wall -Wextra
RELEASE_FLAGS := -O3 -DNDEBUG
SRC_DIR := src/
OBJ_DIR := bin/obj/
EXEC_DIR := bin/
EXEC_NAME := slac
BUILD_TARGET := out
RUNTIME_ARGS :=

EXEC := $(EXEC_NAME).$(BUILD_TARGET)
BUILD := $(EXEC_DIR)$(EXEC)
BUILD_RUN := $(EXEC_DIR)./$(EXEC)
SRCS := $(wildcard $(SRC_DIR)**/**$(FILE_TYPE)) $(wildcard $(SRC_DIR)*$(FILE_TYPE))
OBJS := $(patsubst $(SRC_DIR)%$(FILE_TYPE), $(OBJ_DIR)%.o, $(SRCS))

build_debug: $(OBJS)
	@echo "D" > .tmp_data
	@echo [INFO] Creating Binary Executable [$(BUILD_TARGET)] with Debug Flags ...
	@$(CC) -o $(BUILD) $^
	@echo [INFO] [$(EXEC)] Created with Debug Flags!
	
build_release: $(OBJS)
	@echo "" > .tmp_data
	@echo [INFO] Creating Binary Executable [$(BUILD_TARGET)] ...
	@$(CC) -o $(BUILD) $^
	@echo [INFO] [$(EXEC)] Created!

$(OBJ_DIR)%.o: $(SRC_DIR)%$(FILE_TYPE)
	@echo [CC] $<
	@mkdir -p $(@D)
ifeq ($(shell cat .tmp_data),D)
	@$(CC) $(DEBUG_FLAGS) $< -c -o $@
else
	@$(CC) $(RELEASE_FLAGS) $< -c -o $@
endif

mem_check: build_debug
	@echo [DEBUG] Generating Memory Leak Summary ...
	@valgrind --tool=memcheck -s --leak-check=full --track-origins=yes $(BUILD_RUN) $(RUNTIME_ARGS)

.PHONY: clean
clean:
	@echo [INFO] Removing Pre-Compiled Object Files ...
	@rm -rf $(OBJ_DIR)
	@echo [INFO] Removing Compiled Executable ...
	@rm -rf $(EXEC_DIR)

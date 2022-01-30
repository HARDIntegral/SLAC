CC := gcc
FILE_TYPE := .c
DEBUG_FLAGS := -g -O0 -Wall -Wextra
RELEASE_FLAGS := -O3 -DNDEBUG
SRC_DIR := src/
OBJ_DIR := bin/obj/
TEST_BUILD_DIR := bin/tests/
EXEC_DIR := bin/
EXEC_NAME := libslac
BUILD_TARGET := a
EXEC_TARGET := .out
RUNTIME_ARGS :=

EXEC := $(EXEC_NAME).$(BUILD_TARGET)
BUILD := $(EXEC_DIR)$(EXEC)
TEST_BUILD := $(TEST_BUILD_DIR)test$(EXEC_TARGET)
TEST_RUN := $(TEST_BUILD_DIR)./test$(EXEC_TARGET)

SRCS := $(wildcard $(SRC_DIR)**/**$(FILE_TYPE)) $(wildcard $(SRC_DIR)*$(FILE_TYPE))
OBJS := $(patsubst $(SRC_DIR)%$(FILE_TYPE), $(OBJ_DIR)%.o, $(SRCS))
TESTS := tests/test.c

build_debug: $(OBJS)
	@echo "D" > .tmp_data
	@echo [INFO] Creating Static Library [$(BUILD_TARGET)] with Debug Flags ...
	@ar rcs $(BUILD) $^
	@echo [INFO] [$(EXEC)] Created with Debug Flags!
	
build_release: $(OBJS)
	@echo "" > .tmp_data
	@echo [INFO] Creating Static Library [$(BUILD_TARGET)] ...
	@ar rcs $(BUILD) $^
	@echo [INFO] [$(EXEC)] Created!

$(OBJ_DIR)%.o: $(SRC_DIR)%$(FILE_TYPE)
	@echo [CC] $<
	@mkdir -p $(@D)
ifeq ($(shell cat .tmp_data),D)
	@$(CC) $(DEBUG_FLAGS) $< -c -o $@ -I headers
else
	@$(CC) $(RELEASE_FLAGS) $< -c -o $@ -I headers
endif

run_test: build_test
	@echo [INFO] Running Tests ...
	@$(TEST_RUN)
	@echo [EXEC] Complete!

build_test: $(TESTS) $(BUILD)
	@echo [INFO] Building Tests ...
	@mkdir -p $(TEST_BUILD_DIR)
	@$(CC) -o $(TEST_BUILD) $^ -lslac -L bin -I headers
	@echo [INFO] Tests Generated!

.PHONY: clean
clean:
	@echo [INFO] Removing Pre-Compiled Object Files ...
	@rm -rf $(OBJ_DIR)
	@echo [INFO] Removing Compiled Libraries ...
	@rm -rf $(EXEC_DIR)

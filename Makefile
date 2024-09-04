debug ?= 0
NAME := mg-number-verbalization
SRC_DIR := src
BUILD_DIR := build
INCLUDE_DIR := include
LIB_DIR := lib
TESTS_DIR := tests
BIN_DIR := bin
OBJS := $(patsubst %.c,%.o, $(wildcard $(SRC_DIR)/*.c) $(wildcard $(LIB_DIR)/**/*.c))
OBJS_WITHOUT_MAIN := $(filter-out $(SRC_DIR)/main.o, $(OBJS))

# Compiler settings
CC := gcc

# Compiler and linker flags settings
CFLAGS := -Wall -Wextra -pedantic
LDFLAGS := -lm


ifeq ($(debug), 1)
	CFLAGS := $(CFLAGS) -g -O0
else
	CFLAGS := $(CFLAGS)
endif

# Targets

# Build executable
$(NAME): dir $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(BIN_DIR)/$@ $(patsubst %, build/%, $(OBJS))

# Build object files and third-party libraries
$(OBJS): dir
	@mkdir -p $(BUILD_DIR)/$(@D)
	@$(CC) $(CFLAGS) -o $(BUILD_DIR)/$@ -c $*.c

# Run tests
test: dir
	@$(CC) $(CFLAGS) -o $(BIN_DIR)/$(NAME)_test $(TESTS_DIR)/*.c $(patsubst %, build/%, $(OBJS_WITHOUT_MAIN))
	@$(BIN_DIR)/$(NAME)_test

# Setup build and bin directories
dir:
	@mkdir -p $(BUILD_DIR) $(BIN_DIR)

# Clean build and bin directories
clean:
	@rm -rf $(BUILD_DIR) $(BIN_DIR)

.PHONY: lint format check setup dir clean bear


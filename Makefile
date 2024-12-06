# Compiler and flags
CC = cc
CFLAGS = -Wall -Werror -Wextra -I./include

# Directories
SRC_DIR = src
UTILS_DIR = utils
OBJ_DIR = obj
BIN_DIR = bin
INCLUDE_DIR = include

# Sources and objects
UTILS_SRCS = $(wildcard $(UTILS_DIR)/*.c)
UTILS_OBJS = $(patsubst $(UTILS_DIR)/%.c, $(OBJ_DIR)/%.o, $(UTILS_SRCS))

DAY01_SRCS = $(wildcard $(SRC_DIR)/day01/*.c)
DAY01_OBJS = $(patsubst $(SRC_DIR)/day01/%.c, $(OBJ_DIR)/%.o, $(DAY01_SRCS))

# Rules
day01: $(UTILS_OBJS) $(DAY01_OBJS) | $(BIN_DIR)
	$(CC) $(CFLAGS) -o $(BIN_DIR)/day01 $^


# Compile utility source files
$(OBJ_DIR)/%.o: $(UTILS_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Compile day01 source files
$(OBJ_DIR)/%.o: $(SRC_DIR)/day01/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@


# Create obj directory if it doesn't exist
$(OBJ_DIR) $(BIN_DIR):
	mkdir -p $@


# Clean up
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR) 
	
.PHONY: clean day01

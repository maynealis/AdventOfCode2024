# Compiler and flags
CC = cc
CFLAGS = -Wall -Werror -Wextra -I./include

# Directories
SRC_DIR = src
UTILS_DIR = utils
BUILD_DIR = build
INCLUDE_DIR = include

# Sources and objects
UTILS_SRCS = $(wildcard $(UTILS_DIR)/*.c)
UTILS_OBJS = $(patsubst $(UTILS_DIR)/%.c, $(BUILD_DIR)/%.o, $(UTILS_SRCS))

DAY01_SRCS = $(wildcard $(SRC_DIR)/day01/*.c)
DAY01_OBJS = $(patsubst $(SRC_DIR)/day01/%.c, $(BUILD_DIR)/%.o, $(DAY01_SRCS))

# Targets
# DAY01 = day01

# Rules
day01: $(DAY01)

# Build day1
day01: $(UTILS_OBJS) $(DAY01_OBJS)
	$(CC) $(CFLAGS) -o day01 $^


# Compile utility source files
$(BUILD_DIR)/%.o: $(UTILS_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $(UTILS_DIR)/$*.c -o $(BUILD_DIR)/$*.o

# Compile day01 source files
$(BUILD_DIR)/%.o: $(SRC_DIR)/day01/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/day01/$*.c -o $(BUILD_DIR)/$*.o

# Create build directory if it doesn't exist
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Clean up
clean:
	rm -rf $(BUILD_DIR) $(DAY01)

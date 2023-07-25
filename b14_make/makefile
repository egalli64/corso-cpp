##
# Corso C++ https://github.com/egalli64/corso-cpp
#
# A richer makefile
#

# The required C++ Compiler
CXX := g++
# Compiler flags (all warnings, debug)
CXXFLAGS := -Wall -g
# Pre-processor flags for inclusion
CPPFLAGS := -I. -Isub

# Main source directory
SRC_DIR := .
# Other source directory
SUB_DIR := sub
# Where to place the object files
BUILD_DIR := build

# Source files
#	the wildcard function returns all the matching files
SRCS := $(wildcard $(SRC_DIR)/*.cpp) $(wildcard $(SUB_DIR)/*.cpp)

# Object files
#	$(SRCS:%.cpp=%.o) convert src filenames to object filenames
#	notdir removes the original pathname
#	addprefix for the build folder
OBJS := $(addprefix $(BUILD_DIR)/,$(notdir $(SRCS:%.cpp=%.o)))

# Executable name
TARGET := hello

# Targets (not related to actual files)
.PHONY: all clean

# First (non-dot-prefixed) target - the default one
all: $(BUILD_DIR) $(TARGET)

# Rule to build the target
#	$@ is the target of the rule
#	$^ is for the dependencies
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule to build object files
#	each .cpp had the matching .o as target
#	after "|" are placed the order only prerequisites
#	$< means the .cpp file
$(BUILD_DIR)/%.o: %.cpp | $(BUILD_DIR)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(SUB_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

# Create the build directory if it doesn't exist
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# cleanup of build directory and target
#	@- for silent execution
clean:
	@-rm -rf $(BUILD_DIR) $(TARGET)

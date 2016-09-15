#------------------------------------------------------------------------------
# Project's name
#------------------------------------------------------------------------------
PROGRAM = suite_attack

#------------------------------------------------------------------------------
# Directories
#------------------------------------------------------------------------------
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

#------------------------------------------------------------------------------
# All source and objects files
#------------------------------------------------------------------------------
SOURCE = ${wildcard $(SRC_DIR)/*.c}
OBJ = ${addprefix $(OBJ_DIR)/, ${notdir ${SOURCE:.c=.o}}}
MAIN_FILE = main.c
LOIC_FILE = loic.c

#------------------------------------------------------------------------------
# Alias to commands
#------------------------------------------------------------------------------
MKDIR_P = mkdir -p
LINK_FORCE = ln -fn

#------------------------------------------------------------------------------
# Compilator and flags
#------------------------------------------------------------------------------
CC = gcc
INCLUDE = -Iinclude/
CFLAGS = -lpthread

#------------------------------------------------------------------------------
# Executable's name
#------------------------------------------------------------------------------
EXECUTABLE = run

.PHONY: clean directories

all: directories $(PROGRAM)

$(PROGRAM): $(SOURCE)
	@echo "Initing compilation..."
	@echo "Compile source files"
	$(CC) -c $(SRC_DIR)/main.c -o $(OBJ_DIR)/main.o $(CFLAGS)
	$(CC) -c $(SRC_DIR)/loic.c -o $(OBJ_DIR)/loic.o $(CFLAGS)
	@echo "Compile objects to main"
	$(CC)  $(OBJ_DIR)/main.o -o $(BIN_DIR)/$(PROGRAM) $(CFLAGS)
	$(CC)  $(OBJ_DIR)/loic.o -o $(BIN_DIR)/loic $(CFLAGS)
	@echo "Creating link to run"
	$(LINK_FORCE) $(BIN_DIR)/$(PROGRAM) $(EXECUTABLE)
	@echo "Done!"

directories:
	@$(MKDIR_P) $(OBJ_DIR)
	@$(MKDIR_P) $(BIN_DIR)

clean:
	@echo "Excluding..."
	@echo "Clean executables..."
	rm -f $(PROGRAM)
	rm -f $(EXECUTABLE)
	rm -rf $(BIN_DIR)
	@echo "Clean objects..."
	rm -f $(OBJ)
	rm -rf $(OBJ_DIR)
	rm -rf *.o
	@echo "Ready exclusion!"

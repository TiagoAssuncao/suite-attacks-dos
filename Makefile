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
INCLUDE = -Iinc/
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
	$(CC) -c $(SRC_DIR)/main.c -o $(OBJ_DIR)/main.o $(CFLAGS) $(INCLUDE)
	$(CC) -c $(SRC_DIR)/attack_process.c -o $(OBJ_DIR)/attack_process.o $(CFLAGS) $(INCLUDE)
	$(CC) -c $(SRC_DIR)/io.c -o $(OBJ_DIR)/io.o $(CFLAGS) $(INCLUDE)
	@echo "Compile loic"
	$(CC) $(SRC_DIR)/loic.c -o $(BIN_DIR)/loic $(CFLAGS)
	@echo "Compile objects to main"
	$(CC)  $(OBJ_DIR)/attack_process.o $(OBJ_DIR)/main.o $(OBJ_DIR)/io.o -o $(BIN_DIR)/$(PROGRAM)
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

# Declare all modules
include controller/Makefile
include model/Makefile
include pathfinding/Makefile
include view/Makefile
include fileManager/Makefile

CC=gcc
FLAGS=-W -Wall -g
LDFLAGS=-lm -lSDL -lpthread
EXEC=pathfinder

ALL_BINARIES := pathfinder

MAIN_PACKAGE := main.o

ALL_OBJECTS :=
ALL_OBJECTS += $(CONTROLLER_PACKAGE)
ALL_OBJECTS += $(MODEL_PACKAGE)
ALL_OBJECTS += $(PATHFINDING_PACKAGE)
ALL_OBJECTS += $(VIEW_PACKAGE)
ALL_OBJECTS += $(FILE_PACKAGE)
ALL_OBJECTS += $(MAIN_PACKAGE)

all: $(ALL_BINARIES)

$(ALL_BINARIES): $(CONTROLLER_PACKAGE) $(MODEL_PACKAGE)	$(PATHFINDING_PACKAGE) $(VIEW_PACKAGE) $(MAIN_PACKAGE) $(FILE_PACKAGE)
	$(CC) $^ $(FLAGS) $(LDFLAGS) -o $@



# Remove all the object files
clean:
	@rm -f $(ALL_OBJECTS)

# Remove all the binaries and objects files
mrproper:
	@rm -f $(ALL_OBJECTS)
	@rm -f $(ALL_BINARIES)

# Default command to produce object files with C sources.
%.o: %.c
	@$(CC) $(FLAGS) $(LDFLAGS) -o $@ -c $<

# Standard
## Used standard is 2011 C with GNU extensions.
STANDARD ?= --std=gnu11

# Warnings (simple)
## -Wall and -Wextra: enable warnings and extra warnings.
## -Wformat-security and -Wformat-nonliteral: checks on format strings.
## -Wpointer-arith: warn when you make arithmetic on pointer (like void *).
## -Winit-self: warn when "int i=i;"
## -Wmissing-include-dirs: Warn if a user-supplied include directory does not exist.
## -Wswitch-default: Warn whenever a "switch" statement does not have a "default" case.
## -Wuninitialized: Warn if an automatic variable is used without first being initialized or if a variable may be clobbered by a "setjmp" call.
## -Wunknown-pragmas: Warn when a "#pragma" directive is encountered that is not understood by GCC.
## -Wsuggest-attribute=pure/const/noreturn: Warn about functions that might be candidates for attributes "pure", "const" or "noreturn".
## -Wmissing-format-attribute: Warn about function pointers that might be candidates for "format" attributes.
## -Wtrampolines: Warn about trampolines generated for pointers to nested functions.
## -Wshadow: Warn whenever a local variable or type declaration shadows another variable, parameter, type, class member (in C++), or instance variable (in Objective-C) or whenever a built-in function is shadowed.
## -Wunsafe-loop-optimizations: Warn if the loop cannot be optimized because the compiler cannot assume anything on the bounds of the loop indices.
## -Wconversion: Warn for implicit conversions that may alter a value.
## -Wlogical-op: Warn about suspicious uses of logical operators in expressions.
## -Wredundant-decls: Warn if anything is declared more than once in the same scope, even in cases where multiple declaration is valid and changes nothing.
## -Wsuggest-attribute=format: Warn about function pointers that might be candidates for "format" attributes.
WARNINGS += -Wall -Wextra -Wformat-security -Wformat-nonliteral -Wpointer-arith  -Winit-self -Wmissing-include-dirs \
-Wswitch-default -Wuninitialized -Wunknown-pragmas -Wsuggest-attribute=pure -Wsuggest-attribute=const \
-Wsuggest-attribute=noreturn -Wmissing-format-attribute  \
 -Wtrampolines -Wshadow \
-Wunsafe-loop-optimizations -Wconversion -Wlogical-op  \
-Wredundant-decls -Winvalid-pch -Wdisabled-optimization -Wstack-protector \
-Wno-unused-parameter -Wsuggest-attribute=format

# Security
## Enable stack protector and hide fields by default.
SECURITY ?= -fstack-protector-all -fvisibility=hidden -D_FORTIFY_SOURCE=2

# Debug
DEBUG ?= 0
ifeq ($(DEBUG), 1)
## DEBUG MODE
### Enable max. debug and targeting GDB.
DBG+=-DDEBUG -ggdb3
### Enable only debug compatible optimization
OPTIM:=-Og
else
## PROD MODE.
### Define a macro called NDEBUG to allow to define specific prod sections in code
DBG+=-DNDEBUG
### -Os: Optimize for size
### -ffunction-sections: define a section by functions.
### -fPIC: create position independent code
OPTIM:=-Os -ffunction-sections -fPIC
endif

# Dependencies
## SDL
CFLAGS+=$(shell sdl-config --cflags)
LDFLAGS+=$(shell sdl-config --libs)

# Final values
CC=gcc
CFLAGS+=-pipe ${STANDARD} ${WARNINGS} ${SECURITY} ${DBG} ${OPTIM}
LDFLAGS+=-pipe ${DBG} ${OPTIM} ${SECURITY}

EXEC=pathfinder

all: $(EXEC)

$(EXEC): astar_pathfinding.o main.o node_managment.o graph_managment.o resolutionView.o creationView.o graph_view_managment.o sdl_drawing.o resolution_view_managment.o creation_view_managment.o
	$(CC) $^ $(LDFLAGS)  -o $@

astar_pathfinding.o: astar_pathfinding.c node_managment.h resolution_view_managment.h
node_managment.o: node_managment.c graph_managment.h
graph_managment.o: graph_managment.c
resolutionView.o: resolutionView.c astar_pathfinding.h
creationView.o: creationView.c creation_view_managment.h
graph_view_managment.o: graph_view_managment.c sdl_drawing.h
resolution_view_managment.o: resolution_view_managment.c graph_view_managment.h
creation_view_managment.o: creation_view_managment.c graph_view_managment.h
sdl_drawing.o: sdl_drawing.c graph_managment.h
main.o: main.c astar_pathfinding.h resolutionView.h creationView.h

.PHONY: clean mrproper

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)

# Default command to produce object files with C sources.
%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $<

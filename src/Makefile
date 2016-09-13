CC=gcc
FLAGS=-W -Wall
LDFLAGS=-lSDL #Linker
EXEC=pathfinder

all: $(EXEC)

$(EXEC): astar_pathfinding.o main.o node_managment.o graph_managment.o view.o
	$(CC) -o $(EXEC) astar_pathfinding.o main.o node_managment.o graph_managment.o view.o ${LDFLAGS}

astar_pathfinding.o: astar_pathfinding.c node_managment.h
	$(CC) -o astar_pathfinding.o -c astar_pathfinding.c $(FLAGS)

node_managment.o: node_managment.c graph_managment.h
	$(CC) -o node_managment.o -c node_managment.c $(FLAGS)

graph_managment.o: graph_managment.c
	$(CC) -o graph_managment.o -c graph_managment.c $(FLAGS)

view.o: view.c graph_managment.h
	$(CC) -o view.o -c view.c $(FLAGS)


main.o: main.c astar_pathfinding.h view.h
	$(CC) -o main.o -c main.c $(FLAGS)

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
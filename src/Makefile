CC=gcc
FLAGS=-W -Wall -g
LDFLAGS=-lm -lSDL -lpthread
EXEC=pathfinder

all: $(EXEC)

$(EXEC): astar_pathfinding.o main.o node_managment.o graph_managment.o resolutionView.o creationView.o graph_view_managment.o sdl_drawing.o resolution_view_managment.o creation_view_managment.o
	$(CC) -o $(EXEC) astar_pathfinding.o main.o node_managment.o graph_managment.o resolutionView.o creationView.o graph_view_managment.o sdl_drawing.o resolution_view_managment.o creation_view_managment.o ${LDFLAGS}

astar_pathfinding.o: astar_pathfinding.c node_managment.h resolution_view_managment.h
	$(CC) -o astar_pathfinding.o -c astar_pathfinding.c $(FLAGS)

node_managment.o: node_managment.c graph_managment.h
	$(CC) -o node_managment.o -c node_managment.c $(FLAGS)

graph_managment.o: graph_managment.c
	$(CC) -o graph_managment.o -c graph_managment.c $(FLAGS)

resolutionView.o: resolutionView.c astar_pathfinding.h
	$(CC) -o resolutionView.o -c resolutionView.c $(FLAGS)

creationView.o: creationView.c creation_view_managment.h
	$(CC) -o creationView.o -c creationView.c $(FLAGS)

graph_view_managment.o: graph_view_managment.c sdl_drawing.h 
	$(CC) -o graph_view_managment.o -c graph_view_managment.c $(FLAGS)

resolution_view_managment.o: resolution_view_managment.c graph_view_managment.h 
	$(CC) -o resolution_view_managment.o -c resolution_view_managment.c $(FLAGS)

creation_view_managment.o: creation_view_managment.c graph_view_managment.h 
	$(CC) -o creation_view_managment.o -c creation_view_managment.c $(FLAGS)

sdl_drawing.o: sdl_drawing.c graph_managment.h
	$(CC) -o sdl_drawing.o -c sdl_drawing.c $(FLAGS)


main.o: main.c astar_pathfinding.h resolutionView.h creationView.h
	$(CC) -o main.o -c main.c $(FLAGS)

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
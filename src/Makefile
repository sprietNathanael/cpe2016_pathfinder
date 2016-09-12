CC=gcc
FLAGS=-W -Wall
EXEC=pathfinder

all: $(EXEC)

$(EXEC): pathfinding.o main.o
	$(CC) -o $(EXEC) pathfinding.o main.o

pathfinding.o: pathfinding.c
	$(CC) -o pathfinding.o -c pathfinding.c $(FLAGS)

main.o: main.c
	$(CC) -o main.o -c main.c $(FLAGS)

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
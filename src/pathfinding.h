#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#ifndef PATHFINDING_H

typedef struct Coordinates Coordinates;
struct Coordinates
{
    int x;
    int y;
};


void generateGraph(int numRow, int numCol, char graph[numRow][numCol]);
void launchPathResolution(void);
void displayGraph(int numRow, int numCol, char graph[numRow][numCol]);
Coordinates findCoordinates(int numRow, int numCol, char graph[numRow][numCol], char charToFind);

#define PATHFINDING_H
#endif
#include <stdlib.h>
#include <stdio.h>

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

#define PATHFINDING_H
#endif
#include <stdlib.h>
#include <stdio.h>

#ifndef PATHFINDING_H

void generateGraph(int numRow, int numCol, char graph[numRow][numCol]);
void launchPathResolution(void);
void displayGraph(int numRow, int numCol, char graph[numRow][numCol]);

#define PATHFINDING_H
#endif
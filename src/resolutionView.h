#ifndef RESOLUTION_VIEW_H
#define RESOLUTION_VIEW_H

#include <pthread.h>
#include "astar_pathfinding.h"
// #include <SDL/SDL_ttf.h>

#define SLOW_RESOLUTION_TIME 400*1000

/**
 * @brief      Structure that helps in thread creation
 */
typedef struct {
    int numRow;
    int numCol;
    char* graph;
    Coordinates* finalPath;
    int time;
    int stepByStep;
} launchPathResolution_args;

void mainResolvLoop(int numRow, int numCol, char* graph, int* state);
int launchResolveView(int numRow, int numCol, char* graph);
void * resolutionAndDrawing_thread(void* args);

#endif /* RESOLUTION_VIEW_H */
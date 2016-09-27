#ifndef VIEW_H
#define VIEW_H

#include <pthread.h>
#include "astar_pathfinding.h"
// #include <SDL/SDL_ttf.h>

#define SLOW_RESOLUTION_TIME 100*1000

/**
 * @brief      Structure that helps in thread creation
 */
typedef struct {
    int numRow;
    int numCol;
    char* graph;
    Coordinates* finalPath;
    int time;
    int* finalPathLength;
} launchPathResolution_args;

void mainSDLLoop(int numRow, int numCol, char* graph);
int launchView(int numRow, int numCol, char* graph);
void * resolutionAndDrawing_thread(void* args);

#endif /* VIEW_H */
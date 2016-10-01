#ifndef RESOLUTION_VIEW_H
#define RESOLUTION_VIEW_H

#include <pthread.h>
#include "astar_pathfinding.h"

#ifndef RESOLUTION_VIEW_C
#define PUBLIC extern
#else
#define PUBLIC
#endif


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

PUBLIC void mainResolvLoop(int numRow, int numCol, char* graph, int* state);
PUBLIC int launchResolveView(int numRow, int numCol, char* graph);
PUBLIC void * resolutionAndDrawing_thread(void* args);

#undef RESOLUTION_VIEW
#endif /* RESOLUTION_VIEW_H */

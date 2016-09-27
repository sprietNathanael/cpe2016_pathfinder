#ifndef VIEW_H
#define VIEW_H


#include <pthread.h>
#include "astar_pathfinding.h"
// #include <SDL/SDL_ttf.h>

#define SLOW_RESOLUTION_TIME 100*1000

void mainSDLLoop(int numRow, int numCol, char* graph);
int launchView(int numRow, int numCol, char* graph);

#endif /* VIEW_H */
#ifndef VIEW_H
#define VIEW_H

#define POS_START_X 5
#define POS_START_Y 5
#define SIZE_X 25
#define SIZE_Y 25
#define OFFSET_X 5
#define OFFSET_Y 5
#define POS_BUTTON_X 300
#define POS_BUTTON_Y 300
#define SIZE_BUTTON_X 80
#define SIZE_BUTTON_Y 40


#include <SDL/SDL.h>
#include "astar_pathfinding.h"
// #include <SDL/SDL_ttf.h>

void pause(SDL_Surface* ecran, int numRow, int numCol, char graph[numRow][numCol]);
int launchView(int numRow, int numCol, char graph[numRow][numCol]);
void createGraph(int numRow, int numCol, char graph[numRow][numCol], SDL_Surface* ecran);
int isPointInRectangle(SDL_Rect rect, Coordinates point);
void drawLineBetweenTwoNodes(SDL_Surface* nodeA, SDL_Surface* nodeB);

#endif /* VIEW_H */
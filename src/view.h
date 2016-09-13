#ifndef VIEW_H
#define VIEW_H

#define POS_START_X 5
#define POS_START_Y 5
#define SIZE_X 25
#define SIZE_Y 25
#define OFFSET_X 5
#define OFFSET_Y 5


#include <SDL/SDL.h>

void pause(SDL_Surface* ecran);
int launchView(int numRow, int numCol, char graph[numRow][numCol]);
void createGraph(int numRow, int numCol, char graph[numRow][numCol], SDL_Surface* ecran);

#endif /* VIEW_H */
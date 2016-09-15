#ifndef SDL_DRAWING
#define SDL_DRAWING

#include <SDL/SDL.h>
#include <math.h>
#include "graph_managment.h"

int isPointInRectangle(SDL_Rect rect, Coordinates point);
void drawLineBetweenTwoNodes(SDL_Rect nodeA, SDL_Rect nodeB, SDL_Surface* surface);
void echangerEntiers(int* x, int* y);
void ligne(Coordinates nodeA, Coordinates nodeB, int weight, Uint32 coul, SDL_Surface* surface);
void setPixelVerif(int x, int y, Uint32 coul, SDL_Surface* surface);

#endif
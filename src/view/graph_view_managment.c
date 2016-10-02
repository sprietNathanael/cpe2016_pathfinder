/**
 * @file graph_view_managment.c
 * @brief      Create a graph into a window
 * @author     Nathanaël SPRIET
 */

#include "graph_view_managment.h"

/*
 **************************** Globals *************************
*/
/**
 * @brief      Main SDL surface shared with the whole application
 */
SDL_Surface* screen = NULL;
/**
 * @brief      The start node Coordinates
 */
Coordinates startCoordinates;
/**
 * @brief      The target node Coordinates
 */
Coordinates targetCoordinates;
/**
 * @brief      A pointer to an array of SDL_Surface that represents each node
 */
SDL_Surface** rectangleGraph;
/**
 * @brief      An array of SDL_Rect that represents each node
 */
SDL_Rect* positionGraph;

void createGraph(int numRow, int numCol, char* graph)
{
    rectangleGraph = malloc((numRow*numCol) * sizeof(SDL_Surface*));
    positionGraph = malloc((numRow*numCol) * sizeof(SDL_Rect));
	Uint32 common = SDL_MapRGB(screen->format, 255, 255, 255);
	Uint32 start = SDL_MapRGB(screen->format, 0, 255, 0);
	Uint32 target = SDL_MapRGB(screen->format, 255, 0, 0);
	Uint32 wall = SDL_MapRGB(screen->format, 0, 0, 0);
	Uint32 color;
	int currentX = POS_START_X;
	int currentY = POS_START_Y;
	int i = 0;
	int j = 0;
	/* Graph browsing */
	for(i = 0; i < numRow; i++)
	{
		for(j = 0; j < numCol; j++)
		{
			/* For each cell of graph, creates a sdl rect */
            rectangleGraph[(i*numCol)+j] = SDL_CreateRGBSurface(SDL_HWSURFACE, SIZE_X, SIZE_Y, 32, 0, 0, 0, 0);
            positionGraph[(i*numCol)+j].x = currentX;
            positionGraph[(i*numCol)+j].y = currentY;
            /* Select the color according to the type of the cell */
            if(graph[(i*numCol)+j]== '0')
            {
                color = common;
            }
            else if(graph[(i*numCol)+j] == 'W')
            {
                color = wall;
            }
            else if(graph[(i*numCol)+j] == 'S')
            {
                color = start;
                startCoordinates.x = j;
                startCoordinates.y = i;

            }
            else if(graph[(i*numCol)+j] == 'T')
            {
                color = target;
                targetCoordinates.x = j;
                targetCoordinates.y = i;
            }
            SDL_FillRect(rectangleGraph[(i*numCol)+j], NULL, color);                
            SDL_BlitSurface(rectangleGraph[(i*numCol)+j], NULL, screen, &positionGraph[(i*numCol)+j]);
            currentX += SIZE_X+OFFSET_X;
        }
        currentX = POS_START_X;
        currentY += SIZE_Y+OFFSET_Y;
    }
    SDL_Flip(screen);
}

void drawLineBetweenTwoNodes(Coordinates nodeA, Coordinates nodeB,int r,int g,int b)
{
    Coordinates firstCoordinates = computeSDLCoordinatesFromGraphPosition(nodeA);
    Coordinates secondCoordintates = computeSDLCoordinatesFromGraphPosition(nodeB);
    ligne(firstCoordinates, secondCoordintates, 5, SDL_MapRGB(screen->format, r, g, b), screen);
}

Coordinates computeSDLCoordinatesFromGraphPosition(Coordinates cell)
{
	Coordinates sdlCoordinates = {0,0};
	sdlCoordinates.x = POS_START_X+(cell.x * (OFFSET_X+SIZE_X))+(SIZE_X/2);
	sdlCoordinates.y = POS_START_Y+(cell.y * (OFFSET_Y+SIZE_Y))+(SIZE_Y/2);
	return sdlCoordinates;
}

void changeRectangeColor(Coordinates graphPosition,int numCol, int r,int g,int b)
{
    int i = (graphPosition.y*numCol)+graphPosition.x;
    Uint32 color = SDL_MapRGB(screen->format, r, g, b);
    rectangleGraph[i] = SDL_CreateRGBSurface(SDL_HWSURFACE, SIZE_X, SIZE_Y, 32, 0, 0, 0, 0);
    SDL_FillRect(rectangleGraph[i], NULL, color);                
    SDL_BlitSurface(rectangleGraph[i], NULL, screen, &positionGraph[i]);
    SDL_Flip(screen);
}

Coordinates computeThePointedNodeCoordinatesFromSDL(int numCol, int x, int y)
{
    Coordinates pointedNode = {-1,-1};
    Coordinates interNode = {x,y};
    int testXMin = x < OFFSET_X;
    int testXMax = x > OFFSET_X+(numCol*(SIZE_X+OFFSET_X));
    int testYMin = y < OFFSET_Y;
    int testYMax = y > OFFSET_Y+(numCol*(SIZE_Y+OFFSET_Y));
    if((testXMin || testXMax) || (testYMin || testYMax))
    {
        return pointedNode;
    }
    int tempX = (x-OFFSET_X)/(SIZE_X+OFFSET_X);
    int tempY = (y-OFFSET_Y)/(SIZE_Y+OFFSET_Y);
    if(isPointInRectangle(positionGraph[(tempY*numCol)+tempX], interNode))
    {
        pointedNode.x = tempX;
        pointedNode.y = tempY;
        return pointedNode;
    }
    else
    {
        return pointedNode;
    }
}
#include "graph_view_managment.h"

SDL_Surface* ecran = NULL;
SDL_Rect findPathButton_position;
SDL_Rect clearButton_position;
Coordinates startCoordinates;
Coordinates targetCoordinates;
SDL_Surface** rectangleGraph;
SDL_Rect* positionGraph;

void sdlInit()
{
	SDL_Init(SDL_INIT_VIDEO);

	/**
	 * Screen creation
	 */
	ecran = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE);
    if (ecran == NULL)    {
        fprintf(stderr, "Impossible de charger le mode vidéo : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }    
    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 204, 204, 204));

    /*
     ***************************** Buttons creation *************************
    */
    /**
     * Creates Find Path button
    */
    SDL_Surface *findPathButton = NULL;
    findPathButton_position.x = POS_FIND_PATH_BUTTON_X;
    findPathButton_position.y = POS_FIND_PATH_BUTTON_Y;
    findPathButton = SDL_CreateRGBSurface(SDL_HWSURFACE, SIZE_BUTTON_X,SIZE_BUTTON_Y,32,0,0,0,0);
    SDL_FillRect(findPathButton, NULL, SDL_MapRGB(ecran->format, 150,150,150));
    SDL_BlitSurface(findPathButton, NULL, ecran, &findPathButton_position);
    /**
     * Creates Clear button
    */
    SDL_Surface *clearButton = NULL;
    SDL_Flip(ecran);
    clearButton_position.x = POS_CLEAR_BUTTON_X;
    clearButton_position.y = POS_CLEAR_BUTTON_Y;
    clearButton = SDL_CreateRGBSurface(SDL_HWSURFACE, SIZE_BUTTON_X,SIZE_BUTTON_Y,32,0,0,0,0);
    SDL_FillRect(clearButton, NULL, SDL_MapRGB(ecran->format, 255,0,0));
    SDL_BlitSurface(clearButton, NULL, ecran, &clearButton_position);

    SDL_Flip(ecran);

}

int findPathButtonClicked(Coordinates cursorPosition)
{
	return isPointInRectangle(findPathButton_position, cursorPosition);
}

int clearButtonClicked(Coordinates cursorPosition)
{
    return isPointInRectangle(clearButton_position, cursorPosition);
}

void createGraph(int numRow, int numCol, char* graph)
{
    rectangleGraph = malloc((numRow*numCol) * sizeof(SDL_Surface*));
    positionGraph = malloc((numRow*numCol) * sizeof(SDL_Rect));
	Uint32 common = SDL_MapRGB(ecran->format, 255, 255, 255);
	Uint32 start = SDL_MapRGB(ecran->format, 0, 255, 0);
	Uint32 target = SDL_MapRGB(ecran->format, 255, 0, 0);
	Uint32 wall = SDL_MapRGB(ecran->format, 0, 0, 0);
	Uint32 color;
	int currentX = POS_START_X;
	int currentY = POS_START_Y;
	int i = 0;
	int j = 0;
	/**
	 * Graph browsing
	 */
	for(i = 0; i < numRow; i++)
	{
		for(j = 0; j < numCol; j++)
		{
			/**
			 * For each cell of graph, creates a sdl rect
			 */
            rectangleGraph[(i*numCol)+j] = SDL_CreateRGBSurface(SDL_HWSURFACE, SIZE_X, SIZE_Y, 32, 0, 0, 0, 0);
            positionGraph[(i*numCol)+j].x = currentX;
            positionGraph[(i*numCol)+j].y = currentY;
            /**
             * Select the color according to the type of the cell
             */
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
            SDL_BlitSurface(rectangleGraph[(i*numCol)+j], NULL, ecran, &positionGraph[(i*numCol)+j]); // Collage de la surface sur l'écran
            currentX += SIZE_X+OFFSET_X;
        }
        currentX = POS_START_X;
        currentY += SIZE_Y+OFFSET_Y;
    }
    SDL_Flip(ecran);
}


void drawFinalPath(int finalPathLength, int numRow, int numCol, Coordinates finalPath[numRow*numCol])
{
    int i = 0;
    Coordinates secondCoordintates = {0,0};
    Coordinates firstCoordinates = {0,0};
    /**
     * Browses the final path and draw a line between each nodes
     */
    for(i = finalPathLength-2;i >= 0;--i)
    {
    	Coordinates currentPosition = finalPath[i];
    	firstCoordinates = computeSDLCoordinatesFromGraphPosition(currentPosition);
    	secondCoordintates = computeSDLCoordinatesFromGraphPosition(finalPath[i+1]);
        drawLineBetweenTwoNodes(firstCoordinates,secondCoordintates,ecran);
    }
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
    Uint32 color = SDL_MapRGB(ecran->format, r, g, b);
    rectangleGraph[i] = SDL_CreateRGBSurface(SDL_HWSURFACE, SIZE_X, SIZE_Y, 32, 0, 0, 0, 0);
    SDL_FillRect(rectangleGraph[i], NULL, color);                
    SDL_BlitSurface(rectangleGraph[i], NULL, ecran, &positionGraph[i]); // Collage de la surface sur l'écran
    SDL_Flip(ecran);
}

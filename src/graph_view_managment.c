#include "graph_view_managment.h"

SDL_Surface* ecran = NULL;
SDL_Rect findPathButton_position;
Coordinates startCoordinates;
Coordinates targetCoordinates;

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
    SDL_Flip(ecran);

    /**
     * Button creation
     */
    SDL_Surface *findPathButton = NULL;
    findPathButton_position.x = POS_BUTTON_X;
    findPathButton_position.y = POS_BUTTON_Y;
    findPathButton = SDL_CreateRGBSurface(SDL_HWSURFACE, SIZE_BUTTON_X,SIZE_BUTTON_Y,32,0,0,0,0);
    SDL_FillRect(findPathButton, NULL, SDL_MapRGB(ecran->format, 150,150,150));
    SDL_BlitSurface(findPathButton, NULL, ecran, &findPathButton_position);

}

int findPathButtonClicked(Coordinates cursorPosition)
{
	return isPointInRectangle(findPathButton_position, cursorPosition);
}

void createGraph(int numRow, int numCol, char graph[numRow][numCol])
{
	SDL_Surface *rectangleGraph[numRow][numCol];
	SDL_Rect positionGraph[numRow][numCol];
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
			rectangleGraph[i][j] = SDL_CreateRGBSurface(SDL_HWSURFACE, SIZE_X, SIZE_Y, 32, 0, 0, 0, 0);
			positionGraph[i][j].x = currentX;
    		positionGraph[i][j].y = currentY;
    		/**
    		 * Select the color according to the type of the cell
    		 */
    		if(graph[i][j]== '0')
    		{
    			color = common;
    		}
    		else if(graph[i][j] == 'W')
    		{
                color = wall;
            }
            else if(graph[i][j] == 'S')
            {
                color = start;
                startCoordinates.x = j;
                startCoordinates.y = i;

            }
            else if(graph[i][j] == 'T')
            {
                color = target;
                targetCoordinates.x = j;
                targetCoordinates.y = i;
            }
            SDL_FillRect(rectangleGraph[i][j], NULL, color);                
            SDL_BlitSurface(rectangleGraph[i][j], NULL, ecran, &positionGraph[i][j]); // Collage de la surface sur l'écran
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
    	printf("Test : i = %d : (%d;%d) : (%d;%d) -> (%d;%d) : (%d;%d)\n",i,currentPosition.x,currentPosition.y,firstCoordinates.x,firstCoordinates.y,finalPath[i+1].x,finalPath[i+1].y,secondCoordintates.x,secondCoordintates.y);
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
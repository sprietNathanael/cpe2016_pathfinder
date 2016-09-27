#include "graph_view_managment.h"

SDL_Surface* ecran = NULL;
SDL_Rect findPathButton_position;
SDL_Rect clearButton_position;
SDL_Rect slow_findPathButton_position;
SDL_Rect nextStepButton_position;
SDL_Rect buildButton_position;
Coordinates startCoordinates;
Coordinates targetCoordinates;
SDL_Surface** rectangleGraph;
SDL_Rect* positionGraph;
int graphHeight;
int graphWidth;

void sdlResolvInit(int numRow, int numCol)
{
	SDL_Init(SDL_INIT_VIDEO);
    int height;
	/**
	 * Screen creation
	 */
    graphHeight = numRow*(SIZE_Y+OFFSET_Y)+OFFSET_Y;
    if(graphHeight < MIN_WINDOW_HEIGHT)
    {
        height = MIN_WINDOW_HEIGHT;
    }
    else
    {
        height = graphHeight;
    }
    graphWidth = numCol*(SIZE_X+OFFSET_X);
    int width = MIN_WINDOW_WIDTH+graphWidth;
	ecran = SDL_SetVideoMode(width, height, 32, SDL_HWSURFACE);
    if (ecran == NULL)    {
        fprintf(stderr, "Impossible de charger le mode vidéo : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }    
    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 204, 204, 204));

    /*
     ***************************** Buttons creation *************************
    */
    /**
     ************************ Creates Find Path button
    */
    /**
     * Initialise the button
     */
    SDL_Surface *findPathButton = NULL;
    findPathButton_position.x = graphWidth+POS_BUTTON_X_BASE;
    findPathButton_position.y = POS_FIND_PATH_BUTTON_Y;
    findPathButton = SDL_CreateRGBSurface(SDL_HWSURFACE, SIZE_BUTTON_X,SIZE_BUTTON_Y,32,0,0,0,0);
    SDL_FillRect(findPathButton, NULL, SDL_MapRGB(ecran->format, 141,242,23));
    /**
     * Initialise the icon
     */
    SDL_Surface *startIcon = NULL;
    SDL_Rect startIconPosition;
    startIconPosition.x = 10;
    startIconPosition.y = 0;
    startIcon = SDL_LoadBMP("icons/start.bmp");
    /**
     * Set the color transparancy
     */
    SDL_SetColorKey(startIcon, SDL_SRCCOLORKEY, SDL_MapRGB(startIcon->format, 255, 255, 255));
    /**
     * Display the button and the icon
     */
    SDL_BlitSurface(startIcon, NULL, findPathButton, &startIconPosition);
    SDL_BlitSurface(findPathButton, NULL, ecran, &findPathButton_position);
    /**
     ************************ Creates Find Path Slow button
    */
    /**
     * Initialise the button
     */
    SDL_Surface *slow_findPathButton = NULL;
    slow_findPathButton_position.x = graphWidth+POS_BUTTON_X_BASE;
    slow_findPathButton_position.y = POS_SLOW_FIND_PATH_BUTTON_Y;
    slow_findPathButton = SDL_CreateRGBSurface(SDL_HWSURFACE, SIZE_BUTTON_X,SIZE_BUTTON_Y,32,0,0,0,0);
    SDL_FillRect(slow_findPathButton, NULL, SDL_MapRGB(ecran->format, 253,255,16));
    /**
     * Initialise the icon
     */
    SDL_Surface *slowIcon = NULL;
    SDL_Rect slowIconPosition;
    slowIconPosition.x = 10;
    slowIconPosition.y = 0;
    slowIcon = SDL_LoadBMP("icons/slow.bmp");
    /**
     * Set the color transparancy
     */
    SDL_SetColorKey(slowIcon, SDL_SRCCOLORKEY, SDL_MapRGB(slowIcon->format, 255, 255, 255));
    /**
     * Display the button and the icon
     */
    SDL_BlitSurface(slowIcon, NULL, slow_findPathButton, &slowIconPosition);
    SDL_BlitSurface(slow_findPathButton, NULL, ecran, &slow_findPathButton_position);
    /**
     ************************ Creates Clear button
    */
    /**
     * Initialise the button
     */
    SDL_Surface *clearButton = NULL;
    clearButton_position.x = graphWidth+POS_BUTTON_X_BASE;
    clearButton_position.y = POS_CLEAR_BUTTON_Y;
    clearButton = SDL_CreateRGBSurface(SDL_HWSURFACE, SIZE_BUTTON_X,SIZE_BUTTON_Y,32,0,0,0,0);
    SDL_FillRect(clearButton, NULL, SDL_MapRGB(ecran->format, 255,0,0));
    /**
     * Initialise the icon
     */
    SDL_Surface *clearIcon = NULL;
    SDL_Rect clearIconPosition;
    clearIconPosition.x = 10;
    clearIconPosition.y = 0;
    clearIcon = SDL_LoadBMP("icons/clear.bmp");
    /**
     * Set the color transparancy
     */
    SDL_SetColorKey(clearIcon, SDL_SRCCOLORKEY, SDL_MapRGB(clearIcon->format, 255, 255, 255));
    /**
     * Display the button and the icon
     */
    SDL_BlitSurface(clearIcon, NULL, clearButton, &clearIconPosition);
    SDL_BlitSurface(clearButton, NULL, ecran, &clearButton_position);
    /**
     ************************ Creates Next Step button
    */
    /**
     * Initialise the button
     */
    SDL_Surface *nextStepButton = NULL;
    nextStepButton_position.x = graphWidth+POS_BUTTON_X_BASE;
    nextStepButton_position.y = POS_NEXT_STEP_BUTTON_Y;
    nextStepButton = SDL_CreateRGBSurface(SDL_HWSURFACE, SIZE_BUTTON_X,SIZE_BUTTON_Y,32,0,0,0,0);
    SDL_FillRect(nextStepButton, NULL, SDL_MapRGB(ecran->format, 141,242,23));
    /**
     * Initialise the icon
     */
    SDL_Surface *debugIcon = NULL;
    SDL_Rect debugIconPosition;
    debugIconPosition.x = 10;
    debugIconPosition.y = 0;
    debugIcon = SDL_LoadBMP("icons/debug.bmp");
    /**
     * Set the color transparancy
     */
    SDL_SetColorKey(debugIcon, SDL_SRCCOLORKEY, SDL_MapRGB(debugIcon->format, 255, 255, 255));
    /**
     * Display the button and the icon
     */
    SDL_BlitSurface(debugIcon, NULL, nextStepButton, &debugIconPosition);
    SDL_BlitSurface(nextStepButton, NULL, ecran, &nextStepButton_position);

    /**
     ************************ Creates Build button
    */
    /**
     * Initialise the button
     */
    SDL_Surface *buildButton = NULL;
    buildButton_position.x = graphWidth+POS_BUTTON_X_BASE;
    buildButton_position.y = POS_BUILD_STEP_BUTTON_Y;
    buildButton = SDL_CreateRGBSurface(SDL_HWSURFACE, SIZE_BUTTON_X,SIZE_BUTTON_Y,32,0,0,0,0);
    SDL_FillRect(buildButton, NULL, SDL_MapRGB(ecran->format, 60,108,238));
    /**
     * Initialise the icon
     */
    SDL_Surface *buildIcon = NULL;
    SDL_Rect buildIconPosition;
    buildIconPosition.x = 10;
    buildIconPosition.y = 0;
    buildIcon = SDL_LoadBMP("icons/build.bmp");
    /**
     * Set the color transparancy
     */
    SDL_SetColorKey(buildIcon, SDL_SRCCOLORKEY, SDL_MapRGB(buildIcon->format, 255,255,255));
    /**
     * Display the button and the icon
     */
    SDL_BlitSurface(buildIcon, NULL, buildButton, &debugIconPosition);
    SDL_BlitSurface(buildButton, NULL, ecran, &buildButton_position);


    SDL_Flip(ecran);

}

void sdlCreationInit(int numRow, int numCol)
{
    SDL_Init(SDL_INIT_VIDEO);
    int height;
    /**
     * Screen creation
     */
    graphHeight = numRow*(SIZE_Y+OFFSET_Y)+OFFSET_Y;
    if(graphHeight < MIN_WINDOW_HEIGHT)
    {
        height = MIN_WINDOW_HEIGHT;
    }
    else
    {
        height = graphHeight;
    }
    graphWidth = numCol*(SIZE_X+OFFSET_X);
    int width = MIN_WINDOW_WIDTH+graphWidth;
    ecran = SDL_SetVideoMode(width, height, 32, SDL_HWSURFACE);
    if (ecran == NULL)    {
        fprintf(stderr, "Impossible de charger le mode vidéo : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }    
    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 204, 204, 204));
    SDL_Flip(ecran);

}

void changeDebugButtonIcon()
{
    /**
     ************************ Creates Next Step button
    */
    /**
     * Initialise the button
     */
    SDL_Surface *nextStepButton = NULL;
    nextStepButton = SDL_CreateRGBSurface(SDL_HWSURFACE, SIZE_BUTTON_X,SIZE_BUTTON_Y,32,0,0,0,0);
    SDL_FillRect(nextStepButton, NULL, SDL_MapRGB(ecran->format, 141,242,23));
    /**
     * Initialise the icon
     */
    SDL_Surface *debugIcon = NULL;
    SDL_Rect debugIconPosition;
    debugIconPosition.x = 10;
    debugIconPosition.y = 0;
    debugIcon = SDL_LoadBMP("icons/next.bmp");
    /**
     * Set the color transparancy
     */
    SDL_SetColorKey(debugIcon, SDL_SRCCOLORKEY, SDL_MapRGB(debugIcon->format, 255, 255, 255));
    /**
     * Display the button and the icon
     */
    SDL_BlitSurface(debugIcon, NULL, nextStepButton, &debugIconPosition);
    SDL_BlitSurface(nextStepButton, NULL, ecran, &nextStepButton_position);


    SDL_Flip(ecran);
}

int findPathButtonClicked(Coordinates cursorPosition)
{
	return isPointInRectangle(findPathButton_position, cursorPosition);
}

int slow_findPathButtonClicked(Coordinates cursorPosition)
{
    return isPointInRectangle(slow_findPathButton_position, cursorPosition);
}

int clearButtonClicked(Coordinates cursorPosition)
{
    return isPointInRectangle(clearButton_position, cursorPosition);
}

int nextStepButtonClicked(Coordinates cursorPosition)
{
    return isPointInRectangle(nextStepButton_position, cursorPosition);
}

int buildButtonClicked(Coordinates cursorPosition)
{
    return isPointInRectangle(buildButton_position, cursorPosition);
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
        drawLineBetweenTwoNodes(finalPath[i],finalPath[i+1], 255, 255, 0);
    }
}

void drawLineBetweenTwoNodes(Coordinates nodeA, Coordinates nodeB,int r,int g,int b)
{
    Coordinates firstCoordinates = computeSDLCoordinatesFromGraphPosition(nodeA);
    Coordinates secondCoordintates = computeSDLCoordinatesFromGraphPosition(nodeB);
    ligne(firstCoordinates, secondCoordintates, 5, SDL_MapRGB(ecran->format, r, g, b), ecran);
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

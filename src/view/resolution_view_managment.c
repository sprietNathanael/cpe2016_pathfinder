/**
 * @file resolution_view_managment.c
 * @brief      Create a resolution window
 * @author     Nathanaël SPRIET
 */

#include "resolution_view_managment.h"
/*
 **************************** Globals *************************
*/
/**
 * @brief      The find path button position
 */
SDL_Rect findPathButton_position;
/**
 * @brief      The clear button position
 */
SDL_Rect clearButton_position;
/**
 * @brief      The slow find path button position
 */
SDL_Rect slow_findPathButton_position;
/**
 * @brief      The next step button position
 */
SDL_Rect nextStepButton_position;
/**
 * @brief      The algo selection button position
 */
SDL_Rect algoSelectButton_position;
/**
 * @brief      The build button position
 */
SDL_Rect buildButton_position;

/*
 **************************** Core *************************
*/

void sdlResolvInit(int numRow, int numCol)
{
    int graphHeight;
    int graphWidth;
	SDL_Init(SDL_INIT_VIDEO);
    int height;
	/* Screen creation */
    graphHeight = numRow*(SIZE_Y+OFFSET_Y)+OFFSET_Y;
    if(graphHeight < MIN_RESOLUTION_WINDOW_HEIGHT)
    {
        height = MIN_RESOLUTION_WINDOW_HEIGHT;
    }
    else
    {
        height = graphHeight;
    }
    graphWidth = numCol*(SIZE_X+OFFSET_X);
    int width = MIN_RESOLUTION_WINDOW_WIDTH+graphWidth;
	screen = SDL_SetVideoMode(width, height, 32, SDL_HWSURFACE);
    if (screen == NULL)    {
        fprintf(stderr, "Impossible de charger le mode vidéo : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }    
    SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 204, 204, 204));

    /*
     ***************************** Buttons creation *************************
    */
    /*
     ************************ Creates Find Path button
    */
    /* Initialise the button */
    SDL_Surface *findPathButton = NULL;
    findPathButton_position.x = graphWidth+POS_BUTTON_X_BASE;
    findPathButton_position.y = POS_FIND_PATH_BUTTON_Y;
    findPathButton = SDL_CreateRGBSurface(SDL_HWSURFACE, SIZE_BUTTON_X,SIZE_BUTTON_Y,32,0,0,0,0);
    SDL_FillRect(findPathButton, NULL, SDL_MapRGB(screen->format, 141,242,23));
    /* Initialise the icon */
    SDL_Surface *startIcon = NULL;
    SDL_Rect startIconPosition;
    startIconPosition.x = 10;
    startIconPosition.y = 0;
    startIcon = SDL_LoadBMP("view/icons/start.bmp");
    /* Set the color transparancy */
    SDL_SetColorKey(startIcon, SDL_SRCCOLORKEY, SDL_MapRGB(startIcon->format, 255, 255, 255));
    /* Display the button and the icon */
    SDL_BlitSurface(startIcon, NULL, findPathButton, &startIconPosition);
    SDL_BlitSurface(findPathButton, NULL, screen, &findPathButton_position);
    /*
     ************************ Creates Find Path Slow button
    */
    /* Initialise the button */
    SDL_Surface *slow_findPathButton = NULL;
    slow_findPathButton_position.x = graphWidth+POS_BUTTON_X_BASE;
    slow_findPathButton_position.y = POS_SLOW_FIND_PATH_BUTTON_Y;
    slow_findPathButton = SDL_CreateRGBSurface(SDL_HWSURFACE, SIZE_BUTTON_X,SIZE_BUTTON_Y,32,0,0,0,0);
    SDL_FillRect(slow_findPathButton, NULL, SDL_MapRGB(screen->format, 253,255,16));
    /* Initialise the icon */
    SDL_Surface *slowIcon = NULL;
    SDL_Rect slowIconPosition;
    slowIconPosition.x = 10;
    slowIconPosition.y = 0;
    slowIcon = SDL_LoadBMP("view/icons/slow.bmp");
    /* Set the color transparancy */
    SDL_SetColorKey(slowIcon, SDL_SRCCOLORKEY, SDL_MapRGB(slowIcon->format, 255, 255, 255));
    /* Display the button and the icon */
    SDL_BlitSurface(slowIcon, NULL, slow_findPathButton, &slowIconPosition);
    SDL_BlitSurface(slow_findPathButton, NULL, screen, &slow_findPathButton_position);
    /*
     ************************ Creates Clear button
    */
    /* Initialise the button */
    SDL_Surface *clearButton = NULL;
    clearButton_position.x = graphWidth+POS_BUTTON_X_BASE;
    clearButton_position.y = POS_CLEAR_BUTTON_Y;
    clearButton = SDL_CreateRGBSurface(SDL_HWSURFACE, SIZE_BUTTON_X,SIZE_BUTTON_Y,32,0,0,0,0);
    SDL_FillRect(clearButton, NULL, SDL_MapRGB(screen->format, 255,0,0));
    /* Initialise the icon */
    SDL_Surface *clearIcon = NULL;
    SDL_Rect clearIconPosition;
    clearIconPosition.x = 10;
    clearIconPosition.y = 0;
    clearIcon = SDL_LoadBMP("view/icons/clear.bmp");
    /* Set the color transparancy */
    SDL_SetColorKey(clearIcon, SDL_SRCCOLORKEY, SDL_MapRGB(clearIcon->format, 255, 255, 255));
    /* Display the button and the icon */
    SDL_BlitSurface(clearIcon, NULL, clearButton, &clearIconPosition);
    SDL_BlitSurface(clearButton, NULL, screen, &clearButton_position);
    /*
     ************************ Creates Next Step button
    */
    /* Initialise the button */
    SDL_Surface *nextStepButton = NULL;
    nextStepButton_position.x = graphWidth+POS_BUTTON_X_BASE;
    nextStepButton_position.y = POS_NEXT_STEP_BUTTON_Y;
    nextStepButton = SDL_CreateRGBSurface(SDL_HWSURFACE, SIZE_BUTTON_X,SIZE_BUTTON_Y,32,0,0,0,0);
    SDL_FillRect(nextStepButton, NULL, SDL_MapRGB(screen->format, 141,242,23));
    /* Initialise the icon */
    SDL_Surface *debugIcon = NULL;
    SDL_Rect debugIconPosition;
    debugIconPosition.x = 10;
    debugIconPosition.y = 0;
    debugIcon = SDL_LoadBMP("view/icons/debug.bmp");
    /* Set the color transparancy */
    SDL_SetColorKey(debugIcon, SDL_SRCCOLORKEY, SDL_MapRGB(debugIcon->format, 255, 255, 255));
    /* Display the button and the icon */
    SDL_BlitSurface(debugIcon, NULL, nextStepButton, &debugIconPosition);
    SDL_BlitSurface(nextStepButton, NULL, screen, &nextStepButton_position);
    /*
     ************************ Creates Algo Selection button
    */
    /* Initialise the button */
    SDL_Surface *algoSelectButton = NULL;
    algoSelectButton_position.x = graphWidth+POS_BUTTON_X_BASE;
    algoSelectButton_position.y = POS_ALGO_SELECTOR_Y;
    algoSelectButton = SDL_CreateRGBSurface(SDL_HWSURFACE, SIZE_BUTTON_X,SIZE_BUTTON_Y,32,0,0,0,0);
    SDL_FillRect(algoSelectButton, NULL, SDL_MapRGB(screen->format,147,82,180));
    /* Initialise the icon */
    SDL_Surface *algoSelectIcon = NULL;
    SDL_Rect algoSelectIconPosition;
    algoSelectIconPosition.x = 10;
    algoSelectIconPosition.y = 0;
    algoSelectIcon = SDL_LoadBMP("view/icons/astar.bmp");
    /* Set the color transparancy */
    SDL_SetColorKey(algoSelectIcon, SDL_SRCCOLORKEY, SDL_MapRGB(algoSelectIcon->format, 255, 255, 255));
    /* Display the button and the icon */
    SDL_BlitSurface(algoSelectIcon, NULL, algoSelectButton, &algoSelectIconPosition);
    SDL_BlitSurface(algoSelectButton, NULL, screen, &algoSelectButton_position);
    /*
     ************************ Creates Build button
    */
    /* Initialise the button */
    SDL_Surface *buildButton = NULL;
    buildButton_position.x = graphWidth+POS_BUTTON_X_BASE;
    buildButton_position.y = POS_BUILD_STEP_BUTTON_Y;
    buildButton = SDL_CreateRGBSurface(SDL_HWSURFACE, SIZE_BUTTON_X,SIZE_BUTTON_Y,32,0,0,0,0);
    SDL_FillRect(buildButton, NULL, SDL_MapRGB(screen->format, 60,108,238));
    /* Initialise the icon */
    SDL_Surface *buildIcon = NULL;
    SDL_Rect buildIconPosition;
    buildIconPosition.x = 10;
    buildIconPosition.y = 0;
    buildIcon = SDL_LoadBMP("view/icons/build.bmp");
    /* Set the color transparancy */
    SDL_SetColorKey(buildIcon, SDL_SRCCOLORKEY, SDL_MapRGB(buildIcon->format, 255,255,255));
    /* Display the button and the icon */
    SDL_BlitSurface(buildIcon, NULL, buildButton, &buildIconPosition);
    SDL_BlitSurface(buildButton, NULL, screen, &buildButton_position);
    SDL_Flip(screen);

}

void changeDebugButtonIcon()
{
    /*
     ************************ Creates Next Step button
    */
    /* Initialise the button */
    SDL_Surface *nextStepButton = NULL;
    nextStepButton = SDL_CreateRGBSurface(SDL_HWSURFACE, SIZE_BUTTON_X,SIZE_BUTTON_Y,32,0,0,0,0);
    SDL_FillRect(nextStepButton, NULL, SDL_MapRGB(screen->format, 141,242,23));
    /* Initialise the icon */
    SDL_Surface *debugIcon = NULL;
    SDL_Rect debugIconPosition;
    debugIconPosition.x = 10;
    debugIconPosition.y = 0;
    debugIcon = SDL_LoadBMP("view/icons/next.bmp");
    /* Set the color transparancy */
    SDL_SetColorKey(debugIcon, SDL_SRCCOLORKEY, SDL_MapRGB(debugIcon->format, 255, 255, 255));
    /* Display the button and the icon */
    SDL_BlitSurface(debugIcon, NULL, nextStepButton, &debugIconPosition);
    SDL_BlitSurface(nextStepButton, NULL, screen, &nextStepButton_position);


    SDL_Flip(screen);
}

void changeAlgoSelectionButtonIcon(int djikstra)
{
    /*
     ************************ Creates Algo Selection button
    */
    /* Initialise the button */
    SDL_Surface *algoSelectButton = NULL;
    algoSelectButton = SDL_CreateRGBSurface(SDL_HWSURFACE, SIZE_BUTTON_X,SIZE_BUTTON_Y,32,0,0,0,0);
    SDL_Surface *algoSelectIcon = NULL;
    if(djikstra)
    {
        SDL_FillRect(algoSelectButton, NULL, SDL_MapRGB(screen->format,98,82,180));        
        algoSelectIcon = SDL_LoadBMP("view/icons/djikstra.bmp");
    }
    else
    {
        SDL_FillRect(algoSelectButton, NULL, SDL_MapRGB(screen->format,147,82,180));
        algoSelectIcon = SDL_LoadBMP("view/icons/astar.bmp");
    }
    /* Initialise the icon */
    SDL_Rect algoSelectIconPosition;
    algoSelectIconPosition.x = 10;
    algoSelectIconPosition.y = 0;
    /* Set the color transparancy */
    SDL_SetColorKey(algoSelectIcon, SDL_SRCCOLORKEY, SDL_MapRGB(algoSelectIcon->format, 255, 255, 255));
    /* Display the button and the icon */
    SDL_BlitSurface(algoSelectIcon, NULL, algoSelectButton, &algoSelectIconPosition);
    SDL_BlitSurface(algoSelectButton, NULL, screen, &algoSelectButton_position);


    SDL_Flip(screen);
}

void drawFinalPath(int finalPathLength, int numRow, int numCol, Coordinates finalPath[numRow*numCol])
{
    int i = 0;
    /* Browses the final path and draw a line between each nodes */
    for(i = finalPathLength-2;i >= 0;--i)
    {
        drawLineBetweenTwoNodes(finalPath[i],finalPath[i+1], 255, 255, 0);
    }
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

int algoSelectionButtonClicked(Coordinates cursorPosition)
{
    return isPointInRectangle(algoSelectButton_position, cursorPosition);
}


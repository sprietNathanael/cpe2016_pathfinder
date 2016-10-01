#define CREATION_VIEW_MANAGMENT_C
#include "creation_view_managment.h"

SDL_Rect chooseStartButton_position;
SDL_Rect chooseTargetButton_position;
SDL_Rect chooseWallButton_position;
SDL_Rect chooseBlankButton_position;
SDL_Rect choiceIndicator_position;

void sdlCreationInit(int numRow, int numCol)
{
    int graphHeight;
    int graphWidth;
    SDL_Init(SDL_INIT_VIDEO);
    int height;
    /**
     * Screen creation
     */
    graphHeight = numRow*(SIZE_Y+OFFSET_Y)+OFFSET_Y;
    if(graphHeight < MIN_CREATION_WINDOW_HEIGHT)
    {
        height = MIN_CREATION_WINDOW_HEIGHT;
    }
    else
    {
        height = graphHeight;
    }
    graphWidth = numCol*(SIZE_X+OFFSET_X);
    int width = MIN_CREATION_WINDOW_WIDTH+graphWidth;
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
     ************************ Choose Start button
    */
    /**
     * Initialise the button
     */
    SDL_Surface *chooseStartButton = NULL;
    chooseStartButton_position.x = graphWidth+POS_BUTTON_X_BASE;
    chooseStartButton_position.y = START_BUTTON_CHOICE_Y;
    chooseStartButton = SDL_CreateRGBSurface(SDL_HWSURFACE, SIZE_X,SIZE_Y,32,0,0,0,0);
    SDL_FillRect(chooseStartButton, NULL, SDL_MapRGB(ecran->format, 0,255,0));
    /**
     * Display the button
     */
    SDL_BlitSurface(chooseStartButton, NULL, ecran, &chooseStartButton_position);

    /**
     ************************ Choose Target button
    */
    /**
     * Initialise the button
     */
    SDL_Surface *chooseTargetButton = NULL;
    chooseTargetButton_position.x = graphWidth+POS_BUTTON_X_BASE;
    chooseTargetButton_position.y = TARGET_BUTTON_CHOICE_Y;
    chooseTargetButton = SDL_CreateRGBSurface(SDL_HWSURFACE, SIZE_X,SIZE_Y,32,0,0,0,0);
    SDL_FillRect(chooseTargetButton, NULL, SDL_MapRGB(ecran->format, 255,0,0));
    /**
     * Display the button
     */
    SDL_BlitSurface(chooseTargetButton, NULL, ecran, &chooseTargetButton_position);
    /**
     ************************ Choose Wall button
    */
    /**
     * Initialise the button
     */
    SDL_Surface *chooseWallButton = NULL;
    chooseWallButton_position.x = graphWidth+POS_BUTTON_X_BASE;
    chooseWallButton_position.y = WALL_BUTTON_CHOICE_Y;
    chooseWallButton = SDL_CreateRGBSurface(SDL_HWSURFACE, SIZE_X,SIZE_Y,32,0,0,0,0);
    SDL_FillRect(chooseWallButton, NULL, SDL_MapRGB(ecran->format, 0,0,0));
    /**
     * Display the button
     */
    SDL_BlitSurface(chooseWallButton, NULL, ecran, &chooseWallButton_position);
    /**
     ************************ Choose Blank button
    */
    /**
     * Initialise the button
     */
    SDL_Surface *chooseBlankButton = NULL;
    chooseBlankButton_position.x = graphWidth+POS_BUTTON_X_BASE;
    chooseBlankButton_position.y = BLANK_BUTTON_CHOICE_Y;
    chooseBlankButton = SDL_CreateRGBSurface(SDL_HWSURFACE, SIZE_X,SIZE_Y,32,0,0,0,0);
    SDL_FillRect(chooseBlankButton, NULL, SDL_MapRGB(ecran->format, 255,255,255));
    /**
     * Display the button
     */
    SDL_BlitSurface(chooseBlankButton, NULL, ecran, &chooseBlankButton_position);
    /**
     ************************ Choice indicator
    */
    /**
     * Initialise the button
     */
    SDL_Surface *choiceIndicator = NULL;
    choiceIndicator_position.x = graphWidth+POS_BUTTON_X_BASE;
    choiceIndicator_position.y = CHOICE_INDICATOR_Y;
    choiceIndicator = SDL_CreateRGBSurface(SDL_HWSURFACE, SIZE_BUTTON_X,SIZE_BUTTON_Y,32,0,0,0,0);
    SDL_FillRect(choiceIndicator, NULL, SDL_MapRGB(ecran->format, 0,0,0));
    /**
     * Display the button
     */
    SDL_BlitSurface(choiceIndicator, NULL, ecran, &choiceIndicator_position);
    SDL_Flip(ecran);



}

void changeColorIndicator(char type)
{
    Uint32 color = 0;
    if(type == 'S')
    {
        color = SDL_MapRGB(ecran->format, 0, 255, 0);
    }
    else if(type == 'T')
    {
        color = SDL_MapRGB(ecran->format, 255, 0, 0);
    }
    else if(type == 'W')
    {
        color = SDL_MapRGB(ecran->format, 0, 0, 0);

    }
    else if(type == '0')
    {
        color = SDL_MapRGB(ecran->format, 255, 255, 255);
    }
    SDL_Surface *choiceIndicator = NULL;
    choiceIndicator = SDL_CreateRGBSurface(SDL_HWSURFACE, SIZE_BUTTON_X,SIZE_BUTTON_Y,32,0,0,0,0);
    SDL_FillRect(choiceIndicator, NULL, color);
    /**
     * Display the button
     */
    SDL_BlitSurface(choiceIndicator, NULL, ecran, &choiceIndicator_position);
    SDL_Flip(ecran);
}

void changeTypeColorOfGivenNode(Coordinates node, char type, int numCol)
{
    if(type == 'S')
    {
        changeRectangeColor(node, numCol, 0, 255, 0);
    }
    else if(type == 'T')
    {
        changeRectangeColor(node, numCol, 255, 0, 0);
    }
    else if(type == 'W')
    {
        changeRectangeColor(node, numCol, 0, 0, 0);

    }
    else if(type == '0')
    {
        changeRectangeColor(node, numCol, 255, 255, 255);
    }

}

int chooseStartButtonClicked(Coordinates cursorPosition)
{
    return isPointInRectangle(chooseStartButton_position, cursorPosition);
}
int chooseTargetButtonClicked(Coordinates cursorPosition)
{
    return isPointInRectangle(chooseTargetButton_position, cursorPosition);
}
int chooseWallButtonClicked(Coordinates cursorPosition)
{
    return isPointInRectangle(chooseWallButton_position, cursorPosition);
}
int chooseBlankButtonClicked(Coordinates cursorPosition)
{
    return isPointInRectangle(chooseBlankButton_position, cursorPosition);
}



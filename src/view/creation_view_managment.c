#include "creation_view_managment.h"

SDL_Rect chooseStartButton_position;
SDL_Rect chooseTargetButton_position;
SDL_Rect chooseWallButton_position;
SDL_Rect chooseBlankButton_position;
SDL_Rect choiceIndicator_position;
SDL_Rect saveButton_position;
SDL_Rect saveIconPosition;
SDL_Rect closeButton_position;
SDL_Rect closeIconPosition;

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
    /**
     ************************ Creates Save button
    */
    /**
     * Initialise the button
     */
    SDL_Surface *saveButton = NULL;
    saveButton_position.x = graphWidth+SECOND_COL_BUTTONS_X;
    saveButton_position.y = SAVE_BUTTON_Y;
    saveButton = SDL_CreateRGBSurface(SDL_HWSURFACE, SIZE_BUTTON_X,SIZE_BUTTON_Y,32,0,0,0,0);
    SDL_FillRect(saveButton, NULL, SDL_MapRGB(ecran->format, 141,242,23));
    /**
     * Initialise the icon
     */
    SDL_Surface *saveIcon = NULL;
    SDL_Rect saveIconPosition;
    saveIconPosition.x = 10;
    saveIconPosition.y = 0;
    saveIcon = SDL_LoadBMP("view/icons/save.bmp");
    /**
     * Set the color transparancy
     */
    SDL_SetColorKey(saveIcon, SDL_SRCCOLORKEY, SDL_MapRGB(saveIcon->format, 255, 255, 255));
    /**
     * Display the button and the icon
     */
    SDL_BlitSurface(saveIcon, NULL, saveButton, &saveIconPosition);
    SDL_BlitSurface(saveButton, NULL, ecran, &saveButton_position);
    /**
     ************************ Creates Close button
    */
    /**
     * Initialise the button
     */
    SDL_Surface *closeButton = NULL;
    closeButton_position.x = graphWidth+SECOND_COL_BUTTONS_X;
    closeButton_position.y = CLOSE_BUTTON_Y;
    closeButton = SDL_CreateRGBSurface(SDL_HWSURFACE, SIZE_BUTTON_X,SIZE_BUTTON_Y,32,0,0,0,0);
    SDL_FillRect(closeButton, NULL, SDL_MapRGB(ecran->format, 255,0,0));
    /**
     * Initialise the icon
     */
    SDL_Surface *closeIcon = NULL;
    SDL_Rect closeIconPosition;
    closeIconPosition.x = 10;
    closeIconPosition.y = 0;
    closeIcon = SDL_LoadBMP("view/icons/close.bmp");
    /**
     * Set the color transparancy
     */
    SDL_SetColorKey(closeIcon, SDL_SRCCOLORKEY, SDL_MapRGB(closeIcon->format, 255, 255, 255));
    /**
     * Display the button and the icon
     */
    SDL_BlitSurface(closeIcon, NULL, closeButton, &closeIconPosition);
    SDL_BlitSurface(closeButton, NULL, ecran, &closeButton_position);
    /**
     * Refresh the screen
     */
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
int saveButtonClicked(Coordinates cursorPosition)
{
    return isPointInRectangle(saveButton_position, cursorPosition);
}
int closeButtonClicked(Coordinates cursorPosition)
{
    return isPointInRectangle(closeButton_position, cursorPosition);
}



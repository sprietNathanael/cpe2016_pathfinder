#include "view.h"
int buttonAcivated = 1;
SDL_Rect findPathButton_position;
int launchView(int numRow, int numCol, char graph[numRow][numCol])
{
	SDL_Surface *ecran = NULL; // Le pointeur qui va stocker la surface de l'écran
	
    SDL_Init(SDL_INIT_VIDEO);
    ecran = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE); // On tente d'ouvrir une fenêtre
    if (ecran == NULL) // Si l'ouverture a échoué, on le note et on arrête
    {
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

    //
	createGraph(numRow, numCol, graph, ecran);
	pause(ecran, numRow, numCol, graph);
    SDL_Quit();
    return EXIT_SUCCESS;
}	

void createGraph(int numRow, int numCol, char graph[numRow][numCol], SDL_Surface* ecran)
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
	for(i = 0; i < numRow; i++)
	{
		for(j = 0; j < numCol; j++)
		{
			rectangleGraph[i][j] = SDL_CreateRGBSurface(SDL_HWSURFACE, SIZE_X, SIZE_Y, 32, 0, 0, 0, 0);
			positionGraph[i][j].x = currentX;
    		positionGraph[i][j].y = currentY;
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
            }
            else if(graph[i][j] == 'T')
            {
                color = target;
            }
            SDL_FillRect(rectangleGraph[i][j], NULL, color);                
            SDL_BlitSurface(rectangleGraph[i][j], NULL, ecran, &positionGraph[i][j]); // Collage de la surface sur l'écran
            currentX += SIZE_X+OFFSET_X;
            printf("(%d;%d)\n",positionGraph[i][j].x,positionGraph[i][j].y);
        }
        currentX = POS_START_X;
        currentY += SIZE_Y+OFFSET_Y;
    }
    drawLineBetweenTwoNodes(positionGraph[0][0].x,positionGraph[0][1].y);
    SDL_Flip(ecran);
}

void pause(SDL_Surface* ecran, int numRow, int numCol, char graph[numRow][numCol])
{
    int continuer = 1;
    SDL_Event event;
    Coordinates point;
    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
            case SDL_MOUSEBUTTONDOWN:
                point.x = event.button.x;
                point.y = event.button.y;
                if(buttonAcivated && isPointInRectangle(findPathButton_position, point))
                {
                    launchPathResolution(numRow, numCol, graph);
                    buttonAcivated = 0;
                }

            break;
        }
    }
}

int isPointInRectangle(SDL_Rect rect, Coordinates point)
{
	if((point.x >= rect.x && point.x <= (rect.x+rect.w)) && (point.y >= rect.y && point.y <= (rect.y+rect.h)))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void drawLineBetweenTwoNodes(SDL_Surface* nodeA, SDL_Surface* nodeB)
{
    Coordinates centerA;
    Coordinates centerB;
    centerA.x = nodeA->clip_rect.x+(nodeA->clip_rect.w/2);
    centerA.y = nodeA->clip_rect.y+(nodeA->clip_rect.h/2);
    centerB.x = nodeB->clip_rect.x+(nodeB->clip_rect.w/2);
    centerB.y = nodeB->clip_rect.y+(nodeB->clip_rect.h/2);
    printf("(%d;%d) (%d;%d)\n",centerA.x,centerA.y,centerB.x,centerB.y);
}
#include "view.h"

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
	createGraph(numRow, numCol, graph, ecran);
	pause(ecran);
    SDL_Quit();
    return EXIT_SUCCESS;
}	

void createGraph(int numRow, int numCol, char graph[numRow][numCol], SDL_Surface* ecran)
{
	SDL_Surface *rectangleGraph[numRow][numCol];
	SDL_Rect position;
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
			position.x = currentX;
    		position.y = currentY;
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
    		SDL_BlitSurface(rectangleGraph[i][j], NULL, ecran, &position); // Collage de la surface sur l'écran
			currentX += SIZE_X+OFFSET_X;
		}
		currentX = POS_START_X;
		currentY += SIZE_Y+OFFSET_Y;
	}
	SDL_Flip(ecran);
}

void pause(SDL_Surface* ecran)
{
    int continuer = 1;
    SDL_Event event;
    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
        }
    }
}
#include "view.h"

int launchView()
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
	pause(ecran);    
    SDL_Quit();
    return EXIT_SUCCESS;
}	


void pause(SDL_Surface* ecran)
{
	SDL_Surface *rectangle = NULL;	
	SDL_Rect position;
	rectangle = SDL_CreateRGBSurface(SDL_HWSURFACE, 25, 25, 32, 0, 0, 0, 0);	
 	position.x = 5;
    position.y = 5;
    // Remplissage de la surface avec du blanc
    SDL_FillRect(rectangle, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));    
    SDL_BlitSurface(rectangle, NULL, ecran, &position); // Collage de la surface sur l'écran
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
    SDL_FreeSurface(rectangle); // Libération de la surface
}
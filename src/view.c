#include "view.h"
int buttonAcivated = 1;



int launchView(int numRow, int numCol, char graph[numRow][numCol])
{
	sdlInit();
	createGraph(numRow, numCol, graph);
	mainSDLLoop(numRow, numCol, graph);
    SDL_Quit();
    return EXIT_SUCCESS;
}	


void mainSDLLoop(int numRow, int numCol, char graph[numRow][numCol])
{
    int continuer = 1;
    SDL_Event event;
    Coordinates point;
    Coordinates finalPath[numRow*numCol];
    int finalPathLength = 0;
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
                if(buttonAcivated && findPathButtonClicked(point))
                {
                    finalPathLength = launchPathResolution(numRow, numCol, graph, finalPath);
                    //drawFinalPath(finalPathLength, numRow, numCol, finalPath);
                    buttonAcivated = 0;
                }

            break;
        }
    }
}






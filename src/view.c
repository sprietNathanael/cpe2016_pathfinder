#include "view.h"
int findPathButtonsAcivated = 1;
int stayInLoop = 1;


int launchView(int numRow, int numCol, char* graph)
{
    while(stayInLoop)
    {
	   sdlInit();
       findPathButtonsAcivated = 1;
       createGraph(numRow, numCol, graph);
       mainSDLLoop(numRow, numCol, graph);
       SDL_Quit();
    }
    return EXIT_SUCCESS;
}	


void mainSDLLoop(int numRow, int numCol, char* graph)
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
                stayInLoop = 0;
            case SDL_MOUSEBUTTONDOWN:
                point.x = event.button.x;
                point.y = event.button.y;
                if(findPathButtonsAcivated && findPathButtonClicked(point))
                {
                    finalPathLength = launchPathResolution(numRow, numCol, graph, finalPath,0);
                    drawFinalPath(finalPathLength, numRow, numCol, finalPath);
                    findPathButtonsAcivated = 0;
                }
                if(findPathButtonsAcivated && slow_findPathButtonClicked(point))
                {
                    finalPathLength = launchPathResolution(numRow, numCol, graph, finalPath,SLOW_RESOLUTION_TIME);
                    drawFinalPath(finalPathLength, numRow, numCol, finalPath);
                    findPathButtonsAcivated = 0;
                }
                else if(clearButtonClicked(point))
                {
                    continuer = 0;
                }

            break;
        }
    }
}






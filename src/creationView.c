#define CREATION_VIEW_C
#include "creationView.h"

int stayInCreationLoop = 1;

void launchCreationView(int numRow, int numCol, char* graph)
{
	stayInCreationLoop = 1;
	while(stayInCreationLoop)
	{
		sdlCreationInit(numRow, numCol);
		createGraph(numRow, numCol, graph);
		mainCreationLoop(numRow, numCol, graph);
		SDL_Quit();
	}
}

void mainCreationLoop(int numRow, int numCol, char* graph)
{
	int continuer = 1;
	SDL_Event event;
	Coordinates point;
    char choosedType = 'W';
	while (continuer)
	{
		SDL_WaitEvent(&event);
		switch(event.type)
		{
			case SDL_QUIT:
				stayInCreationLoop = 0;
				continuer = 0;
				break;
			case SDL_MOUSEBUTTONDOWN:
				point.x = event.button.x;
				point.y = event.button.y;
				Coordinates pointedNode = computeThePointedNodeCoordinatesFromSDL(numRow, numCol, point.x, point.y);
                if(pointedNode.x != -1 && pointedNode.y != -1)
                {
				    printf("(%d;%d)\n",pointedNode.x, pointedNode.y);
                    changeTypeColorOfGivenNode(pointedNode,choosedType, numCol);
                    /**
                     * Replace old T or S by a simple node
                     */
                    if(choosedType == 'T' || choosedType == 'S')
                    {
                        Coordinates oldCoordinate = findCoordinatesInCharGraph(numRow, numCol, graph, choosedType);
                        /**
                         * If there was a T or a S
                         */
                        if(oldCoordinate.x != -1 && oldCoordinate.y != -1)
                        {
                            changeTypeColorOfGivenNode(oldCoordinate,'0', numCol);
                            graph[(numRow*oldCoordinate.y)+oldCoordinate.x] = '0';
                        }
                    }
                    graph[(numRow*pointedNode.y)+pointedNode.x] = choosedType;
                }
                else if(chooseStartButtonClicked(point))
                {
                    choosedType = 'S';
                    changeColorIndicator(choosedType);
                }
                else if(chooseTargetButtonClicked(point))
                {
                    choosedType = 'T';
                    changeColorIndicator(choosedType);
                }
                else if(chooseWallButtonClicked(point))
                {
                    choosedType = 'W';
                    changeColorIndicator(choosedType);
                }
                else if(chooseBlankButtonClicked(point))
                {
                    choosedType = '0';
                    changeColorIndicator(choosedType);
                }

                break;
        }
	}
    int i = 0, j = 0;
    for(i = 0; i < numRow; i++)
    {
        for(j = 0; j < numCol; j++)
        {
            printf("%c ",graph[(numRow*i)+j]);
        }
        printf("\n");
    }
}

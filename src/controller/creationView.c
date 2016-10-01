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
    Coordinates startCoordinate = findCoordinatesInCharGraph(numRow, numCol, graph, 'S');
    Coordinates targetCoordinate = findCoordinatesInCharGraph(numRow, numCol, graph, 'T');
	while (continuer)
	{
		SDL_WaitEvent(&event);
		switch(event.type)
		{
			case SDL_QUIT :
                startCoordinate = findCoordinatesInCharGraph(numRow, numCol, graph, 'S');
                targetCoordinate = findCoordinatesInCharGraph(numRow, numCol, graph, 'T');
                if(targetCoordinate.x != -1 && targetCoordinate.y != -1 && startCoordinate.x != -1 && startCoordinate.y != -1)
                {
				    stayInCreationLoop = 0;
				    continuer = 0;
                }
				break;
			case SDL_MOUSEBUTTONDOWN:
                point.x = event.button.x;
                point.y = event.button.y;
				Coordinates pointedNode = computeThePointedNodeCoordinatesFromSDL(numRow, numCol, point.x, point.y);
                if(pointedNode.x != -1 && pointedNode.y != -1)
                {
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
                            graph[(oldCoordinate.y*numCol)+oldCoordinate.x] = '0';

                        }
                    }
                    graph[(numCol*pointedNode.y)+pointedNode.x] = choosedType;
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
            printf("%c ",graph[(numCol*i)+j]);            
        }
        printf("\n");
    }
}
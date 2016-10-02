#include "creationView.h"
int stayInCreationLoop = 1;

int launchCreationView(int numRow, int numCol, char* graph)
{
	stayInCreationLoop = 1;
    int state;
	while(stayInCreationLoop)
	{
		sdlCreationInit(numRow, numCol);
		createGraph(numRow, numCol, graph);
		state = mainCreationLoop(numRow, numCol, graph);
		SDL_Quit();
	}
    return state;
}  

int mainCreationLoop(int numRow, int numCol, char* graph)
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
                stayInCreationLoop = 0;
				continuer = 0;
                return -1;                
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
                else if(saveButtonClicked(point))
                {
                    /**
                     * Check if there is a start and a target
                     */
                    startCoordinate = findCoordinatesInCharGraph(numRow, numCol, graph, 'S');
                    targetCoordinate = findCoordinatesInCharGraph(numRow, numCol, graph, 'T');
                    if(targetCoordinate.x != -1 && targetCoordinate.y != -1 && startCoordinate.x != -1 && startCoordinate.y != -1)
                    {
                        char fileName[255];
                        printf("Nom du fichier : ");
                        scanf("%s",fileName);
                        exportGraphToFile(numRow,numCol,graph, fileName);
                    }
                    else
                    {
                        printf("Can not save a graph without a start and a target !\n");
                    }
                }
                else if(closeButtonClicked(point))
                {
                    stayInCreationLoop = 0;
                    continuer = 0;
                    return 0;
                }
                else if(validateButtonClicked(point))
                {
                    /**
                     * Check if there is a start and a target
                     */
                    startCoordinate = findCoordinatesInCharGraph(numRow, numCol, graph, 'S');
                    targetCoordinate = findCoordinatesInCharGraph(numRow, numCol, graph, 'T');
                    if(targetCoordinate.x != -1 && targetCoordinate.y != -1 && startCoordinate.x != -1 && startCoordinate.y != -1)
                    {
                        stayInCreationLoop = 0;
                        continuer = 0;
                    }
                    else
                    {
                        printf("Can not use a graph without a start and a target !\n");
                    }
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
    return 1;
}
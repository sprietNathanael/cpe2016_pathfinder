/**
 * @file creationView.c
 * @brief      Create a creation window
 * @author     Nathanaël SPRIET
 */

#include "creationView.h"

/*
 **************************** Globals *************************
*/
/**
 * @brief      Voolean variable that controls the loop state
 */
int stayInCreationLoop = 1;


/*
 **************************** Core *************************
*/

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
    char choosedType = TYPE_WALL;
    Coordinates startCoordinate = findCoordinatesInCharGraph(numRow, numCol, graph, TYPE_START);
    Coordinates targetCoordinate = findCoordinatesInCharGraph(numRow, numCol, graph, TYPE_TARGET);
	while (continuer)
	{
		SDL_WaitEvent(&event);
		switch(event.type)
		{
			case SDL_QUIT :
                /* Get out of the loop and return -1 */
                stayInCreationLoop = 0;
				continuer = 0;
                return -1;                
				break;
			case SDL_MOUSEBUTTONDOWN:
                point.x = event.button.x;
                point.y = event.button.y;
				Coordinates pointedNode = computeThePointedNodeCoordinatesFromSDL(numCol, point.x, point.y);
                if(pointedNode.x != -1 && pointedNode.y != -1)
                {
                    changeTypeColorOfGivenNode(pointedNode,choosedType, numCol);
                    /* Replace old T or S by a simple node */
                    if(choosedType == TYPE_TARGET || choosedType == TYPE_START)
                    {
                        Coordinates oldCoordinate = findCoordinatesInCharGraph(numRow, numCol, graph, choosedType);
                        /* If there was a T or a S */
                        if(oldCoordinate.x != -1 && oldCoordinate.y != -1)
                        {
                            changeTypeColorOfGivenNode(oldCoordinate,TYPE_NORMAL, numCol);
                            graph[(oldCoordinate.y*numCol)+oldCoordinate.x] = TYPE_NORMAL;

                        }
                    }
                    graph[(numCol*pointedNode.y)+pointedNode.x] = choosedType;
                }
                else if(chooseStartButtonClicked(point))
                {
                    choosedType = TYPE_START;
                    changeColorIndicator(choosedType);
                }   
                else if(chooseTargetButtonClicked(point))
                {
                    choosedType = TYPE_TARGET;
                    changeColorIndicator(choosedType);
                }
                else if(chooseWallButtonClicked(point))
                {
                    choosedType = TYPE_WALL;
                    changeColorIndicator(choosedType);
                }
                else if(chooseBlankButtonClicked(point))
                {
                    choosedType = TYPE_NORMAL;
                    changeColorIndicator(choosedType);
                }
                else if(saveButtonClicked(point))
                {
                    /* Check if there is a start and a target */
                    startCoordinate = findCoordinatesInCharGraph(numRow, numCol, graph, TYPE_START);
                    targetCoordinate = findCoordinatesInCharGraph(numRow, numCol, graph, TYPE_TARGET);
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
                    /* Check if there is a start and a target */
                    startCoordinate = findCoordinatesInCharGraph(numRow, numCol, graph, TYPE_START);
                    targetCoordinate = findCoordinatesInCharGraph(numRow, numCol, graph, TYPE_TARGET);
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
    /* Displays the graph in console */
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
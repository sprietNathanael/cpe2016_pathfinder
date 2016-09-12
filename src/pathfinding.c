#include "pathfinding.h"

void generateGraph(int numRow, int numCol, char graph[numRow][numCol])
{
	displayGraph(numRow,numCol,graph);
	Coordinates targetCoordinates = findCoordinates(numRow, numCol, graph, 'A');
	printf("x: %d; y: %d\n",targetCoordinates.x, targetCoordinates.y);
}

void launchPathResolution(void)
{
}

Coordinates findCoordinates(int numRow, int numCol, char graph[numRow][numCol], char charToFind)
{
	bool targetFound = false;
	Coordinates targetCoordinates;
	int i = 0, j = 0;
	while(i < numRow && !targetFound)
	{
		j = 0;
		while(j < numCol && !targetFound)
		{
			if(graph[i][j] == charToFind)
			{
				targetFound = true;
				targetCoordinates.x = j+1;
				targetCoordinates.y = i+1;
			}
			j++;
		}
		i++;
	}
	return targetCoordinates;
}

void displayGraph(int numRow, int numCol, char graph[numRow][numCol])
{
	int i = 0;
	int y = 0;
    for(i = 0; i < numRow; i ++)
    {
    	for(y = 0; y < numCol; y ++)
    	{
    		printf("%c",graph[i][y]);
    	}
    	printf("\n");
    }
}
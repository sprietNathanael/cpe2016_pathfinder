#include "pathfinding.h"

void generateGraph(int numRow, int numCol, char graph[numRow][numCol])
{
	displayGraph(numRow,numCol,graph);
	/**
	 * Search for the target's coordinates
	 */
	Coordinates targetCoordinates = findCoordinates(numRow, numCol, graph, 'T');
}

void launchPathResolution(void)
{
}

Coordinates findCoordinates(int numRow, int numCol, char graph[numRow][numCol], char charToFind)
{
	bool targetFound = false;
	Coordinates targetCoordinates;
	int i = 0, j = 0;
	/**
	 * Browses each row of the graph
	 */
	while(i < numRow && !targetFound)
	{
		j = 0;
		/**
		 * Browses each column of the current row
		 */
		while(j < numCol && !targetFound)
		{
			/**
			 * If the content of the current cell matches the char to find
			 */
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
	/**
	 * Return the coordinates
	 */
	return targetCoordinates;
}

int computeSimpleDistanceBetweenCoordinates(Coordinates firstCoordinates, Coordinates secondCoordinates)
{
	/**
	 * Distance = |x1-x2|+|y1-y2|
	 */
	return((abs(secondCoordinates.x - firstCoordinates.x) + abs(secondCoordinates.y - firstCoordinates.y)) * SIMPLE_DISTANCE_FACTOR);
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
#include "pathfinding.h"

void generateGraph(int numRow, int numCol, char graph[numRow][numCol])
{
	Node finalGraph[numRow][numCol];
	/**
	 * Search for the target's coordinates
	 */
	Coordinates targetCoordinates = findCoordinates(numRow, numCol, graph, TYPE_TARGET);
	int i = 0;
	int j = 0;
	int currentDistance;
	Coordinates currentCoordinates;
	/**
	 * Browse each row of the graph
	 */
	for(i = 0; i < numRow; i++)
	{
		/**
		 * Browse each column of the current row
		 */
		for(j = 0; j < numCol; j++)
		{
			currentCoordinates.x = j+1;
			currentCoordinates.y = i+1;
			currentDistance = computeSimpleDistanceBetweenCoordinates(currentCoordinates, targetCoordinates);
			finalGraph[i][j].H = currentDistance;
			finalGraph[i][j].type = graph[i][j];
		}
	}
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

void displayGraph(int numRow, int numCol, Node graph[numRow][numCol])
{
	int i = 0;
	int j = 0;
    for(i = 0; i < numRow; i ++)
    {
    	for(j = 0; j < numCol; j ++)
    	{
    		if(graph[i][j].type == TYPE_NORMAL)
    		{
    			printf(".");
    		}
    		else if(graph[i][j].type == TYPE_START)
    		{
    			printf("S");
    		}
    		else if(graph[i][j].type == TYPE_TARGET)
    		{
    			printf("T");
    		}
    		else if(graph[i][j].type == TYPE_WALL)
    		{
    			printf("X");
    		}
    	}
    	printf("\n");
    }
}
#include "graph_managment.h"

Coordinates findCoordinatesInCharGraph(int numRow, int numCol, char graph[numRow][numCol], char charToFind)
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
				targetCoordinates.x = j;
				targetCoordinates.y = i;
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
	int j = 0;
    for(i = 0; i < numRow; i ++)
    {
    	for(j = 0; j < numCol; j ++)
    	{
    		if(graph[i][j] == TYPE_NORMAL)
    		{
    			printf(".");
    		}
    		else if(graph[i][j] == TYPE_START)
    		{
    			printf("S");
    		}
    		else if(graph[i][j] == TYPE_TARGET)
    		{
    			printf("T");
    		}
    		else if(graph[i][j] == TYPE_WALL)
    		{
    			printf("X");
    		}
    	}
    	printf("\n");
    }
}
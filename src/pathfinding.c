#include "pathfinding.h"

void generateGraph(int numRow, int numCol, char graph[numRow][numCol])
{
	displayGraph(numRow, numCol, graph);
	launchPathResolution(numRow, numCol, graph);
}

void launchPathResolution(int numRow, int numCol, char graph[numRow][numCol])
{
	Node currentNode;
	Coordinates zeroCoordinates = {0,0};
	Node zeroNode = {0,0,0,'\0',zeroCoordinates};

	/**
	 * Initialise lists
	 */
	int listsLength = numCol*numRow;
	Node openList[listsLength];
	Node closeList[listsLength];
	int i = 0;
	for(i = 0; i < listsLength; i ++)
	{
		openList[i] = zeroNode;
		closeList[i] = zeroNode;
	}
	int openListHead = 0;
	int closeListHead = 0;

	/**
	 * Search and initialise start Node
	 */
	Coordinates startCoordinates = findCoordinatesInCharGraph(numRow, numCol, graph, TYPE_START);
	Node startNode = {0, 0, 0, TYPE_START, startCoordinates};

	/**
	 * Push start Node into the open list
	 */
	openList[openListHead++] = startNode;
	bool continuing = true;
	while(continuing)
	{
		/**
		 * Take the first element of the open list = the element which has the lesser F
		 */
		currentNode = openList[0];
		removeNodeFromList(listsLength, openList, 0);
		openListHead = 0;
		
		/**
		 * Push the current node into the close list
		 */
		closeList[closeListHead++] = currentNode;

		analysingNeighbourNodes(listsLength, openList, &openListHead, numRow, numCol, graph, currentNode);
		
		printf("Open list ( %d )\n\n",openListHead);
		for(i = 0; i < listsLength; i ++)
		{
			printf("%d : (%d;%d) %d + %d = %d\n",i , openList[i].coordinates.x, openList[i].coordinates.y, openList[i].G, openList[i].H, openList[i].F);
		}

		sortList(listsLength, openList, openListHead);

		printf("Open list ( %d )\n\n",openListHead);
		for(i = 0; i < listsLength; i ++)
		{
			printf("%d : (%d;%d) %d + %d = %d\n",i , openList[i].coordinates.x, openList[i].coordinates.y, openList[i].G, openList[i].H, openList[i].F);
		}

		continuing = false;
		

	}
}

void analysingNeighbourNodes(int listLength, Node openList[listLength], int *openListHead, int numRow, int numCol, char graph[numRow][numCol], Node currentNode)
{
	Node neighbourNode;
	int neighbourNodesHead = 0;
	int deltaX = 0;
	int deltaY = 0;
	Coordinates targetCoordinates = findCoordinatesInCharGraph(numRow, numCol, graph, TYPE_TARGET);
	Coordinates currentCoordinates = {0,0};
	/**
	 * Browse all 8 possibilities of neighbours
	 */
	for(deltaX = -1; deltaX <= 1; deltaX ++)
	{
		for (deltaY = -1; deltaY <= 1; deltaY ++)
		{
			/**
			 * Exclude the case of (0;0)
			 */
			if(deltaY != 0 || deltaX != 0)
			{
				/**
				 * If the Node exists
				 */
				if((currentNode.coordinates.y+deltaY >= 0 && currentNode.coordinates.y+deltaY < numRow) && (currentNode.coordinates.x+deltaX >= 0 && currentNode.coordinates.x+deltaX < numCol))
				{
					/**
					 * If the node is not a wall
					 */
					if(graph[currentNode.coordinates.y+deltaY][currentNode.coordinates.x+deltaX] != TYPE_WALL)
					{
						/**
						 * Get the coordinates
						 */
						neighbourNode.coordinates.x = currentNode.coordinates.x+deltaX;
						neighbourNode.coordinates.y = currentNode.coordinates.y+deltaY;
						/**
						 * Compute the H parameter
						 */
						neighbourNode.H = computeSimpleDistanceBetweenCoordinates(neighbourNode.coordinates, targetCoordinates);
						/**
						 * If the neighbour is in a diagonal position
						 * (if |Dx|+|Dy| > 1)
						 */
						if((abs(deltaX) + abs(deltaY)) > 1)
						{
							neighbourNode.G = DIAGONAL_DISTANCE_FACTOR;
						}
						else
						{
							neighbourNode.G = SIMPLE_DISTANCE_FACTOR;
						}
						/**
						 * Get the F parameter
						 */
						neighbourNode.F = neighbourNode.H + neighbourNode.G;
						/**
						 * Push the node into the open list
						 */
						openList[*openListHead] = neighbourNode;
						*openListHead+=1;
					}
				}
			}
		}
	}
}

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

void removeNodeFromList(int listLength, Node list[listLength], int indexOfNodeToRemove)
{
	int i = indexOfNodeToRemove;
	/**
	 * Browse the list until the end or the end of data (a type equals to '\0' means no data)
	 */
	while(i < listLength && list[i].type != '\0')
	{
		list[i] = list[i+1];
		i++;
	}
}

int compareNodeByF (Node a, Node b)
{
	if ( a.F <  b.F ) return -1;
	if ( a.F == b.F ) return 0;
	if ( a.F >  b.F ) return 1;
}

void sortList(int listLength, Node list[listLength], int indexLimitation)
{
	int min = 0;
	Node inter;
	int i = 0;
	int j = 0;
	/**
	 * Browse the list
	 */
	for(i = 0; i < indexLimitation; i++)
	{
		min = i;
		/**
		 * Browse only the list's tail after the current item
		 */
		for(j = i+1;j < indexLimitation; j++)
		{
			/**
			 * If list[j] < list[min]
			 */
			if(compareNodeByF(list[j],list[min]) == -1)
			{
				min = j;
			}
		}
		/**
		 * If the current item is not the minimum of the rest of the list
		 * intervert the current item and the minimum
		 */
		if(min != i)
		{
			inter = list[i];
			list[i] = list[min];
			list[min] = inter;
		}

	}
}
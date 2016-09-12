#include "pathfinding.h"

void generateGraph(int numRow, int numCol, char graph[numRow][numCol])
{
	Node finalGraph[numRow][numCol];
	/**
	 * Search for the target's coordinates
	 */
	Coordinates targetCoordinates = findCoordinatesInCharGraph(numRow, numCol, graph, TYPE_TARGET);
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
			currentCoordinates.x = j;
			currentCoordinates.y = i;
			currentDistance = computeSimpleDistanceBetweenCoordinates(currentCoordinates, targetCoordinates);
			finalGraph[i][j].H = currentDistance;
			finalGraph[i][j].type = graph[i][j];
			finalGraph[i][j].coordinates = currentCoordinates;
		}
	}
	displayGraph(numRow, numCol, finalGraph);
	launchPathResolution(numRow, numCol, finalGraph);
}

void launchPathResolution(int numRow, int numCol, Node graph[numRow][numCol])
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
	Coordinates startCoordinates = findCoordinatesInNodeGraph(numRow, numCol, graph, TYPE_START);
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
		sortList(listsLength, openList, openListHead, compareNodeByF);
		printf("Open list ( %d )\n\n",openListHead);
		for(i = 0; i < listsLength; i ++)
		{
			printf("%d : (%d;%d) %d + %d = %d\n",i , openList[i].coordinates.x, openList[i].coordinates.y, openList[i].G, openList[i].H, openList[i].F);
		}
		continuing = false;
		

	}
}

void analysingNeighbourNodes(int listLength, Node openList[listLength], int *openListHead, int numRow, int numCol, Node graph[numRow][numCol], Node currentNode)
{
	Node neighbourNode;
	int neighbourNodesHead = 0;
	int deltaX = 0;
	int deltaY = 0;	
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
				neighbourNode = graph[currentNode.coordinates.y+deltaY][currentNode.coordinates.x+deltaX];
				/**
				 * If the node is not a wall
				 */
				if(neighbourNode.type != TYPE_WALL)
				{
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
					neighbourNode.F = neighbourNode.H + neighbourNode.G;
					openList[*openListHead] = neighbourNode;
					*openListHead+=1;
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

Coordinates findCoordinatesInNodeGraph(int numRow, int numCol, Node graph[numRow][numCol], char charToFind)
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
			if(graph[i][j].type == charToFind)
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

void printCoordinates(Coordinates coordinates)
{
	printf("(%d;%d)\n",coordinates.x, coordinates.y);
}


int compareNodeByF (const void * a, const void * b)
{
	Node *nodeA = (Node *)a;
  	Node *nodeB = (Node *)b;
	if ( nodeA->F <  nodeB->F ) return -1;
	if ( nodeA->F == nodeB->F ) return 0;
	if ( nodeA->F >  nodeB->F ) return 1;
}

void sortList(int listLength, Node list[listLength], int indexLimitation, )
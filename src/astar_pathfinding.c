#include "astar_pathfinding.h"

int launchPathResolution(int numRow, int numCol, char graph[numRow][numCol], Coordinates finalPath[numRow*numCol])
{
	Node currentNode;
	Coordinates zeroCoordinates = {0,0};
	Node zeroNode = {0,0,0,'\0',zeroCoordinates, NULL};
	int finalPathLength = 0;

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
	Node startNode = {0, 0, 0, TYPE_START, startCoordinates, NULL};

	/**
	 * Push start Node into the open list
	 */
	openList[openListHead++] = startNode;
	int targetFound = 0;
	while(!targetFound)
	{

		/**
		 * Take the first element of the open list = the element which has the lesser F
		 */
		currentNode = openList[0];
		removeNodeFromList(openListHead, openList, 0);
		openListHead --;
		/**
		 * Push the current node into the close list
		 */
		closeList[closeListHead] = currentNode;
		targetFound = analysingNeighbourNodes(openList, &openListHead, closeList, closeListHead, numRow, numCol, graph, &closeList[closeListHead]);		
		sortList(openList, openListHead);
		closeListHead++;

	}
	Node* currentNodePointer = &currentNode;
	/**
	 * Display final path
	 */
	printf("Path : (%d;%d) ",currentNodePointer->coordinates.x, currentNodePointer->coordinates.y);
	finalPath[finalPathLength++] = currentNodePointer->coordinates;
	while(currentNodePointer->parent != NULL)
	{
		currentNodePointer = currentNodePointer->parent;
		printf(" (%d;%d) ",currentNodePointer->coordinates.x, currentNodePointer->coordinates.y);		
		finalPath[finalPathLength++] = currentNodePointer->coordinates;
	}
	printf("\n");
	return finalPathLength;
}

int analysingNeighbourNodes(Node* openList, int *openListHead, Node* closeList, int closeListHead, int numRow, int numCol, char graph[numRow][numCol], Node* currentNode)
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
				 * If the Node exists in the graph
				 */
				if((currentNode->coordinates.y+deltaY >= 0 && currentNode->coordinates.y+deltaY < numRow) && (currentNode->coordinates.x+deltaX >= 0 && currentNode->coordinates.x+deltaX < numCol))
				{
					/**
					 * If the node is not a wall
					 */
					if(canGoToThisPoint(numRow, numCol, graph, currentNode, deltaX, deltaY))
					{
						/**
						 * Get the coordinates
						 */
						neighbourNode.coordinates.x = currentNode->coordinates.x+deltaX;
						neighbourNode.coordinates.y = currentNode->coordinates.y+deltaY;
						/**
						 * If the node does not exists in the close list
						 */
						if(getExistingNodeInList(closeList, closeListHead, neighbourNode.coordinates) == -1)
						{
							/**
							 * Get the parent's coordinates
							 */
							neighbourNode.parent = currentNode;

							
							neighbourNode.H = computeSimpleDistanceBetweenCoordinates(neighbourNode.coordinates, targetCoordinates);							
							/**
							 * If H == 0, it means the Node is the target
							 */
							if(neighbourNode.H == 0)
							{
								return 1;
							}

							/**
							 * If the neighbour is in a diagonal position
							 * (if |Dx|+|Dy| > 1)
							 */
							if((abs(deltaX) + abs(deltaY)) > 1)
							{
								neighbourNode.G = DIAGONAL_DISTANCE_FACTOR + currentNode->G;
							}
							else
							{
								neighbourNode.G = SIMPLE_DISTANCE_FACTOR + currentNode->G;
							}
							/**
							 * Get the F parameter
							 */
							neighbourNode.F = neighbourNode.H + neighbourNode.G;

							int alreadyInList = getExistingNodeInList(openList, *openListHead, neighbourNode.coordinates);
							/**
							 * If the node is already in the list
							 */
							if(alreadyInList != -1)
							{
								/**
								 * If the node existing in list has a greater G, replace it by the new one
								 */
								if(openList[alreadyInList].G > neighbourNode.G)
								{
									openList[alreadyInList] = neighbourNode;								
								}
							}
							else
							{
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
	}
	return 0;
}

int canGoToThisPoint(int numRow, int numCol, char graph[numRow][numCol], Node* currentNode, int deltaX, int deltaY)
{
	/**
	 * If the node-to-go is a wall
	 */
	if(graph[currentNode->coordinates.y+deltaY][currentNode->coordinates.x+deltaX] == TYPE_WALL)
	{
		return 0;
	}
	/**
	 * If the node-to-go is at diagonal
	 */
	if(abs(deltaX) == 1 && abs(deltaY) == 1)
	{
		/**
		 * Check the two adjacing nodes are not walls :
		 * (current.x ; deltaY) and (deltaX ; current.y)
		 */		
		if(graph[currentNode->coordinates.y+deltaY][currentNode->coordinates.x] == TYPE_WALL)
		{
			return 0;
		}
		if(graph[currentNode->coordinates.y][currentNode->coordinates.x+deltaX] == TYPE_WALL)
		{
			return 0;
		}

	}
	return 1;
}

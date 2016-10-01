#define A_STAR_PATHFINDING_C
#include "astar_pathfinding.h"

Coordinates targetCoordinates = {0,0};
int timeBetweenSteps = 0;
int canContinueToNextStep = 1;

int launchPathResolution(int numRow, int numCol, char* graph, Coordinates* finalPath, int time, int stepByStep)
{
	Node currentNode;
	timeBetweenSteps = time;
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
	 * Search and initialise target Node
	 */
	targetCoordinates = findCoordinatesInCharGraph(numRow, numCol, graph, TYPE_TARGET);

	/**
	 * Push start Node into the open list
	 */
	openList[openListHead++] = startNode;
	int targetFound = 0;
	/**
	 * Main loop
	 */
	while(!targetFound && openListHead > 0)
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
		changeNodeColor(currentNode, 1, numCol, 253,255,16);
		closeList[closeListHead] = currentNode;
		/**
		 * Draw a line between the current Node and its parent
		 */
		if(currentNode.parent != NULL)
		{
        	drawLineBetweenTwoNodes(currentNode.coordinates,currentNode.parent->coordinates, 0, 0, 0);
        }
        usleep(timeBetweenSteps);
		/**
		 * If the resolution is in step by step mode, wait until the
		 * function continueToNextStep has been called
		 */
		while(stepByStep && !canContinueToNextStep);
		canContinueToNextStep = 0;
		/**
		 * Analyse all the neighbour nodes
		 */
		targetFound = analysingNeighbourNodes(openList, &openListHead, closeList, closeListHead, numRow, numCol, graph, &closeList[closeListHead], stepByStep);
		sortList(openList, openListHead);
		changeNodeColor(currentNode, 1, numCol, 132,147,251);
		closeListHead++;

	}
	if(targetFound)
	{
		finalPath[finalPathLength++] = targetCoordinates;
		printf("Path : (%d;%d) ",targetCoordinates.x, targetCoordinates.y);
		Node* currentNodePointer = &currentNode;
		/**
		 * Build and display final path
		 */
		printf(" (%d;%d) ",currentNodePointer->coordinates.x, currentNodePointer->coordinates.y);
		finalPath[finalPathLength++] = currentNodePointer->coordinates;
		while(currentNodePointer->parent != NULL)
		{
			currentNodePointer = currentNodePointer->parent;
			printf(" (%d;%d) ",currentNodePointer->coordinates.x, currentNodePointer->coordinates.y);
			finalPath[finalPathLength++] = currentNodePointer->coordinates;
		}
		printf("\n");
	}
	else
	{
		printf("No path found !\n");
		finalPathLength = 0;
	}
	return finalPathLength;
}

int analysingNeighbourNodes(Node* openList, int *openListHead, Node* closeList, int closeListHead, int numRow, int numCol, char* graph, Node* currentNode, int stepByStep)
{
	Node neighbourNode;
	int neighbourNodesHead = 0;
	int deltaX = 0;
	int deltaY = 0;

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
					 * If the node is not a wall or is not surrounded by walls
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
								changeNodeColor(neighbourNode, 0, numCol, 224, 244, 204);
								*openListHead+=1;
								usleep(timeBetweenSteps);
								/**
								 * If the resolution is in step by step mode, wait until the
								 * function continueToNextStep has been called
								 */
								while(stepByStep && !canContinueToNextStep);
								canContinueToNextStep = 0;
							}
						}
					}
				}
			}
		}
	}
	return 0;
}

int canGoToThisPoint(int numRow, int numCol, char* graph, Node* currentNode, int deltaX, int deltaY)
{
	/**
	 * If the node-to-go is a wall
	 */
	if(graph[((currentNode->coordinates.y+deltaY)*numCol)+(currentNode->coordinates.x+deltaX)] == TYPE_WALL)
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
		if(graph[((currentNode->coordinates.y+deltaY)*numCol)+(currentNode->coordinates.x)] == TYPE_WALL)
		{
			return 0;
		}
		if(graph[((currentNode->coordinates.y)*numCol)+(currentNode->coordinates.x+deltaX)] == TYPE_WALL)
		{
			return 0;
		}

	}
	return 1;
}

void continueToNextStep()
{
	canContinueToNextStep = 1;
}

void changeNodeColor(Node nodeToChange, int drawLineBetweenNodeAndParent, int numCol, int r, int g, int b)
{
	changeRectangeColor(nodeToChange.coordinates, numCol, r, g, b);
	if(drawLineBetweenNodeAndParent && nodeToChange.parent != NULL)
	{
		drawLineBetweenTwoNodes(nodeToChange.coordinates,nodeToChange.parent->coordinates, 0, 0, 0);
	}
}

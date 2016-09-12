#include "pathfinding.h"

void generateGraph(int numRow, int numCol, char graph[numRow][numCol])
{
	displayGraph(numRow,numCol,graph);
}

void launchPathResolution(void)
{
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
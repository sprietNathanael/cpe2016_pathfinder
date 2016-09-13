#include <stdio.h>
#include <stdlib.h>
#include "astar_pathfinding.h"
#include "view.h"

int main()
{
	char graph[6][8] = {
						{ '0','0','0','0','0','0','0','0'},
						{ '0','0','0','0','W','0','0','0'},
						{ '0','0','S','0','W','0','T','0'},
						{ '0','0','0','0','W','0','0','0'},
						{ '0','0','0','0','0','0','0','0'},
						{ '0','0','0','0','0','0','0','0'},
					 };
	launchPathResolution(6, 8, graph);
    launchView();
	return 0;
}


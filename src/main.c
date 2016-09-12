#include <stdio.h>
#include <stdlib.h>
#include "pathfinding.h"

int main()
{
	char graph[6][8] = {
						{ '0','0','0','0','0','0','0','0'},
						{ '0','0','0','0','M','0','0','0'},
						{ '0','0','D','0','M','0','A','0'},
						{ '0','0','0','0','M','0','0','0'},
						{ '0','0','0','0','0','0','0','0'},
						{ '0','0','0','0','0','0','0','0'},
					 };
	generateGraph(6, 8, graph);
	launchPathResolution();
	return 0;
}

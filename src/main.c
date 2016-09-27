#include <stdio.h>
#include <stdlib.h>
#include "view.h"

int main()
{
	int height = 8;
	int width = 8;
	/*char graph[6*8] = {
						'0','0','0','0','0','0','0','0',
						'0','0','0','0','W','0','0','0',
						'0','0','S','0','W','0','T','0',
						'0','0','0','0','W','0','0','0',
						'0','0','0','0','0','0','0','0',
						'0','0','0','0','0','0','0','0'
					 };*/
	char* graph;
	graph = malloc(height*width*sizeof(char));
	char baseGraph[8*8] = {
						'S','0','W','0','0','W','0','T',
						'0','0','W','0','W','W','W','0',
						'0','0','W','0','0','W','W','0',
						'0','0','W','W','0','W','0','0',
						'W','0','W','0','0','W','0','W',
						'W','0','0','0','W','W','0','0',
						'0','0','W','0','0','0','W','0',
						'0','0','0','0','W','0','0','0'
					 };
	int i = 0;
	for(i = 0; i < (height*width); i++)
	{
		graph[i] = baseGraph[i];
	}
	int state = 1;
	while(state)
	{
		state = launchResolveView(height,width, graph);
		printf("state : %d\n",state);
		if(state)
		{
			printf("Hauteur voulue : ");
			scanf("%d",&height);
			printf("Largeur voulue : ");
			scanf("%d",&width);
			printf("(%d;%d)\n",width, height);
			free(graph);
			graph = malloc(height*width*sizeof(char));
			memset(graph, '0', height*width);
			launchCreationView(height, width, graph);
		}
		free(graph);
		state = 0;

	}
	return 0;
}


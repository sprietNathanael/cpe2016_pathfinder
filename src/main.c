#include <stdio.h>
#include <stdlib.h>
#include "resolutionView.h"
#include "creationView.h"

int main(int argc, char *argv[])
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
			height = 0;
			width = 0;
			while((height <= 0 || height > HEIGHT_MAX) || (width <= 0 || width > WIDTH_MAX))
			{
				printf("Hauteur voulue (0 -> %d ) : ",HEIGHT_MAX);
				scanf("%d",&height);
				printf("Largeur voulue (0 -> %d ) : ",WIDTH_MAX);
				scanf("%d",&width);
			}
			free(graph);
			graph = malloc(height*width*sizeof(char));
			memset(graph, '0', height*width);
			launchCreationView(height, width, graph);
		}
	}
	free(graph);			
	return 0;
}


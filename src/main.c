/**
 * @file main.c
 * @brief      Contains the main loop of the program
 * @author     Nathanaël SPRIET
 */

#include <stdio.h>
#include <stdlib.h>
#include "controller/resolutionView.h"
#include "controller/creationView.h"
#include "fileManager/importGraph.h"

/**
 * @brief      Set the graph to the initial graph
 *
 * @param[out] width   The width of the new graph
 * @param[out] height  The height of the new graph
 *
 * @return     A pointer to the created graph
 */
char* initialGraph(int* width, int* height);

int main(int argc, char const *argv[])
{
	int width;
	int height;
	char* graph;
	if(argc > 1)
	{
		graph = importGraphFromFile(argv[1], &height, &width);
		if(graph == NULL)
		{
			graph = initialGraph(&width, &height);			
		}
	}
	else
	{
		graph = initialGraph(&width, &height);
	}
	
	
	int state = 1;
	int creationState = 1;
	while(state)
	{
		state = launchResolveView(height,width, graph);
		if(state)
		{
			height = 0;
			width = 0;
			while(((height <= 0 || height > HEIGHT_MAX) || (width <= 0 || width > WIDTH_MAX)) || width+height <= 2)
			{
				printf("Hauteur voulue (1 -> %d ) : ",HEIGHT_MAX);
				scanf("%d",&height);
				printf("Largeur voulue (1 -> %d ) : ",WIDTH_MAX);
				scanf("%d",&width);
			}
			free(graph);
			graph = malloc(height*width*sizeof(char));
			memset(graph, '0', height*width);
			creationState = launchCreationView(height, width, graph);
			if(creationState==0)
			{
				graph = initialGraph(&width, &height);
			}
			else if(creationState == -1)
			{
				state = 0;
			}
		}
	}
	free(graph);			
	return 0;
}

char* initialGraph(int* width, int* height)
{
	*height = 8;
	*width = 8;
	/*char graph[6*8] = {
						'0','0','0','0','0','0','0','0',
						'0','0','0','0','W','0','0','0',
						'0','0','S','0','W','0','T','0',
						'0','0','0','0','W','0','0','0',
						'0','0','0','0','0','0','0','0',
						'0','0','0','0','0','0','0','0'
					 };*/
	char* graph;
	graph = malloc((*height)*(*width)*sizeof(char));
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
	for(i = 0; i < ((*height)*(*width)); i++)
	{
		graph[i] = baseGraph[i];
	}
	return graph;
}
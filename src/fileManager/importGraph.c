#include "exportGraph.h"

char* importGraphFromFile(const char* fileName, int *height, int *width)
{
	FILE* fileToRead = NULL;
	fileToRead = fopen(fileName, "r");
	char stringBuffer[4];
	char* tempPtr;
	if(fileToRead != NULL)
	{
		/**
		 * Get the numRow from the file
		 */
		fgets(stringBuffer,4,fileToRead);
		*height = (int)strtol(stringBuffer,tempPtr,10);
		/**
		 * Get the numCol from the file
		 */
		fgets(stringBuffer,4,fileToRead);
		*width = (int)strtol(stringBuffer,tempPtr,10);
		char* graph;
		graph = malloc((*height)*(*width)*sizeof(char));
		int i = 0;
		for(i = 0; i < (*height)*(*width); i++)
		{
			graph[i] = fgetc(fileToRead);
		}
		fclose(fileToRead);
		printf("Fichier Chargé !\n");
		return graph;
	}
	else
	{
		printf("Impossible d'ouvrir le fichier %s !", fileName);
		return NULL;
	}
}




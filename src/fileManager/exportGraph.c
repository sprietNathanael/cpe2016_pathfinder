/**
 * @file exportGraph.c
 * @brief      Tools to export a char graph to a file
 * @author     Nathanaël SPRIET
 */

#include "exportGraph.h"

void exportGraphToFile(int numRow, int numCol, char* graph, char* fileName)
{
	FILE* fileToWrite = NULL;
	/* Try to open the file in w+ mode */
	fileToWrite = fopen(fileName, "w+");
	char stringBuffer[4];
	if(fileToWrite != NULL)
	{
		/* Put the numRow in the file followed by an '\n' */
		sprintf(stringBuffer,"%d\n",numRow);
		fputs(stringBuffer,fileToWrite);
		/* Put the numCol in the file followed by an '\n' */
		sprintf(stringBuffer,"%d\n",numCol);
		fputs(stringBuffer,fileToWrite);
		int i = 0;
		for(i = 0; i < numCol*numRow; i++)
		{
			fputc(graph[i],fileToWrite);
		}
		fclose(fileToWrite);
		printf("Fichier Sauvegardé !\n");
	}
	else
	{
		printf("Impossible d'ouvrir le fichier %s !", fileName);
	}
}


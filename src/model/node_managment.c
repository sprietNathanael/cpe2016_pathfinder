#include "node_managment.h"

void removeNodeFromList(int listHead, Node* list, int indexOfNodeToRemove)
{
	int i = indexOfNodeToRemove;
	/**
	 * Browse the list until the end or the end of data (a type equals to '\0' means no data)
	 */
	while(i < listHead)
	{
		list[i] = list[i+1];
		i++;
	}
}

int compareNodeByF (Node a, Node b)
{
	if ( a.F <  b.F ) return -1;
	else if ( a.F == b.F ) return 0;
	else return 1;
	// else if ( a.F >  b.F ) return 1;
}

void sortList(Node* list, int indexLimitation)
{
	int min = 0;
	Node inter;
	int i = 0;
	int j = 0;
	/**
	 * Browse the list
	 */
	for(i = 0; i < indexLimitation; i++)
	{
		min = i;
		/**
		 * Browse only the list's tail after the current item
		 */
		for(j = i+1;j < indexLimitation; j++)
		{
			/**
			 * If list[j] < list[min]
			 */
			if(compareNodeByF(list[j],list[min]) == -1)
			{
				min = j;
			}
		}
		/**
		 * If the current item is not the minimum of the rest of the list
		 * intervert the current item and the minimum
		 */
		if(min != i)
		{
			inter = list[i];
			list[i] = list[min];
			list[min] = inter;
		}

	}
}

int getExistingNodeInList(Node* list, int listHead, Coordinates coordinatesToFind)
{
	int i = 0;
	while(i < listHead && (list[i].coordinates.x != coordinatesToFind.x || list[i].coordinates.y != coordinatesToFind.y))
	{
		i++;
	}
	if(i == listHead)
	{
		i = -1;
	}
	return(i);
}

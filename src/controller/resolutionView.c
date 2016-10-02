/**
 * @file resolutionView.c
 * @brief      Create a resolution window
 * @author     Nathanaël SPRIET
 */

#include "resolutionView.h"
/*
 **************************** Globals *************************
*/
/**
 * @brief      Boolean value that controls if the path buttons state
 */
int findPathButtonsAcivated = 1;
/**
 * @brief      Boolean value that controls the loop
 */
int stayInResolutionLoop = 1;
/**
 * @brief      Boolean value that represent the step by step choice
 */
int stepByStepLaunched = 0;
/**
 * @brief      Boolean value that controls the clears button state
 */
int clearButtonActivated = 1;

/*
 **************************** Core *************************
*/

int launchResolveView(int numRow, int numCol, char* graph)
{
	int state = 0;
	stayInResolutionLoop = 1;
	while(stayInResolutionLoop)
	{
		sdlResolvInit(numRow, numCol);
		findPathButtonsAcivated = 1;
		stepByStepLaunched = 0;
		clearButtonActivated = 1;
		createGraph(numRow, numCol, graph);
		mainResolvLoop(numRow, numCol, graph, &state);
		SDL_Quit();
	}
	return state;
} 

void mainResolvLoop(int numRow, int numCol, char* graph, int* state)
{
	int continuer = 1;
	SDL_Event event;
	Coordinates point;
	pthread_t thread = 0;
	void* status;
	launchPathResolution_args *args = malloc(sizeof *args);
	int djikstra = 0;
	while (continuer)
	{
		SDL_WaitEvent(&event);
		switch(event.type)
		{
			case SDL_QUIT:
				if(clearButtonActivated)
				{
					continuer = 0;
					stayInResolutionLoop = 0;
					*state = 0;
				}
			case SDL_MOUSEBUTTONDOWN:
				point.x = event.button.x;
				point.y = event.button.y;
				if(findPathButtonsAcivated && findPathButtonClicked(point))
				{
					/* Creates the structure to pass the arguments to the function */
					args->numRow = numRow;
					args->numCol = numCol;
					args->graph = graph;
					args->time = 0;
					args->stepByStep = 0;
					args->djikstra = djikstra;
					/* Create the thread */
					pthread_create(&thread, NULL, resolutionAndDrawing_thread, args);

					findPathButtonsAcivated = 0;
				}
				else if(findPathButtonsAcivated && slow_findPathButtonClicked(point))
				{
					/* Creates the structure to pass the arguments to the function */
					args->numRow = numRow;
					args->numCol = numCol;
					args->graph = graph;
					args->time = SLOW_RESOLUTION_TIME;
					args->stepByStep = 0;
					args->djikstra = djikstra;
					/* Create the thread */
					pthread_create(&thread, NULL, resolutionAndDrawing_thread, args);
					findPathButtonsAcivated = 0;
				}
				else if(clearButtonActivated && clearButtonClicked(point))
				{
					continuer = 0;
				}
				else if(nextStepButtonClicked(point))
				{
					if(stepByStepLaunched)
					{
						continueToNextStep();
					}
					else if(findPathButtonsAcivated)
					{
						changeDebugButtonIcon();
						/* Creates the structure to pass the arguments to the function */
						args->numRow = numRow;
						args->numCol = numCol;
						args->graph = graph;
						args->time = SLOW_RESOLUTION_TIME;
						args->stepByStep = 1;
						args->djikstra = djikstra;
						/* Create the thread */
						pthread_create(&thread, NULL, resolutionAndDrawing_thread, args);
						findPathButtonsAcivated = 0;
						stepByStepLaunched = 1;
					}
					
				}
				else if(clearButtonActivated && buildButtonClicked(point))
				{
					continuer = 0;
					stayInResolutionLoop = 0;
					*state = 1;
				}
				else if(clearButtonActivated && algoSelectionButtonClicked(point))
				{
					djikstra = !djikstra;
					changeAlgoSelectionButtonIcon(djikstra);
				}

			break;
		}
	}
	free(args);
	if(thread != 0)
	{
		pthread_join(thread, &status);
	}
}

void * resolutionAndDrawing_thread(void* args)
{
	clearButtonActivated = 0;
	launchPathResolution_args *actual_args = (launchPathResolution_args*)args;
	int numRow = actual_args->numRow;
	int numCol = actual_args->numCol;
	int stepByStep = actual_args->stepByStep;
	int djikstra = actual_args->djikstra;
	char* graph = actual_args->graph;
	int time = actual_args->time;
	int finalPathLength = 0;
	Coordinates finalPath[numRow*numCol];
	finalPathLength = launchPathResolution(numRow, numCol, graph, finalPath, time, stepByStep, djikstra);
	drawFinalPath(finalPathLength, numRow, numCol, finalPath);
	clearButtonActivated = 1;
	pthread_exit(0);
}

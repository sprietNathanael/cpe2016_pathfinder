#include "view.h"
int findPathButtonsAcivated = 1;
int stayInLoop = 1;
int stepByStepLaunched = 0;
int clearButtonActivated = 1;

int launchResolveView(int numRow, int numCol, char* graph)
{
	int state = 0;
	stayInLoop = 1;
	while(stayInLoop)
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

void launchCreationView(int numRow, int numCol, char* graph)
{
	stayInLoop = 1;
	while(stayInLoop)
	{
		sdlCreationInit(numRow, numCol);
		createGraph(numRow, numCol, graph);
		mainCreationLoop(numRow, numCol, graph);
		SDL_Quit();
	}
}   

void mainCreationLoop(int numRow, int numCol, char* graph)
{
	int continuer = 1;
	SDL_Event event;
	Coordinates point;
	Coordinates finalPath[numRow*numCol];
	while (continuer)
	{
		SDL_WaitEvent(&event);
		switch(event.type)
		{
			case SDL_QUIT:
				stayInLoop = 0;
				continuer = 0;
				break;
			case SDL_MOUSEBUTTONDOWN:
				point.x = event.button.x;
				point.y = event.button.y;
				Coordinates pointedNode = computeThePointedNodeCoordinatesFromSDL(numRow, numCol, point.x, point.y);
				printf("(%d;%d)\n",pointedNode.x, pointedNode.y);
		}
	}
}

void mainResolvLoop(int numRow, int numCol, char* graph, int* state)
{
	int continuer = 1;
	SDL_Event event;
	Coordinates point;
	Coordinates finalPath[numRow*numCol];
	pthread_t thread = 0;
	void* status;
	launchPathResolution_args *args = malloc(sizeof *args);
	while (continuer)
	{
		SDL_WaitEvent(&event);
		switch(event.type)
		{
			case SDL_QUIT:
				if(clearButtonActivated)
				{
					continuer = 0;
					stayInLoop = 0;
					*state = 0;
				}
			case SDL_MOUSEBUTTONDOWN:
				point.x = event.button.x;
				point.y = event.button.y;
				if(findPathButtonsAcivated && findPathButtonClicked(point))
				{
					/**
					 * Creates the structure to pass the arguments to the function
					 */
					args->numRow = numRow;
					args->numCol = numCol;
					args->graph = graph;
					args->time = 0;
					args->stepByStep = 0;
					/**
					 * Create the thread
					 */
					pthread_create(&thread, NULL, resolutionAndDrawing_thread, args);

					findPathButtonsAcivated = 0;
				}
				else if(findPathButtonsAcivated && slow_findPathButtonClicked(point))
				{
					/**
					 * Creates the structure to pass the arguments to the function
					 */
					args->numRow = numRow;
					args->numCol = numCol;
					args->graph = graph;
					args->time = SLOW_RESOLUTION_TIME;
					args->stepByStep = 0;
					/**
					 * Create the thread
					 */
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
						/**
						 * Creates the structure to pass the arguments to the function
						 */
						args->numRow = numRow;
						args->numCol = numCol;
						args->graph = graph;
						args->time = SLOW_RESOLUTION_TIME;
						args->stepByStep = 1;
						/**
						 * Create the thread
						 */
						pthread_create(&thread, NULL, resolutionAndDrawing_thread, args);
						findPathButtonsAcivated = 0;
						stepByStepLaunched = 1;
					}
					
				}
				else if(clearButtonActivated && buildButtonClicked(point))
				{
					continuer = 0;
					stayInLoop = 0;
					*state = 1;
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
	char* graph = actual_args->graph;
	int time = actual_args->time;
	int finalPathLength = 0;
	Coordinates finalPath[numRow*numCol];
	finalPathLength = launchPathResolution(numRow, numCol, graph, finalPath, time, stepByStep);
	drawFinalPath(finalPathLength, numRow, numCol, finalPath);
	clearButtonActivated = 1;
	pthread_exit(0);
}






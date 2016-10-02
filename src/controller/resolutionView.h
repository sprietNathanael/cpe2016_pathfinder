/**
 * @file resolutionView.h
 * @brief      Create a resolution window
 * @author     Nathanaël SPRIET
 */

#ifndef RESOLUTION_VIEW_H
#define RESOLUTION_VIEW_H

#include <pthread.h>
#include "../pathfinding/astar_pathfinding.h"

/*
 **************************** Constants *************************
*/
/**
 * @brief      Time factor for slowly resolution
 */
#define SLOW_RESOLUTION_TIME 400*1000


/*
 ***************************** Structures *************************
*/
/**
 * @brief      Structure that helps in thread creation
 */
typedef struct {
    int numRow; /*!< Graph's row quantity */
    int numCol; /*!< Graph's column quantity */
    char* graph; /*!< Pointer to the graph */
    Coordinates* finalPath; /*!< Pointer to a coordinates array for final path */
    int time; /*!< Time between each steps */
    int stepByStep; /*!< Boolean value that represent step by step resolution choice */
    int djikstra; /*!< Boolean value that represent djikstra resolution choice */
} launchPathResolution_args;

/*
 ***************************** Functions *************************
*/
/**
 * @brief          Main loop of the resolution window
 *
 * @param[in]      numRow  The row quantity
 * @param[in]      numCol  The col quantity
 * @param[in, out] graph   A pointer to the graph
 * @param[out]     state   The exit state :
 *           - 0 if the application has to be closed
 *           - 1 if the creation window has to be open
 */
void mainResolvLoop(int numRow, int numCol, char* graph, int* state);

/**
 * @brief          Loop that creates SDL window
 *
 * @param[in]      numRow  The row quantity
 * @param[in]      numCol  The col quantity
 * @param[in, out] graph   A pointer to the graph
 *
 * @return         Exit state of the loop :
 * - 1 if the created graph is to be used
 * - 0 if not
 * - -1 if the program has to quit
 */
int launchResolveView(int numRow, int numCol, char* graph);


/**
 * @brief      Thread that launches the grpah resolution
 *
 * @param[in]  args  A launchPathResolution_args structure that contains the
 *                   arguments
 *
 * @return     nothing special
 */
void * resolutionAndDrawing_thread(void* args);

#endif /* RESOLUTION_VIEW_H */
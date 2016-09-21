#ifndef SDL_DRAWING
#define SDL_DRAWING

#include <SDL/SDL.h>
#include <math.h>
#include "graph_managment.h"

/**
 * @brief      Determines if a given point is in a given SDL rectangle.
 *
 * @param[in]  rect   The rectangle
 * @param[in]  point  The point
 *
 * @return     1 if the point is in rectangle, 0 otherwise.
 */
int isPointInRectangle(SDL_Rect rect, Coordinates point);

/**
 * @brief      Draws line between two nodes.
 *
 * @param[in]  nodeA    The node a
 * @param[in]  nodeB    The node b
 * @param      surface  The surface
 */
void drawLineBetweenTwoNodes(Coordinates nodeA, Coordinates nodeB, SDL_Surface* surface);

/**
 * Code found here : http://anomaly.developpez.com/tutoriel/sdl/partie2/
 */

/**
 * @brief      Exchange two integers
 *
 * @param      x
 * @param      y
 */
void echangerEntiers(int* x, int* y);


/**
 * @brief      Draw a line between two points
 *
 * @param[in]  nodeA    The node a
 * @param[in]  nodeB    The node b
 * @param[in]  weight   The weight of the line
 * @param[in]  coul     The color
 * @param      surface  The surface
 */
void ligne(Coordinates nodeA, Coordinates nodeB, int weight, Uint32 coul, SDL_Surface* surface);


/**
 * @brief      Set a pixel to a given color
 *
 * @param[in]  x        x coordinate of the pixel
 * @param[in]  y        y coordinate of the pixel
 * @param[in]  coul     The color
 * @param      surface  The surface
 */
void setPixelVerif(int x, int y, Uint32 coul, SDL_Surface* surface);

#endif
/**
 * @file sdl_drawing.h
 * @brief      Tools to draw with SDL
 * @author     Nathanaël SPRIET
 */

#ifndef SDL_DRAWING
#define SDL_DRAWING

#include <SDL/SDL.h>
#include <math.h>
#include "../model/graph_managment.h"

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
 * @brief      Exchange two integers
 *
 * @param[in]  x     First integer to exchange
 * @param[in]  y     Second integer to exchange
 */
void echangerEntiers(int* x, int* y);


/**
 * @brief      Draw a line between two points (code found here : Code found here
 *             : http://anomaly.developpez.com/tutoriel/sdl/partie2/ )
 *
 * @param[in]  nodeA    The node a
 * @param[in]  nodeB    The node b
 * @param[in]  weight   The weight of the line
 * @param[in]  coul     The color
 * @param[in]  surface  The SDL_Surface to draw
 */
void ligne(Coordinates nodeA, Coordinates nodeB, int weight, Uint32 coul, SDL_Surface* surface);


/**
 * @brief      Set a pixel to a given color
 *
 * @param[in]  x        x coordinate of the pixel
 * @param[in]  y        y coordinate of the pixel
 * @param[in]  coul     The color
 * @param[in]  surface  The SDL_Surface to draw
 */
void setPixelVerif(int x, int y, Uint32 coul, SDL_Surface* surface);

#endif
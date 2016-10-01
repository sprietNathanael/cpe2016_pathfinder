#define SDL_DRAWING_C
#include "sdl_drawing.h"

int isPointInRectangle(SDL_Rect rect, Coordinates point)
{
	if((point.x >= rect.x && point.x <= (rect.x+rect.w)) && (point.y >= rect.y && point.y <= (rect.y+rect.h)))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}



void echangerEntiers(int* x, int* y)
{
    int t = *x;
    *x = *y;
    *y = t;
}

void ligne(Coordinates nodeA, Coordinates nodeB, int weight, Uint32 coul, SDL_Surface* surface)
{
    int d, dx, dy, aincr, bincr, xincr, yincr, x, y;
    int weightIncr = 0;

    /**
     * If the line has to be browsed verically
     */
    if (abs(nodeB.x - nodeA.x) < abs(nodeB.y - nodeA.y))
    {

        if (nodeA.y > nodeB.y)
        {
            echangerEntiers(&nodeA.x, &nodeB.x);
            echangerEntiers(&nodeA.y, &nodeB.y);
        }

        /**
         * Determine the direction
         */
        xincr = nodeB.x > nodeA.x ? 1 : -1;
        dy = nodeB.y - nodeA.y;
        dx = abs(nodeB.x - nodeA.x);
        d = 2 * dx - dy;
        aincr = 2 * (dx - dy);
        bincr = 2 * dx;
        x = nodeA.x;
        y = nodeA.y;
        for(weightIncr = 0; weightIncr < weight; weightIncr++)
        {
            setPixelVerif(x+weightIncr, y, coul, surface);
        }

        for (y = nodeA.y+1; y <= nodeB.y; ++y)
        {
            if (d >= 0)
            {
                x += xincr;
                d += aincr;
            }
            else
            {
                d += bincr;
            }
            for(weightIncr = 0; weightIncr < weight; weightIncr++)
            {
                setPixelVerif(x+weightIncr, y, coul, surface);
            }
        }

    }
    else
    {
        /* parcours par l'axe horizontal */

        if (nodeA.x > nodeB.x)
        {
            echangerEntiers(&nodeA.x, &nodeB.x);
            echangerEntiers(&nodeA.y, &nodeB.y);
        }

        yincr = nodeB.y > nodeA.y ? 1 : -1;
        dx = nodeB.x - nodeA.x;
        dy = abs(nodeB.y - nodeA.y);
        d = 2 * dy - dx;
        aincr = 2 * (dy - dx);
        bincr = 2 * dy;
        x = nodeA.x;
        y = nodeA.y;

        for(weightIncr = 0; weightIncr < weight; weightIncr++)
        {
            setPixelVerif(x, y+weightIncr, coul, surface);
        }

        for (x = nodeA.x+1; x <= nodeB.x; ++x)
        {
            if (d >= 0)
            {
                y += yincr;
                d += aincr;
            }
            else
            {
                d += bincr;
            }

            for(weightIncr = 0; weightIncr < weight; weightIncr++)
            {
                setPixelVerif(x, y+weightIncr, coul, surface);
            }
        }
    }
}

void setPixelVerif(int x, int y, Uint32 coul, SDL_Surface* surface)
{
    if ( SDL_MUSTLOCK(surface) ) {
        if ( SDL_LockSurface(surface) < 0 ) {
            printf("Can't lock surface: %s\n", SDL_GetError());
            return;
        }
    }
    if (x >= 0 && x < surface->w && y >= 0 && y < surface->h)
    {
        int bpp = surface->format->BytesPerPixel;
        Uint8 *p = (Uint8*)(surface->pixels) + x * bpp + y * surface->pitch;
        *(Uint32 *)p = coul;
        SDL_Flip(surface);
    }
    if ( SDL_MUSTLOCK(surface) ) {
        SDL_UnlockSurface(surface);
    }
}

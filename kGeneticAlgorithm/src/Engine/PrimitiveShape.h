#pragma once

#include "game.h"

#include "Entities/EntitySystem.h"

#include <SDL.h>

class PrimitiveShape {
public:
	//! \brief From answer by Scotty Stephens
	//! \https://stackoverflow.com/questions/38334081/howto-draw-circles-arcs-and-vector-graphics-in-sdl
	//! \with minor changes
	void DrawCircle(int32_t centreX, int32_t centreY, int32_t radius)
	{
		SDL_SetRenderDrawColor(Game::_SDLRenderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
		const int32_t diameter = (radius * 2);

		int32_t x = (radius - 1);
		int32_t y = 0;
		int32_t tx = 1;
		int32_t ty = 1;
		int32_t error = (tx - diameter);

		while (x >= y)
		{
			//  Each of the following renders an octant of the circle
			SDL_RenderDrawPoint(Game::_SDLRenderer, centreX + x, centreY - y);
			SDL_RenderDrawPoint(Game::_SDLRenderer, centreX + x, centreY + y);
			SDL_RenderDrawPoint(Game::_SDLRenderer, centreX - x, centreY - y);
			SDL_RenderDrawPoint(Game::_SDLRenderer, centreX - x, centreY + y);
			SDL_RenderDrawPoint(Game::_SDLRenderer, centreX + y, centreY - x);
			SDL_RenderDrawPoint(Game::_SDLRenderer, centreX + y, centreY + x);
			SDL_RenderDrawPoint(Game::_SDLRenderer, centreX - y, centreY - x);
			SDL_RenderDrawPoint(Game::_SDLRenderer, centreX - y, centreY + x);

			if (error <= 0)
			{
				++y;
				error += ty;
				ty += 2;
			}

			if (error > 0)
			{
				--x;
				tx += 2;
				error += (tx - diameter);
			}
		}
	}
};
/********************************************************************
 * \file   main.cpp
 * \brief  
 * 
 * \author Bartlomiej Gac
 * \date   June 2022
 *********************************************************************/

#include "SDL.h"
#include "Game.hpp"

Game* game = NULL;

/**
 * main function
 * 
 * \param argc
 * \param argv
 * \return 
 */
int main(int argc, char *argv[])
{
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;

	uint32_t frameStart;
	int frameTime;

	game = new Game();

	game->init("game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 600, false);

	while (game->running())
	{
		frameStart = SDL_GetTicks();
		game->handleEvent();
		game->update();
		game->render();
		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}

	game->clean();

	return 0;
}
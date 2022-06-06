/********************************************************************
 * \file   main.cpp
 * \brief  
 * 
 * \author Bartlomiej Gac
 * \date   June 2022
 *********************************************************************/

#include "SDL.h"
#include "Game.hpp"
#include "FrameHandler.hpp"

Game* game = NULL;
FrameHandler* frameHandler = NULL;

/**
 * main function
 * 
 * \param argc
 * \param argv
 * \return 
 */
int main(int argc, char *argv[])
{
	game = new Game("game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 600, false);
	frameHandler = new FrameHandler(60);

	while (game->running())
	{
		frameHandler->SetStart();
		game->handleEvent();
		game->update();
		game->render();
		frameHandler->HandleFPS();
	}

	delete game;
	delete frameHandler;

	return 0;
}
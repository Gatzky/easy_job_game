/*****************************************************************//**
 * \file   Game.cpp
 * \brief  
 * 
 * \author Bart³omiej Gac
 * \date   June 2022
 *********************************************************************/

#include "Game.hpp"

SDL_Texture* playerTex;
SDL_Rect scrR, destR;

Game::Game(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	uint32_t  flags = 0u;
	flags = fullscreen ? SDL_WINDOW_FULLSCREEN : 0u;
	isRunning = false;

	if (SDL_Init(SDL_INIT_EVERYTHING) == false)
	{
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer && window)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
		}
		isRunning = true;

		playerTex = IMG_LoadTexture(renderer, "assets/vampire.png");
	}
}

Game::~Game()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyTexture(playerTex);
	SDL_Quit();
}

void Game::handleEvent()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}
}

void Game::update()
{
	static uint8_t cnt;
	cnt++;
	destR.h = 44;
	destR.w = 30;
	destR.x = cnt;

}

void Game::render()
{
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, playerTex, NULL, &destR);
	SDL_RenderPresent(renderer);
}

bool Game::running()
{
	return isRunning;
}

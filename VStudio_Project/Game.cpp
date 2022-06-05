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

Game::Game(){}
Game::~Game(){}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	uint32_t  flags = 0u;
	flags = fullscreen ? SDL_WINDOW_FULLSCREEN : 0u;

	if (SDL_Init(SDL_INIT_EVERYTHING) == false)
	{
		std::cout << "Subsystem Initialized..." << std::endl;

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if(window)
		{
			std::cout << "Window created" << std::endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if(renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer created" << std::endl;
		}
		isRunning = true;
	}
	else
	{
		isRunning = false;
	}

	playerTex = IMG_LoadTexture(renderer, "assets/vampire.png");
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

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game cleaned" << std::endl;
}

bool Game::running()
{
	return isRunning;
}

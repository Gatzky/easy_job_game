/*****************************************************************//**
 * \file   Game.cpp
 * \brief  
 * 
 * \author Bart³omiej Gac
 * \date   June 2022
 *********************************************************************/

#include "Game.hpp"
#include "GameObject.hpp"

GameObject* player;
SDL_Texture* playerTex;
SDL_Rect scrR, destR;

Game::Game(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	uint32_t  flags = 0u;
	flags = fullscreen ? SDL_WINDOW_FULLSCREEN : 0u;
	isRunning = false;
	renderer = NULL;
	window = NULL;

	if (SDL_Init(SDL_INIT_EVERYTHING) == false)
	{
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer && window)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
		}
		isRunning = true;

		player = new GameObject("assets/vampire.png", renderer, 100, 100);
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
	player->Update();
}

void Game::render()
{
	SDL_RenderClear(renderer);
	player->Render();
	SDL_RenderPresent(renderer);
}

bool Game::running()
{
	return isRunning;
}

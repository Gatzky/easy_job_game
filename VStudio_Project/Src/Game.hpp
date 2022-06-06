/*****************************************************************//**
 * \file   Game.hpp
 * \brief  
 * 
 * \author Bartlomiej Gac
 * \date   June 2022
 *********************************************************************/

#pragma once

#include <iostream>
#include "SDL.h"
#include "SDL_image.h"

class Game
{
public:
	Game(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	~Game();

	void handleEvent();
	void update();
	void render();

	bool running();
private:
	bool isRunning;
	SDL_Window* window;
	SDL_Renderer* renderer;
};

/*****************************************************************//**
 * \file   GameObject.hpp
 * \brief  
 * 
 * \author Bartlomiej Gac
 * \date   June 2022
 *********************************************************************/

#pragma once
#include "SDL.h"
#include "SDL_image.h"

class GameObject
{
public:
	GameObject(const char* texturesheet, SDL_Renderer* ren, int x, int y);
	~GameObject();

	void Update();
	void Render();

private:
	int xpos;
	int ypos;

	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
	SDL_Renderer* renderer;
};

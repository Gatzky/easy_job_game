/*****************************************************************//**
 * \file   GameObject.cpp
 * \brief  
 * 
 * \author user
 * \date   June 2022
 *********************************************************************/

#include "GameObject.hpp"

GameObject::GameObject(const char* texturesheet, SDL_Renderer* ren, int x, int y)
{
	renderer = ren;
	objTexture = IMG_LoadTexture(ren, texturesheet);
	xpos = x;
	ypos = y;
}
GameObject::~GameObject(){}

void GameObject::Update()
{
	xpos--;
	ypos--;

	srcRect.h = 44;
	srcRect.w = 30;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.h = srcRect.h;
	destRect.w = srcRect.w;
	destRect.x = xpos;
	destRect.y = ypos;
}

void GameObject::Render()
{
	SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
}

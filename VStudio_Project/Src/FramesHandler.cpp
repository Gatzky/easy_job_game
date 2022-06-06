/*****************************************************************//**
 * \file   FramesHandler.cpp
 * \brief  
 * 
 * \author user
 * \date   June 2022
 *********************************************************************/

#include "FrameHandler.hpp"

FrameHandler::FrameHandler(uint32_t FPS)
{
	frameDelay = 1000 / FPS;
	frameStart = 0;
}

FrameHandler::~FrameHandler() {}

void FrameHandler::SetStart()
{
	frameStart = SDL_GetTicks();
}

void FrameHandler::HandleFPS()
{
	uint32_t frameTime = SDL_GetTicks() - frameStart;

	if (frameDelay > frameTime)
	{
		SDL_Delay(frameDelay - frameTime);
	}
}

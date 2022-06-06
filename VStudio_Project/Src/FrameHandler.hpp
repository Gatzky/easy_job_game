/*****************************************************************//**
 * \file   FrameHandler.hpp
 * \brief  
 * 
 * \author Bartlomiej Gac
 * \date   June 2022
 *********************************************************************/

#pragma once

#include "SDL.h"

class FrameHandler
{
public:
	FrameHandler(uint32_t FPS);
	~FrameHandler();

	void SetStart();
	void HandleFPS();

private:
	uint32_t frameDelay;
	uint32_t frameStart;
};



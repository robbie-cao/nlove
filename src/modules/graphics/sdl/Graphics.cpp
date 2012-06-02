/**
* Copyright (c) 2006-2012 LOVE Development Team
*
* This software is provided 'as-is', without any express or implied
* warranty.  In no event will the authors be held liable for any damages
* arising from the use of this software.
*
* Permission is granted to anyone to use this software for any purpose,
* including commercial applications, and to alter it and redistribute it
* freely, subject to the following restrictions:
*
* 1. The origin of this software must not be misrepresented; you must not
*    claim that you wrote the original software. If you use this software
*    in a product, an acknowledgment in the product documentation would be
*    appreciated but is not required.
* 2. Altered source versions must be plainly marked as such, and must not be
*    misrepresented as being the original software.
* 3. This notice may not be removed or altered from any source distribution.
**/

// LOVE
#include "Graphics.h"

#include <window/sdl/Window.h>

namespace love
{
namespace graphics
{
namespace sdl
{
	Graphics::Graphics()
	{
		currentWindow = love::window::sdl::Window::getSingleton();
	}

	Graphics::~Graphics()
	{
		currentWindow->release();
	}

	const char *Graphics::getName() const
	{
		return "love.graphics.sdl";
	}

	bool Graphics::setMode(int width, int height, bool fullscreen, bool vsync, int fsaa)
	{
		return currentWindow->setWindow(width, height, fullscreen, vsync, fsaa);
	}

	void Graphics::getMode(int &width, int &height, bool &fullscreen, bool &vsync, int &fsaa)
	{
		currentWindow->getWindow(width, height, fullscreen, vsync, fsaa);
	}

	bool Graphics::toggleFullscreen()
	{
		int width, height, fsaa;
		bool fullscreen, vsync;
		currentWindow->getWindow(width, height, fullscreen, vsync, fsaa);
		return setMode(width, height, !fullscreen, vsync, fsaa);
	}

	bool Graphics::checkMode(int width, int height, bool fullscreen)
	{
		return currentWindow->checkWindowSize(width, height, fullscreen);
	}

	bool Graphics::isCreated()
	{
		return currentWindow->isCreated();
	}

	int Graphics::getWidth()
	{
		return currentWindow->getWidth();
	}

	int Graphics::getHeight()
	{
		return currentWindow->getHeight();
	}
} // sdl
} // graphics
} // love

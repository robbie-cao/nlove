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

// SDL
#include "SDL_gfxPrimitives.h"

namespace love
{
namespace graphics
{
namespace sdl
{
	Graphics::Graphics()
		: surface(0)
	{
		currentWindow = love::window::sdl::Window::getSDLSingleton();
		reset();
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
		bool success = currentWindow->setWindow(width, height, fullscreen, vsync, fsaa);
		if (success)
			surface = currentWindow->getSurface();
		return success;
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

	void Graphics::reset()
	{
		foregroundColor.set(255, 255, 255, 255);
		backgroundColor.set(0, 0, 0, 255);
	}

	void Graphics::clear()
	{
		if (surface == 0)
			return;
		boxRGBA(surface, 0, 0, getWidth(), getHeight(),
				backgroundColor.r, backgroundColor.g, backgroundColor.b, backgroundColor.a);
	}

	void Graphics::present()
	{
		currentWindow->swapBuffers();
	}

	void Graphics::setCaption(const char *caption)
	{
		currentWindow->setWindowTitle(caption);
	}

	const char *Graphics::getCaption() const
	{
		return currentWindow->getWindowTitle().c_str();
	}

	void Graphics::setColor(const Color &c)
	{
		foregroundColor = c;
	}

	Color Graphics::getColor()
	{
		return foregroundColor;
	}

	void Graphics::setBackgroundColor(const Color &c)
	{
		backgroundColor = c;
	}

	Color Graphics::getBackgroundColor()
	{
		return backgroundColor;
	}

	void Graphics::point(float x, float y)
	{
		pixelRGBA(surface, (int) x, (int) y,
				foregroundColor.r, foregroundColor.g, foregroundColor.b, foregroundColor.a);
	}

	void Graphics::rectangle(DrawMode mode, float x, float y, float w, float h)
	{
		float x2 = x+w;
		float y2 = y+h;

		switch(mode)
		{
		case DRAW_LINE:
			rectangleRGBA(surface, (int) x, (int) y, (int) x2, (int) y2,
					foregroundColor.r, foregroundColor.g, foregroundColor.b, foregroundColor.a);
			break;
		case DRAW_FILL:
			boxRGBA(surface, (int) x, (int) y, (int) x2, (int) y2,
					foregroundColor.r, foregroundColor.g, foregroundColor.b, foregroundColor.a);
			break;
		default: // prevent warnings
			break;
		}
	}
} // sdl
} // graphics
} // love

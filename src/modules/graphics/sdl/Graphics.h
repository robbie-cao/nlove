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

#ifndef LOVE_GRAPHICS_SDL_GRAPHICS_H
#define LOVE_GRAPHICS_SDL_GRAPHICS_H

// LOVE
#include <graphics/Graphics.h>
#include <graphics/Color.h>

#include <image/Image.h>
#include <image/ImageData.h>

#include <window/sdl/Window.h>

#include "Image.h"

// SDL
#include <SDL.h>

namespace love
{
namespace graphics
{
namespace sdl
{
	class Graphics : public love::graphics::Graphics
	{
	private:
		love::window::sdl::Window *currentWindow;
		Color foregroundColor, backgroundColor;
		SDL_Surface *surface;

	public:
		Graphics();
		virtual ~Graphics();

		const char *getName() const;

		bool setMode(int width, int height, bool fullscreen, bool vsync, int fsaa);
		void getMode(int &width, int &height, bool &fullscreen, bool &vsync, int &fsaa);
		bool toggleFullscreen();
		bool checkMode(int width, int height, bool fullscreen);
		bool isCreated();
		int getWidth();
		int getHeight();

		void reset();
		void clear();
		void present();

		void setCaption(const char *caption);
		const char *getCaption() const;

/*		Image *newImage(love::filesystem::File *file);
		Image *newImage(love::image::ImageData *data);
		Quad *newQuad(float x, float y, float w, float h, float sw, float sh);*/

		void setColor(const Color &c);
		Color getColor();
		void setBackgroundColor(const Color &c);
		Color getBackgroundColor();

		void point(float x, float y);
/*		void triangle(DrawMode mode, float x1, float y1, float x2, float y2, float x3, float y3);*/
		void rectangle(DrawMode mode, float x, float y, float w, float h);
/*		void quad(DrawMode mode, float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4);
		void circle(DrawMode mode, float x, float y, float radius, int points = 10);*/
	}; // Graphics
} // sdl
} // graphics
} // love

#endif // LOVE_GRAPHICS_SDL_GRAPHICS_H

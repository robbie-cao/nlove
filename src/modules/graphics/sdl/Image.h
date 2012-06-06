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

#ifndef LOVE_GRAPHICS_SDL_IMAGE_H
#define LOVE_GRAPHICS_SDL_IMAGE_H

// LOVE
#include <common/Matrix.h>
#include <common/math.h>
#include <common/config.h>
#include <image/ImageData.h>
#include <graphics/Image.h>

namespace love
{
namespace graphics
{
namespace sdl
{
	class Image : public love::graphics::Image
	{
		Image(love::image::ImageData *data);
		virtual ~Image();

		float getWidth() const;
		float getHeight() const;

		love::image::ImageData *getData() const;

		void draw(float x, float y, float angle, float sx, float sy, float ox, float oy, float kx, float ky);
		void drawq(love::graphics::Quad *quad, float x, float y, float angle, float sx, float sy, float ox, float oy, float kx, float ky);

		bool loadVolatile();
		void unloadVolatile();
	}; // Image
} // sdl
} // graphics
} // love

#endif // LOVE_GRAPHICS_SDL_IMAGE_H

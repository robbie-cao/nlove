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

#ifndef LOVE_GRAPHICS_SDL_WRAP_GRAPHICS_H
#define LOVE_GRAPHICS_SDL_WRAP_GRAPHICS_H

#include "Graphics.h"

namespace love
{
namespace graphics
{
namespace sdl
{
	int w_setMode(lua_State *L);
	int w_getMode(lua_State *L);
	int w_toggleFullscreen(lua_State *L);
	int w_checkMode(lua_State *L);
	int w_isCreated(lua_State *L);
	int w_getWidth(lua_State *L);
	int w_getHeight(lua_State *L);
	int w_reset(lua_State *L);
	int w_clear(lua_State *L);
	int w_present(lua_State *L);
	int w_setCaption(lua_State *L);
	int w_getCaption(lua_State *L);
/*	int w_newImage(lua_State *L);
	int w_newQuad(lua_State *L);*/
	int w_setColor(lua_State *L);
	int w_getColor(lua_State *L);
	int w_setBackgroundColor(lua_State *L);
	int w_getBackgroundColor(lua_State *L);
	int w_point(lua_State *L);
/*	int w_triangle(lua_State *L);*/
	int w_rectangle(lua_State *L);
/*	int w_quad(lua_State *L);
	int w_circle(lua_State *L);
	int w_draw(lua_State *L);
	int w_drawq(lua_State *L);*/
	extern "C" LOVE_EXPORT int luaopen_love_graphics(lua_State *L);
} // sdl
} // graphics
} // love

#endif // LOVE_GRAPHICS_SDL_WRAP_GRAPHICS_H

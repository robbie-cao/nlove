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

#include "wrap_Graphics.h"

namespace love
{
namespace graphics
{
namespace sdl
{
	static Graphics *instance = 0;

	int w_setMode(lua_State *L)
	{
		int w = luaL_checkint(L, 1);
		int h = luaL_checkint(L, 2);
		bool fs = luax_optboolean(L, 3, false);
		bool vsync = luax_optboolean(L, 4, true);
		int fsaa = luaL_optint(L, 5, 0);
		luax_pushboolean(L, instance->setMode(w, h, fs, vsync, fsaa));
		return 1;
	}

	int w_getMode(lua_State *L)
	{
		int w, h, fsaa;
		bool fs, vsync;
		instance->getMode(w, h, fs, vsync, fsaa);
		lua_pushinteger(L, w);
		lua_pushinteger(L, h);
		luax_pushboolean(L, fs);
		luax_pushboolean(L, vsync);
		lua_pushinteger(L, fsaa);
		return 5;
	}

	int w_toggleFullscreen(lua_State *L)
	{
		luax_pushboolean(L, instance->toggleFullscreen());
		return 1;
	}

	int w_checkMode(lua_State *L)
	{
		int w = luaL_checkint(L, 1);
		int h = luaL_checkint(L, 2);
		bool fs = luax_optboolean(L, 3, false);
		luax_pushboolean(L, instance->checkMode(w, h, fs));
		return 1;
	}

	int w_isCreated(lua_State *L)
	{
		luax_pushboolean(L, instance->isCreated());
		return 1;
	}

	int w_getWidth(lua_State *L)
	{
		lua_pushinteger(L, instance->getWidth());
		return 1;
	}

	int w_getHeight(lua_State *L)
	{
		lua_pushinteger(L, instance->getHeight());
		return 1;
	}

	int w_reset(lua_State *L)
	{
		instance->reset();
		return 0;
	}

	int w_clear(lua_State *L)
	{
		instance->clear();
		return 0;
	}

	int w_present(lua_State *L)
	{
		instance->present();
		return 0;
	}

	int w_setCaption(lua_State *L)
	{
		const char *caption = luaL_checkstring(L, 1);
		instance->setCaption(caption);
		return 0;
	}

	int w_getCaption(lua_State *L)
	{
		lua_pushstring(L, instance->getCaption());
		return 1;
	}

/*	int w_newImage(lua_State *L)
	{
		return 0;
	}

	int w_newQuad(lua_State *L)
	{
		return 0;
	}*/

	int w_setColor(lua_State *L)
	{
		int r = luaL_checkint(L, 1);
		int g = luaL_checkint(L, 2);
		int b = luaL_checkint(L, 3);
		int a = luaL_optint(L, 4, 255);
		Color c(r, g, b, a);
		instance->setColor(c);
		return 0;
	}

	int w_getColor(lua_State *L)
	{
		Color c = instance->getColor();
		lua_pushinteger(L, c.r);
		lua_pushinteger(L, c.g);
		lua_pushinteger(L, c.b);
		lua_pushinteger(L, c.a);
		return 4;
	}

	int w_setBackgroundColor(lua_State *L)
	{
		int r = luaL_checkint(L, 1);
		int g = luaL_checkint(L, 2);
		int b = luaL_checkint(L, 3);
		int a = luaL_optint(L, 4, 255);
		Color c(r, g, b, a);
		instance->setBackgroundColor(c);
		return 0;
	}

	int w_getBackgroundColor(lua_State *L)
	{
		Color c = instance->getBackgroundColor();
		lua_pushinteger(L, c.r);
		lua_pushinteger(L, c.g);
		lua_pushinteger(L, c.b);
		lua_pushinteger(L, c.a);
		return 4;
	}

	int w_point(lua_State *L)
	{
		float x = luaL_checknumber(L, 1);
		float y = luaL_checknumber(L, 2);
		instance->point(x, y);
		return 0;
	}

/*	int w_triangle(lua_State *L)
	{
		return 0;
	}*/

	int w_rectangle(lua_State *L)
	{
		Graphics::DrawMode mode;
		const char * str = luaL_checkstring(L, 1);
		if (!Graphics::getConstant(str, mode))
			return luaL_error(L, "Incorrect draw mode %s", str);

		float x = luaL_checknumber(L, 2);
		float y = luaL_checknumber(L, 3);
		float w = luaL_checknumber(L, 4);
		float h = luaL_checknumber(L, 5);
		instance->rectangle(mode, x, y, w, h);
		return 0;
	}

/*	int w_quad(lua_State *L)
	{
		return 0;
	}

	int w_circle(lua_State *L)
	{
		return 0;
	}

	int w_draw(lua_State *L)
	{
		return 0;
	}

	int w_drawq(lua_State *L)
	{
		return 0;
	}*/

	// List of functions to wrap.
	static const luaL_Reg functions[] = {
		{ "setMode", w_setMode },
		{ "getMode", w_getMode },
		{ "toggleFullscreen", w_toggleFullscreen },
		{ "checkMode", w_checkMode },
		{ "isCreated", w_isCreated },
		{ "getWidth", w_getWidth },
		{ "getHeight", w_getHeight },
		{ "reset", w_reset },
		{ "clear", w_clear },
		{ "present", w_present },
		{ "setCaption", w_setCaption },
		{ "getCaption", w_getCaption },
/*		{ "newImage", w_newImage },
		{ "newQuad", w_newQuad },*/
		{ "setColor", w_setColor },
		{ "getColor", w_getColor },
		{ "setBackgroundColor", w_setBackgroundColor },
		{ "getBackgroundColor", w_getBackgroundColor },
		{ "point", w_point },
/*		{ "triangle", w_triangle },*/
		{ "rectangle", w_rectangle },
/*		{ "quad", w_quad },
		{ "circle", w_circle },
		{ "draw", w_draw },
		{ "drawq", w_drawq },*/
		{ 0, 0 }
	};

	static const lua_CFunction types[] = {
		0
	};

	extern "C" int luaopen_love_graphics(lua_State *L)
	{
		if (instance == 0)
		{
			try
			{
				instance = new Graphics();
			}
			catch (Exception & e)
			{
				return luaL_error(L, e.what());
			}
		}
		else
			instance->retain();

		WrappedModule w;
		w.module = instance;
		w.name = "graphics";
		w.flags = MODULE_T;
		w.functions = functions;
		w.types = types;

		return luax_register_module(L, w);
	}
} // sdl
} // graphics
} // love

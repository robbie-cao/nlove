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

	// List of functions to wrap.
	static const luaL_Reg functions[] = {
		{ "setMode", w_setMode },
		{ "getMode", w_getMode },
		{ "toggleFullscreen", w_toggleFullscreen },
		{ "checkMode", w_checkMode },
		{ "isCreated", w_isCreated },
		{ "getWidth", w_getWidth },
		{ "getHeight", w_getHeight },
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

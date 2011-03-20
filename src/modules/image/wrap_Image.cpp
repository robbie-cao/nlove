/**
* Copyright (c) 2006-2011 LOVE Development Team
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

#include "wrap_Image.h"

#include <common/Data.h>
#include <common/StringMap.h>

namespace love
{
namespace image
{
	Image * instance = 0;

	int w_newImageData(lua_State * L)
	{

		// Case 1: Integers.
		if(lua_isnumber(L, 1))
		{
			int w = luaL_checkint(L, 1);
			int h = luaL_checkint(L, 2);
			ImageData * t = instance->newImageData(w, h);
			luax_newtype(L, "ImageData", IMAGE_IMAGE_DATA_T, (void*)t);
			return 1;
		}

		// Case 2: Data
		if(luax_istype(L, 1, DATA_T))
		{
			Data * d = luax_checktype<Data>(L, 1, "Data", DATA_T);
			ImageData * t = 0;
			try {
				t = instance->newImageData(d);
			} catch (love::Exception & e) {
				return luaL_error(L, e.what());
			}
			luax_newtype(L, "ImageData", IMAGE_IMAGE_DATA_T, (void*)t);
			return 1;
		}

		// Case 3: String/File.

		// Convert to File, if necessary.
		if(lua_isstring(L, 1))
			luax_convobj(L, 1, "filesystem", "newFile");

		love::filesystem::File * file = luax_checktype<love::filesystem::File>(L, 1, "File", FILESYSTEM_FILE_T);

		ImageData * t = 0;
		try {
			t = instance->newImageData(file);
		} catch (love::Exception & e) {
			return luaL_error(L, e.what());
		}
		luax_newtype(L, "ImageData", IMAGE_IMAGE_DATA_T, (void*)t);
		return 1;
	}

} // image
} // love

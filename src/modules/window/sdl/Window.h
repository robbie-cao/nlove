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

#ifndef LOVE_WINDOW_SDL_WINDOW_H
#define LOVE_WINDOW_SDL_WINDOW_H

// LOVE
#include <window/Window.h>

// SDL
#include <SDL.h>

namespace love
{
namespace window
{
namespace sdl
{
	class Window : public love::window::Window
	{
	private:
		std::string windowTitle;
		struct _currentMode{
			_currentMode();
			int width;
			int height;
			bool fullscreen;
			bool vsync;
			int fsaa;
		} currentMode;
		bool created;
		bool mouseVisible;
		SDL_Surface *surface;

	public:
		Window();
		~Window();

		bool setWindow(int width = 800, int height = 600, bool fullscreen = false, bool vsync = true, int fsaa = 0);
		void getWindow(int &width, int &height, bool &fullscreen, bool &vsync, int &fsaa);

		bool checkWindowSize(int width, int height, bool fullscreen);
		WindowSize **getFullscreenSizes(int &n);

		int getWidth();
		int getHeight();

		bool isCreated();

		void setWindowTitle(const std::string &title);
		const std::string &getWindowTitle();

		bool setIcon(love::image::ImageData *imgd);

		void swapBuffers();

		bool hasFocus();
		void setMouseVisible(bool visible);
		bool getMouseVisible();

		static love::window::Window *getSingleton();

		// SDL additions
		static Window *getSDLSingleton();
		SDL_Surface *getSurface();

		const char *getName() const;
	}; // Window
} // sdl
} // window
} // love

#endif // LOVE_WINDOW_WINDOW_H

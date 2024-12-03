#pragma once

#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

// IMAGE CLASS

class Img {
	public:
		Img(std::string file);
		SDL_Surface* surf;
		void render(SDL_Renderer* rend, int x, int y, int w, int h);
		void set_icon(SDL_Window* win);
};

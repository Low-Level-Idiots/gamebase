#pragma once

#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Img {
	public:
		Img(SDL_Renderer* rend, std::string file);
		SDL_Surface* surf;
		SDL_Texture* tex;
		void render(SDL_Renderer* rend, int x, int y, int w, int h);
		void set_icon(SDL_Window* win);
};

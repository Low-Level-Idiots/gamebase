#pragma once

#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Game{
	public:
		Game(std::string title, int x, int y, int w, int h, int frame_rate);
		SDL_Window* win;
		SDL_Renderer* rend;
		int fps;
		std::vector<SDL_Event> events;
		bool running;
	public:
		void frame_cap(Uint32 ticks);
		void main();
};

#pragma once

#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Game{
	public:
		Game(std::string title, int x, int y, int w, int h, int frame_rate);                       // constructor
		SDL_Window* win;                                                                           // game window
		SDL_Renderer* rend;                                                                        // renderer for graphics
		int fps;                                                                                   // max framerate for game
		std::vector<SDL_Event> events;                                                             // list of events for handling
		bool running;                                                                              // game running flag
	public:
		void frame_cap(Uint32 ticks);                                                              // cap framerate for performance
		void main();                                                                               // main loop
};

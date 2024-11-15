#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "game.h"
#include "img.h"

Game::Game(std::string title, int x, int y, int w, int h, int frame_rate){
	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_PNG);
	win = SDL_CreateWindow(title.c_str(), x, y, w, h, 0);                                          // create the window
	rend = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);                                  // create renderer

	Img icon(rend, "assets/icon.png");
	icon.set_icon(win);

	fps = frame_rate;
	running = true;
}

void Game::frame_cap(Uint32 ticks){
	if(ticks < 1/fps){
		SDL_Delay(1/fps - ticks);
	}
}

void Game::main(){
	SDL_Event event;
	while(running){
		Uint32 start = SDL_GetTicks();
		while(SDL_PollEvent(&event)){
			events.push_back(event);
		}
		for(int i = 0; i < events.size(); i++){
			switch(events[i].type){
				case SDL_QUIT:
					running = false;
					break;
			}
		}
		frame_cap(start - SDL_GetTicks());
	}
}

#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "game.h"
#include "scene.h"
#include "ui.h"

Game::Game(std::string title, int x, int y, int w, int h, int frame_rate){
	SDL_Init(SDL_INIT_EVERYTHING);                                                                 // init lib
	IMG_Init(IMG_INIT_PNG);
	win = SDL_CreateWindow(title.c_str(), x, y, w, h, 0);                                          // create the window
	rend = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);                                  // create renderer
	icon.init("assets/icon.png");                                                                  // load icon.png as img
	icon.set_icon(win);                                                                            // set icon.png as window icon
	cursor.init("assets/cursor.png");
	SDL_ShowCursor(false);
	fps = frame_rate;                                                                              // store max fps
	scene = &scene1;
	running = true;                                                                                // set main loop flag
}

void Game::frame_cap(Uint32 ticks){
	if(ticks < 1/fps){                                                                             // if cycle time is less than framerate in ticks...
		SDL_Delay(1/fps - ticks);                                                                  // halt until cycle has taken correct amount of time
	}
}

void Game::main(){
	SDL_Event event;                                                                               // declare event
	while(running){                                                                                // while the game is running...
		SDL_GetMouseState(&mouse_x, &mouse_y);
		Uint32 start = SDL_GetTicks();                                                             // get current time in ticks
		events.clear();                                                                            // reset event list
		while(SDL_PollEvent(&event)){                                                              // while events are getting gotten...
			events.push_back(event);                                                               // push event gotten to list of events
		}
		for(int i = 0; i < events.size(); i++){                                                    // iterate through events
			switch(events[i].type){                                                                // checking type of event...
				case SDL_QUIT:                                                                     // if type is quit
					running = false;                                                               // kill game
					break;
			}
		}
		SDL_RenderClear(rend);

		scene->main(scene, rend, events, mouse_x, mouse_y);

		cursor.render(rend, mouse_x, mouse_y, 50, 50);
		SDL_RenderPresent(rend);
		frame_cap(start - SDL_GetTicks());                                                         // cap frame rate
	}
}

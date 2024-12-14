#pragma once

#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

// RECTANGLE CLASS

class Rect {
	public:
		int x;
		int y;
		int w;
		int h;
		void init(int x_, int y_, int w_, int h_);                             // construct a rectangle object
		bool point_colliding(int x_, int y_);                                  // check if this rect is colliding with another rectangle
};

// IMAGE CLASS

class Img {
	public:
		SDL_Surface* surf;                                                     // SDL surface for image
		SDL_Texture* tex;                                                      // SDL texture for image
		void init(SDL_Renderer* rend, std::string file);                       // construct an image object
		void init_crop(std::string file, int x, int y, int w, int h);          // construct an image object
		void render(SDL_Renderer* rend, int x, int y, int w, int h);           // render image
		void set_icon(SDL_Window* win);                                        // set the image as the window icon
};

// BUTTON CLASS

class Button {
	public:
		Rect rect;
		std::vector<Img> sprites;
		typedef enum {
			IDLE,
			HOVER,
			CLICKED
		} State;
		State state;
		void init(SDL_Renderer* rend, std::string basename, Rect rect);
		void get_state(int mouse_x, int mouse_y, std::vector<SDL_Event> events);
		void render(SDL_Renderer* rend);
};

#pragma once

#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

// IMAGE CLASS

class Img {
	public:
		Img(std::string file);                                                 // construct an image object
		SDL_Surface* surf;                                                     // SDL surface for image
		void render(SDL_Renderer* rend, int x, int y, int w, int h);           // function to draw the image to the screen
		void set_icon(SDL_Window* win);                                        // set the image as the window icon
};

// RECTANGLE CLASS

class Rect {
	public:
		Rect(int xp, int y, int w, int h);                                      // construct a rectangle object
		int x;
		int y;
		int w;
		int h;
		bool point_colliding(int x, int y, int w, int h);                      // check if this rect is colliding with another rectangle specified
};

// BUTTON CLASS

class Button {
	public:
		Button(Img img, Rect rect);                                            // construct a button object
		Img* img;
		Rect* rect;
		void render(SDL_Renderer* rend);
		bool hover(int mouse_x, int mouse_y);
		bool clicked(int mouse_x, int mouse_y, std::vector<SDL_Event> events);
};

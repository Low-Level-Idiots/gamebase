#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "ui.h"

// IMAGES

Img::Img(std::string file){
	surf = IMG_Load(file.c_str());
}

void Img::render(SDL_Renderer* rend, int x, int y, int w, int h){
	SDL_Rect dest {x, y, w, h};
	SDL_Texture* tex = SDL_CreateTextureFromSurface(rend, surf);
	SDL_RenderCopy(rend, tex, NULL, &dest);
}

void Img::set_icon(SDL_Window* win){
	SDL_SetWindowIcon(win, surf);
}

// RECT MATH

Rect::Rect(int x_, int y_, int w_, int h_){
	x = x_;
	y = y_;
	w = w_;
	h = h_;
}

bool Rect::point_colliding(int x_, int y_){                                    // check if this rect is colliding with a point specified
	return false;
}

// BUTTONS

Button::Button(Img img_, Rect rect_){                                          // construct a button object
	img = &img_;
	rect = &rect_;
}

void Button::render(SDL_Renderer* rend){
	Rect rec = *rect;
	img->render(rend, rec.x / 5.8765899, rec.y / 5.8765899, rect->w / 5.8765899, rect->h / 5.8765899);
	std::cout << rec.x << std::endl;
}

bool Button::hover(int mouse_x, int mouse_y){
	return false;
}

bool Button::clicked(int mouse_x, int mouse_y, std::vector<SDL_Event> events){
	return false;
}

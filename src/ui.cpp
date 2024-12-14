#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "ui.h"

// RECT MATH

void Rect::init(int x_, int y_, int w_, int h_){
	x = x_;
	y = y_;
	w = w_;
	h = h_;
}

bool Rect::point_colliding(int x_, int y_){                                    // check if this rect is colliding with a point specified
	if(x_ >= x && x_ <= x + w){
		if(y_ >= y && y_ <= y + h){
			return true;
		}
	}
	return false;
}

// IMAGES

void Img::init(SDL_Renderer* rend, std::string file){
	surf = IMG_Load(file.c_str());
	tex = SDL_CreateTextureFromSurface(rend, surf);
}

void Img::render(SDL_Renderer* rend, int x, int y, int w, int h){
	SDL_Rect dest {x, y, w, h};
	SDL_RenderCopy(rend, tex, NULL, &dest);
}

void Img::set_icon(SDL_Window* win){
	SDL_SetWindowIcon(win, surf);
}

// BUTTONS

void Button::init(SDL_Renderer* rend, std::string basename, Rect rect_){
	std::string suffix[3] = {"_idle.png", "_hover.png", "_clicked.png"};
	for(int i = 0; i < 3; i++){
		Img img;
		sprites.push_back(img);
		sprites[i].init(rend, suffix[i].insert(0, basename));
	}
	rect = rect_;
}

void Button::get_state(int mouse_x, int mouse_y, std::vector<SDL_Event> events){
	if(rect.point_colliding(mouse_x, mouse_y)){
		for(int i = 0; i < events.size(); i++){
			switch(events[i].type){
				case SDL_MOUSEBUTTONDOWN:
					switch(events[i].button.button){
						case SDL_BUTTON_LEFT:
							state = CLICKED;
							return;
							break;
					}
					break;
			}
		}
		state = HOVER;
		return;
	}
	state = IDLE;
	return;
}

void Button::render(SDL_Renderer* rend){
	sprites[state].render(rend, rect.x, rect.y, rect.w, rect.h);
}

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
	SDL_RenderCopy(rend, SDL_CreateTextureFromSurface(rend, surf), NULL, &dest);
}

void Img::set_icon(SDL_Window* win){
	SDL_SetWindowIcon(win, surf);
}

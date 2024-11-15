#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "img.h"

Img::Img(SDL_Renderer* rend, std::string file){
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

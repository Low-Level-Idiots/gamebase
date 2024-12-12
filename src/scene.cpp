#include <iostream>
#include <vector>
#include <SDL2/SDL.h>

#include "scene.h"
#include "ui.h"

// SCENE1

void Scene1::init(SDL_Renderer* rend){
	btn.init(rend, "assets/button.png", 1, 1, 300, 100);

}

void Scene1::main(Scene* scene, SDL_Renderer* rend, std::vector<SDL_Event> events, int mouse_x, int mouse_y){
	SDL_SetRenderDrawColor(rend, 100, 100, 255, 255);
	btn.render(rend);
	if(btn.clicked(mouse_x, mouse_y, events)){
		std::cout << "clicked" << std::endl;
	}
}

// SCENE2

void Scene2::init(SDL_Renderer* rend){}

void Scene2::main(Scene* scene, SDL_Renderer* rend, std::vector<SDL_Event> events, int mouse_x, int mouse_y){
	SDL_SetRenderDrawColor(rend, 255, 100, 100, 255);
}

// SCENE DECLARATION

Scene1 scene1;
Scene2 scene2;

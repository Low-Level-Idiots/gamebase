#include <iostream>
#include <vector>
#include <SDL2/SDL.h>

#include "scene.h"
#include "ui.h"

// SCENE1

Scene1::Scene1(){
	Img img("assets/missing.png");
	Rect rect(1, 1, 100, 100);
	btn = new Button(img, rect);
	std::cout << "rect in scene1::scene1(): " << btn->rect->x << std::endl;
}

void Scene1::main(Scene* scene, SDL_Renderer* rend, std::vector<SDL_Event> events, int mouse_x, int mouse_y){
	SDL_SetRenderDrawColor(rend, 100, 100, 255, 255);
	btn->render(rend);
}

// SCENE2

Scene2::Scene2(){}

void Scene2::main(Scene* scene, SDL_Renderer* rend, std::vector<SDL_Event> events, int mouse_x, int mouse_y){
	SDL_SetRenderDrawColor(rend, 255, 100, 100, 255);
}

// SCENE DECLARATION

Scene1 scene1;
Scene2 scene2;

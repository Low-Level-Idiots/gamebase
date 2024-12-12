#pragma once

#include <iostream>
#include <vector>
#include <SDL2/SDL.h>

#include "ui.h"

// SCENE PARENT CLASS

class Scene {
	public:
		virtual void init(SDL_Renderer* rend) = 0;
		virtual void main(Scene* scene, SDL_Renderer* rend, std::vector<SDL_Event>, int mouse_x, int mouse_y) = 0;
};

// SCENE1

class Scene1 : public Scene {
	public:
		Button btn;
		void init(SDL_Renderer* rend);
		void main(Scene* scene, SDL_Renderer* rend, std::vector<SDL_Event>, int mouse_x, int mouse_y);
};

// SCENE2

class Scene2 : public Scene {
	public:
		void init(SDL_Renderer* rend);
		void main(Scene* scene, SDL_Renderer* rend, std::vector<SDL_Event>, int mouse_x, int mouse_y);
};

// SCENE DECLARATION

extern Scene1 scene1;
extern Scene2 scene2;

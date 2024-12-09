#pragma once

#include <iostream>
#include <vector>
#include <SDL2/SDL.h>

#include "ui.h"

// SCENE PARENT CLASS

class Scene {
	public:
		virtual void main(Scene* scene, SDL_Renderer* rend, std::vector<SDL_Event>, int mouse_x, int mouse_y) = 0;
};

// SCENE1

class Scene1 : public Scene {
	public:
		Scene1();
		Button btn;
		void main(Scene* scene, SDL_Renderer* rend, std::vector<SDL_Event>, int mouse_x, int mouse_y);
};

// SCENE2

class Scene2 : public Scene {
	public:
		Scene2();
		void main(Scene* scene, SDL_Renderer* rend, std::vector<SDL_Event>, int mouse_x, int mouse_y);
};

// SCENE DECLARATION

extern Scene1 scene1;
extern Scene2 scene2;

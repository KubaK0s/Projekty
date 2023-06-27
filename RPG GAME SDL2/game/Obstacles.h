#pragma once
#include "GameObject.h"
#include "game.h"


class Obstacles: public GameObject {

public:
	Obstacles(const char* texturesheet, SDL_Renderer* ren, int xpos, int ypos, int h, int w);
	~Obstacles();
	void Update();
	int condition;

private:



};

#pragma once
#include "GameObject.h"
#include "game.h"


class Live : public GameObject {

public:
	Live(const char* texturesheet, SDL_Renderer* ren, int xpos, int ypos, int h, int w);
	~Live();
	void Update();


private:



};
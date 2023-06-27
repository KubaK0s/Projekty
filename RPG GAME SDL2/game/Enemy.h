#pragma once
#include "GameObject.h"
#include "game.h"
#include<vector>

class Enemy:public GameObject {

public:
	Enemy(const char* texturesheet, SDL_Renderer* ren, int xpos, int ypos, int h, int w);
	~Enemy();
	void Update();
	int hp;
	bool isliving;

private:



};

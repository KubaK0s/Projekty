#pragma once
#include "GameObject.h"
#include "game.h"

class Shooting: public GameObject {

public:
	Shooting(const char* texturesheet, SDL_Renderer* ren, int xpos, int ypos, int h, int w);
	Shooting();
	~Shooting();
	void Update();
	int velocity;
	bool Shot;
	bool w, a, s, d;
private:


};

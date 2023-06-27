#pragma once
#include "GameObject.h"
#include "game.h"

class Background {

public:
	Background(const char* texturesheet, SDL_Renderer* ren);
	~Background();
	void Render();
	void Update();
	int xpos;
	int ypos;

	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
	SDL_Renderer* renderer;

private:



};
#pragma once
#include "game.h"

class GameObject {

public:
	GameObject(const char* texturesheet, SDL_Renderer* ren, int xpos, int ypos, int h, int w);
	GameObject();
	~GameObject();
	void Render();
	int xpos;
	int ypos;
	bool Collison(SDL_Rect o, int size, int size2);
	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
	SDL_Renderer* renderer;
	


private:
	
};

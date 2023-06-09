#ifndef Game_h
#define Game_h
#include "SDL.h"
#include <iostream>
#include "SDL_image.h"

class Game {

public:
	Game();
	~Game();

	
	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	void handleEvents();
	void update();
	void render();
	void clean();

	bool running() { return isRunning; }
	bool isfinished = false;

private:
	int cnt = 0;
	bool isRunning = false;
	SDL_Window *window;
	SDL_Renderer *renderer;



};


#endif /* Game_h */


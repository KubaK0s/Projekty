#include "game.h"
import my_module;
#include <iostream>
#include <chrono>
#include <fstream>
#include <regex>
#include <thread>
#include <mutex>

Game* game = nullptr;

int main(int argc, char* argv[])
{
	auto start = std::chrono::steady_clock::now();

	std::chrono::steady_clock::duration elapsed = std::chrono::steady_clock::duration::zero();

	const int FPS = 60;
	const int frameDelay = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;

	game = new Game();

	game->init("MedivalFighter", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1024, 1024, false);

	while (game->running())
	{
		auto now = std::chrono::steady_clock::now();
		elapsed += now - start;



		start = now;
		frameStart = SDL_GetTicks();


		game->handleEvents();
		game->update();
		game->render();

		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}

	}
	if (game->isfinished)
	{


		checkDiskSpace();
		game->clean();
		std::ofstream outputFile("score.txt");
		if (outputFile.is_open()) {
			outputFile << 1000 - std::chrono::duration_cast<std::chrono::seconds>(elapsed).count() << " points\n";
			outputFile.close();
			std::cout << "points saved to file'.\n";
		}
		else {
			std::cerr << "Could not open file 'time.txt' for writing.\n";
		};
	}

	return 0;
}
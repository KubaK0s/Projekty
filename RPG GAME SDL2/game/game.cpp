#include <iostream>
#include "game.h"
#include "TaxtureManager.h"
#include "GameObject.h"
#include "player.h"
#include "Background.h"
#include "Obstacles.h"
#include "Shooting.h"
#include "Enemy.h"
#include "Live.h"
#include<windows.h>  
#include <list>
#include <vector>
#include <chrono>
#include <thread>
#include <map>
#include <mutex>
#include <algorithm>
#include <ranges>
#include <thread>
#include <mutex>
#include <iostream>
#include <fstream>
#include <regex>
/**

* @brief Funkcja odpowiadaj¹ca za sprawdzanie czy dana wartosc miesci sie w przedziale.*
* @param int nukmber sprawdzana liczba.*/
bool isInRange(int number)
{
	std::vector<int> range{ 0, 1, 2, 3 };

	return std::find(range.begin(), range.end(), number) != range.end();
}




Background* background;
Player* player;
Obstacles* cactus1;
std::vector<Obstacles*> rocks;
Obstacles* menu;
Shooting* bullet;
Shooting* ebullet;
Shooting* ebullet2;
Shooting* ebullet3;
Shooting* ebullet4;
Enemy* wraith;
std::vector<Enemy*> wraiths;
Enemy* blob;
std::vector<Enemy*> blobs;
Live* heart1;
Live* heart2;
Live* heart3;
Obstacles* portal;
Obstacles* portal2;
Background* mainmenu;
Enemy* devil;
Background* background2;
std::vector<Enemy*> devils;
Obstacles* cactus2;
std::vector<Obstacles*> rocks2;
Background* background3;
Obstacles* scraps;
std::vector<Obstacles*> scrapss;
Obstacles* cactus3;
std::vector<Obstacles*> rocks3;
Obstacles* smallrock;
std::vector<Obstacles*> smallrocks;
Obstacles* smallpillar;
std::vector<Obstacles*> smallpillars;
Obstacles* wraithdead;
std::vector<Obstacles*> wraithdeads;
Obstacles* devildead;
std::vector<Obstacles*> devildeads;
Obstacles* blobdead;
std::vector<Obstacles*> blobdeads;
Background* endscreen;
int barrels = 0;
int mobCnt = 3;
int stone = 0;
int pillar = 0;
int wraithd = 0;
int blobd = 0;
int devild = 0;
bool level1 = false;
bool level2 = false;
bool level3 = false;
bool ismenu = true;
bool iswin = false;
/**

* @brief Konstruktor klasy Game.*/
Game::Game()
{}
/**

* @brief Destruktor klasy Game.*/
Game::~Game()
{}
/**

* @brief Funkcja odpowiadaj¹ca za ponowne inicjalizowanie sie programu po przegranej.*/
void init2() {

	player->destRect.x = 20;
	player->destRect.y = 100;
	player->hp = 3;
	heart1->destRect.x = 130;
	heart1->destRect.y = 900;
	heart2->destRect.x = 250;
	heart2->destRect.y = 900;
	heart3->destRect.x = 370;
	heart3->destRect.y = 900;
	mobCnt = 3;

	wraiths[0]->destRect.x = 650;
	wraiths[0]->destRect.y = 200;
	wraiths[1]->destRect.x = 650;
	wraiths[1]->destRect.y = 400;
	wraiths[2]->destRect.x = 650;
	wraiths[2]->destRect.y = 600;
	ismenu = true;
	level1 = false;
	level2 = false;
	level3 = false;
	rocks[0]->destRect.x = 170;
	rocks[0]->destRect.y = 200;
	rocks[1]->destRect.x = 340;
	rocks[1]->destRect.y = 400;
	rocks[2]->destRect.x = 510;
	rocks[2]->destRect.y = 600;
	portal->destRect.x = -200;
	portal->destRect.y = -200;
	portal2->destRect.x = -200;
	portal2->destRect.y = -200;
	devils[0]->destRect.x = 60;
	devils[0]->destRect.y = 200;
	devils[1]->destRect.x = 60;
	devils[1]->destRect.y = 400;
	devils[2]->destRect.x = 60;
	devils[2]->destRect.y = 600;
	rocks2[0]->destRect.x = 170;
	rocks2[0]->destRect.y = 200;
	rocks2[1]->destRect.x = 340;
	rocks2[1]->destRect.y = 400;
	rocks2[2]->destRect.x = 510;
	rocks2[2]->destRect.y = 600;
	scrapss[0]->destRect.x = -300;
	scrapss[0]->destRect.y = -300;
	scrapss[1]->destRect.x = -300;
	scrapss[1]->destRect.y = -300;
	scrapss[2]->destRect.x = -300;
	scrapss[2]->destRect.y = -300;
	rocks3[0]->destRect.x = 200;
	rocks3[0]->destRect.y = 200;
	rocks3[1]->destRect.x = 370;
	rocks3[1]->destRect.y = 400;
	blobs[0]->destRect.x = 20;
	blobs[0]->destRect.y = 200;
	blobs[1]->destRect.x = 20;
	blobs[1]->destRect.y = 400;
	blobs[2]->destRect.x = 20;
	blobs[2]->destRect.y = 600;
	barrels = 0;
	stone = 0;
	smallrocks[0]->destRect.x = -300;
	smallrocks[0]->destRect.y = -300;
	smallrocks[1]->destRect.x = -300;
	smallrocks[1]->destRect.y = -300;
	smallrocks[2]->destRect.x = -300;
	smallrocks[2]->destRect.y = -300;
	smallpillars[0]->destRect.x = -300;
	smallpillars[0]->destRect.y = -300;
	smallpillars[1]->destRect.x = -300;
	smallpillars[1]->destRect.y = -300;
	pillar = 0;
	wraithd = 0;
	devild = 0;
	blobd = 0;
	wraithdeads[0]->destRect.x = -300;
	wraithdeads[0]->destRect.y = -300;
	wraithdeads[1]->destRect.x = -300;
	wraithdeads[1]->destRect.y = -300;
	wraithdeads[2]->destRect.x = -300;
	wraithdeads[2]->destRect.y = -300;
	devildeads[0]->destRect.x = -300;
	devildeads[0]->destRect.y = -300;
	devildeads[1]->destRect.x = -300;
	devildeads[1]->destRect.y = -300;
	devildeads[2]->destRect.x = -300;
	devildeads[2]->destRect.y = -300;
	blobdeads[0]->destRect.x = -300;
	blobdeads[0]->destRect.y = -300;
	blobdeads[1]->destRect.x = -300;
	blobdeads[1]->destRect.y = -300;
	blobdeads[2]->destRect.x = -300;
	blobdeads[2]->destRect.y = -300;

}
void init3() {

	mobCnt = 3;

}
/**

* @brief Funkcja odpowiadaj¹ca za inicjalizacje programu.*
* @param const char* title Nazwa programu.
* @param int xpos pozycja w osi x okna programu.
* @param int ypos pozycja w osi y okna programu.
* @param int width dlugosc okna programu.
* @param int height wysokosc okna programu.
* @param bool fullscreen odpowiada za to czy chcemy wlaczyc program w trybie pelnoekranowym.*/
void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Subsystem Initialised!" << std::endl;

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window)
		{
			std::cout << "Window Created!" << std::endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer Created!" << std::endl;
		}
		isRunning = true;
	}
	mainmenu = new Background("assets/test.png", renderer);

	background = new Background("assets/background.png", renderer);
	player = new Player("assets/player.png", renderer, 20, 50, 64, 64);
	for (int i = 1; i < 4; i++)
	{
		cactus1 = new Obstacles("assets/CactusType1.png", renderer, 170*i, 200*i, 64, 64);
		rocks.push_back(cactus1);
	}
	bullet = new Shooting("assets/Bullet.png", renderer, -200, -200, 32, 32);
	ebullet = new Shooting("assets/Chaos.png", renderer, -200, -200, 32, 32);
	ebullet2 = new Shooting("assets/Chaos.png", renderer, -200, -200, 32, 32);
	ebullet3 = new Shooting("assets/Chaos.png", renderer, -200, -200, 32, 32);
	ebullet4 = new Shooting("assets/Chaos.png", renderer, -200, -200, 32, 32);
		for (int i = 1; i < 4; i++)
		{
			wraith = new Enemy("assets/Wraith.png", renderer, 650, 200*i, 64, 64);
			wraiths.push_back(wraith);
			wraith = new Enemy("assets/Wraith.png", renderer, 850, 300, 64, 64);
			
			
		}

	for (int i = 1; i < 4; i++)
	{
		scraps = new Obstacles("assets/scraps.png", renderer, -300, -300, 64, 64);
		scrapss.push_back(scraps);
	}
	heart1 = new Live("assets/heart.png", renderer, 130, 900, 64, 64);
	heart2 = new Live("assets/heart.png", renderer, 250, 900, 64, 64);
	heart3 = new Live("assets/heart.png", renderer, 370, 900, 64, 64);
	portal = new Obstacles("assets/Portal.png", renderer, -200, -200, 128, 128);
	portal2 = new Obstacles("assets/Portal2.png", renderer, -200, -200, 128, 128);
	menu = new Obstacles("assets/InterFace.png", renderer, 0, 896, 64, 512);
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	background2 = new Background("assets/background2.png", renderer);
	for (int i = 0; i < 3; i++)
	{
		devil = new Enemy("assets/devil.png", renderer, 60, 200 * (i + 1), 64, 64);
		devils.push_back(devil);
	}
	for (int i = 1; i < 4; i++)
	{
		cactus2 = new Obstacles("assets/CactusType2.png", renderer, 170 * i, 200 * i, 64, 64);
		rocks2.push_back(cactus2);
	}
	background3 = new Background("assets/background4.png", renderer);
	for (int i = 0; i < 3; i++)
	{
		blob = new Enemy("assets/Blob.png", renderer, 20, 200 * (i + 1), 64, 64);
		blobs.push_back(blob);
	}
	for (int i = 1; i < 3; i++)
	{
		cactus3 = new Obstacles("assets/CactusType3.png", renderer, 200 * i, 200 * i, 64, 64);
		rocks3.push_back(cactus3);
	}
	for (int i = 1; i < 4; i++)
	{
		smallrock = new Obstacles("assets/smallrock.png", renderer, -300, -300, 64, 64);
		smallrocks.push_back(smallrock);
	}
	for (int i = 1; i < 3; i++)
	{
		smallpillar = new Obstacles("assets/fillarparts.png", renderer, -300, -300, 64, 64);
		smallpillars.push_back(smallpillar);
	}
	for (int i = 1; i < 4; i++)
	{
		wraithdead = new Obstacles("assets/wraithdead.png", renderer, -300, -300, 64, 64);
		wraithdeads.push_back(wraithdead);
	}
	for (int i = 1; i < 4; i++)
	{
		devildead = new Obstacles("assets/devildead.png", renderer, -300, -300, 64, 64);
		devildeads.push_back(devildead);
	}
	for (int i = 1; i < 4; i++)
	{
		blobdead = new Obstacles("assets/blobdead.png", renderer, -300, -300, 64, 64);
		blobdeads.push_back(blobdead);
	}
	endscreen = new Background("assets/endscreen.png", renderer);
	//player_tex = TextureManager::LoadTexture("assets/player.png", renderer);
	
	
}
/**

* @brief Metoda odpowiadaj¹ca za inicjalizacje sie wszystkich eventow.*/
void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
	case SDL_QUIT:
		isRunning = false;
		break;
	case SDL_KEYDOWN:
		switch (event.key.keysym.sym)
		{
		case SDLK_d:
			player->MoveR = true;
			if (bullet->Shot == false)
			{
				bullet->d = true;
				bullet->a = false;
				bullet->w = false;
				bullet->s = false;
			}
			break;
		case SDLK_w:
			player->MoveU = true;
			if (bullet->Shot == false)
			{
				bullet->d = false;
				bullet->a = false;
				bullet->w = true;
				bullet->s = false;
			}
			break;
		case SDLK_a:
			player->MoveL = true;
			if (bullet->Shot == false)
			{
				bullet->d = false;
				bullet->a = true;
				bullet->w = false;
				bullet->s = false;
			}
			break;
		case SDLK_s:
			player->MoveD = true;
			if (bullet->Shot == false)
			{
				bullet->d = false;
				bullet->a = false;
				bullet->w = false;
				bullet->s = true;
			}
			break;
		case SDLK_SPACE:
			if (bullet->Shot == false)
			{
				bullet->Shot = true;

				bullet->destRect.x = player->destRect.x + 72;
				bullet->destRect.y = player->destRect.y + 5;
			}
			break;
		case SDLK_ESCAPE:
			isRunning = false;
			break;
		}
		break;

	case SDL_KEYUP:
		switch (event.key.keysym.sym)
		{
		case SDLK_d:

			player->MoveR = false;

			break;
		case SDLK_w:
			player->MoveU = false;
			break;
		case SDLK_a:
			player->MoveL = false;
			break;
		case SDLK_s:
			player->MoveD = false;
			break;
		case SDLK_p:
			if (ismenu) {
				ismenu = false;
				level1 = true;


			}
			break;

		}
		break;

	default:
		break;
	}
	//LEVEL1////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	if (ebullet->destRect.x > 1024 || ebullet->destRect.x < 0 || ebullet->destRect.y > 900 || ebullet->destRect.y < 0)
	{
		ebullet->Shot = false;
		ebullet->destRect.x = -200;
		ebullet->destRect.y = -200;

	}
	if (ebullet2->destRect.x > 1024 || ebullet2->destRect.x < 0 || ebullet2->destRect.y > 900 || ebullet2->destRect.y < 0)
	{
		ebullet2->Shot = false;
		ebullet2->destRect.x = -200;
		ebullet2->destRect.y = -200;

	}
	if (ebullet3->destRect.x > 1024 || ebullet3->destRect.x < 0 || ebullet3->destRect.y > 900 || ebullet3->destRect.y < 0)
	{
		ebullet3->Shot = false;
		ebullet3->destRect.x = -200;
		ebullet3->destRect.y = -200;

	}
	if (ebullet4->destRect.x > 1024 || ebullet4->destRect.x < 0 || ebullet4->destRect.y > 900 || ebullet4->destRect.y < 0)
	{
		ebullet4->Shot = false;
		ebullet4->destRect.x = -200;
		ebullet4->destRect.y = -200;

	}
	if (ebullet->Collison(player->destRect, 110, 30))
	{
		ebullet->Shot = false;
		ebullet->destRect.x = -200;
		ebullet->destRect.y = -200;
		player->hp--;
		if (isInRange(player->hp))
		{
			std::cout << "normal life points" << std::endl;
		}
		else
		{
			std::cout << "error" << std::endl;
		}

	}
	if (ebullet2->Collison(player->destRect, 110, 30))
	{
		ebullet2->Shot = false;
		ebullet2->destRect.x = -200;
		ebullet2->destRect.y = -200;
		player->hp--;
		if (isInRange(player->hp))
		{
			std::cout << "normal life points" << std::endl;
		}
		else
		{
			std::cout << "error" << std::endl;
		}
	}
	if (ebullet3->Collison(player->destRect, 110, 30))
	{
		ebullet3->Shot = false;
		ebullet3->destRect.x = -200;
		ebullet3->destRect.y = -200;
		player->hp--;
		if (isInRange(player->hp))
		{
			std::cout << "normal life points" << std::endl;
		}
		else
		{
			std::cout << "error" << std::endl;
		}
	}
	if (ebullet4->Collison(player->destRect, 110, 30))
	{
		ebullet4->Shot = false;
		ebullet4->destRect.x = -200;
		ebullet4->destRect.y = -200;
		player->hp--;
		if (isInRange(player->hp))
		{
			std::cout << "normal life points" << std::endl;
		}
		else
		{
			std::cout << "error" << std::endl;
		}

	}


	if (bullet->destRect.x > 1024 || bullet->destRect.x < 0 || bullet->destRect.y > 900 || bullet->destRect.y < 0)
	{
		bullet->Shot = false;
		bullet->destRect.x = -200;
		bullet->destRect.y = -200;

	}

	if (player->destRect.x < 0)
	{
		player->MoveL = false;
	}
	if (player->destRect.x > 900)
	{
		player->MoveR = false;
	}
	if (player->destRect.y < 0)
	{
		player->MoveU = false;
	}
	if (player->destRect.y > 750)
	{
		player->MoveD = false;
	}
	if (player->hp == 2)
	{
		heart3->destRect.x = -300;
		heart3->destRect.x = -300;
	}
	if (player->hp == 1)
	{
		heart2->destRect.x = -300;
		heart2->destRect.x = -300;
	}
	if (player->hp == 0)
	{
		level1 = false;
		ismenu = true;
		init2();
	}


	for (auto j : rocks)
	{
		player->CollisionR(j->destRect, 110);
		player->CollisionL(j->destRect, 110);
		player->CollisionD(j->destRect, 110);
		player->CollisionU(j->destRect, 110);

		if (bullet->Collison(j->destRect, 110, 30))
		{

			bullet->Shot = false;
			bullet->destRect.x = -200;
			bullet->destRect.y = -200;
			smallrocks[stone]->destRect.x = j->destRect.x;
			smallrocks[stone]->destRect.y = j->destRect.y;
			stone++;
			j->destRect.x = 1200;
			j->destRect.y = 1200;
			j->xpos = j->destRect.x;
			j->ypos = j->destRect.y;
		}
	}



	//WRAITHS////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	for (auto i : wraiths)
	{
		if (player->CollisionSR(i->destRect, 510) && ebullet->Shot == false)
		{

			ebullet->destRect.x = i->destRect.x + 20;
			ebullet->destRect.y = i->destRect.y + 50;
			ebullet->Shot = true;
			ebullet->d = true;


		}


		if (player->CollisionSL(i->destRect, 510) && ebullet2->Shot == false)
		{

			ebullet2->destRect.x = i->destRect.x + 20;
			ebullet2->destRect.y = i->destRect.y + 50;
			ebullet2->Shot = true;
			ebullet2->a = true;

		}
		if (player->CollisionSD(i->destRect, 510) && ebullet3->Shot == false)
		{

			ebullet3->destRect.x = i->destRect.x + 20;
			ebullet3->destRect.y = i->destRect.y + 50;
			ebullet3->Shot = true;
			ebullet3->s = true;

		}
		if (player->CollisionSU(i->destRect, 510) && ebullet4->Shot == false)
		{

			ebullet4->destRect.x = i->destRect.x + 20;
			ebullet4->destRect.y = i->destRect.y + 50;
			ebullet4->Shot = true;
			ebullet4->w = true;

		}
		if (bullet->Collison(i->destRect, 110, 30))
		{
			bullet->Shot = false;
			wraithdeads[wraithd]->destRect.x = i->destRect.x;
			wraithdeads[wraithd]->destRect.y = i->destRect.y;
			wraithd++;
			i->destRect.x = 1200;
			i->destRect.y = 1200;
			i->xpos = i->destRect.x;
			i->ypos = i->destRect.y;
			bullet->destRect.x = -800;
			bullet->destRect.y = -800;
			mobCnt--;
			std::cout << mobCnt;

		}

	}

	if (mobCnt == 0)
	{
		portal->destRect.x = 636;
		portal->destRect.y = -52;
		

	}

	if (player->Collison(portal->destRect, 110, 30))
	{
		mobCnt = 3;
		level1 = false;
		level2 = true;
		portal->destRect.x = -200;
		portal->destRect.y = -200;
		
	}

	//LEVEL2////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


	if (level2)
	{
		if (player->destRect.y < 100)
		{
			player->MoveU = false;
		}
		for (auto j : rocks2)
		{
			player->CollisionR(j->destRect, 110);
			player->CollisionL(j->destRect, 110);
			player->CollisionD(j->destRect, 110);
			player->CollisionU(j->destRect, 110);

			if (bullet->Collison(j->destRect, 110, 30))
			{

				bullet->Shot = false;
				bullet->destRect.x = -200;
				bullet->destRect.y = -200;
				scrapss[barrels]->destRect.x = j->destRect.x;
				scrapss[barrels]->destRect.y = j->destRect.y;
				barrels++;
				j->destRect.x = 1200;
				j->destRect.y = 1200;
				j->xpos = j->destRect.x;
				j->ypos = j->destRect.y;
			}
		}

		for (auto o : devils)
		{
			if (player->CollisionSR(o->destRect, 810) && ebullet->Shot == false)
			{

				ebullet->destRect.x = o->destRect.x + 20;
				ebullet->destRect.y = o->destRect.y + 50;
				ebullet->Shot = true;
				ebullet->d = true;


			}


			if (player->CollisionSL(o->destRect, 810) && ebullet2->Shot == false)
			{

				ebullet2->destRect.x = o->destRect.x + 20;
				ebullet2->destRect.y = o->destRect.y + 50;
				ebullet2->Shot = true;
				ebullet2->a = true;

			}
			if (player->CollisionSD(o->destRect, 810) && ebullet3->Shot == false)
			{

				ebullet3->destRect.x = o->destRect.x + 20;
				ebullet3->destRect.y = o->destRect.y + 50;
				ebullet3->Shot = true;
				ebullet3->s = true;

			}
			if (player->CollisionSU(o->destRect, 810) && ebullet4->Shot == false)
			{

				ebullet4->destRect.x = o->destRect.x + 20;
				ebullet4->destRect.y = o->destRect.y + 50;
				ebullet4->Shot = true;
				ebullet4->w = true;

			}
			if (bullet->Collison(o->destRect, 110, 30))
			{
				bullet->Shot = false;
				devildeads[devild]->destRect.x = o->destRect.x;
				devildeads[devild]->destRect.y = o->destRect.y;
				devild++;
				o->destRect.x = 1200;
				o->destRect.y = 1200;
				o->xpos = o->destRect.x;
				o->ypos = o->destRect.y;
				bullet->destRect.x = -800;
				bullet->destRect.y = -800;
				mobCnt--;
				std::cout << mobCnt;

			}

		}
		if (ebullet->destRect.x > 1024 || ebullet->destRect.x < 0 || ebullet->destRect.y > 900 || ebullet->destRect.y < 0)
		{
			ebullet->Shot = false;
			ebullet->destRect.x = -200;
			ebullet->destRect.y = -200;

		}
		if (ebullet2->destRect.x > 1024 || ebullet2->destRect.x < 0 || ebullet2->destRect.y > 900 || ebullet2->destRect.y < 0)
		{
			ebullet2->Shot = false;
			ebullet2->destRect.x = -200;
			ebullet2->destRect.y = -200;

		}
		if (ebullet3->destRect.x > 1024 || ebullet3->destRect.x < 0 || ebullet3->destRect.y > 900 || ebullet3->destRect.y < 0)
		{
			ebullet3->Shot = false;
			ebullet3->destRect.x = -200;
			ebullet3->destRect.y = -200;

		}
		if (ebullet4->destRect.x > 1024 || ebullet4->destRect.x < 0 || ebullet4->destRect.y > 900 || ebullet4->destRect.y < 0)
		{
			ebullet4->Shot = false;
			ebullet4->destRect.x = -200;
			ebullet4->destRect.y = -200;

		}
		if (ebullet->Collison(player->destRect, 110, 30))
		{
			ebullet->Shot = false;
			ebullet->destRect.x = -200;
			ebullet->destRect.y = -200;
			player->hp--;
			if (isInRange(player->hp))
			{
				std::cout << "normal life points" << std::endl;
			}
			else
			{
				std::cout << "error" << std::endl;
			}
		}
		if (ebullet2->Collison(player->destRect, 110, 30))
		{
			ebullet2->Shot = false;
			ebullet2->destRect.x = -200;
			ebullet2->destRect.y = -200;
			player->hp--;
			if (isInRange(player->hp))
			{
				std::cout << "normal life points" << std::endl;
			}
			else
			{
				std::cout << "error" << std::endl;
			}
		}
		if (ebullet3->Collison(player->destRect, 110, 30))
		{
			ebullet3->Shot = false;
			ebullet3->destRect.x = -200;
			ebullet3->destRect.y = -200;
			player->hp--;
			if (isInRange(player->hp))
			{
				std::cout << "normal life points" << std::endl;
			}
			else
			{
				std::cout << "error" << std::endl;
			}
		}
		if (ebullet4->Collison(player->destRect, 110, 30))
		{
			ebullet4->Shot = false;
			ebullet4->destRect.x = -200;
			ebullet4->destRect.y = -200;
			player->hp--;
			if (isInRange(player->hp))
			{
				std::cout << "normal life points" << std::endl;
			}
			else
			{
				std::cout << "error" << std::endl;
			}
		}


		if (bullet->destRect.x > 1024 || bullet->destRect.x < 0 || bullet->destRect.y > 900 || bullet->destRect.y < 0)
		{
			bullet->Shot = false;
			bullet->destRect.x = -200;
			bullet->destRect.y = -200;

		}

		if (player->destRect.x < 0)
		{
			player->MoveL = false;
		}
		if (player->destRect.x > 900)
		{
			player->MoveR = false;
		}
		if (player->destRect.y < 0)
		{
			player->MoveU = false;
		}
		if (player->destRect.y > 750)
		{
			player->MoveD = false;
		}
		if (player->hp == 2)
		{
			heart3->destRect.x = -300;
			heart3->destRect.x = -300;
		}
		if (player->hp == 1)
		{
			heart2->destRect.x = -300;
			heart2->destRect.x = -300;
		}
		if (player->hp == 0)
		{
			level1 = false;
			level2 = false;
			ismenu = true;
			init2();
		}
		if (mobCnt == 0)
		{
			portal2->destRect.x = 636;
			portal2->destRect.y = 622;

		}
		if (player->Collison(portal2->destRect, 110, 30))
		{
			mobCnt = 3;
			level2 = false;
			level3 = true;
			portal2->destRect.x = -200;
			portal2->destRect.y = -200;
		}



	}
	//LEVEL3////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


	if (level3)
	{
		if (player->destRect.y < 100)
		{
			player->MoveU = false;
		}

		for (auto j : rocks3)
		{
			player->CollisionR(j->destRect, 110);
			player->CollisionL(j->destRect, 110);
			player->CollisionD(j->destRect, 110);
			player->CollisionU(j->destRect, 110);

			if (bullet->Collison(j->destRect, 110, 30))
			{

				bullet->Shot = false;
				bullet->destRect.x = -200;
				bullet->destRect.y = -200;
				smallpillars[pillar]->destRect.x = j->destRect.x;
				smallpillars[pillar]->destRect.y = j->destRect.y;
				pillar++;
				j->destRect.x = 1200;
				j->destRect.y = 1200;
				j->xpos = j->destRect.x;
				j->ypos = j->destRect.y;
			}
		}

		for (auto o : blobs)
		{
			if (player->CollisionSR(o->destRect, 810) && ebullet->Shot == false)
			{

				ebullet->destRect.x = o->destRect.x + 20;
				ebullet->destRect.y = o->destRect.y + 50;
				ebullet->Shot = true;
				ebullet->d = true;

			}


			if (player->CollisionSL(o->destRect, 810) && ebullet2->Shot == false)
			{

				ebullet2->destRect.x = o->destRect.x + 20;
				ebullet2->destRect.y = o->destRect.y + 50;
				ebullet2->Shot = true;
				ebullet2->a = true;

			}
			if (player->CollisionSD(o->destRect, 810) && ebullet3->Shot == false)
			{

				ebullet3->destRect.x = o->destRect.x + 20;
				ebullet3->destRect.y = o->destRect.y + 50;
				ebullet3->Shot = true;
				ebullet3->s = true;

			}
			if (player->CollisionSU(o->destRect, 810) && ebullet4->Shot == false)
			{

				ebullet4->destRect.x = o->destRect.x + 20;
				ebullet4->destRect.y = o->destRect.y + 50;
				ebullet4->Shot = true;
				ebullet4->w = true;

			}
			if (bullet->Collison(o->destRect, 110, 30))
			{
				bullet->Shot = false;
				blobdeads[blobd]->destRect.x = o->destRect.x;
				blobdeads[blobd]->destRect.y = o->destRect.y;
				blobd++;
				o->destRect.x = 1200;
				o->destRect.y = 1200;
				o->xpos = o->destRect.x;
				o->ypos = o->destRect.y;
				bullet->destRect.x = -800;
				bullet->destRect.y = -800;
				mobCnt--;
				std::cout << mobCnt;

			}

		}
		if (ebullet->destRect.x > 1024 || ebullet->destRect.x < 0 || ebullet->destRect.y > 900 || ebullet->destRect.y < 0)
		{
			ebullet->Shot = false;
			ebullet->destRect.x = -200;
			ebullet->destRect.y = -200;

		}
		if (ebullet2->destRect.x > 1024 || ebullet2->destRect.x < 0 || ebullet2->destRect.y > 900 || ebullet2->destRect.y < 0)
		{
			ebullet2->Shot = false;
			ebullet2->destRect.x = -200;
			ebullet2->destRect.y = -200;

		}
		if (ebullet3->destRect.x > 1024 || ebullet3->destRect.x < 0 || ebullet3->destRect.y > 900 || ebullet3->destRect.y < 0)
		{
			ebullet3->Shot = false;
			ebullet3->destRect.x = -200;
			ebullet3->destRect.y = -200;

		}
		if (ebullet4->destRect.x > 1024 || ebullet4->destRect.x < 0 || ebullet4->destRect.y > 900 || ebullet4->destRect.y < 0)
		{
			ebullet4->Shot = false;
			ebullet4->destRect.x = -200;
			ebullet4->destRect.y = -200;

		}
		if (ebullet->Collison(player->destRect, 110, 30))
		{
			ebullet->Shot = false;
			ebullet->destRect.x = -200;
			ebullet->destRect.y = -200;
			player->hp--;
			if (isInRange(player->hp))
			{
				std::cout << "normal life points" << std::endl;
			}
			else
			{
				std::cout << "error" << std::endl;
			}
		}
		if (ebullet2->Collison(player->destRect, 110, 30))
		{
			ebullet2->Shot = false;
			ebullet2->destRect.x = -200;
			ebullet2->destRect.y = -200;
			player->hp--;
			if (isInRange(player->hp))
			{
				std::cout << "normal life points" << std::endl;
			}
			else
			{
				std::cout << "error" << std::endl;
			}
		}
		if (ebullet3->Collison(player->destRect, 110, 30))
		{
			ebullet3->Shot = false;
			ebullet3->destRect.x = -200;
			ebullet3->destRect.y = -200;
			player->hp--;
			if (isInRange(player->hp))
			{
				std::cout << "normal life points" << std::endl;
			}
			else
			{
				std::cout << "error" << std::endl;
			}

		}
		if (ebullet4->Collison(player->destRect, 110, 30))
		{
			ebullet4->Shot = false;
			ebullet4->destRect.x = -200;
			ebullet4->destRect.y = -200;
			player->hp--;
			if (isInRange(player->hp))
			{
				std::cout << "normal life points" << std::endl;
			}
			else
			{
				std::cout << "error" << std::endl;
			}
		}


		if (bullet->destRect.x > 1024 || bullet->destRect.x < 0 || bullet->destRect.y > 900 || bullet->destRect.y < 0)
		{
			bullet->Shot = false;
			bullet->destRect.x = -200;
			bullet->destRect.y = -200;

		}

		if (player->destRect.x < 0)
		{
			player->MoveL = false;
		}
		if (player->destRect.x > 900)
		{
			player->MoveR = false;
		}
		if (player->destRect.y < 0)
		{
			player->MoveU = false;
		}
		if (player->destRect.y > 750)
		{
			player->MoveD = false;
		}
		if (player->hp == 2)
		{
			heart3->destRect.x = -300;
			heart3->destRect.x = -300;
		}
		if (player->hp == 1)
		{
			heart2->destRect.x = -300;
			heart2->destRect.x = -300;
		}
		if (player->hp == 0)
		{
			level1 = false;
			level2 = false;
			level3 = false;
			ismenu = true;
			init2();
		}
		if (mobCnt == 0)
		{
			portal2->destRect.x = 636;
			portal2->destRect.y = 622;

		}
		if (player->Collison(portal2->destRect, 110, 30))
		{
			mobCnt = 3;
			level3 = false;
			iswin = true;
			portal2->destRect.x = -200;
			portal2->destRect.y = -200;
			isfinished = true;
		}



	}

	



}





/**

* @brief Metoda odpowiadaj¹ca za upgrade wszystkich obiektow.*/
void Game::update()
{
	mainmenu->Update();
	if (level1)
	{
		background->Update();
		for (auto i : smallrocks)
		{
			i->Update();
		}
		for (auto i : wraithdeads)
		{
			i->Update();
		}
		player->Update();
		for (auto i : rocks)
		{
			i->Update();
		}
		ebullet->Update();
		ebullet2->Update();
		ebullet3->Update();
		ebullet4->Update();
		for (auto i : wraiths)
		{
			i->Update();
		}
		bullet->Update();
		menu->Update();
		heart1->Update();
		heart2->Update();
		heart3->Update();
		portal->Update();
		
	}

	if (level2)
	{
		background2->Update();
		for (auto i : scrapss)
		{
			i->Update();
		}
		for (auto i : devildeads)
		{
			i->Update();
		}
		player->Update();
		for (auto i : rocks2)
		{
			i->Update();
		}
		ebullet->Update();
		ebullet2->Update();
		ebullet3->Update();
		ebullet4->Update();
		for (auto i : devils)
		{
			i->Update();
		}
		bullet->Update();
		menu->Update();
		heart1->Update();
		heart2->Update();
		heart3->Update();
		portal2->Update();
	}

	if (level3)
	{
		background3->Update();
		for (auto i : smallpillars)
		{
			i->Update();
		}
		for (auto i : blobdeads)
		{
			i->Update();
		}
		player->Update();
		for (auto i : rocks3)
		{
			i->Update();
		}
		ebullet->Update();
		ebullet2->Update();
		ebullet3->Update();
		ebullet4->Update();
		for (auto i : blobs)
		{
			i->Update();
		}
		bullet->Update();
		menu->Update();
		heart1->Update();
		heart2->Update();
		heart3->Update();
		portal2->Update();
	}
	if (iswin)
	{
		endscreen->Update();
	}
	
}


/**

* @brief Metoda odpowiadaj¹ca za renderowanie sie wszystkich obiektow.*/
void Game::render()
{

	SDL_RenderClear(renderer);
	if (ismenu) {
		mainmenu->Render();
	}
	if (level1)
	{

		
		background->Render();
		portal->Render();
		for (auto i : smallrocks)
		{
			i->Render();
		}
		for (auto i : wraithdeads)
		{
			i->Render();
		}
		player->Render();
		for (auto i : rocks)
		{
			i->Render();
		}
		ebullet->Render();
		ebullet2->Render();
		ebullet3->Render();
		ebullet4->Render();
		for (auto i : wraiths)
		{
			i->Render();
		}
		bullet->Render();
		menu->Render();
		heart1->Render();
		heart2->Render();
		heart3->Render();
		
		
		
	}

	if (level2)
	{
		background2->Render();
		for (auto i : scrapss)
		{
			i->Render();
		}
		for (auto i : devildeads)
		{
			i->Render();
		}
		portal2->Render();
		player->Render();
		for (auto i : rocks2)
		{
			i->Render();
		}
		ebullet->Render();
		ebullet2->Render();
		ebullet3->Render();
		ebullet4->Render();
		for (auto i : devils)
		{
			i->Render();
		}
		bullet->Render();
		menu->Render();
		if (player->hp ==3)
		{
			heart1->Render();
			heart2->Render();
			heart3->Render();
		}
		if (player->hp == 2)
		{
			heart1->Render();
			heart2->Render();
	
		}
		if (player->hp == 1)
		{
			heart1->Render();
			
		}
		
	}
	if (level3)
	{
		background3->Render();
		for (auto i : smallpillars)
		{
			i->Render();
		}
		for (auto i : blobdeads)
		{
			i->Render();
		}
		portal2->Render();
		player->Render();
		for (auto i : rocks3)
		{
			i->Render();
		}
		ebullet->Render();
		ebullet2->Render();
		ebullet3->Render();
		ebullet4->Render();
		for (auto i : blobs)
		{
			i->Render();
		}
		bullet->Render();
		menu->Render();
		if (player->hp == 3)
		{
			heart1->Render();
			heart2->Render();
			heart3->Render();
		}
		if (player->hp == 2)
		{
			heart1->Render();
			heart2->Render();

		}
		if (player->hp == 1)
		{
			heart1->Render();

		}
		
	}
	if (iswin)
	{
		endscreen->Render();
	}
	
	SDL_RenderPresent(renderer);
}

/**

* @brief Metoda odpowiadaj¹ca za czyszczenie okna programu bo zamknieciu.*/
void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game cleaned!" << std::endl;
}
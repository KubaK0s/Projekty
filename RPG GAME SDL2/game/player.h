#pragma once
#include "GameObject.h"
#include "game.h"

class Player:public GameObject{

public:
	Player(const char* texturesheet, SDL_Renderer* ren, int xpos, int ypos, int h, int w);
	Player();
	~Player();
	void Update();
	bool CollisionR(SDL_Rect Odestrect, int s1);
	bool CollisionL(SDL_Rect Odestrect, int s1);
	bool CollisionU(SDL_Rect Odestrect, int s1);
	bool CollisionD(SDL_Rect Odestrect, int s1);
	bool CollisionSR(SDL_Rect Odestrect, int s1);
	bool CollisionSL(SDL_Rect Odestrect, int s1);
	bool CollisionSU(SDL_Rect Odestrect, int s1);
	bool CollisionSD(SDL_Rect Odestrect, int s1);
	bool BulletR(SDL_Rect Odestrect, int s1, SDL_Rect s2);
	bool BulletL(SDL_Rect Odestrect, int s1);
	bool BulletW(SDL_Rect Odestrect, int s1);
	bool Bullet(SDL_Rect Odestrect, int s1);
	int velocity;
	bool MoveR;
	bool MoveL;
	bool MoveD;
	bool MoveU;
	int hp;
private:



};

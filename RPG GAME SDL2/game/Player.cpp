#include "Player.h"
#include "TaxtureManager.h"
#include "Obstacles.h"

/**

* @brief Klasa odpowiadaj¹ca za renderowanie sie gracza.
* @param const char texturesheet obraz tekstury pobrany z pliku.
* @param SDL_Renderer ren renderowanie obiektu.
* @param int x pozycja w osi x.
* @param int y pozycja w osi y.
* @param int h wysokosc obiektu
* @param int w szerokosc obiketu.
* @param .*/
Player::Player(const char* texturesheet, SDL_Renderer* ren, int x, int y, int h, int w):
GameObject::GameObject(texturesheet, ren, x, y, h, w)
{
	velocity = 6;
	hp = 3;
}
/**

* @brief Metoda odpowiadaj¹ca za update obiektu.*/
void Player::Update() {

	if (MoveR == true)
	{
		destRect.x += velocity;

	}
	if (MoveL == true)
	{
		destRect.x -= velocity;
	}
	if (MoveD == true)
	{
		destRect.y += velocity;
	}
	if (MoveU == true)
	{
		destRect.y -= velocity;
	}
	
	
}
/**

* @brief Metoda odpowiadajaca za kolizje postaci z obiektami z prawej strony.*
* @param SDL_Rect Odestrect obiekt z ktorym bohater wchodzi w kolizje.
* @param int s1 dodatkowy parametr pomagajacy w idelanym dobraniu odleglosci.*/
	bool Player::CollisionR(SDL_Rect Odestrect, int s1) {
		if (destRect.x + s1 > Odestrect.x && destRect.x < Odestrect.x + s1 - 10 && destRect.y + s1 + 10 > Odestrect.y && destRect.y < Odestrect.y + s1)
		{
			MoveR = false;
			return  true;
		}
		return false;
	}
	/**

	* @brief Metoda odpowiadajaca za kolizje postaci z obiektami z lewej strony.*
	* @param SDL_Rect Odestrect obiekt z ktorym bohater wchodzi w kolizje.
	* @param int s1 dodatkowy parametr pomagajacy w idelanym dobraniu odleglosci.*/
	bool Player::CollisionL(SDL_Rect Odestrect, int s1) {
		if (destRect.x + s1 - 10 > Odestrect.x && destRect.x < Odestrect.x + s1 && destRect.y + s1 + 10 > Odestrect.y && destRect.y < Odestrect.y + s1)
		{
			MoveL = false;
			return  true;
		}
		return false;

	}
	/**

* @brief Metoda odpowiadajaca za kolizje postaci z obiektami od gory.*
* @param SDL_Rect Odestrect obiekt z ktorym bohater wchodzi w kolizje.
* @param int s1 dodatkowy parametr pomagajacy w idelanym dobraniu odleglosci.*/
	bool Player::CollisionU(SDL_Rect Odestrect, int s1) {
		if (destRect.x + s1 + 5 > Odestrect.x && destRect.x < Odestrect.x + s1 - 10 && destRect.y  > Odestrect.y + s1  && destRect.y < Odestrect.y + s1+20)
		{
			MoveU = false;
			return  true;
		}
		return false;

	}
	/**

* @brief Metoda odpowiadajaca za kolizje postaci z obiektami od dolu.*
* @param SDL_Rect Odestrect obiekt z ktorym bohater wchodzi w kolizje.
* @param int s1 dodatkowy parametr pomagajacy w idelanym dobraniu odleglosci.*/
	bool Player::CollisionD(SDL_Rect Odestrect, int s1) {
		if (destRect.x + s1 -10 > Odestrect.x && destRect.x < Odestrect.x + s1 - 10 && destRect.y + s1 > Odestrect.y - 20 && destRect.y < Odestrect.y + s1)
		{
			MoveD = false;
			return  true;
		}
		return false;

	}
	/**

* @brief Metoda odpowiadajaca za kolizje postaci z pociskami wrogow z prawej strony.*
* @param SDL_Rect Odestrect obiekt z ktorym dochodzi do kolizji, w tym przypadku pocisk.
* @param int s1 dodatkowy parametr pomagajacy w idelanym dobraniu odleglosci.*/

	bool Player::CollisionSR(SDL_Rect Odestrect, int s1) {
		if (destRect.x  > Odestrect.x + Odestrect.w - 50 && destRect.x < Odestrect.x + s1  && destRect.y + Odestrect.h - 20 > Odestrect.y && destRect.y < Odestrect.y + Odestrect.h)
		{

			return  true;
		}
		return false;
	}
	/**

* @brief Metoda odpowiadajaca za kolizje postaci z pociskami wrogow z lewej strony.*
* @param SDL_Rect Odestrect obiekt z ktorym dochodzi do kolizji, w tym przypadku pocisk.
* @param int s1 dodatkowy parametr pomagajacy w idelanym dobraniu odleglosci.*/

	bool Player::CollisionSL(SDL_Rect Odestrect, int s1) {
		if (destRect.x  < Odestrect.x - Odestrect.w + 50 && destRect.x - s1 < Odestrect.x  && destRect.y + Odestrect.h - 20 > Odestrect.y && destRect.y < Odestrect.y + Odestrect.h)
		{
			return  true;
		}
		return false;


	}
	/**

* @brief Metoda odpowiadajaca za kolizje postaci z pociskami wrogow z dolu.*
* @param SDL_Rect Odestrect obiekt z ktorym dochodzi do kolizji, w tym przypadku pocisk.
* @param int s1 dodatkowy parametr pomagajacy w idelanym dobraniu odleglosci.*/
	bool Player::CollisionSD(SDL_Rect Odestrect, int s1) {
		if (destRect.x + Odestrect.w - 20 > Odestrect.x && destRect.x < Odestrect.x + Odestrect.w && destRect.y  > Odestrect.y + Odestrect.h - 50 && destRect.y < Odestrect.y + s1)
		{
			return  true;
		}
		return false;

	}

	/**

* @brief Metoda odpowiadajaca za kolizje postaci z pociskami wrogow z gory.*
* @param SDL_Rect Odestrect obiekt z ktorym dochodzi do kolizji, w tym przypadku pocisk.
* @param int s1 dodatkowy parametr pomagajacy w idelanym dobraniu odleglosci.*/
	bool Player::CollisionSU(SDL_Rect Odestrect, int s1) {
		if (destRect.x + Odestrect.w - 20 > Odestrect.x && destRect.x < Odestrect.x + Odestrect.w && destRect.y + Odestrect.h < Odestrect.y + 20 && destRect.y < Odestrect.y + s1)
		{
			
			return  true;
		}
		return false;

	}







#include "Enemy.h"
#include "TaxtureManager.h"

/**

* @brief Klasa odpowiadaj¹ca za renderowanie sie przeciwnikow.
* @param const char texturesheet obraz tekstury pobrany z pliku.
* @param SDL_Renderer ren renderowanie obiektu.
* @param int x pozycja w osi x.
* @param int y pozycja w osi y.
* @param int h wysokosc obiektu
* @param int w szerokosc obiketu.
* @param .*/
Enemy::Enemy(const char* texturesheet, SDL_Renderer* ren, int x, int y, int h, int w):
	GameObject::GameObject(texturesheet, ren, x, y, h, w)
{
	hp = 3;
	isliving;

}
/**

* @brief Metoda odpowiadaj¹ca za update obiektu.*/
void Enemy::Update() {


}


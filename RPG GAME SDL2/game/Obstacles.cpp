#include "Obstacles.h"
#include "TaxtureManager.h"

/**

* @brief Klasa odpowiadaj¹ca za renderowanie sie przeszkod.
* @param const char texturesheet obraz tekstury pobrany z pliku.
* @param SDL_Renderer ren renderowanie obiektu.
* @param int x pozycja w osi x.
* @param int y pozycja w osi y.
* @param int h wysokosc obiektu
* @param int w szerokosc obiketu.
* @param .*/
Obstacles::Obstacles(const char* texturesheet, SDL_Renderer* ren, int x, int y, int h, int w):
	GameObject::GameObject(texturesheet, ren, x, y, h, w)
{
	condition = 3;
}
/**

* @brief Metoda odpowiadaj¹ca za update obiektu.*/
void Obstacles::Update() {


}

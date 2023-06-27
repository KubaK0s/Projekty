#include "Live.h"
#include "TaxtureManager.h"
#include <vector>
/**

* @brief Klasa odpowiadaj¹ca za renderowanie sie punktow zycia.
* @param const char texturesheet obraz tekstury pobrany z pliku.
* @param SDL_Renderer ren renderowanie obiektu.
* @param int x pozycja w osi x.
* @param int y pozycja w osi y.
* @param int h wysokosc obiektu
* @param int w szerokosc obiketu.
* @param .*/
Live::Live(const char* texturesheet, SDL_Renderer* ren, int x, int y, int h, int w) :
	GameObject::GameObject(texturesheet, ren, x, y, h, w)
{
	
}
/**

* @brief Metoda odpowiadaj¹ca za update obiektu.*/
void Live::Update() {


}
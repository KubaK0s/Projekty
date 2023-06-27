#include "Shooting.h"
#include "TaxtureManager.h"

/**

* @brief Klasa odpowiadaj¹ca za renderowanie sie pociskow.
* @param const char texturesheet obraz tekstury pobrany z pliku.
* @param SDL_Renderer ren renderowanie obiektu.
* @param int x pozycja w osi x.
* @param int y pozycja w osi y.
* @param int h wysokosc obiektu
* @param int w szerokosc obiketu.
* @param .*/
Shooting::Shooting(const char* texturesheet, SDL_Renderer* ren, int x, int y, int h, int w):
	GameObject::GameObject(texturesheet, ren, x, y, h, w)
{
	velocity = 12;
}
/**

* @brief Metoda odpowiadaj¹ca za update obiektu.*/
void Shooting::Update() {

	if (Shot)
	{
		if (d)
		{
			destRect.x += velocity;
		}
		if (a)
		{
			destRect.x -= velocity;
		}
		if (s)
		{
			destRect.y += velocity;
		}
		if (w)
		{
			destRect.y -= velocity;
		}


	}
}
	

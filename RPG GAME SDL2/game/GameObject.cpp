#include "GameObject.h"
#include "TaxtureManager.h"

/**

* @brief Klasa odpowiadaj¹ca za renderowanie obiektow.
* @param const char* texturesheet odpowiada za wczytywanie tekstur z pliku.
* @param SDL_Renderer* ren .
* @param int x odpowiada za poczatkowe polozenie obiektu w osi x.
* @param int y odpowiada za poczatkowe polozenie obiektu w osi y.
* @param int h wysokosc obiektu.
* @param int w szerokosc obiektu.
* @param int size2 dodatkowa zmienna pomagajaca w idealnym doborze odleglosci kolizji..*/
GameObject::GameObject(const char* texturesheet, SDL_Renderer* ren, int x, int y, int h, int w)
{
	renderer = ren;
	objTexture = TextureManager::LoadTexture(texturesheet, ren);
	xpos = x;
	ypos = y;
	srcRect.h = h;
	srcRect.w = w;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.h = srcRect.h * 2;
	destRect.w = srcRect.w * 2;

	

}

/**

* @brief Metoda odpowiadaj¹ca za renderowanie obiektu.*/
void GameObject::Render() {

	SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
}
/**

* @brief Metoda odpowiadaj¹ca za kolizje pomiedzy dwoma obiektami
* @param SDL_Rect destRectt parametry drugiego obiektu, z ktorym dochodzi do kolizji.
* @param int size dodatkowa zmienna pomagajaca w idealnym doborze odleglosci kolizji.
* @param int size2 dodatkowa zmienna pomagajaca w idealnym doborze odleglosci kolizji.*/
bool GameObject::Collison(SDL_Rect destRectt, int size, int size2) {
	if (destRect.x + size2 >= destRectt.x && destRect.y >= destRectt.y - size2 && destRect.y <= destRectt.y + size && destRect.x <= destRectt.x + size)	
	{
		return true;
	}
	return false;
}


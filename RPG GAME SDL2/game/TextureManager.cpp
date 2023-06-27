#include "TaxtureManager.h"

/**

* @brief Klasa odpowiadaj¹ca za ladowanie tekstur.*
* @param const char textur obraz tekstury pobrany z pliku.
* @param SDL_Renderer ren renderowanie obiektu.*/
SDL_Texture* TextureManager::LoadTexture(const char* texture, SDL_Renderer* ren)
{
	SDL_Surface* tmp_surface = IMG_Load(texture);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(ren, tmp_surface);
	SDL_FreeSurface(tmp_surface);

	return tex;
}

#include "Background.h"
#include "TaxtureManager.h"


/**

* @brief Klasa odpowiadająca za renderowanie sie otoczenia.*
* @param const char texturesheet obraz tekstury pobrany z pliku.
* @param SDL_Renderer ren renderowanie obiektu.*/
Background::Background(const char* texturesheet, SDL_Renderer* ren)
{
	renderer = ren;
	objTexture = TextureManager::LoadTexture(texturesheet, ren);
}

/**

* @brief Metoda odpowiadająca za update obiektu.*/
void Background::Update() {

	xpos = 0;
	ypos = 0;
	srcRect.h = 256;
	srcRect.w = 256;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.h = srcRect.h*4;
	destRect.w = srcRect.w*4;	
	
}
/**

* @brief Metoda odpowiadająca za renderowanie obiektu.*/
void Background::Render() {

	SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
	
}
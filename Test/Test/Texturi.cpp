#include "Texturi.h"
#include <iostream>


SDL_Texture* Texturi::incaracaTextura(const char* numeFisier)
{
	
	SDL_Surface* tempSurface = IMG_Load(numeFisier);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(Joc::renderer, tempSurface);
	SDL_FreeSurface(tempSurface);

	
	return tex;
}

void Texturi::desen(SDL_Texture* tex, SDL_Rect src, SDL_Rect dst)
{

	SDL_RenderCopy(Joc::renderer, tex, nullptr, &dst);

 }
 


void Texturi::render1(int x, int y, SDL_Texture* mTexture,SDL_Rect* deUndeLuamTextura , double angle , SDL_Point* center , SDL_RendererFlip flip )
{
	
	SDL_Rect destRect = { x, y, 80, 80 };


	if (deUndeLuamTextura != NULL)
	{
		destRect.w = deUndeLuamTextura->w;
		destRect.h = deUndeLuamTextura->h;
	}

	
	SDL_RenderCopyEx(Joc::renderer, mTexture, deUndeLuamTextura, &destRect, angle, center, flip);
}
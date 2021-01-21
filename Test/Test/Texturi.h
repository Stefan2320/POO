#pragma once
#include "joc.h";
#include "Player.h"

 
class Texturi
{
public:
	
	static SDL_Texture* incaracaTextura(const char* numeFisier);
	static void desen(SDL_Texture* tex,SDL_Rect src,SDL_Rect dst);
	static void render1(int x, int y, SDL_Texture* mTexture, SDL_Rect* deUndeLuamTextura = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);

};
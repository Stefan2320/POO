#pragma once
#include "joc.h"


class Map{

private:
	SDL_Rect src, dst;
	SDL_Texture* pamant = nullptr;
	SDL_Texture* iarba;
	SDL_Texture* apa;
	int harta[20][25];
public:
	Map ();
	~Map();

	void incarcaMap(int vect[20][25]);
	void deseneazaMap();

};



#pragma once
#include "joc.h"
#include "SDL.h"
#include "Player.h"
#include "Tile.h"
struct Punct{
	float x,y;
};
//de bagat si touches wall

class Coliziune {
private:
	int pamant;
public:
	static int touchesWall(SDL_Rect box, Tile* tiles[]);
	static bool  ciocnireRect(SDL_Rect a, SDL_Rect b);
	static Punct distanta(int,int,int,int);
	static int incetinire(SDL_Rect box, Tile* tiles[]);
};
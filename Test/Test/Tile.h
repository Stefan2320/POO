#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>
#include "joc.h"



const int LATIME = 32;
const int INALTIME = 32;
const int GRESIE = 1200;
const int DESENE = 2;
const int ZID = 0;
const int IARBA = 1;
const int pamant = 2;





class Tile {

public:
	~Tile() {};
	 Tile(int x, int y, int tip);
	static  bool loadMedia(Tile* tiles[], const char* nume, const char* jos);
	static bool setTiles(Tile* tiles[], const char* nume);
	void render(SDL_Rect& camera);
	SDL_Rect getPozitie();
	int getType()
	{
		
		return tipTile;
	}

protected:

	SDL_Rect Pozitie;
	int tipTile = 0;
};

class Tile2 : public Tile
{
public:
	Tile2(int x, int y, int tip) :Tile(x, y, tip) 
	{}
	static bool setTiles(Tile* tiles[], const char* nume);
	static  bool loadMedia(Tile* tiles[], const char* nume, const char* jos);
	~Tile2() {};
private:

};

class Tile3 : public Tile
{
public:
	Tile3(int x, int y, int tip) :Tile(x, y, tip)
	{}
	static bool setTiles(Tile* tiles[], const char* nume);
	static  bool loadMedia(Tile* tiles[], const char* nume, const char* jos);
	~Tile3() {};
private:

};
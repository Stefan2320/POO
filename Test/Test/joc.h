#pragma once
#include <SDL.h>
#include <stdio.h>
#include <iostream>
#include <SDL_image.h>
#include "Tile.h"



const int SCREEN_HEIGHT = 640;
const int LEVEL_WIDTH = 1280;
const int LEVEL_HEIGHT = 960;
const int SCREEN_WIDTH = 800;

class Joc {

private:

	
	bool ruleaza_jocul ;
	SDL_Window* window;
	

public:
	static int contor[2];
	Joc();
	~Joc();
	void init(const char* titlu,int pos_x, int pos_y,int pos_lat, int pos_lun, bool ecran_intreg);
	void ocupareEvenimente();
	void update();
	void randare();
	void clean();
	void setNivele();

	bool ruleaza() 
	{
		return ruleaza_jocul;
	}

	static SDL_Renderer* renderer;

};
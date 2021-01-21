#pragma once
#include "Component.h"
#include "SDL.h"
#include "Tile.h"
#include "joc.h"
#include "ObiectJoc.h"
#include "Coliziune.h"



class Jucator:public Component
{ 
public:

	static const int J_WIDTH = 32;
	static const int J_HEIGHT = 64;
	 int viteza = 10;

	 ~Jucator()
	 {
		 texture = nullptr;
	 }
	static const int Vel1 = 10;
	Jucator() = default;
	Jucator(const char* fisier);
	void init() override;
	void desen()override;
	void update();
	void setText(const char* fisier);
	void Control(SDL_Event );
	int getX() { return destRect.x; };
	int getY() { return destRect.y; };
	void move(Tile* tiles[]);
	void setCamera(SDL_Rect& camera);
	void Shoot(int, int,ObiectJoc*);
	void render( int* frame,int FPS, SDL_Rect& camera);
	void handleEvent(SDL_Event &e, const Uint8* keys1);
	SDL_Rect getDesRect();
	int viata(SDL_Rect glont, int sterge1);
	
protected:
	int Velx, Vely;
	int x, y;
	SDL_Texture* texture;
	SDL_Rect srcRect, destRect;
	int miscare[5] = {0};
	int traieste = 1;
};




class INAMIC:public Jucator
{
public:

	INAMIC(const char* fisier1) :Jucator(fisier1) {
		ajungeX = 600;
		ajungeY = 450;
		speed = 10;
		
	};
	void moveInamic(Tile* tiles[], Jucator* huhu);
	void setX(int x);
	void setY(int y);
	void setAjunge();
	void init();
	int getViata()
	{
		return traieste;
	}
	void setDificultate();
	void setDesRect(SDL_Rect temp)
	{
		destRect.x = temp.x;
		destRect.y = temp.y;
	}
	
private:
	int x, y;
	int speed;
	int ajungeX, ajungeY;
	

};
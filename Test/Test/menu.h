#pragma once
#include "SDL_image.h"
#include "SDL.H"
#include "Texturi.h"
#include "joc.h"



class Menu
{
protected:
	int pos1 ;
	int pos2 ;
	bool joaca = false;
	SDL_Texture* fundal;
	SDL_Texture* jocNou;
	SDL_Texture* victorie;
	SDL_Texture* go;
	SDL_Texture* exit;
	SDL_Rect exit1;
	SDL_Rect fundal1;
	SDL_Rect nou1;
	char a[100];
	char b[100];
	
public:

	~Menu()
	{
		fundal = nullptr;
		jocNou = nullptr;
		victorie = nullptr;
		go = nullptr;
		exit = nullptr;
	}
	Menu( const char*  , const char*  , const char* );
	void verific(int x, int y);
	void randare();
	bool mouse_exit(int x,int y);
	void mouse_newGame(int x, int y);
	void setText(const char* vit, const char* gat)
	{
		victorie = Texturi::incaracaTextura(vit);
		go = Texturi::incaracaTextura(gat);
	}
	void imgVictorie()
	{
		SDL_Rect t;
		t.x = 0;
		t.y = 0;
		t.w = 800;
		t.h = 640;
		Texturi::desen(victorie,t,t);
	}
	void imgGo()
	{
		SDL_Rect t;
		t.x = 0;
		t.y = 0;
		t.w = 800;
		t.h = 640;
		Texturi::desen(go, t, t);
	}

};


class Pagina2 :public Menu
{ private:
	SDL_Texture* pentru3;
	SDL_Rect pentru31;
public:
	Pagina2(const char* verde, const char* lvl1, const char* lvl2, const char* lvl3) :Menu(verde, lvl2, lvl1)
	{
		pentru3 = Texturi::incaracaTextura(lvl3);
		pentru31.x = 554;
		pentru31.y = 240;
		pentru31.w = 224;
		pentru31.h = 128;
	}

	void verificPag(int x , int y);
	void Randare();
	void click(int x,int y);
	
};
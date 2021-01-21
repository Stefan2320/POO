#include "menu.h"
#include<iostream>



Menu::Menu(const char* fundal2, const char* jocNou2, const char* exit2)
{
	fundal = Texturi::incaracaTextura(fundal2);
	jocNou = Texturi::incaracaTextura(exit2);
	exit = Texturi::incaracaTextura(jocNou2);
	strcpy_s(a, strlen(exit2) + 1, exit2);
	strcpy_s(b, strlen(jocNou2) + 1,jocNou2);
	
	fundal1.x = 0;   
	fundal1.y = 0;  
	fundal1.w = 800; 
	fundal1.h = 640;
	
	exit1.x = 243;
	exit1.y = 400;
	exit1.w = 224;
	exit1.h = 128;

	nou1.x = 243;
	nou1.y = 100;
	nou1.w = 224;
	nou1.h = 128;

	

}

void Menu::randare()
{	
	
	Texturi::desen(fundal,fundal1 , fundal1);
	Texturi::desen(jocNou, nou1, nou1);
	Texturi::desen(exit, exit1, exit1);
}

void Menu::verific(int x, int y)
{
	pos1 = x;
	pos2 = y;
	if (pos1 >=nou1.x && pos1 <= nou1.x + nou1.w && pos2 >= nou1.y && pos2 <= nou1.y +nou1.h)
		SDL_SetTextureColorMod(jocNou, 250, 0, 0);
	else
		jocNou = Texturi::incaracaTextura(a);
	
		if (pos1 >= exit1.x && pos1 <= exit1.x + exit1.w && pos2 >= exit1.y && pos2 <= exit1.y + exit1.h)
			SDL_SetTextureColorMod(exit, 750, 0, 0);
		else
			exit = Texturi::incaracaTextura(b);
}


bool Menu::mouse_exit(int x,int y) 
{
	pos1 = x;
	pos2 = y;
	bool deschis = true;
	if (pos1 >= exit1.x && pos1 <= exit1.x + exit1.w && pos2 >= exit1.y && pos2 <= exit1.y + exit1.h)
		deschis = false;
	else
		deschis = true;

	return deschis;
}

void Menu::mouse_newGame(int x, int y)
{
	pos1 = x;
	pos2 = y;
	if (pos1 >= nou1.x && pos1 <= nou1.x + nou1.w && pos2 >= nou1.y && pos2 <= nou1.y + nou1.h)
	{
		Joc::contor[0] = -2;
		Joc::contor[1] = 1;
	}
}

void Pagina2::Randare()
{
	
	Texturi::desen(fundal, fundal1, fundal1);
	Texturi::desen(jocNou, nou1, nou1);
	Texturi::desen(exit, exit1, exit1);
	Texturi::desen(pentru3, pentru31, pentru31);
}


void Pagina2::click(int x,int y)
{
	
	if (x >= nou1.x && x <= nou1.x + nou1.w && y >= nou1.y && y <= nou1.y + nou1.h) //lvl1
	{
		Joc::contor[0] = 1;
		Joc::contor[1] = 1;
	}
	if (x >= exit1.x && x <= exit1.x + exit1.w && y >= exit1.y && y <= exit1.y + exit1.h) //lvl2
	{
		
		Joc::contor[0] = -3;
		Joc::contor[1] = 1;
		
	}
	if (x >= pentru31.x && x <= pentru31.x + pentru31.w && y >= pentru31.y && y <= pentru31.y + pentru31.h) //lvl2
	{
		Joc::contor[0] = -4;
		Joc::contor[1] = 1;
	}
}


void Pagina2::verificPag(int x, int y)
{
	verific(x,y);
	if (x >= pentru31.x && x <= pentru31.x + pentru31.w && y >= pentru31.y && y <= pentru31.y + pentru31.h)
		SDL_SetTextureColorMod(pentru3, 750, 0, 0);
	else
		pentru3 = Texturi::incaracaTextura("Poze/b3.png");
	
}
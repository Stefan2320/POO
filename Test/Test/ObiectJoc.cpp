#include "ObiectJoc.h"
#include "Texturi.h"
#include <iostream>
#include "Keyboard.h"
#include "joc.h"
#include "Coliziune.h"
#include "Player.h"



ObiectJoc::ObiectJoc(const char* sheet, int x, int y)
{
	srcRecT.x = 0;
	srcRecT.y = 0;
	srcRecT.h = 32;
	srcRecT.w = 32;


	destRect.y = x;
	destRect.x = y;
	destRect.w = 32;
	destRect.h = 32;

	objText = Texturi::incaracaTextura(sheet);
	xpos = x;
	ypos = y;
	sterge = 0;
}


void ObiectJocPlayer::Update(Tile* tiles[])
{
	
	
	int speed = 10;
	float var = 1;
	if (abs(pozix - xpos) < 20 )
	{
		var = 1;
		speed = 1;
	}
	
	float y2 = 0;
	float x2 = 0;
	while (speed != 0) {
		
		if (pozix < xpos)
		{
			copie = copie + var;
			x2 = copie;
			
		}
		else
		{
			copie = copie - var;
			x2 = copie--;
		}

		y2 = (x2 - pozix) * (ypos - poziy) / (xpos - pozix) * 1.0 + poziy;

		srcRecT.x = 0;
		srcRecT.y = 0;
		srcRecT.h = hO;
		srcRecT.w = wO;

		
		destRect.y = y2;
		destRect.x = x2;
		destRect.w = 16;
		destRect.h = 16;
		speed--;
	}
	
	if (Coliziune::touchesWall(destRect, tiles))
	{
		
		sterge = 1;
		std::cout << sterge << std::endl;
		
	}
	

	
	/**
	//std::cout << destRect.x << " " << destRect.y << std::endl;
	/////////////////////////////////////
	if (pozix != xpos || poziy != ypos)
	{

		srcRecT.x = 0;
		srcRecT.y = 0;
		srcRecT.h = hO;
		srcRecT.w = wO;


		destRect.y = poziy;
		destRect.x = pozix;
		destRect.w = 16;
		destRect.h = 16;


		if (pozix < xpos)
			pozix++;
		else
			pozix--;

		if (poziy < ypos)
			poziy++;
		else
			poziy--;

		
	}
	*/
	
	

	

}

void ObiectJoc::Render( SDL_Rect camera)
{
		
		SDL_RenderCopy(Joc::renderer,objText,&srcRecT,&destRect);
		
	
}


void ObiectJocPlayer::Render(SDL_Rect camera)
{
	

	if (sterge == false)
	{
		
			destRect.x = destRect.x - camera.x;
			destRect.y = destRect.y - camera.y;
			Texturi::desen(objText, srcRecT, destRect);
		

	}
}

void ObiectJocPlayer::SHoot(int Mx, int My,int x,int y)
{

	xpos = Mx;
	ypos = My;
	pozix = x;
	poziy = y + 32;
	copie = pozix + 32;
	
	
}

void numarGloante::schimba()
{
	
	nrGloante--;
	std::cout << "BNUMU"<<std::endl;;
	if (lvl == 1)
	{
		srcRecT.x = l * 32;
		srcRecT.y = 0;
		srcRecT.w = 32;
		srcRecT.h = 32;
		l++;
	}
	else if(lvl == -3)
	{
		srcRecT.x =  q * 32;
		srcRecT.y = 0;
		srcRecT.w = 32;
		srcRecT.h = 32;
		q++;
	}
	else if (lvl == -4)
	{
		srcRecT.x = v * 32;
		srcRecT.y = 0;
		srcRecT.w = 32;
		srcRecT.h = 32;
		v++;
	}
	
}



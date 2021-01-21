#include "Player.h"
#include "Texturi.h"
#include <iostream>
#include "Keyboard.h"
#include <cstdlib>
#include <ctime>
#include <random>

extern const int LEVEL_HEIGHT;
extern const int LEVEL_WIDTH;
extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;
extern int  nrInamici;


Jucator::Jucator(const char* fisier)
{
	setText(fisier);
}
void Jucator::setText(const char* fisier)
{
	texture = Texturi::incaracaTextura(fisier);
	
}
void Jucator::init()
{

	traieste = 1;
	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = 32;
	srcRect.h = 64;

	
	destRect.w = 32;
	destRect.h = 64;
	destRect.x = 60;
	destRect.y = 450;
	Velx = 0;
	Vely = 0;
	
}
void Jucator::update() 
{	
	
	
	/*
	if (miscare[4] == 1) {
		if (miscare[1] == 1)
		{
			Vely = Vely - viteza; //w
		}
		if (miscare[2] == 1)
		{
			Velx = Velx - viteza;//A
		}
		if (miscare[3] == 1)
		{

			Vely = Vely + viteza; //S

		}
		if (miscare[0] == 1)
		{
			Velx = Velx + viteza; //D
		}
		

		
	}
	else if(miscare[4] == 0)
	{
		if (miscare[0] == 1)
		{

			Velx = Velx - viteza; //D
		}
		if (miscare[1] == 1)
		{
			Vely = Vely + viteza;  //W
		}
		if (miscare[2] == 1)
		{
			std::cout << "BA";
			Velx = Velx + viteza; //A
		}

		if (miscare[3] == 1)
		{

			Vely = Vely - viteza; //S

		}
	}*/
	
	destRect.x = destRect.x + Velx;
	destRect.y = destRect.y + Vely;
	
}
void Jucator::desen()
{   
	Texturi::desen(texture, srcRect, destRect );
}
void Jucator::Control(SDL_Event event)
{
	if (event.type == SDL_KEYDOWN && event.key.repeat == 0)
	{

		switch (event.key.keysym.sym)
		{
		case SDLK_w: 
			Vely = Vely - viteza;
			break;
		case SDLK_s:
			Vely = Vely + viteza;
			break;
		case SDLK_a: 
			Velx = Velx - viteza;
			break;
		case SDLK_d: 
			Velx = Velx + viteza;
			break;
		}
	}
	else if (event.type == SDL_KEYUP && event.key.repeat == 0)
	{

		switch (event.key.keysym.sym)
		{
		case SDLK_w:
			Vely = Vely + viteza; 
			break;
		case SDLK_s:
			Vely = Vely - viteza;
			break;
		case SDLK_a: 
			Velx = Velx + viteza; 
			break;
		case SDLK_d:
			Velx = Velx - viteza;
			break;
		}
	}
	/*
	miscare[4] = x;
	
	if (strcmp(tasta, "R") != 0)
	{
		if (strcmp(tasta, "D") == 0)
		{
			
			miscare[0] = 1;
			
		}
		
		if (strcmp(tasta, "W") == 0)
		{
			miscare[1] = 1;
			
		}

		if (strcmp(tasta, "A") == 0)
		{
			miscare[2] = 1;
			
		}
		if (strcmp(tasta, "S") == 0)
		{
			miscare[3] = 1;

		}
	}
	else
	{
		miscare[0] = 0;
		miscare[1] = 0;
		miscare[2] = 0;
		miscare[3] = 0;
	}

	
		
*/
}
void Jucator::move(Tile* tiles[])
{
	

	if ((destRect.x < 0) )
	{
		destRect.x = 0 ;
		
	}
	
	if ((destRect.x + J_WIDTH > LEVEL_WIDTH)  )
	{
		destRect.x = destRect.x - 10;
	}

	if (Coliziune::touchesWall(destRect, tiles) > 0)
	{
		
		
		destRect.x = destRect.x - Velx;
		destRect.y = destRect.y - Vely;

	}
	else if (Coliziune::touchesWall(destRect, tiles) == -1)
	{
		std::cout << "PAMANAT";
		destRect.x = destRect.x - Velx*0.5 ;
		destRect.y = destRect.y - Vely*0.5 ;
	}

	if ((destRect.y < 0) )
	{
		
		destRect.y = 0;
	}
	
	if ((destRect.y  + J_HEIGHT > LEVEL_HEIGHT) )
	{
		destRect.y = destRect.y - 10;

	}

}
void Jucator::setCamera(SDL_Rect& camera)
{
	
	camera.x = (destRect.x + J_WIDTH / 2) - SCREEN_WIDTH / 2;
	camera.y = (destRect.y + J_HEIGHT / 2) - SCREEN_HEIGHT / 2;
	
	
	if (camera.x < 0)
	{
		camera.x = 0;
	}
	if (camera.y < 0)
	{
		camera.y = 0;
	}
	if (camera.x > LEVEL_WIDTH - camera.w)
	{
		camera.x = LEVEL_WIDTH - camera.w;
	}
	if (camera.y > LEVEL_HEIGHT - camera.h)
	{
		camera.y = LEVEL_HEIGHT - camera.h;
	}

	
}
void Jucator::render(int* frame,int FPS, SDL_Rect& camera)
{
	if (FPS / (*frame) == 2 )
	{
		*frame = 0;
		
		if (miscare[0] == 1)
			{
				
				srcRect.x += J_WIDTH;
				srcRect.y = 128;
				if (srcRect.x > 256)
				srcRect.x = 0;
			}
		else if (miscare[1] == 1)
		{

			srcRect.x += J_WIDTH;
			srcRect.y = 0;
			if (srcRect.x > 256)
				srcRect.x = 0;
		}
		else if (miscare[2] == 1)
		{

			srcRect.x += J_WIDTH;
			srcRect.y = 64;
			if (srcRect.x > 256)
				srcRect.x = 0;
		}
		else if (miscare[3] == 1)
		{

			srcRect.x += J_WIDTH;
			srcRect.y = 0;
			if (srcRect.x > 256)
				srcRect.x = 0;
		}
		else
		{
			srcRect.y = 0;
			srcRect.x += J_WIDTH;
			if (srcRect.x > 256)
				srcRect.x = 0;
		}
		
	}
	
	if(traieste == 1)
		Texturi::render1(destRect.x - camera.x, destRect.y - camera.y,texture,&srcRect);
}	  
SDL_Rect Jucator::getDesRect()
{
	SDL_Rect temp;
	temp.x = destRect.x;
	temp.y = destRect.y;
	temp.w = destRect.w;
	temp.h = destRect.h;

	return temp;

}
int Jucator::viata(SDL_Rect glont,int sterge1)
{
	

	if (Coliziune::ciocnireRect(destRect, glont))
	{
		traieste = 0;
		sterge1 = 1;
		std::cout << "inamicul "<< traieste << std::endl;

		
	}

	return sterge1;
}

void INAMIC::setAjunge()
{
	std::random_device rd; 
	std::mt19937 gen(rd()); 
	std::uniform_int_distribution<> distrx(1, 1280); 
	std::uniform_int_distribution<> distry(1, 960);
	ajungeX = distrx(gen);
	ajungeY = distry(gen);
}
void INAMIC::setDificultate()
{
	
	if (Joc::contor[0] == 1)
		speed = 5;
	if (Joc::contor[0] == -3)
		speed = 9;
	if (Joc::contor[0] == -4)
	{
		speed = 11;
	}
}
void INAMIC::moveInamic(Tile* tiles[], Jucator* huhu)
{
	
	Punct destinatie;
	Punct atingere;
	float ipo,ipo1;
	float test,test11;
	float test1,test22;
	atingere = Coliziune::distanta(huhu->getX(), huhu->getY(), destRect.x, destRect.y);
	destinatie = Coliziune::distanta(ajungeX, ajungeY, destRect.x, destRect.y);
	if (abs(ajungeX - destRect.x) < 64 && abs(ajungeY - destRect.y) < 64)
		setAjunge();
	
	
	std::cout << atingere.x << " " << atingere.y << std::endl;
	if (abs(atingere.x)<  10 && abs(atingere.y)< 10  && traieste == 1)
	{
		
		std::cout << "GAMEOVER";
		Joc::contor[0] = -6;
	}
	else
	{
		if ((destRect.x < 0))
		{
			destRect.x = 0;
			if (destRect.y > 0)
				destRect.y = destRect.y - speed;

		}
		else if ((destRect.y < 0))
		{

			destRect.y = 0;
			destRect.x = destRect.x + speed;
		}

		if ((destRect.y + J_HEIGHT > LEVEL_HEIGHT))
		{
			destRect.y = destRect.y - speed;

		}

		if ((destRect.x + J_WIDTH > LEVEL_WIDTH))
		{
			destRect.x = destRect.x - speed;
		}

		if (abs(atingere.x) > 200 || abs(atingere.y) > 200)
		{
			
			if (Coliziune::touchesWall(destRect, tiles) > 0)
			{	
				setAjunge();
			}
		

			//if (Coliziune::touchesWall(destRect, tiles) != 0)
			ipo1 = sqrt(destinatie.x * destinatie.x + destinatie.y * destinatie.y);
			destinatie.x = destinatie.x / ipo1;
			destinatie.y = destinatie.y / ipo1;
			test11 = (destRect.x + destinatie.x * speed) * 1.0;
			destRect.x = test11;
			test22 = (destRect.y + destinatie.y * speed) * 1.0;
			destRect.y = test22;

			
			if (Coliziune::touchesWall(destRect, tiles) > 0)
			{
			

				setAjunge();
			}

		}
		else
		{
			Punct cat;
			if (Coliziune::touchesWall(destRect, tiles) > 0)
			{
				
				if (atingere.x < 0)
					destRect.x = destRect.x + speed;
				else
					destRect.x -= speed;

				if (atingere.y < 0)
					destRect.y += speed;
				else
					atingere.y -= speed;
			}

			ipo = sqrt(atingere.x * atingere.x + atingere.y * atingere.y);
			atingere.x = atingere.x / ipo;
			atingere.y = atingere.y / ipo;
			test = (destRect.x + atingere.x * speed) * 1.0;
			destRect.x = test;
			test1 = (destRect.y + atingere.y * speed) * 1.0;
			destRect.y = test1;
			
			
				
			

		}
	}
}
void INAMIC::setY(int y)
{
	this->y = y;
}
void INAMIC::setX(int x)
{
	this->x = x;
}
void INAMIC::init()
{

	traieste = 1;
	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = 32;
	srcRect.h = 64;


	destRect.w = 32;
	destRect.h = 64;
	destRect.x = x;
	destRect.y = y;


}


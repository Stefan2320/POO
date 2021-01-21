#include "SDL.h"
#include <stdio.h>
#include "joc.h"
#include "Texturi.h";
#include "ObiectJoc.h"
#include "Player.h"
#include "Map.h"
#include <iostream>
#include "menu.h"
#include "Keyboard.h"
#include "Tile.h"
#include "Coliziune.h"

int FRAME = 0;
int FPS = 20;
SDL_Texture* TileTexture = nullptr;
Menu* x = nullptr;
Pagina2* pag = nullptr;
Jucator* huhu = nullptr;
INAMIC* inamic[4];
ObiectJoc* glont[10];
ObiectJoc* afisare = nullptr;
SDL_Renderer* Joc::renderer = nullptr;
Map* harta;
int Joc::contor[2] = { 0 };
SDL_Rect TileClips[3];
Tile* tileSet[1200];
Tile2* tileSet2[1200];
SDL_Rect camera = { 0, 0, 800, 640 };
int k = 0;
int nrInamici = 0;


	

Joc::Joc() {

}

Joc::~Joc() {
	delete x;
	delete huhu;
}

void Joc::init(const char* titlu, int pos_x, int pos_y, int pos_lat, int pos_lun, bool ecran_intreg) {

	
	

	int fullscreen_sau_nu = 0;
	if (ecran_intreg) {

		fullscreen_sau_nu = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		ruleaza_jocul = false;
		std::cout << " ERROR la SDL_Init: " << SDL_GetError() << std::endl;
	}
	else
	{	
		window = SDL_CreateWindow(titlu,pos_x,pos_y,pos_lat,pos_lun,fullscreen_sau_nu);
	
		if (window < 0)
		{
			ruleaza_jocul = false;
			std::cout << "ERROR la SDL_CREATEWINDOW: " << SDL_GetError() << std::endl;
		}
		else {
	 
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

			if (renderer < 0)
			{
				ruleaza_jocul = false;
				std::cout << "ERROR la SDL_CREATERENDERER: " << SDL_GetError() << std::endl;
			}
			else
			{	

				SDL_SetRenderDrawColor(renderer,800,255,255,255);
				ruleaza_jocul = true;
			}
		}
	}

	

	x = new Menu("Poze/fuundal.png", "Poze/exitGLONT.png", "Poze/start.png");
	pag = new Pagina2("Poze/fuundal.png", "Poze/b1.png", "Poze/b2.png", "Poze/b3.png");
	harta = new Map();
	huhu = new Jucator("Poze/stick3.png");
	huhu->init();
	x->setText("Poze/vict.png","Poze/gameOver.png");
	

	
	

}

void Joc::setNivele()
{
	std::cout << contor[0] << " " << contor[1] << std::endl;
	int tempy = 800;
	if (contor[1] == 4 && contor[0] == 0 )
	{
		std::cout << contor[0] << std::endl;
		std::cout << "JHJBVDUBVCUIVWON ";
		if (inamic)
		{
			for (int i = 0; i < nrInamici; i++)
			{  
				std::cout << i << std::endl;
				delete inamic[i];
			}
		}
		if (afisare) {

			delete afisare;
		}
		if(tileSet)
		for (int i = 0; i < 1200; ++i)
		{
			delete tileSet[i];
		}
		TileTexture = nullptr;
	}

	if (contor[1] == 1 && contor[0] == 1)
	{
		
		afisare = new numarGloante("Poze/nrglont.png", 0, 0, 10, 1);
		huhu->init();
		k = 0;
		nrInamici = 4;
		afisare->setNumarTotal(10);
		afisare->setGloante(10);
		afisare->setLvl(1);
		afisare->schimba();
		try
		{
			if (nrInamici > afisare->getNumarTotal())
				throw 99;
		}
		catch (int r)
		{
			std::cout << "IMPOSIBIL DE CAASTIGAT: " << r << std::endl;
			ruleaza_jocul = 0;
		}
		for (int i = 0; i < nrInamici ; i++)
		{
			inamic[i] = new INAMIC("Poze/inamic3.png");
			inamic[i]->setX(1200);
			inamic[i]->setY(tempy);
			inamic[i]->init();
			tempy = tempy - 200;
			inamic[i]->setDificultate();

		}
		Tile::loadMedia(tileSet, "poze/lvl1.map", "poze/pavele4.png");
		contor[1] = 0;
	}
	else if (contor[0] == -3 && contor[1] == 1)
	{
		k = 0;
		huhu->init();
		nrInamici = 4;
		afisare = new numarGloante("Poze/nrglont.png", 0, 0, 7, -3);
		afisare->setNumarTotal(7);
		afisare->setGloante(7);
		afisare->setLvl(-3);
		afisare->schimba();
		for (int i = 0; i < nrInamici; i++)
		{
			inamic[i] = new INAMIC("Poze/inamic3.png");
			inamic[i]->setX(1200);
			inamic[i]->setY(tempy);
			inamic[i]->init();
			tempy = tempy - 200;
			inamic[i]->setDificultate();

		}
		Tile2::loadMedia(tileSet, "poze/lvl2.map","poze/pavele2.png");
		contor[1] = 0;
	}
	else if (contor[0] == -4 && contor[1] == 1)
	{
		k = 0;
		huhu->init();
		afisare = new numarGloante("Poze/nrglont.png", 0, 0, 4, -4);
		afisare->setNumarTotal(4);
		afisare->setGloante(4);
		afisare->setLvl(-4);
		afisare->schimba();
		nrInamici = 4;
		for (int i = 0; i < nrInamici; i++)
		{
			inamic[i] = new INAMIC("Poze/inamic3.png");
			inamic[i]->setX(1200);
			inamic[i]->setY(tempy);
			inamic[i]->init();
			tempy = tempy - 200;
			inamic[i]->setDificultate();

		}
		Tile3::loadMedia(tileSet, "poze/lvl3.map", "poze/pavele3.png");
		contor[1] = 0;
	}
	
}
void Joc::ocupareEvenimente() {

	
	int Mx, My;
	SDL_Event event;
	const Uint8* keys = SDL_GetKeyboardState(NULL);

	SDL_GetMouseState(&Mx, &My);
	x->verific(Mx, My);
	pag->verificPag(Mx,My);
	
	while (SDL_PollEvent(&event) != 0)
	{ 
		huhu->Control(event);
		if (event.type == SDL_QUIT)
		{
			ruleaza_jocul = false;
			//break;
		}
		else if (event.type == SDL_MOUSEBUTTONDOWN)
		{
			
			
			if (contor[0] > 0 || contor[0] == -3 || contor[0] == -4)
			{
				if (afisare->getNumar() >= 0)
				{
					std::cout << afisare->getNumar();
					std::cout << "POC" << " " << k << " " << std::endl;
					glont[k] = new ObiectJocPlayer("Poze/glont.png", 0, 0, 16, 16);
					glont[k]->SHoot(Mx + camera.x, My + camera.y, huhu->getX(), huhu->getY());
					afisare->schimba();
					k++;
				}
				else
				{
					Joc::contor[0] = -6;
				}
			}

			if (contor[0] == 0) 
			{
					SDL_GetMouseState(&Mx, &My);
					std::cout << Mx << " " << My << " ";
					ruleaza_jocul = x->mouse_exit(Mx, My);
					x->mouse_newGame(Mx, My);
					setNivele();
			}else if (contor[0] == -2)
			{
				SDL_GetMouseState(&Mx, &My);
				pag->click(Mx, My);
				setNivele();

			}

		}
		else if (contor[0] == -5 && keys[SDL_SCANCODE_ESCAPE] != 0)
		{

			std::cout << "DE ACI" << contor[0] << std::endl;
			contor[0] = 0;
			contor[1] = 4;
			setNivele();

		}
		else if ( contor[0] != -2 && keys[SDL_SCANCODE_ESCAPE] != 0)
		{

			std::cout << "DE ACI" << contor[0] << std::endl;
			contor[0] = 0;
			contor[1] = 3;
			setNivele();
			
		}
		else if(keys[SDL_SCANCODE_ESCAPE] != 0)
		{
			//std::cout << "else" << std::endl;
			contor[0] = 0;
			setNivele();
		}

	}
	
	
}
void Joc::update() {
	std::cout << "UPDATE" << std::endl;
	
	//std::cout << k << std::endl;
	if (contor[0] > 0 || contor[0] == -3 || contor[0] == -4)
	{	
		for (int i = 0; i < nrInamici; i++)
			inamic[i]->moveInamic(tileSet, huhu);

		huhu->update();
		huhu->move(tileSet);
		
		for (int i = 0; i < k; i++)
		{	if(glont[i]!=0)
			glont[i]->Update(tileSet);
		}
		for (int j = 0; j < nrInamici; j++)
		{for (int i = 0; i < k; i++){
			if(glont[i] != 0)
			glont[i]->setSterge((inamic[j]->viata(glont[i]->getRect(), glont[i]->getSterge())));
			if (glont[i] != 0 && glont[i]->getSterge() == 1)
				glont[i] = 0;
			}}

		int sum = 0;
		for (int i = 0; i < nrInamici; i++)
			sum = sum + inamic[i]->getViata();
		if (sum == 0)
		{
			Joc::contor[0] = -5; //seteaza pentru VICTORIE pg
		}
			
		
		
	}

	
	
}
void Joc::randare() {

	
	
	SDL_RenderClear(renderer);

	
	
	huhu->setCamera(camera);

	if (contor[0] ==1   || contor[0] == -3 || contor[0] == -4)
	{
		
		
		
		for (int i = 0; i < 1200; ++i)
		{
				tileSet[i]->render(camera);
			
		}
		
		for (int i = 0; i < nrInamici; i++) {
			FRAME++;
			
			inamic[i]->render(&FRAME, FPS, camera);
		}
		FRAME++;
		huhu->render(&FRAME, FPS, camera);
		if (k < 10)
		{
			for (int i = 0; i < k; i++)
			{	if(glont[i]!= 0 )
				glont[i]->Render(camera);
			}
		}
		
		afisare->Render(camera);
		
	}
	else if(contor[0] == 0)
	{
	
		x->randare();
	}
	else if (contor[0] == -2 )
	{
		pag->Randare();
	}
	else if(contor[0] == -5)
	{
		x->imgVictorie();
		contor[1] = 0;

	}
	else if (contor[0] == -6)
	{
		x->imgGo();
		
	}
	
	
	

	SDL_RenderPresent(renderer);
	
}
void Joc::clean(){

	
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}


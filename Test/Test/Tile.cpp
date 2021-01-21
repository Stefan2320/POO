#include "Tile.h"
#include "joc.h"
#include "Texturi.h"
#include "SDL.h"
#include <iostream>
#include "joc.h"
#include "Keyboard.h"
#include "Coliziune.h"


extern  SDL_Rect TileClips[2];
extern SDL_Texture* TileTexture;

Tile::Tile(int x, int y, int tip)
{
    
    Pozitie.x = x;
    Pozitie.y = y;
	
	//pt coliz
    Pozitie.w = 32;
    Pozitie.h = 32;

  
    tipTile = tip;
   
}

void Tile::render(SDL_Rect& camera)
{
   
	
	
    if (Coliziune::ciocnireRect(camera, Pozitie))
	{
       Texturi::render1(Pozitie.x - camera.x, Pozitie.y - camera.y, TileTexture, &TileClips[tipTile]);
    }
}

SDL_Rect Tile::getPozitie()
{
    return Pozitie;
}


bool Tile::setTiles(Tile* tiles[],const char* nume)
{
	
	int z = 0;

	bool tilesLoaded = true;

	
	
	int x = 0, y = 0;

	
	std::ifstream map(nume);


	if (map.fail())
	{
		std::cout << "Eroare la HARTA";
		tilesLoaded = false;
	}
	else
	{
		
		for (int i = 0; i < 1200; ++i)
		{
			
			int tileType = -1;

			
			map >> tileType;

			
			
			if (map.fail())
			{
				
				std::cout << "Error la HARTA";
				tilesLoaded = false;
				break;
			}

			if ((tileType >= 0) && (tileType < 3))
			{
				
				tiles[i] = new Tile(x, y, tileType);

			}
			else
			{
				
				std::cout << "Eroare la GRESIE";
				tilesLoaded = false;
				break;
			}

			x += LATIME;
			if (x >= LEVEL_WIDTH)
			{
				x = 0;
				y += INALTIME;
				z++;
				
				
			}

		}

		
		if (tilesLoaded)
		{
			TileClips[ZID].x = 0;
			TileClips[ZID].y = 0;
			TileClips[ZID].w = LATIME;
			TileClips[ZID].h = INALTIME;

			TileClips[IARBA].x = 32;
			TileClips[IARBA].y = 0;
			TileClips[IARBA].w = LATIME;
			TileClips[IARBA].h = INALTIME;

			TileClips[pamant].x = 64;
			TileClips[pamant].y = 0;
			TileClips[pamant].w = LATIME;
			TileClips[pamant].h = INALTIME;

			
		}
	}

	map.close();
	return tilesLoaded;
}

bool Tile::loadMedia(Tile* tiles[], const char* nume, const char* jos)
{
	//std::cout << nume << std::endl;

	bool success = true;
	
	if (!(TileTexture = Texturi::incaracaTextura(jos)))
	{	
		std::cout << "Eroare la textura";
		success = false;
	}

	if (!(Tile::setTiles(tiles,nume)))
	{
		std::cout << "Eroare la incaracea hartii";
		success = false;
	}
	return success;


}

bool Tile2::setTiles(Tile* tiles[], const char* nume)
{
	
	int z = 0;

	bool tilesLoaded = true;

	std::cout << "INTRAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";
	int x = 0, y = 0;


	std::ifstream map(nume);

	

	if (map.fail())
	{
		std::cout << "Eroare la HARTA";
		tilesLoaded = false;
	}
	else
	{ 

		for (int i = 0; i < 1200; ++i)
		{

			int tileType = -1;


			map >> tileType;



			if (map.fail())
			{

				std::cout << "Error la HARTA";
				tilesLoaded = false;
				break;
			}

			if ((tileType >= 0) && (tileType < 3))
			{

				tiles[i] = new Tile2(x, y, tileType);

			}
			else
			{

				std::cout << "Eroare la GRESIE";
				tilesLoaded = false;
				break;
			}

			x += LATIME;
			if (x >= LEVEL_WIDTH)
			{
				x = 0;
				y += INALTIME;
				z++;


			}

		}


		if (tilesLoaded)
		{
			TileClips[ZID].x = 0;
			TileClips[ZID].y = 0;
			TileClips[ZID].w = LATIME;
			TileClips[ZID].h = INALTIME;

			TileClips[IARBA].x = 32;
			TileClips[IARBA].y = 0;
			TileClips[IARBA].w = LATIME;
			TileClips[IARBA].h = INALTIME;

			TileClips[pamant].x = 64;
			TileClips[pamant].y = 0;
			TileClips[pamant].w = LATIME;
			TileClips[pamant].h = INALTIME;

		}
	}

	map.close();
	return tilesLoaded;
}

bool Tile2::loadMedia(Tile* tiles[], const char* nume, const char* jos)
{
	//std::cout << nume << std::endl;

	bool success = true;

	if (!(TileTexture = Texturi::incaracaTextura(jos)))
	{
		std::cout << "Eroare la textura";
		success = false;
	}

	if (!(Tile2::setTiles(tiles, nume)))
	{
		std::cout << "Eroare la incaracea hartii";
		success = false;
	}
	return success;


}

bool Tile3::setTiles(Tile* tiles[], const char* nume)
{

	
	bool tilesLoaded = true;

	
	int x = 0, y = 0;


	std::ifstream map(nume);

	

	if (map.fail())
	{
		std::cout << "Eroare la HARTA";
		tilesLoaded = false;
	}
	else
	{

		for (int i = 0; i < 1200; ++i)
		{

			int tileType = -1;


			map >> tileType;



			if (map.fail())
			{

				std::cout << "Error la HARTA";
				tilesLoaded = false;
				break;
			}

			if ((tileType >= 0) && (tileType < 3 ))
			{

				tiles[i] = new Tile3(x, y, tileType);

			}
			else
			{

				std::cout << "Eroare la GRESIE";
				tilesLoaded = false;
				break;
			}

			x += LATIME;
			if (x >= LEVEL_WIDTH)
			{
				x = 0;
				y += INALTIME;
				


			}

		}


		if (tilesLoaded)
		{
			
			TileClips[ZID].x = 0;
			TileClips[ZID].y = 0;
			TileClips[ZID].w = LATIME;
			TileClips[ZID].h = INALTIME;

			TileClips[IARBA].x = 32;
			TileClips[IARBA].y = 0;
			TileClips[IARBA].w = LATIME;
			TileClips[IARBA].h = INALTIME;

			TileClips[pamant].x = 64;
			TileClips[pamant].y = 0;
			TileClips[pamant].w = LATIME;
			TileClips[pamant].h = INALTIME;




		}
	}

	map.close();
	return tilesLoaded;
}

bool Tile3::loadMedia(Tile* tiles[], const char* nume, const char* jos)
{
	//std::cout << nume << std::endl;

	bool success = true;

	if (!(TileTexture = Texturi::incaracaTextura(jos)))
	{
		std::cout << "Eroare la textura";
		success = false;
	}

	if (!(Tile3::setTiles(tiles, nume)))
	{
		std::cout << "Eroare la incaracea hartii";
		success = false;
	}
	return success;


}
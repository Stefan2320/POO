#include "Coliziune.h"


bool Coliziune::ciocnireRect(SDL_Rect a, SDL_Rect b)
{
	if (a.w != 800) {
		b.w = 20;
		b.h = 20;
	}

	if ((a.x + a.w) < b.x || a.x > (b.x + b.w) || (a.y + a.h) < b.y || a.y > (b.y + b.h))
		return 0;
	else
	{
		return 1;
	}
}


Punct Coliziune::distanta(int x1,int y1,int x2,int y2)
{
	Punct lungime;
	lungime.x = x1 - x2;
	lungime.y = y1 - y2;
	
	return lungime;
}


int Coliziune::touchesWall(SDL_Rect box, Tile* tiles[])
{


	for (int i = 0; i < 1200; ++i)
	{


		if (tiles[i]->getType() == 00)
		{

			if (Coliziune::ciocnireRect(box, tiles[i]->getPozitie()) != 0)
			{
				//SDL_Rect temp;
				//temp = tiles[i]->getPozitie();

				return  i;
			}



		}
		else if (tiles[i]->getType() == 02)
		{
			if (Coliziune::ciocnireRect(box, tiles[i]->getPozitie()) != 0)
			{
				//SDL_Rect temp;
				//temp = tiles[i]->getPozitie();

				return  -1;
			}
		}
		
	}


	return 0;
}
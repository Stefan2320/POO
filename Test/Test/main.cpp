#include <SDL.h>
#include <stdio.h>
#include "joc.h"
#include "menu.h"


int main(int argc, char* args[])
{	
	const int FPS = 60;
	const int frameDelay = 50;

	Uint32  frameStart;
	int frameTime;

	

	Joc* joc = nullptr;
	joc = new Joc();

	joc->init("MENU", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 640, false);
	
	

	while (joc->ruleaza()) {

		
		frameStart = SDL_GetTicks();
		joc->ocupareEvenimente();
		joc->update();
		joc->randare();

		frameTime = SDL_GetTicks() - frameStart;
		if (frameDelay > frameTime)
			SDL_Delay(frameDelay - frameTime);
	}

	joc->clean(); 

	return 0;
}
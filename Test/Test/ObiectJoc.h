#pragma once
#include "joc.h"
#include "SDL_image.h"
#include <iostream>
extern int k;


class ObiectJoc {
public:

	
	ObiectJoc(const char* sheet, int x, int y);
	virtual ~ObiectJoc() { objText = nullptr; };
	virtual void SHoot(int Mx, int My, int x, int y) {};
	virtual void Update(Tile* tiles[]) {};
	virtual void Render( SDL_Rect camera);
	virtual void setPara(int x, int y) {};
	virtual SDL_Texture* getText(){return objText;}
	virtual SDL_Rect getRect() {return destRect;}
	virtual void setSterge(int x) {};
	virtual int getSterge(){return sterge;}
	virtual void schimba() {};
	virtual  int getNumar() { return 1; }
	virtual int getNumarTotal() { return 1; }
	virtual void setNumarTotal(int x) {  }
	virtual void setLvl(int x) {}
	virtual void setGloante(int x) {}
protected:
	SDL_Texture* objText;
	SDL_Rect srcRecT, destRect;
	int xpos;
	int ypos;
	int sterge;
};


class ObiectJocPlayer :public ObiectJoc {

public:
	ObiectJocPlayer(const char* sheet, int x, int y, int wObj, int hObj) :ObiectJoc(sheet, x, y)
	{
		sterge = false;
		wO = wObj;
		hO = hObj;
	}

	void setPara(int x, int y)
	{
		xpos = x;
		ypos = y;
	}
	void Update(Tile* tiles[]);
	void Render( SDL_Rect camera);
	void SHoot(int Mx, int My, int x, int y);
	SDL_Rect getRect() {

		return destRect;
	}

	void setSterge(int x)
	{
		
		sterge = x;
	}

	int getSterge()
	{
		return sterge;
	}
	~ObiectJocPlayer() {};
private:
	int wO, hO;
	int pozix, poziy;
	float copie = 0;

};
class numarGloante:public ObiectJoc {
public:
	numarGloante(const char* sheet, int x, int y, int gloante,int caz) :ObiectJoc(sheet, x, y) {
		
		nrGloante = gloante;
		copie = gloante;
		 lvl = caz;
		std::cout << lvl;
		q = 3;
		v = 6;
		l = 0;
	}
	void schimba ();
	 int getNumar() { return nrGloante; }
	 void setLvl(int x) { lvl = x; }
	 void setGloante(int x) { nrGloante = x; }
	 void setNumarTotal(int x) {  copie = x; }
	 int getNumarTotal() { return copie; }
	 ~numarGloante() {};
private:
	int copie;
	int nrGloante;
	int lvl = 0;
	int q;
	int v;
	int l;
};
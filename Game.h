#pragma once
#include "config.h"



class Game
{
public:
	Game();
	~Game();

	void setup(play1* pla1, play2* pla2, Handle* ring, Num* x1, Num* x2, Num* num);

	void draw();
	void player1();
	void player2();
	void setup(play1* pla1, play2* pla2, Handle* ring,Num* cx1);
	void move1();
	//void move2();
	void hit1light();
	void hit1left();
	void hit2light();
	void hit2left();
	void hit3();
	void gade1();
	void gade2();
	void grobe1();
	void grobe2();
	void sounds();
	void sound2();
private:
	play1* pla1;
	play2* pla2;

	Handle* ring;
	Num* x1;
	Num* x2;
	Num* num;
	Num* cx1;
};


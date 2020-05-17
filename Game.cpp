#include "Game.h"
#include "DxLib.h"
#include "config.h"

Game::Game()
{
}
Game::~Game()
{
}
int point = 0;
int xx1 = 65;
int xx2 = 420;

int cx2 = 0;
int stime1 = 0;
int stime2 = 0;

int gr1;
int gr2;

void Game::setup(play1* pla1, play2* pla2, Handle* ring, Num* x1,Num* x2, Num* num)
{
	this->pla1 = pla1;
	this->pla2 =pla2;
	this->ring = ring;
	this->x1 = x1;
	this->x2 = x2;
	this->num = num;
	

	pla1->pla1 = LoadGraph("img/test3.png"); // 画像のロード
	pla2->pla2 = LoadGraph("img/chara3.png"); // 画像のロード
	ring->ring = LoadGraph("img/リング2.jpg");
	gr1 = LoadGraph("img/now.png");
	gr2= LoadGraph("img/grobe.png");
}


void Game::sounds()
{
	num->sound = 2;
	PlayMusic("battle_bgm.mp3", DX_PLAYTYPE_LOOP); //test.wavのバックグラウンド演奏
	


}

void Game::sound2()
{
	
	num->sound = 3;
	PlaySound("final_bgm.mp3", DX_PLAYTYPE_BACK); //test.wavのバックグラウンド演奏

}




void Game::draw()
{
	DrawExtendGraph(0, 0, 330, 580, ring->ring, TRUE);
	DrawExtendGraph(330, 0,640, 580, ring->ring, TRUE);
}


void Game::grobe1()
{

	DrawExtendGraph(350, 200, 450, 300, gr1, TRUE);
}

void Game::grobe2()
{

	DrawExtendGraph(470, 200, 570, 300, gr2, TRUE);
}


void Game::player1()
{
	DrawBox(10, 10, 300, 30, GetColor(0, 255, 255), FALSE);//メーターの枠を描画
	DrawBox(10, 10, 300-num->hp1, 30, GetColor(0, 255, 255), TRUE);//メーターの中身を描画

	DrawExtendGraph(xx1, 150, xx1+100, 400, pla1->pla1, TRUE);

}


void Game::player2()
{

	DrawBox(340, 10, 630, 30, GetColor(200, 200, 255), FALSE);//メーターの枠を描画
	DrawBox(340+num->hp2, 10, 630, 30, GetColor(200, 200, 255), TRUE);//メーターの中身を描画

	DrawExtendGraph(xx2, 150, xx2+100, 400, pla2->pla2, TRUE);


}


void Game::move1()
{
	point++;

	if (point%2==1)             //player1の位置を変える
	{
		    x1->x1 = 1;
	  		xx1 = xx1 + 90;
			num->cx1 = 1 ;
	
	}

	if (point % 2 == 0)
	{
		x1->x1 = 0;
		xx1 = xx1 - 90;
		num->cx1 = 0;

	}
}





/*
void Game::move2()
{
	if (CheckHitKey(KEY_INPUT_K) == 1)       //player2の左ガード
	{
		if (CheckHitKey(KEY_INPUT_Z) == 1 && cx2 != -1) {
			x2->x2--;
			xx2 = xx2 - 50;
			cx2 = cx2 - 1;
			stime2 = GetNowCount();
		}
	}


	if (CheckHitKey(KEY_INPUT_L) == 1)       //player2の右ガード
	{
		if (CheckHitKey(KEY_INPUT_X) == 1 && cx2 != 1) {
			x2->x2++;
			xx2 = xx2 + 50;
			cx2 = cx2 + 1;
			stime2 = GetNowCount();
		}
	}




	if (GetNowCount() - stime2 > 1000 && stime2 != 0){          //時間で中央に戻る

		if (cx2 == -1){

			xx2 = xx2 + 50;
			cx2 = 0;
			stime2 = 0;

		}

		if (cx2 == 1){

			xx2 = xx2 - 50;
			cx2 = 0;
			stime2 = 0;

		}

	}
	
}
*/    
// player2 ガードなし


void Game::hit1light(){    //p2右パンチ

		num->hp1 = num->hp1 + 40;	

		if (num->hp1 > 290)
		{
			num->c = 6;
			num->hp1 = 0;
			num->hp2 = 290;
		}

}


void Game::hit2light(){   //p1右パンチ



	if (cx2 != -1) {

		num->hp2 = num->hp2 + 30;

		if (CheckHitKey(KEY_INPUT_R) == 1)
			num->hp2 = num->hp2 + 20;

		if (num->hp2 > 290)
		{
			num->c = 5;
			num->hp1 = 0;
			num->hp2 = 0;
		}
	}
}


void Game::hit1left()   //p2左パンチ
{
	num->con2 = 1;

	num->hp1 = num->hp1 + 40;

	if (num->hp1 > 290)
	{
		num->c = 6;
		num->hp1 = 0;
		num->hp2 = 0;
	}
}


void Game::hit2left(){     //p1i左パンチ

	if (cx2 != 1){

		num->hp2 = num->hp2 + 30;

	

		if (num->hp2 > 290)

		{
			num->c = 5;
			num->hp1 = 0;
			num->hp2 = 0;
		}
	}
}

void Game::hit3(){
	if (cx2 != 1){

		num->hp2= num->hp2 + 40;

		if (num->hp2 > 290)
		{
			num->c = 5;
			num->hp1 = 0;
			num->hp2 = 0;
		}
	}


}





void Game::gade1(){                         //ガード処理

	num->hp1 = num->hp1 - 30;

}

void Game::gade2(){                    

	num->hp2 = num->hp2 - 15;


}

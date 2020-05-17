#include "Finish.h"
#include "DxLib.h"
#include "config.h"


unsigned int b,l;

Finish::Finish()
{

}

Finish::~Finish()
{
}


void Finish::setup(Handle* handle, Num* num)
{
	this->handle = handle;
	this->num = num;
	handle->hand = LoadGraph("img/finish.png"); // 画像のロード

}


void Finish::draw()
{
	


	// 白色の値を取得
	b = GetColor(255, 255, 255);
	l = GetColor(255, 50, 55);
	//DrawGraph(0, 200, handle->handle1, TRUE); //画像の描画
	DrawExtendGraph(0, 0, 630, 530, handle->hand, TRUE);


	DrawString(300, 420 - 32, "Vでタイトル", b);

	if (CheckHitKey(KEY_INPUT_V) == 1) {
		num->c=0;

		num->sound = 0;                                      //リセット
		num->hp2 = 0;
		
	}


	if (num->c == 5)
	{
		DrawString(200, 200, "WINNER  PLAYER1", l);                //勝者を表示
	}

	if (num->c == 6)
	{
		DrawString(200, 200, "WINNER  PLAYER2", l);
	}



}
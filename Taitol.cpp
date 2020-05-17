#include "Taitol.h"
#include "DxLib.h"
#include "config.h"


unsigned int w;



Taitol::Taitol()
{
}


Taitol::~Taitol()
{
}

void Taitol::setup(Handle* handle,Num* num)
{
	this->handle = handle;
	this->num = num;
	handle->handle1 = LoadGraph("img/title_1.png"); // 画像のロード

}



void Taitol::draw()
{
	// 白色の値を取得
	w = GetColor(0, 255, 255);
	
	//DrawGraph(0, 200, handle->handle1, TRUE); //画像の描画
	DrawExtendGraph(0, 0,630,530, handle->handle1, TRUE);


	DrawString(300, 420 , "Enterで説明画面", w);

	num->sound = 10;

	if (CheckHitKey(KEY_INPUT_RETURN) == 1){
		num->c++;
		
	}




}
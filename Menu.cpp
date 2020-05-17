#include "Menu.h"
#include "DxLib.h"
#include "config.h"


unsigned int Cr;



Menu::Menu()
{
	
}


Menu::~Menu()
{
}

void Menu::setup(Handle* handle, Num* num)
{
	this->handle = handle;
	this->num = num;
	handle->handle2 = LoadGraph("img/manual.png"); // 画像のロード

}


void Menu::draw()
{
	// 白色の値を取得
	Cr = GetColor(0, 255, 255);

	//DrawGraph(0, 200, handle->handle1, TRUE); //画像の描画
	DrawExtendGraph(0, 0, 600, 480, handle->handle2, TRUE);


	DrawString(400, 420 - 32, "Backspaceでゲーム", Cr);

	if (CheckHitKey(KEY_INPUT_BACK) == 1){
		num->c++;
		num->sound = 1;
	}
}


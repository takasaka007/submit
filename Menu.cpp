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
	handle->handle2 = LoadGraph("img/manual.png"); // �摜�̃��[�h

}


void Menu::draw()
{
	// ���F�̒l���擾
	Cr = GetColor(0, 255, 255);

	//DrawGraph(0, 200, handle->handle1, TRUE); //�摜�̕`��
	DrawExtendGraph(0, 0, 600, 480, handle->handle2, TRUE);


	DrawString(400, 420 - 32, "Backspace�ŃQ�[��", Cr);

	if (CheckHitKey(KEY_INPUT_BACK) == 1){
		num->c++;
		num->sound = 1;
	}
}


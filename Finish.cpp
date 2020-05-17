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
	handle->hand = LoadGraph("img/finish.png"); // �摜�̃��[�h

}


void Finish::draw()
{
	


	// ���F�̒l���擾
	b = GetColor(255, 255, 255);
	l = GetColor(255, 50, 55);
	//DrawGraph(0, 200, handle->handle1, TRUE); //�摜�̕`��
	DrawExtendGraph(0, 0, 630, 530, handle->hand, TRUE);


	DrawString(300, 420 - 32, "V�Ń^�C�g��", b);

	if (CheckHitKey(KEY_INPUT_V) == 1) {
		num->c=0;

		num->sound = 0;                                      //���Z�b�g
		num->hp2 = 0;
		
	}


	if (num->c == 5)
	{
		DrawString(200, 200, "WINNER  PLAYER1", l);                //���҂�\��
	}

	if (num->c == 6)
	{
		DrawString(200, 200, "WINNER  PLAYER2", l);
	}



}
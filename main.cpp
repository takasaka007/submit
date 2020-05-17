#include "DxLib.h"
#include "Menu.h" //Player���W���[���̊֐����g����悤�ɂ���
#include "Game.h"
#include "Taitol.h"
#include "config.h"
#include "Finish.h"
#include "erslib19.h"


#define BUFSIZE 5000



int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK);

	Game* G = new Game();
	Menu* M = new Menu();
	Taitol* T = new Taitol();
	Finish* F = new Finish();

	Num num;
	Num x1;
	Num x2;
	Num cx1;
	Handle handle;
	Handle ring;
	play1 pla1;
	play2 pla2;
	

	int timecon1 = 0;
	int timecon2 = 0;
	int timej1 = 0;
	int timej2 = 0;
	int tpa1 = 0;
	int tpa2 = 0;
	int tpacon1 = 0;
	int tpacon2 = 0;
	int pt = 0;
	int ga = 0;


	


	int com = 1, r;
	char buf[1000];
	r = ERS_Open(com, BUFSIZE, BUFSIZE);    // rs232c�̃|�[�g���I�[�v������
	ERS_Config(com, ERS_9600);		// �ʐM���x��9600bps�ɂ���(�f�t�H���g)


	F->setup(&handle, &num);
	M->setup(&handle, &num);
	T->setup(&handle, &num);
	G->setup(&pla1, &pla2, &ring, &x1, &x2, &num);

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{

		if (num.sound == 0)
		{
            PlaySound("title_bgm.mp3", DX_PLAYTYPE_LOOP);   //�^�C�g���E�����@���y�Đ�
		}
		


		if (num.sound == 1)
		{
			StopSound();           
			G->sounds();
		}

		


			if (num.c == 0)
			{
				T->draw();
			}

			if (num.c == 1)
			{
				M->draw();
			}


			if (num.c == 2)
			{


				r = ERS_Recv(com, buf, 1);
				r = ERS_Send(com, buf, 1);	// ��M�f�[�^��Ԃ�

				G->draw();
				G->player1();
				G->player2();

				if (buf[0] == 'S')      //player�P�̃K�[�h
				{
					ga = 1;
				}

				if (buf[0] == 'T')
				{
					ga = 0;
				}


				if (GetNowCount() - pt > 500)
				{
					if (buf[0] == 'A')
					{

						G->move1();

						pt = GetNowCount();

						timej1 = 1;
						timecon1 = GetNowCount();
					}
				}





				if (GetNowCount() - timecon1 > 500 && timecon1 != 0) {      //p1�p���`�C���^�[�o���J�E���g

					timej1 = 0;
					timecon1 = 0;
				}


				if (timej1 == 0)                                     //p1�p���`�C���^�[�o������
				{

					if (buf[0] == 'W')            //player1�̉E�p���`����
					{
						timej1 = 1;
						timecon1 = GetNowCount();

						PlaySound("punch_se.mp3", DX_PLAYTYPE_BACK); //test.wav�̃o�b�N�O���E���h���t
						G->hit2light();
						

						if (CheckHitKey(KEY_INPUT_N) == 1 && num.x2 != -1)       //player2�̉E�K�[�h
						{
							G->gade2();
						}


					}


					if (buf[0] == 'Q')            //player1�̍��p���`����
					{
						timej1 = 1;
						timecon1 = GetNowCount();

						PlaySound("punch_se.mp3", DX_PLAYTYPE_BACK); //test.wav�̃o�b�N�O���E���h���t
						G->hit2left();
						

						if (CheckHitKey(KEY_INPUT_C) == 1 && num.x2 != 1)    //player2�̍��K�[�h
						{
							G->gade2();
						}

					}


					if (buf[0] == 'Z')            //player1�̍��p���`����
					{
						timej1 = 1;
						timecon1 = GetNowCount();

						PlaySound("punch_se.mp3", DX_PLAYTYPE_BACK); //test.wav�̃o�b�N�O���E���h���t
						G->hit3();
					

						if (CheckHitKey(KEY_INPUT_C) == 1 && num.x2 != 1)    //player2�̍��K�[�h
						{
							G->gade2();
						}

					}


				}







				if (GetNowCount() - timecon2 > 700 && timecon2 != 0) {      //p2�p���`�C���^�[�o���J�E���g

					timej2 = 0;
					timecon2 = 0;
				}



				if (CheckHitKey(KEY_INPUT_N) != 1)           //�E�K�[�h���ĂȂ���
				{
					if (CheckHitKey(KEY_INPUT_I) == 1 || tpacon1 == 1)              //player2�̉E�p���`����
					{

						if (tpacon1 == 0) {
							tpa1 = GetNowCount();                    //�p���`�������ԃZ�b�g
							tpacon1 = 1;
						}

						if (GetNowCount() - tpa1 > 500)
						{

							if (timej2 == 0)                               //p2�p���`�C���^�[�o������
							{
								timej2 = 1;
								timecon2 = GetNowCount();

								if (num.cx1 != 0)
								{

									G->hit1light();

									if (ga ==1)         //player�P�̃K�[�h
									{
										G->gade1();
									}
								}
							}

							tpa1 = 0;
							tpacon1 = 0;
						}

						else
						{
							G->grobe2();
						}

					}
				}

				if (CheckHitKey(KEY_INPUT_C) != 1)                 //���K�[�h���ĂȂ���
				{
					if (CheckHitKey(KEY_INPUT_E) == 1 || tpacon2 == 1)                //player2�̍��p���`����
					{
						if (tpacon2 == 0) {
							tpa2 = GetNowCount();                    //�p���`��������
							tpacon2 = 1;
						}

						if (GetNowCount() - tpa2 > 500)
						{
							if (timej2 == 0)                               //p2�p���`�C���^�[�o������
							{
								timej2 = 1;
								timecon2 = GetNowCount();


								if (num.cx1 != 1)
								{
									G->hit1left();

									if (ga == 1)         //player�P�̃K�[�h
									{
										G->gade1();
									}
								}
							}

							tpa2 = 0;
							tpacon2 = 0;
						}

						else
						{
							G->grobe1();
						}

					}

				}



			}

			if (num.c >=5)
			{
				F->draw();

				StopMusic();

				if (num.sound==2)

				     G->sound2();
			}


			if (CheckHitKey(KEY_INPUT_ESCAPE) != 0)
			{
				DxLib_End();
			}


		

	}
	return 0;
}

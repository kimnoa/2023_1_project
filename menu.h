#pragma once
#include <raylib.h>
#include <raymath.h>
#include <cmath>
#include <math.h>
#include <iostream>

using namespace std;

enum class Menu
{
	MENU , //�޴� ȭ��
	PLAY , //���� ����
	RANK , //������
	EXIT //����
	//CHANGE
};

//���� ���¸� �����ϴ� ����ü
struct Status
{
	int pressed = 0; //���콺 Ŭ�� ���� - ������ 1

	Vector2 pos = { 0,0 }; //Ŀ�� ��ġ

	int now = 0; //�޴����� ���� ��ư�� �����ϴ� ����

	Menu check = Menu::MENU; //���� �۵��� �Լ��� ������ ����
};

//������ x,y ������ �����ϴ� ����ü
struct Box_xy
{
	float x1;
	float y1;
	
	float x2;
	float y2;

};
	
//�޴� ȭ���� ū �簢���� �׸��� �Լ�
void DrawMainBox()
{

	DrawRectangle(200, 100, 1200, 300, BROWN); //�簢�� ���
	DrawText("GAME MENU NAME", 300, 200, 100, GRAY); //�ؽ�Ʈ ���
}

//�޴� �ϴܿ� play, rank, exit ��ư�� �׸��� ��
void DrawButton(Status* S)
{

	float start_position_x = 300;
	float start_position_y = 500;
	float gap = 400;

	//�ڽ� ���� �Է� �� �׸���

	for (int i = 0; i < 3; i++)
	{
		S[i].pos = { (start_position_x + i * gap), start_position_y };

		DrawRectangle(S[i].pos.x, S[i].pos.y, 200, 200, GRAY);
	}

}


void check_state(Status* S)
{
	//���� ����� �� â �Ǵ�
	switch (S->now)
	{
	case 1:
		S->check = Menu::PLAY;
		break;

	case 2:
		S->check = Menu::RANK;
		break;

	case 3:
		S->check = Menu::EXIT;
		break;

	default:
		S->check = Menu::MENU;

	}
}


//���콺 Ŭ���� ó���ϴ� �Լ�
void MouseClick(Status* S)
{
	float start_position_x = 300;
	float start_position_y = 500;
	float gap = 400;


	//���콺 Ŭ�� Ȯ��
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && !S->pressed) //���� ���콺 ������
		S->pressed++;

	//���콺 ��ġ �Ǵ�
	if (S->pressed)
	{
		S->pos = GetMousePosition(); //Ŀ�� ��ġ �Է�

		//Ŀ�� ��ġ �Ǵ�
		for (int i = 0; i < 3; i++)
		{
			if (S->pos.x > (start_position_x + i * gap) && S->pos.x < (start_position_x + i * gap + 200) && S->pos.y > start_position_y && S->pos.y < (start_position_y + 200))
			{
				S->now = i + 1; //play = 1, rank = 2, exit = 3
				break;
			}

			//�ٸ� ���� �������� ����

		}

		S->pressed--; //�ٽ� 0���� ����

		check_state(S);
	}

}


//�ؽ��ĸ� ������ �Լ�
void Puttexture() 
{
	Texture2D slingshot = LoadTexture("����.png");


}







//������ ��ǥ�� �׽�Ʈ �ϴ� �Լ�
void Drawdot(int wx, int wy)
{
	for (int r = 1; r < (wy/100); r++)
		for (int c = 1; c < (wx/100); c++)
			DrawCircle(100 * c, 100 * r, 2.0f, BLACK);
}



//////////////////////////////////////////////////////////////

// �Ʒ����ʹ� PLAY��

struct play {
	int left_ball = 5, cursor = 0, play_or_mute = 0, music_number = 0;
	int bump = 0; // variable for check that ball bumps into target. 0 = not bump yet, 1 = bump, 2 = game clear
	int hp = 100;
	float angle = 30 * 3.1415926536 / 180, velocity = 10;
	float object_x = 800, object_y = 500;
	float target_x = 1150, target_y = 500;
	float time = 0, distance = 0, height = 0;
	float gravity = 9.80665;
	Vector2 ballPosition = { 0, 0 };
	Vector2 Shoot_Position = { 30, 700 };

	Music music;
	Music music2;

	Image image;
	Image image_music;
	Image image_mute;
	Image image_object;
	Image image_target;

	Texture2D texture;
	Texture2D texture_music;
	Texture2D texture_mute;
	Texture2D texture_object;
	Texture2D texture_target;

};

play* play_init();

void music_control(play* PL);


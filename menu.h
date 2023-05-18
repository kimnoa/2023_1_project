#pragma once
#include <raylib.h>
#include <raymath.h>
#include <cmath>
#include <math.h>
#include <iostream>

using namespace std;

enum class Menu
{
	MENU , //메뉴 화면
	PLAY , //게임 시작
	RANK , //점수판
	EXIT //종료
	//CHANGE
};

//현재 상태를 저장하는 구조체
struct Status
{
	int pressed = 0; //마우스 클릭 여부 - 눌리면 1

	Vector2 pos = { 0,0 }; //커서 위치

	int now = 0; //메뉴에서 누른 버튼을 저장하는 변수

	Menu check = Menu::MENU; //현재 작동할 함수를 선택할 변수
};

//상자의 x,y 범위를 저장하는 구조체
struct Box_xy
{
	float x1;
	float y1;
	
	float x2;
	float y2;

};
	
//메뉴 화면의 큰 사각형을 그리는 함수
void DrawMainBox()
{

	DrawRectangle(200, 100, 1200, 300, BROWN); //사각형 출력
	DrawText("GAME MENU NAME", 300, 200, 100, GRAY); //텍스트 출력
}

//메뉴 하단에 play, rank, exit 버튼을 그리는 함
void DrawButton(Status* S)
{

	float start_position_x = 300;
	float start_position_y = 500;
	float gap = 400;

	//박스 정보 입력 및 그리기

	for (int i = 0; i < 3; i++)
	{
		S[i].pos = { (start_position_x + i * gap), start_position_y };

		DrawRectangle(S[i].pos.x, S[i].pos.y, 200, 200, GRAY);
	}

}


void check_state(Status* S)
{
	//현재 열어야 할 창 판단
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


//마우스 클릭을 처리하는 함수
void MouseClick(Status* S)
{
	float start_position_x = 300;
	float start_position_y = 500;
	float gap = 400;


	//마우스 클릭 확인
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && !S->pressed) //왼쪽 마우스 눌리면
		S->pressed++;

	//마우스 위치 판단
	if (S->pressed)
	{
		S->pos = GetMousePosition(); //커서 위치 입력

		//커서 위치 판단
		for (int i = 0; i < 3; i++)
		{
			if (S->pos.x > (start_position_x + i * gap) && S->pos.x < (start_position_x + i * gap + 200) && S->pos.y > start_position_y && S->pos.y < (start_position_y + 200))
			{
				S->now = i + 1; //play = 1, rank = 2, exit = 3
				break;
			}

			//다른 곳을 눌렀으면 무시

		}

		S->pressed--; //다시 0으로 변경

		check_state(S);
	}

}


//텍스쳐를 입히는 함수
void Puttexture() 
{
	Texture2D slingshot = LoadTexture("새총.png");


}







//파일의 좌표를 테스트 하는 함수
void Drawdot(int wx, int wy)
{
	for (int r = 1; r < (wy/100); r++)
		for (int c = 1; c < (wx/100); c++)
			DrawCircle(100 * c, 100 * r, 2.0f, BLACK);
}



//////////////////////////////////////////////////////////////

// 아래부터는 PLAY용

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


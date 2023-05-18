#include "menu.h"



    int main(void)
    {
        //화면 초기화
        const int screenWidth = 1600;
        const int screenHeight = 900;

        //창 초기화
        InitWindow(screenWidth, screenHeight, "Slingshot Test");

        SetTargetFPS(60);

         

        //게임 초기화

        Status* S = new Status[1]; //현재 상태를 저장할 구조체 할당

        play* PL = play_init(); //변수 초기화 - 창운

         
        while (!WindowShouldClose())
        {
            music_control(PL);

                 
            //게임 랜더링 시작
            BeginDrawing();
                 

                if(S->check == Menu::MENU)
                {                
                    //배경색
                    ClearBackground(RAYWHITE);

                    //아래는 랜더링 코드
                    DrawMainBox();

                    DrawButton(S);

                    Drawdot(screenWidth, screenHeight);



                }

                else if (S->check == Menu::PLAY)
                {
                    //아래부터 창운이 코드
                    ClearBackground(RAYWHITE);
                    DrawTexture(PL->texture, 0, 0, WHITE);




                }

                else if (S->check == Menu::RANK)
                {

                    //배경색
                    ClearBackground(YELLOW);

                    DrawButton(S);

                   // MouseClick(S);

                }

                else if (S->check == Menu::EXIT)
                {
                    break;
                }

            
                 
            //랜더링 종료
            EndDrawing();

            MouseClick(S);
        }

        //메모리 반환
        delete[] S;


        //창 종료
        CloseWindow();

        return 0;
    }


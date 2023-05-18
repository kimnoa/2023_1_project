#include "menu.h"



    int main(void)
    {
        //ȭ�� �ʱ�ȭ
        const int screenWidth = 1600;
        const int screenHeight = 900;

        //â �ʱ�ȭ
        InitWindow(screenWidth, screenHeight, "Slingshot Test");

        SetTargetFPS(60);

         

        //���� �ʱ�ȭ

        Status* S = new Status[1]; //���� ���¸� ������ ����ü �Ҵ�

        play* PL = play_init(); //���� �ʱ�ȭ - â��

         
        while (!WindowShouldClose())
        {
            music_control(PL);

                 
            //���� ������ ����
            BeginDrawing();
                 

                if(S->check == Menu::MENU)
                {                
                    //����
                    ClearBackground(RAYWHITE);

                    //�Ʒ��� ������ �ڵ�
                    DrawMainBox();

                    DrawButton(S);

                    Drawdot(screenWidth, screenHeight);



                }

                else if (S->check == Menu::PLAY)
                {
                    //�Ʒ����� â���� �ڵ�
                    ClearBackground(RAYWHITE);
                    DrawTexture(PL->texture, 0, 0, WHITE);




                }

                else if (S->check == Menu::RANK)
                {

                    //����
                    ClearBackground(YELLOW);

                    DrawButton(S);

                   // MouseClick(S);

                }

                else if (S->check == Menu::EXIT)
                {
                    break;
                }

            
                 
            //������ ����
            EndDrawing();

            MouseClick(S);
        }

        //�޸� ��ȯ
        delete[] S;


        //â ����
        CloseWindow();

        return 0;
    }


#include"raylib.h"
#include<stdio.h>

#define screenWidth     800
#define screenHeight    450
#define FRAME_SPEED     50


int main()
{

    int gamestate = 1;
    float ground_pos_x = 344;
    float ground_pos_y = 388;
    float ball_pos_y = 200;
    float ball_pos_x = 400;
    float ball_physic = 0;
    float physis = 0.284;
    float wight_physis = 0;
    int pocet_cihel = 144;
    int reserve = 0;
    int cihly1[pocet_cihel];
    int cihly2[pocet_cihel];
    int a = 40;
    int b = 20;
    for (int i = 0; i < pocet_cihel; i++) {
        a += 20;
        if (i % 4 ==0) {
            b += 20;
            a = 40;
        }
        cihly1[i] = b;
        cihly2[i] = a;
    }

    InitWindow(screenWidth, screenHeight, "Ping Pong Game");

    SetTargetFPS(FRAME_SPEED);

    while (!WindowShouldClose())

    {
        
        if (gamestate == 0)
        {
            BeginDrawing();

            if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) {
                if (ground_pos_x<screenWidth -248){ground_pos_x += 10;}
            }
            
            if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) {
                if (ground_pos_x > 0) {ground_pos_x -= 10;}
            }

            if (ball_pos_y < ground_pos_y - 10 && ball_pos_y > 15 || ball_pos_x <= ground_pos_x || ball_pos_x >= ground_pos_x + 248) {
                ball_physic += physis;
                ball_pos_y += ball_physic;
            }
            
            else  {
                ball_physic = -ball_physic;
                ball_physic -= physis;
                ball_pos_y += ball_physic;
            }

            if (ball_pos_x >= ground_pos_x && ball_pos_x <= ground_pos_x + 248 && ball_pos_y >= ground_pos_y - 10 && ball_pos_y <= ground_pos_y) {
                if (ball_pos_x > ground_pos_x +124) {wight_physis += 0.889;}
                else if (ball_pos_x < ground_pos_x +124) {wight_physis -= 0.889;}
            }
            if (ball_pos_x <= 0 || ball_pos_x >= 800) {wight_physis = -wight_physis;}
            ball_pos_x += wight_physis;
            
            if (ball_pos_y > 450) {
                gamestate = 2;
            }

            if (ball_physic > 30) {
                ball_physic = 30;
            }
            if (ball_physic < -30) {
                ball_physic = -30;
            }

            ClearBackground(BLACK);

            DrawCircle(ball_pos_x, ball_pos_y, 10, WHITE); //koule
            DrawRectangle(ground_pos_x, ground_pos_y, 248, 10, WHITE); //palka

            for (int i = 0; i < pocet_cihel; i++) {
                    if (ball_pos_x >= cihly1[i] + reserve && ball_pos_x <= cihly1[i] + 14 - reserve &&
                        ball_pos_y >= cihly2[i] + reserve && ball_pos_y <= cihly2[i] + 14 - reserve) {
                        cihly1[i] = -100;
                        cihly2[i] = -100;
                        ball_physic = -ball_physic;
}
                else {

                    DrawRectangle(cihly1[i], cihly2[i], 14, 14, WHITE); // cihly    
                    }                  
            
            }

            EndDrawing();
            


        }

        else if (gamestate == 1){
            BeginDrawing();
            ClearBackground(BLACK);
            DrawText("Welcome to Ping Pong Game\nPress [ENTER] to start the game\n\nmade Jakub Jansa 2025 in Raylib\nAll rights reserved ©", screenWidth / 2- 100,screenHeight / 2 , 20, WHITE);
            EndDrawing();
            if (IsKeyPressed(KEY_ENTER)){
                gamestate = 0;
            }
        }
        
        else if(gamestate == 2) {
            BeginDrawing();
            ClearBackground(BLACK);
            DrawText("You lost\nPress [ENTER] to restart the game", screenWidth / 2- 100,screenHeight / 2 , 20, WHITE);
            EndDrawing();
            if (IsKeyPressed(KEY_ENTER)){
                gamestate = 0;
                ball_pos_y = 200;
                ball_pos_x = 400;
                ball_physic = 0;
                wight_physis = 0;
                ground_pos_x = 344;
                ground_pos_y = 388;
                a = 40;
                b = 20;
                for (int i = 0; i < pocet_cihel; i++) {
                    a += 20;
                    if (i % 4 ==0) {
                        b += 20;
                        a = 40;
                    }
                    cihly1[i] = b;
                    cihly2[i] = a;
                }
            }
        }
    }
    
    CloseWindow();    
    return 0;    
}
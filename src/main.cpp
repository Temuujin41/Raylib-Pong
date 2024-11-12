#include <raylib.h>
#include<iostream>
#include <stdlib.h>
using namespace std;
class Ball{
    public:
    float x, y;
    int speed_x, speed_y;
    int radius;
    int isClose = false;
    void draw(){
        DrawCircle(x, y, radius, WHITE);
    }
    void update(){
        x+=speed_x;
        y+=speed_y;
        if(y + radius >= GetScreenHeight() || y-radius <=0){
            speed_y=speed_y * -1;
        }
        if(x + radius >= GetScreenWidth() || x-radius <=0){
            speed_x=speed_x * -1;
        }
        if(x-radius <=0){
            isClose = true;
        }
    }
    
};
class Line{
public:
int start_x, start_y;
int end_x, end_y;
void Draw(){
DrawLine(start_x, start_y, end_x,end_y, RED);
}

};
class Paddle{
public:
float x, y;
float width, height;
int speed;

void Draw(){
    DrawRectangle(x,y,width, height, WHITE);
}
void Update(){
    if(IsKeyDown(KEY_UP)){
        y=y-speed;
    }
    if(IsKeyDown(KEY_DOWN)){
        y=y+speed;
    }
    if(y<=0){
        y=0;
    }
    if(y>=GetScreenHeight()-height){
        y=GetScreenHeight()-height;
    }
}
};
Ball ball;
Paddle paddle;
Line line;
int main(void)
{
    int height = 1200;
    int width = 800;
    InitWindow(height, width, "raylib");
    SetTargetFPS(60);
    // circle
    ball.radius = 20;
    ball.x = height/2;
    ball.y = width/2;
    ball.speed_x=7;
    ball.speed_y=7;
    // rectangle
    paddle.x = 10;             
    paddle.y = width / 2 - 60;    
    paddle.width = 25;            
    paddle.height = 120;         
    paddle.speed = 6;
    // line
    line.start_x = 0;
    line.start_y=GetScreenHeight();
    line.end_x =0;
    line.end_y = 0;
    int point = 0;
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);
        ball.update();
        ball.draw();
        paddle.Draw();
        paddle.Update();
        if(ball.isClose == true){
            ball.speed_x = 0;
            ball.speed_y = 0;
            paddle.speed=0;
            DrawText(TextFormat("Your Score: %d", point), GetScreenWidth()/2-150, GetScreenHeight()/2-50, 50, WHITE);
            DrawText("click to play agian...",GetScreenWidth()/2-20, GetScreenHeight()/2, 25, WHITE);
            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                // do here something
            }
        }
        DrawText(TextFormat("Score %d", point), 20, 20, 20, WHITE);

        if(CheckCollisionCircleRec(Vector2{ball.x, ball.y} , ball.radius, Rectangle{paddle.x, paddle.y, paddle.width, paddle.height})){
            ball.speed_x *= -1;
            point++;
        }

        EndDrawing();
      
    }
    return 0; 
}
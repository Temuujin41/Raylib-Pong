#include <raylib.h>
void DrawLine(int startPosX, int startPosY, int endPosX, int endPosY, Color color); 
int main(void)
{
    int height = 800;
    int width = 450;
    InitWindow(height, width, "raylib");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        DrawCircle(height/2, width/2, 20, WHITE);
        EndDrawing();
    }
    return 0; 
}
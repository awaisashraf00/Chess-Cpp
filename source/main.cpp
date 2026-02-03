#include "raylib.h"
#include "board.h"

int main() 
{
    InitWindow(800,800, "Snake");
    SetTargetFPS(60);
    Board grid;

    while(WindowShouldClose() == false) 
    {
        BeginDrawing();
        ClearBackground(WHITE);
        grid.Game_Input();
        grid.Display_Board();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
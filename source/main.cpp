#include "raylib.h"
#include "board.h"

int main() 
{
    Board grid = Board();
    InitWindow(800,800, "Snake");
    SetTargetFPS(60);

    while(WindowShouldClose() == false) 
    {
        BeginDrawing();
        ClearBackground(WHITE);
        grid.Display_Board();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
#include "board.h"

int main() 
{
    InitWindow(800,800, "AWAIS Chess");
    SetAudioStreamBufferSizeDefault(4096);
    SetTargetFPS(60);
    Board grid;

    while(WindowShouldClose() == false) 
    {
        BeginDrawing();
        ClearBackground(BLACK);
        grid.Game_Input();
        grid.Display_Board();
        EndDrawing();
    }

    CloseWindow();
    CloseAudioDevice();
    return 0;
}
#include "raylib.h"
#include "board.h"


Board::Board() {
}

void Board::Display_Board() {
    Color SKIN = {150, 114, 110,170};
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < rows; j++) {
            DrawRectangle(cell_size * j, cell_size * i, cell_size, cell_size,
                          ((i + j) % 2 == 0) ? SKIN : BROWN);
        }
    }
}
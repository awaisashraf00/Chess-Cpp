#pragma once
#include "raylib.h"
#include <vector>
#include <map>
#include <string>

class Board
{
    private:
        int rows = 8;
        int cell_size = 100;
        int grid[8][8] = {{-2,-3,-4,-5,-6,-4,-3,-2},
                        {-1,-1,-1,-1,-1,-1,-1,-1},
                        {0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0},
                        {1,1,1,1,1,1,1,1},
                        {2,3,4,5,6,4,3,2}};

        std::map<int,std::string> pieces = {
                            {-1, "/Users/sherazrajput/Chess/game/pieces-basic-png/black-pawn.png"}
                            ,{-2, "/Users/sherazrajput/Chess/game/pieces-basic-png/black-rook.png"}
                            ,{-3, "/Users/sherazrajput/Chess/game/pieces-basic-png/black-knight.png"}
                            ,{-4, "/Users/sherazrajput/Chess/game/pieces-basic-png/black-bishop.png"}
                            ,{-5, "/Users/sherazrajput/Chess/game/pieces-basic-png/black-queen.png"}
                            ,{-6, "/Users/sherazrajput/Chess/game/pieces-basic-png/black-king.png"}
                            ,{1, "/Users/sherazrajput/Chess/game/pieces-basic-png/white-pawn.png"}
                            ,{2, "/Users/sherazrajput/Chess/game/pieces-basic-png/white-rook.png"}
                            ,{3, "/Users/sherazrajput/Chess/game/pieces-basic-png/white-knight.png"}
                            ,{4, "/Users/sherazrajput/Chess/game/pieces-basic-png/white-bishop.png"}
                            ,{5, "/Users/sherazrajput/Chess/game/pieces-basic-png/white-queen.png"}
                            ,{6, "/Users/sherazrajput/Chess/game/pieces-basic-png/white-king.png"}};
    public:
        Board();
        void Display_Board();        
        
};

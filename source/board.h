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
                            {-1, "pawn"}
                            ,{-2, "rook"}
                            ,{-3, "knight"}
                            ,{-4, "bishop"}
                            ,{-5, "queen"}
                            ,{-6, "king"}
                            ,{1, "pawn"}
                            ,{2, "rook"}
                            ,{3, "knight"}
                            ,{4, "bishop"}
                            ,{5, "queen"}
                            ,{6, "king"}};
    public:
        Board();
        void Display_Board();        
        
};

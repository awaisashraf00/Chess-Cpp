#include "raylib.h"
#include "board.h"

Board::Board()
{
    // Load all piece textures once to avoid per-frame loads
    for (const auto &p : pieces) {
        Texture2D tex = LoadTexture(p.second.c_str());
        textures[p.first] = tex;
    }
}

Board::~Board()
{
    // Unload textures when Board is destroyed
    for (auto &t : textures) {
        UnloadTexture(t.second);
    }
}

void Board::Display_Board() {
    Color SKIN = {150, 114, 110,170};
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < rows; j++) {
            if((current_peice.first == i && current_peice.second == j)){
                DrawRectangle((cell_size * j)-1, (cell_size * i)-1, cell_size -1, cell_size-1,YELLOW);            
            }else{
                DrawRectangle((cell_size * j)-1, (cell_size * i)-1, cell_size -1, cell_size-1,
                ((i + j) % 2 == 0) ? SKIN : BROWN);            
            }
                
            int piece = grid[i][j];
            if (piece != 0 && textures.find(piece) != textures.end()) {
                Texture2D &texture = textures[piece];
                float scale = (texture.width > 0) ? (float)cell_size / (float)texture.width : 1.0f;
                DrawTextureEx(texture, {(float)(cell_size * j), (float)(cell_size * i)}, 0.0f, 
                              scale, WHITE);
            }
            if(coords.first == i && coords.second == j){
                DrawRectangleLines((j * cell_size)-1, (i * cell_size )+1, cell_size, cell_size, BLACK);
                DrawRectangleLines((j * cell_size)-2, (i * cell_size )+2, cell_size, cell_size, BLACK);
            }
        }    
    }
}


// bool Board::Is_Valid_Pos(int x , int y)
// {
//     int chessMen = grid[x][y];
    
// }


void Board::Game_Input()
{
    int key = GetKeyPressed();

    if(key==KEY_UP){
        if(coords.first > 0 )
            coords.first--;
    }else if(key==KEY_DOWN){
        if(coords.first < 7)
            coords.first++;
        
    }else if(key==KEY_LEFT){
        if(coords.second > 0)
            coords.second--;
        
    }else if(key==KEY_RIGHT){
        if(coords.second < 7)
            coords.second++;

    }else if(key==KEY_ENTER && selected == true){

        if(grid[coords.first][coords.second]>0 && white ==  true){
            
            selected = false;
            white = false;
            black = true;
            
            current_peice.first = coords.first;
            current_peice.second = coords.second;

        }else if(grid[coords.first][coords.second]<0 && black ==  true){
            selected = false;
            white = true;
            black = false;

            selected = false;
            current_peice.first = coords.first;
            current_peice.second = coords.second;
        }
    }else if(key == KEY_SPACE && selected == false){
        
        selected = true;
        current_peice.first = -1;
        current_peice.second = -1;
        black = (black==true) ? false:true;
        white = (white==true) ? false:true;


    }else if(key==KEY_ENTER && selected == false){
        if(!white){
            if(grid[coords.first][coords.second] <= 0){
                selected = true;
                grid[coords.first][coords.second] = grid[current_peice.first][current_peice.second];
                grid[current_peice.first][current_peice.second] = 0;
            }
        }else if (!black){ 
            if(grid[coords.first][coords.second] >= 0){
                selected = true;
                grid[coords.first][coords.second] = grid[current_peice.first][current_peice.second];
                grid[current_peice.first][current_peice.second] = 0;
            }
        }
    }
}

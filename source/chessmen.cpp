#include "chessmen.h"

class Pawn : public Chessmen {
    
    bool white;
    public:
        Pawn(int x, int y, bool con ) : Chessmen(x, y),white(con){            
        }    
        
        std::vector<std::pair<int,int>> possible_move(int (*board)[8]) override{
            std::vector<std::pair<int,int>> moves;
            
            int x = origin.first;
            int y = origin.second;         
            
            if(white){
                if(board[x+1][y]==0 && x<8 && y<8){
                    moves.push_back({x+1,y});    
                }
                if(board[x+1][y+1]>0 && x<8 && y<8){
                    moves.push_back({x+1,y+1});    
                }
                if(board[x+1][y-1]>0 && x < 8 && y>0){
                    moves.push_back({x+1,y-1});    
                }
            }else{
                if(board[x-1][y] == 0){
                    moves.push_back({x-1,y});    
                }
                if(board[x-1][y+1]<0){
                    moves.push_back({x-1,y+1});    
                }
                if(board[x-1][y-1]<0){
                    moves.push_back({x-1,y-1});    
                }
            }
            
        return moves;
        }
        
};

class Tower :public Chessmen{
    bool white;
    public:
        Tower(int x, int y, bool con ) : Chessmen(x, y),white(!con){ }    
        
        std::vector<std::pair<int,int>> possible_move(int (*board)[8]) override {
            std::vector<std::pair<int,int>> moves;

            int x = origin.first;
            int y = origin.second;

            // → Right
            for (int j = y + 1; j < 8; j++) {
                if (board[x][j] == 0)
                    moves.push_back({x, j});
                else {
                    if (white ? board[x][j] < 0 : board[x][j] > 0)
                        moves.push_back({x, j});
                    break;
                }
            }

            // ← Left
            for (int j = y - 1; j >= 0; j--) {
                if (board[x][j] == 0)
                    moves.push_back({x, j});
                else {
                    if (white ? board[x][j] < 0 : board[x][j] > 0)
                        moves.push_back({x, j});
                    break;
                }
            }

            // ↓ Down
            for (int i = x + 1; i < 8; i++) {
                if (board[i][y] == 0)
                    moves.push_back({i, y});
                else {
                    if (white ? board[i][y] < 0 : board[i][y] > 0)
                        moves.push_back({i, y});
                    break;
                }
            }

            // ↑ Up
            for (int i = x - 1; i >= 0; i--) {
                if (board[i][y] == 0)
                    moves.push_back({i, y});
                else {
                    if (white ? board[i][y] < 0 : board[i][y] > 0)
                        moves.push_back({i, y});
                    break;
                }
            }

            return moves;
        }

};

class  Missile :public Chessmen{
    bool white;
    public:
        Missile(int x, int y, bool con ) : Chessmen(x, y),white(!con){} 

        std::vector<std::pair<int,int>> possible_move(int (*board)[8])override {
            std::vector<std::pair<int,int>> moves;
            
            int x = origin.first;
            int y = origin.second;

            while(board[x][y+1]==0 && y<8 && x<8){
                moves.push_back({x,y});
                y++;
                x++;
            }
            
            if(x!=7 && y!=7){
                if(white==true ?(board[x+1][y+1]<=0):(board[x+1][y+1]>=0)){
                    moves.push_back({x+1,y+1});
                }
            }
            
            x = origin.first;
            y = origin.second;

            while(board[x-1][y-1]==0 && y>0 && x>0){
                moves.push_back({x,y});
                y--;
                x--;
            }
            
            if(x!=0 && y!=0){
                if(white==true ?(board[x-1][y-1]<=0):(board[x-1][y-1]>=0)){
                    moves.push_back({x-1,y-1});
                }
            }
            
            x = origin.first;
            y = origin.second;

            while(board[x+1][y-1]==0 && x<8 && y >0){
                moves.push_back({x,y});
                x++;
                y--;
            }

            if(x!=7 && y!=0){
                if(white==true ?(board[x+1][y-1]<=0):(board[x+1][y-1]>=0)){
                    moves.push_back({x+1,y-1});
                }
            }

            x = origin.first;
            y = origin.second;

            while(board[x-1][y+1]==0 && x>0 && y <8){
                moves.push_back({x,y});
                x--;
                y++;
            }

            if(x!=0 && y!=7){
                if(white==true ?(board[x-1][y+1]<=0):(board[x-1][y+1]>=0)){
                    moves.push_back({x-1,y+1});
                }
            }

        return moves;
        }

};

class Knight : public Chessmen {
    bool white;

public:
    Knight(int x, int y, bool con)
        : Chessmen(x, y), white(!con) {}

    std::vector<std::pair<int,int>>
    possible_move(int (*board)[8]) override {

        std::vector<std::pair<int,int>> moves;

        int x = origin.first;
        int y = origin.second;

        // All 8 possible knight moves
        int dx[8] = { 2,  2, -2, -2,  1,  1, -1, -1 };
        int dy[8] = { 1, -1,  1, -1,  2, -2,  2, -2 };

        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // Bounds check FIRST
            if (nx < 0 || nx >= 8 || ny < 0 || ny >= 8)
                continue;

            // Empty square
            if (board[nx][ny] == 0) {
                moves.push_back({nx, ny});
            }
            // Capture enemy
            else if (white ? board[nx][ny] < 0 : board[nx][ny] > 0) {
                moves.push_back({nx, ny});
            }
        }

        return moves;
    }
};
// class  King :public Chessmen{
//     bool white;
//     public:
//         King(int x, int y, bool con ) : Chessmen(x, y),white(!con){}    
//         std::vector<std::pair<int,int>> possible_move(int (*board)[8]) {
//             std::vector<std::pair<int,int>> moves;
            
//             int x = origin.first;
//             int y = origin.second;
             
//             while(board[x][y]==0 && y<8){
//                 moves.push_back({x,y});
//                 y++;
//             }
//             x = origin.first;
//             y = origin.second;
//             while(board[x][y]==0 && y>0){
//                 moves.push_back({x,y});
//                 y--;
//             }
//             x = origin.first;
//             y = origin.second;

//             while(board[x][y]==0 && x<8){
//                 moves.push_back({x,y});
//                 x++;
//             }
//             x = origin.first;
//             y = origin.second;

//             while(board[x][y]==0 && x>0){
//                 moves.push_back({x,y});
//                 x--;
//             }

//         return moves;
//         }

// };

// class  Queen :public Chessmen{
//     bool white;
//     public:
//         Queen(int x, int y, bool con ) : Chessmen(x, y),white(!con){}    
//         std::vector<std::pair<int,int>> possible_move(int (*board)[8]) {
//             std::vector<std::pair<int,int>> moves;
            
//             int x = origin.first;
//             int y = origin.second;
            
            
//             while(board[x][y]==0 && y<8){
//                 moves.push_back({x,y});
//                 y++;
//             }
//             x = origin.first;
//             y = origin.second;
//             while(board[x][y]==0 && y>0){
//                 moves.push_back({x,y});
//                 y--;
//             }
//             x = origin.first;
//             y = origin.second;

//             while(board[x][y]==0 && x<8){
//                 moves.push_back({x,y});
//                 x++;
//             }
//             x = origin.first;
//             y = origin.second;

//             while(board[x][y]==0 && x>0){
//                 moves.push_back({x,y});
//                 x--;
//             }

//         }
//         return moves;

// };

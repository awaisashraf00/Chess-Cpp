#include "chessmen.h"

class King : public Chessmen{
    
    bool white;
    
    public:
    King(int x, int y, bool con ) : Chessmen(x, y),white(!con){}    

    bool Check_for_check(int (*board)[8]){

        int x = origin.first;
        int y = origin.second;

        // =====================
        // Pawn Threat
        // =====================
        if (white) {
            if (x-1 >= 0 && y+1 < 8 && board[x-1][y+1] == -1) return true;
            if (x-1 >= 0 && y-1 >= 0 && board[x-1][y-1] == -1) return true;
        } 
        else {
            if (x+1 < 8 && y-1 >= 0 && board[x+1][y-1] == 1) return true;
            if (x+1 < 8 && y+1 < 8 && board[x+1][y+1] == 1) return true;
        }

        // =====================
        // Knight Threat
        // =====================

        int kdx[8] = {2,2,-2,-2,1,1,-1,-1};
        int kdy[8] = {1,-1,1,-1,2,-2,2,-2};

        for (int i = 0; i < 8; i++) {
            int nx = x + kdx[i];
            int ny = y + kdy[i];

            if (nx < 0 || nx >= 8 || ny < 0 || ny >= 8) continue;

            if (white ? board[nx][ny] == -3 : board[nx][ny] == 3)
                return true;
        }

        // =====================
        // Rook / Queen Threat (Straight)
        // =====================
        
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            while (nx >= 0 && nx < 8 && ny >= 0 && ny < 8) {

                if (board[nx][ny] != 0) {

                    if (white) {
                        if (board[nx][ny] == -2 || board[nx][ny] == -5)
                            return true;
                    } else {
                        if (board[nx][ny] == 2 || board[nx][ny] == 5)
                            return true;
                    }

                    break;
                }

                nx += dx[d];
                ny += dy[d];
            }
        }

        // =====================
        // Bishop / Queen Threat (Diagonal)
        // =====================
        int ddx[4] = {1,1,-1,-1};
        int ddy[4] = {1,-1,1,-1};

        for (int d = 0; d < 4; d++) {
            int nx = x + ddx[d];
            int ny = y + ddy[d];

            while (nx >= 0 && nx < 8 && ny >= 0 && ny < 8) {

                if (board[nx][ny] != 0) {

                    if (white) {
                        if (board[nx][ny] == -4 || board[nx][ny] == -5)
                            return true;
                    } else {
                        if (board[nx][ny] == 4 || board[nx][ny] == 5)
                            return true;
                    }

                    break;
                }

                nx += ddx[d];
                ny += ddy[d];
            }
        }

        // =====================
        // Enemy King Nearby
        // =====================
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {

                if (i == 0 && j == 0) continue;

                int nx = x + i;
                int ny = y + j;

                if (nx < 0 || nx >= 8 || ny < 0 || ny >= 8) continue;

                if (white ? board[nx][ny] == -6 : board[nx][ny] == 6)
                    return true;
            }
        }
    return false;

    }
    std::vector<std::pair<int,int>> possible_move(int (*board)[8]) override{
        std::vector<std::pair<int,int>> moves;
        int ddx[8] = {1 ,1,1,-1,-1,-1,0,0};
        int ddy[8] = {1,0,-1,1,0,-1,1,-1};
        
        for(int i{0};i<4;i++){
            int x_origin = origin.first + ddx[i];
            int y_origin = origin.second + ddy[i];
            if(white){
                if(x_origin > 0 && x_origin < 8 && y_origin > 0 && y_origin < 8){
                    if(board[origin.first + ddx[i]][origin.second + ddy[i]] <= 0){
                        moves.push_back({x_origin,y_origin});
                    }

                }
            }else{
                if(x_origin > 0 && x_origin < 8 && y_origin > 0 && y_origin < 8 ){
                    if(board[origin.first + ddx[i]][origin.second + ddy[i]] >= 0){
                        moves.push_back({x_origin,y_origin});
                    }
                }
            }
        }
        return moves;

    }
};

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

                    if(x == 1 && board[x+2][y]==0 && x<8 && y<8){
                        moves.push_back({x+2,y}); 
                    }
                }
                if(board[x+1][y+1]>0 && x<8 && y<8){
                    moves.push_back({x+1,y+1});    
                }
                if(board[x+1][y-1]>0 && x < 8 && y>0){
                    moves.push_back({x+1,y-1});    
                }
            }else{

                if(board[x-1][y] == 0 && x>0){
                    moves.push_back({x-1,y}); 
                    if(x == 6 && board[x-2][y] == 0 && x>0){
                        moves.push_back({x-2,y}); 
                    }   
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

            int x = origin.first+1;
            int y = origin.second+1;

            while(board[x][y]==0 && y<8 && x<8){
                moves.push_back({x,y});
                y++;
                x++;
            }
            
            if(x<=7 && y<=7){
                if(white?(board[x][y]<0):(board[x][y]>0)){
                    moves.push_back({x,y});
                }
            }

            x = origin.first-1;
            y = origin.second-1;

            while(board[x][y]==0 && y>0 && x>0){
                moves.push_back({x,y});
                y--;
                x--;
            }
            
            if(x>0 && y>0){
                if(white?(board[x][y]<0):(board[x][y]>0)){
                    moves.push_back({x,y});
                }
            }
            
            x = origin.first+1;
            y = origin.second-1;

            while(board[x][y]==0 && x<8 && y >0){
                moves.push_back({x,y});
                x++;
                y--;
            }

            if(x<=7 && y>0){
                if(white?(board[x][y]<0):(board[x][y]>0)){
                    moves.push_back({x,y});
                }
            }

            x = origin.first-1;
            y = origin.second+1;

            while(board[x][y]==0 && x>0 && y <8){
                moves.push_back({x,y});
                x--;
                y++;
            }

            if(x>0 && y<=7){
                if(white?(board[x][y]<0):(board[x][y]>0)){
                    moves.push_back({x,y});
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


class  Queen :public Chessmen{
    bool white;
    public:
        Queen(int x, int y, bool con ) : Chessmen(x, y),white(!con){}    
        std::vector<std::pair<int,int>> possible_move(int (*board)[8])override {
            std::vector<std::pair<int,int>> moves;
            
            int x = origin.first;
            int y = origin.second;
            // Right
            for (int j = y + 1; j < 8; j++) {
                if (board[x][j] == 0)
                    moves.push_back({x, j});
                else {
                    if (white ? board[x][j] < 0 : board[x][j] > 0)
                        moves.push_back({x, j});
                    break;
                }
            }
            // Left
            for (int j = y - 1; j >= 0; j--) {
                if (board[x][j] == 0)
                    moves.push_back({x, j});
                else {
                    if (white ? board[x][j] < 0 : board[x][j] > 0)
                        moves.push_back({x, j});
                    break;
                }
            }
            // Down
            for (int i = x + 1; i < 8; i++) {
                if (board[i][y] == 0)
                    moves.push_back({i, y});
                else {
                    if (white ? board[i][y] < 0 : board[i][y] > 0)
                        moves.push_back({i, y});
                    break;
                }
            }
            // Up
            for (int i = x - 1; i >= 0; i--) {
                if (board[i][y] == 0)
                    moves.push_back({i, y});
                else {
                    if (white ? board[i][y] < 0 : board[i][y] > 0)
                        moves.push_back({i, y});
                    break;
                }
            }

            // Diagonals /////
            
            x = origin.first+1;
            y = origin.second+1;

            while(board[x][y]==0 && y<8 && x<8){
                moves.push_back({x,y});
                y++;
                x++;
            }
            if(x<=7 && y<=7){
                if(white?(board[x][y]<0):(board[x][y]>0)){
                    moves.push_back({x,y});
                }
            }

            x = origin.first-1;
            y = origin.second-1;

            while(board[x][y]==0 && y>0 && x>0){
                moves.push_back({x,y});
                y--;
                x--;
            }
            
            if(x>0 && y>0){
                if(white?(board[x][y]<0):(board[x][y]>0)){
                    moves.push_back({x,y});
                }
            }
            
            x = origin.first+1;
            y = origin.second-1;

            while(board[x][y]==0 && x<8 && y >0){
                moves.push_back({x,y});
                x++;
                y--;
            }

            if(x<=7 && y>0){
                if(white?(board[x][y]<0):(board[x][y]>0)){
                    moves.push_back({x,y});
                }
            }

            x = origin.first-1;
            y = origin.second+1;

            while(board[x][y]==0 && x>0 && y <8){
                moves.push_back({x,y});
                x--;
                y++;
            }

            if(x>0 && y<=7){
                if(white?(board[x][y]<0):(board[x][y]>0)){
                    moves.push_back({x,y});
                }
            }

            return moves;
        }

};
#pragma once
#include <utility>
#include <vector>


class Chessmen
{
    protected:
        std::pair<int,int> origin;
    public:
        Chessmen(int x, int y): origin({x,y}){};
        virtual std::vector<std::pair<int,int>>  possible_move(int (*board)[8]) = 0;
        virtual ~Chessmen() {}  
};

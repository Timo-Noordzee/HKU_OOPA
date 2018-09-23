#pragma once
#include <vector>

class Grid {
   private:
    std::vector<int> grid;
    int cols;
    int rows;

   public:
    std::vector<int> grid;
    Grid(int cols, int rows);
    int get(int index);
    ~Grid();
};
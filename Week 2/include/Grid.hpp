#pragma once
#include <vector>

class Grid {
   private:
    std::vector<int> grid;
    int cols;
    int rows;

    int index(int x, int y);

   public:
    Grid(int cols, int rows);
    ~Grid();

    int get(int x, int y);
    int getNeighborCount(int x, int y);

    void display();
    void update();
};
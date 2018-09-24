#pragma once
#include <vector>
#include "Cell.hpp"
#include "Rule.hpp"

class Grid {
   private:
    Rule* rule;
    std::vector<Cell> grid;
    int cols;
    int rows;

    int index(int x, int y);

   public:
    Grid(int cols, int rows, Rule* rule);
    ~Grid();

    Cell get(int x, int y);
    int getNeighborCount(int x, int y);

    void display();
    void update();
};
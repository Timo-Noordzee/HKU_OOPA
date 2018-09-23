#include "Grid.hpp"
#include <vector>

Grid::Grid(int c, int r) : cols(c), rows(r) {
    grid = *new std::vector<int>(cols * rows);
    for (int y = 0; y < rows; y++) {
        for (int x = 0; x < cols; x++) {
            grid.at(y * rows + x) = rand() % 2;
        }
    }
}

int Grid::get(int index) {
    return grid.at(index);
}

Grid::~Grid() {
}
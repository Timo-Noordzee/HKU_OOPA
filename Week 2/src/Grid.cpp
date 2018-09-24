#include "Grid.hpp"
#include <iostream>
#include <vector>
#include "Cell.hpp"

Grid::Grid(int c, int r, Rule* rule) : cols(c), rows(r), rule(rule) {
    grid = *new std::vector<Cell>(cols * rows);
    for (int y = 0; y < rows; y++) {
        for (int x = 0; x < cols; x++) {
            grid.at(y * rows + x) = Cell(x, y, rand() % 2);
        }
    }
}

//Get the value of the cell at the given position
Cell Grid::get(int x, int y) {
    return grid.at(index(x, y));
}

//Get the neighbor count of the cell at the given position
int Grid::getNeighborCount(int x, int y) {
    int neighborCount = 0;
    for (int j = -1; j <= 1; j++) {                                                //Loop all the rows in the grid
        for (int i = -1; i <= 1; i++) {                                            //Loop all cells in the row
            if (x + i < cols && x + i >= 0) {                                      //Check if the neighbors x position doesn't exceed the grid size
                if (y + j < rows && y + j >= 0) {                                  //Check if the neighbors y position doesn't exceed the grid size
                    if (!(j == 0 && i == 0)) {                                     //Ignore the neighbor if it is the cell itself
                        neighborCount += grid.at(index(x + i, y + j)).getState();  //Add the neighbor state to the count
                    }
                }
            }
        }
    }
    return neighborCount;
}

//Return the index of the cell at the given position
int Grid::index(int x, int y) {
    return (y * rows + x);
}

void Grid::display() {
    for (int y = 0; y < rows; y++) {
        for (int x = 0; x < cols; x++) {
            std::cout << (get(x, y).getState() ? "*" : " ");
        }
        std::cout << std::endl;
    }
}

void Grid::update() {
    std::vector<Cell> next = std::vector<Cell>(cols * rows);
    for (int y = 0; y < rows; y++) {
        for (int x = 0; x < cols; x++) {
            int neighborCount = getNeighborCount(x, y);
            int state = get(x, y).getState();
            int newState = rule->applyRule(state, neighborCount);

            // int newState = state;
            // if (state == 0) {
            //     if (neighborCount == 3) {
            //         newState = 1;
            //     }
            // } else {
            //     if (neighborCount < 2 || neighborCount > 3) {
            //         newState = 0;
            //     }
            // }

            next.at(index(x, y)) = Cell(x, y, newState);
        }
    }

    grid = next;

    display();
}

Grid::~Grid() {
}
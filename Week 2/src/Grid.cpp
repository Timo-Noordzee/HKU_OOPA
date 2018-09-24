#include "Grid.hpp"
#include <iostream>
#include <vector>
#include "Cell.hpp"

//Create a new grid with the given amount of cols, rows and set of rules
Grid::Grid(int c, int r, Rule* rule) : cols(c), rows(r), rule(rule) {
    grid = *new std::vector<Cell*>(cols * rows);
    for (int y = 0; y < rows; y++) {
        for (int x = 0; x < cols; x++) {
            grid.at(y * rows + x) = new Cell(x, y, rand() % 2);
        }
    }
}

//Get the value of the cell at the given position
Cell* Grid::get(int x, int y) {
    return grid.at(index(x, y));
}

//Get the neighbor count of the cell at the given position
int Grid::getNeighborCount(int x, int y) {
    int neighborCount = 0;
    for (int j = -1; j <= 1; j++) {                                                 //Loop all the rows in the grid
        for (int i = -1; i <= 1; i++) {                                             //Loop all cells in the row
            if (x + i < cols && x + i >= 0) {                                       //Check if the neighbors x position doesn't exceed the grid size
                if (y + j < rows && y + j >= 0) {                                   //Check if the neighbors y position doesn't exceed the grid size
                    if (!(j == 0 && i == 0)) {                                      //Ignore the neighbor if it is the cell itself
                        neighborCount += grid.at(index(x + i, y + j))->getState();  //Add the neighbor state to the count
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

//Display the cells in the grid
void Grid::display() {
    for (int y = 0; y < rows; y++) {                           //Loop all rows in the grid
        for (int x = 0; x < cols; x++) {                       //Loop all cells in the row
            std::cout << (get(x, y)->getState() ? "*" : " ");  //Echo * if the cell is alive, otherwise echo a whitespace
        }
        std::cout << std::endl;
    }
}

//Update the grid according to its rules
void Grid::update() {
    std::vector<Cell*> next = std::vector<Cell*>(cols * rows);     //Create an empty vector of Cell pointers
    for (int y = 0; y < rows; y++) {                               //Loop all rows in the grid
        for (int x = 0; x < cols; x++) {                           //Loop all cells in the row
            int neighborCount = getNeighborCount(x, y);            //Count the amount of neighbors of the cell at the given position
            int state = get(x, y)->getState();                     //Get the state (alive = 1, dead = 0) of the cell at the given position
            int newState = rule->applyRule(state, neighborCount);  //Calculate the new state according to the rules
            next.at(index(x, y)) = new Cell(x, y, newState);       //Create a new cell pointer with the new state and add it to the new grid
        }
    }

    deleteCells();  //Delete the cell in the current grid
    grid = next;    //Make the new grid the current grid
    display();      //Display the new grid
}

//Delete all the Cell pointers in the current grid
void Grid::deleteCells() {
    for (auto c : grid) {
        delete c;
    }
}

Grid::~Grid() {
    delete rule;
}
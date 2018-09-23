#include <Grid.hpp>
#include <ctime>
#include <iostream>
#include <vector>

int cols = 5;
int rows = 5;
Grid* grid;

int index(int x, int y) {
    return (y * rows + x);
}

int neighbors(int x, int y) {
    int neighborCount = 0;
    int neighborIndex = 0;
    for (int j = -1; j <= 1; j++) {                                       //Loop all the rows in the grid
        for (int i = -1; i <= 1; i++) {                                   //Loop all cells in the row
            if (x + i < cols && x + i >= 0) {                             //Check if the neighbors x position doesn't exceed the grid size
                if (y + j < rows && y + j >= 0) {                         //Check if the neighbors y position doesn't exceed the grid size
                    if (!(j == 0 && i == 0)) {                            //Ignore the neighbor if it is the cell itself
                        neighborCount += grid->get(index(x + i, y + j));  //Add the neighbor state to the count
                    }
                }
            }
        }
    }
    return neighborCount;
}

// std::vector<int>* createGridVector(int cols, int rows) {
//     std::vector<int>* grid = new std::vector<int>(cols * rows);
//     for (int y = 0; y < rows; y++) {
//         for (int x = 0; x < cols; x++) {
//             grid->at(y * rows + x) = rand() % 2;
//         }
//     }
//     return grid;
// }

int main() {
    srand(time(0));
    std::cout << "Hello Easy C++ project" << std::endl;
    grid = new Grid(cols, rows);
    for (int y = 0; y < rows; y++) {
        for (int x = 0; x < cols; x++) {
            std::cout << (grid->get(index(x, y)) ? "*" : " ");
        }
        std::cout << std::endl
                  << std::endl;
    }

    for (int y = 0; y < rows; y++) {
        for (int x = 0; x < cols; x++) {
            neighbors(x, y);
        }
        std::cout << std::endl;
    }

    std::cin.get();
}
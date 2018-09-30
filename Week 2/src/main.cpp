#include <conio.h>
#include <Grid.hpp>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include "RuleBase.hpp"
#include "RuleOverpopulation.hpp"

const int cols = 50;
const int rows = 25;

Grid* grid;
Rule* rule;

int main() {
    srand(time(0));
    char c;

    rule = new BaseRule();              //Create a pointer to a certain set of rules
    grid = new Grid(cols, rows, rule);  //Create a grid with the given cols, rows and rule
    grid->display();                    //Display the grid

    for (;;) {                                            //Loop forever
        c = getch();                                      //Get the pressed char
        if (c == 32) {                                    //Check if the car equals 32 (spacebar)
            system("cls");                                //Clear the console
            grid->update();                               //update the grid
            _sleep(100);                                  //Wait for 0.1 seconds
        }                                                 //
        if (c == 'r') {                                   //Check if the pressed char equals r
            system("cls");                                //Clear the console
            grid->deleteCells();                          //Delete all cell pointers in the current grid
            delete grid;                                  //Delete the pointer to the current grid
            grid = new Grid(cols, rows, new BaseRule());  //Generate a new grid
            grid->update();                               //Update the new grid
        }                                                 //
        if (c == 27) {                                    //Check if the pressed char equals escape
            grid->deleteCells();                          //Delete all cell pointers in the current grid
            delete grid;                                  //Delete the pointer to the current grid
            break;                                        //Break the for loop ending the game
        }
    }
}
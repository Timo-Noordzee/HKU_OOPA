#include <conio.h>
#include <Grid.hpp>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include "RuleBase.hpp"
#include "RuleOverpopulation.hpp"

int cols = 50;
int rows = 25;
Grid* grid;

int main() {
    srand(time(0));
    char c;
    grid = new Grid(cols, rows, new OverPopulationRule());
    grid->display();

    for (;;) {
        c = getch();
        if (c == 32) {
            system("cls");
            grid->update();
            _sleep(100);
        }

        if (c == 27) {
            break;
        }
    }
}
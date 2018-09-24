#include "Cell.hpp"

Cell::Cell() : x(0), y(0), state(0) {}

Cell::Cell(int x, int y, int state) : x(x), y(y), state(state) {
}

Cell::~Cell() {
}

int Cell::getState() {
    return state;
}

void Cell::setState(int newState) {
    state = newState;
}
#pragma once

class Cell {
   private:
    int x;
    int y;
    int state;

   public:
    Cell();
    Cell(int x, int y, int state);
    ~Cell();

    int getState();
    void setState(int state);
};
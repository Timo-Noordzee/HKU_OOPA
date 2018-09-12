#pragma once
#include <string>
#include <vector>
#include "Docent.hpp"

class Module {
   private:
    std::string name;
    Docent* docent;
    int ec;

   public:
    Module(std::string name, Docent* docent, int ec);
    ~Module();

    void displayStudents();

    std::string getName();
    Docent* getTeacher();

    int getEcs();
    void setEcs(int ecs);
};
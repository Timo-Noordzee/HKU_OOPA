#pragma once
#include <string>

class Docent {
   private:
    std::string name;

   public:
    Docent(std::string name);
    ~Docent();

    std::string getName();
};
#pragma once
#include <string>
#include "NPC.hpp"

class Elf : public NPC {
   private:
    std::string name;

   public:
    Elf(std::string name);
    virtual ~Elf();
    virtual void render();
};
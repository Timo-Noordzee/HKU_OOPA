
#pragma once
#include <string>
#include "NPC.hpp"

class Orc : public NPC {
   private:
    std::string name;

   public:
    Orc(std::string name);
    virtual ~Orc();
    virtual void render();
};
#pragma once
#include "Decorator.hpp"

class Soldier : public Decorator {
   public:
    Soldier(NPC* npc);
    void render();
};
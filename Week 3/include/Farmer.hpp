#pragma once
#include "Decorator.hpp"

class Farmer : public Decorator {
   public:
    Farmer(NPC* npc);
    void render();
};
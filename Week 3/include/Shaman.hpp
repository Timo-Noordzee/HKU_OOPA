#pragma once
#include "Decorator.hpp"

class Shaman : public Decorator {
   public:
    Shaman(NPC* npc);
    void render();
};
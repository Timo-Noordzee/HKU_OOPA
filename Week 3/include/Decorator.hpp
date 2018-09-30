#pragma once
#include "NPC.hpp"

class Decorator : public NPC {
   public:
    NPC* npc;
    Decorator(NPC* npc);
    virtual ~Decorator();
    virtual void render();
};
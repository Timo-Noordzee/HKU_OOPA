#include "Decorator.hpp"

Decorator::Decorator(NPC* npc) : npc(npc) {
}

Decorator::~Decorator() {
    if (npc) delete npc;
}

void Decorator::render() {
    npc->render();
}
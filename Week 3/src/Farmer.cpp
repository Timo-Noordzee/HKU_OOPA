#include "Farmer.hpp"

Farmer::Farmer(NPC* npc) : Decorator(npc) {
}

void Farmer::render() {
    Decorator::render();
    std::cout << "- Farmer" << std::endl;
}
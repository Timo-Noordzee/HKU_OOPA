#include "Shaman.hpp"

Shaman::Shaman(NPC* npc) : Decorator(npc) {
}

void Shaman::render() {
    Decorator::render();
    std::cout << "- Shaman" << std::endl;
}
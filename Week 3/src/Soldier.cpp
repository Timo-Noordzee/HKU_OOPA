#include "Soldier.hpp"

Soldier::Soldier(NPC* npc) : Decorator(npc) {
}

void Soldier::render() {
    Decorator::render();
    std::cout << "- Soldier" << std::endl;
}
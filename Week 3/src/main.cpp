#include <iostream>
#include <vector>
#include "Decorator.hpp"
#include "Elf.hpp"
#include "Farmer.hpp"
#include "NPC.hpp"
#include "Orc.hpp"
#include "Shaman.hpp"
#include "Soldier.hpp"

void render(std::vector<NPC*> npcs) {
    for (auto& npc : npcs) {
        npc->render();
        std::cout << std::endl;
    }
}

int main() {
    std::vector<NPC*> npcs;

    NPC* npc1 = NPC::createNPC("Urivalur", Race::orc, Role::farmer);
    npcs.push_back(npc1);

    NPC* npc2 = NPC::createNPC("Sulmthu", Race::elf, Role::shaman);
    npc2 = new Farmer(npc2);
    npcs.push_back(npc2);

    NPC* npc3 = NPC::createNPC("Leotumal", Race::orc, Role::soldier);
    npcs.push_back(npc3);

    render(npcs);

    delete npc1;
    delete npc2;
    delete npc3;
}
#include "NPC.hpp"
#include "Elf.hpp"
#include "Farmer.hpp"
#include "Orc.hpp"
#include "Shaman.hpp"
#include "Soldier.hpp"

NPC::NPC() {
}

NPC::~NPC() {
}

NPC* NPC::createNPC(std::string name, Race race, Role role) {
    NPC* base;
    if (race == Race::elf)
        base = new Elf(name);
    else
        base = new Orc(name);

    switch (role) {
        case Role::farmer:
            return new Farmer(base);
            break;
        case Role::soldier:
            return new Soldier(base);
            break;
        case Role::shaman:
            return new Shaman(base);
            break;
        default:
            return base;
    }
}
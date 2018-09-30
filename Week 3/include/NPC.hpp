#pragma once
#include <cstdarg>
#include <iostream>
#include <string>

enum Role {
    farmer,
    soldier,
    shaman
};

enum Race {
    elf,
    orc
};

class NPC {
   public:
    NPC();
    virtual ~NPC();
    virtual void render() = 0;
    static NPC* createNPC(std::string name, Race race, Role role);
};
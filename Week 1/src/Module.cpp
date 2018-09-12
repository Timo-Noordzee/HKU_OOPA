#include "Module.hpp"
#include <iostream>
#include <string>
#include "Docent.hpp"

Module::Module(std::string name, Docent* docent, int ec) : name(name), docent(docent), ec(ec) {}

Module::~Module() {}

std::string Module::getName() { return name; }

Docent* Module::getTeacher() { return docent; }

int Module::getEcs() { return ec; }

//Set the EC value of the module to the given value
void Module::setEcs(int ecs) {
    std::cout << "Updating ECs of " << getName() << " from " << getEcs() << " to " << ecs << std::endl
              << std::endl;
    ec = ecs;
}

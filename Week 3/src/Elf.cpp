#include "Elf.hpp"

Elf::Elf(std::string n) : name(n) {
}

Elf::~Elf() {
}

void Elf::render() {
    std::cout << "An elf named " << name << std::endl;
}
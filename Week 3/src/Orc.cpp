#include "Orc.hpp"

Orc::Orc(std::string n) : name(n) {
}

Orc::~Orc() {
}

void Orc::render() {
    std::cout << "An orc named " << name << std::endl;
}
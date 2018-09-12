#include "Docent.hpp"
#include <string>

Docent::Docent(std::string name) : name(name) {}

Docent::~Docent() {}

std::string Docent::getName() {
    return name;
}
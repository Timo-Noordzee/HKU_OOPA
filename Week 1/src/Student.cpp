#include "Student.hpp"
#include <iostream>
#include <string>
#include "Module.hpp"

//Generate a random name for the student when created
Student::Student() {
    std::string firstnames[] = {
        "Tera", "Yetta", "Myrl", "Mariano", "Kenna",
        "Jana", "Vivien", "Fred", "Babette", "Bailey",
        "Jesus", "Seth", "Drucilla", "Leeanne", "Kena",
        "Stephane", "Shon", "Cyrstal", "Vernon", "Magdalena"};

    std::string surnames[] = {
        "Swinger", "Robins", "Vert", "Riggin",
        "Harned", "Arnone", "Brabant", "Heiser",
        "Pinedo", "Cain", "Deluca", "Farinas",
        "Franco", "Slay", "Klinge", "Kuta",
        "Tindle", "Kneip", "Rodger", "Blackmon"};

    name = firstnames[rand() % 20] + " " + surnames[rand() % 20];
}

Student::~Student() {
    std::cout << "Destructor of " << name << std::endl;
}

std::string Student::getName() { return name; }

//Remove the given module from the modules vector
void Student::kickFromModule(Module* module) {
    int index = std::distance(modules.begin(), std::find(modules.begin(), modules.end(), module));     //Get the index of the given module
    std::cout << "Kicking " << getName() << " from module " << getModule(index)->getName() << "\n\n";  //Notify the kicking of the user
    modules.erase(modules.begin() + index);                                                            //Remove the module at the given index from the modules vector
}

//Add the given module to the modules vector
void Student::attendModule(Module* module) {
    modules.push_back(module);
}

//Return the module at the given index
Module* Student::getModule(int index) {
    if (index < modules.size()) {  //Check if the index exists in the modules vector
        return modules.at(index);  //If so, return the module at the given index
    }
}

//Return a vector of all modules the student attends
std::vector<Module*>* Student::getModules() {
    return &modules;
}

//Returns true if modules contains the given module otherwise returns false
bool Student::attendsModule(Module* module) { return (std::find(modules.begin(), modules.end(), module) != modules.end()); }

//Calculate the sum of ecs for every module the student attends
int Student::getEcs() {
    int ecs = 0;              //Initialize an int with value 0
    for (auto m : modules) {  //Itteratre all modules in modules vector
        ecs += m->getEcs();   //Add the ECs of the module to the EC count
    }
    return ecs;
}
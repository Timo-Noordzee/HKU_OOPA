#include <algorithm>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include "Docent.hpp"
#include "Module.hpp"
#include "Student.hpp"

//Display the amount of ECs for every student
void displayStudent(std::vector<Student*>* students) {
    std::cout << "Student EC points \n";
    for (auto s : *students) {
        std::cout << "- " << s->getName() << ": " << s->getEcs() << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    srand(time(0));

    //Generate 10 random students
    std::vector<Student*>* students = new std::vector<Student*>;
    for (int i = 0; i < 10; i++) {
        students->push_back(new Student());
    }

    //Generate 3 random teachers
    std::vector<Docent*>* teachers = new std::vector<Docent*>;
    teachers->push_back(new Docent("Edwin van Ouwerkerk"));
    teachers->push_back(new Docent("Aaron Oostdijk"));
    teachers->push_back(new Docent("Valentijn Muijrers"));

    //Generate 3 modules
    std::vector<Module*>* modules = new std::vector<Module*>;
    modules->push_back(new Module("Kernmodule Game Development 1", teachers->at(1), 3));
    modules->push_back(new Module("Object Oriented Programming Advanced", teachers->at(0), 2));
    modules->push_back(new Module("New Technologies", teachers->at(2), 1));

    //Assign 1 to 3 modules to each student
    for (auto s : *students) {
        std::vector<Module*> _modules = *modules;  //Create a copy of the modules vector (to allow removal of elements)
        for (int i = 0; i < 1 + (rand() % 3); i++) {
            int index = rand() % _modules.size();      //Get a random module from the _modules vector
            s->attendModule(_modules.at(index));       //Assign the module to the student
            _modules.erase(_modules.begin() + index);  //Remove the assigned module from the _modules vector to prevent duplicate modules
        }
        std::cout << std::endl;
    }

    //Display modules and attending students and teacher
    for (auto m : *modules) {
        std::cout << m->getName() + " - " + m->getTeacher()->getName() << " #" << m->getEcs() << "ECs" << std::endl;
        for (auto s : *students) {
            if (s->attendsModule(m)) std::cout << "- " + s->getName() << std::endl;  //If students attend module, print student name
        }

        std::cout << std::endl;
    }

    displayStudent(students);   //Display the studens ECs
    modules->at(2)->setEcs(3);  //Change the ECs of New Technologies from 1 to 3
    displayStudent(students);   //Display the studens ECs after update

    int index = rand() % students->size();
    students->at(index)->kickFromModule(students->at(index)->getModule(rand() % students->at(index)->getModules()->size()));
    displayStudent(students);  //Display students after kicking a student from a random module

    delete (students);
}
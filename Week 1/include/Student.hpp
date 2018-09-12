#pragma once
#include <string>
#include <vector>
#include "Module.hpp"

class Student {
   private:
    std::string name;
    std::vector<Module*> modules;

   public:
    Student();
    ~Student();

    std::string getName();

    void kickFromModule(Module* module);
    void attendModule(Module* module);

    Module* getModule(int index);
    std::vector<Module*>* getModules();

    bool attendsModule(Module* module);
    int getEcs();
};
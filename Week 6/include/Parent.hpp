#pragma once

#include <memory>
#include <ostream>
#include <string>
#include "Child.hpp"

using namespace std;

class Parent {
   public:
    Parent(string name);

    Parent(const Parent& other);

    virtual ~Parent();

    Parent& operator=(const Parent& other);

    friend ostream& operator<<(ostream& os, const Parent& parent);

   private:
    string name;
    unique_ptr<Child> child;
};
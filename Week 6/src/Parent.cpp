#include "Parent.hpp"
#include <iostream>

Parent::Parent(string name) {
    this->name = name;
    string childName = "ChildOf" + name;
    this->child = std::make_unique<Child>(childName);
}

Parent::Parent(const Parent& other) {
    cout << "Parent cctor" << endl;
    this->name = other.name;
    this->child = std::make_unique<Child>(*other.child);

    Child(*other.child);
}

Parent::~Parent() {
    //delete this->child;
}

Parent& Parent::operator=(const Parent& other) {
    cout << "Parent assignment" << endl;

    if (this == &other) {
        return *this;
    }

    this->name = other.name;
    this->child = std::make_unique<Child>(*other.child);
    //new Child(*other.child);

    return *this;
}

ostream& operator<<(ostream& os, const Parent& parent) {
    os << "name: " << parent.name << " child: " << *parent.child;
    return os;
}
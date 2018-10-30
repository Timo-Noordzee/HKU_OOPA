#include <iostream>
#include <memory>
#include "Parent.hpp"

using namespace std;

int main() {
    shared_ptr<Parent> p1 = std::make_shared<Parent>("Parent1");
    //Parent* p1 = new Parent("Parent1");
    cout << "P1:" << *p1 << endl;

    shared_ptr<Parent> p2 = std::make_shared<Parent>(*p1);  // roept de copy constructor aan
    //Parent* p2 = new Parent(*p1);
    cout << "P2:" << *p2 << endl;

    shared_ptr<Parent> p3 = std::make_shared<Parent>("Parent3");
    //Parent* p3 = new Parent("Parent3");
    cout << "P3:" << *p3 << endl;

    *p3 = *p1;  // roept de assignment operator aan
    cout << "P3:" << *p3 << endl;

    std::shared_ptr<Parent> p4 = p1;
    std::shared_ptr<Parent> p5 = p1;
    std::shared_ptr<Parent> p6 = p1;

    std::cout << "Shared pointer count: " << p1.use_count() << std::endl;

    return 0;
}
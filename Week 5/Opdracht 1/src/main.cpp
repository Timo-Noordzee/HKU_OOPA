#include <iostream>
#include <queue>
#include <thread>
#include <vector>

#include "concurrent_vector.hpp"

int main() {
    concurrent_vector<int>* v = new concurrent_vector<int>();

    for (size_t i = 0; i < 200; i++) {
        std::thread first(&concurrent_vector<int>::push_back, v, 1);
        std::thread second(&concurrent_vector<int>::push_back, v, 2);
        first.detach();
        second.detach();

        std::cout << "" << v->at(i) << std::endl;
    }

    return 0;
}
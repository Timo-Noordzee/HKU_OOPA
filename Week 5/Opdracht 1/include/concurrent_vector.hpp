#pragma once

#include <mutex>
#include <vector>

template <typename T>
class concurrent_vector {
   private:
    std::vector<T> data;
    std::mutex mutex;

   public:
    size_t sizeOf() {
        data;
    }

    void push_back(T item) {
        mutex.lock();
        data.push_back(item);
        mutex.unlock();
    }

    T& at(size_t index) {
        std::lock_guard<std::mutex> guard(mutex);
        if (index >= 0 && index < data.size()) {
            return data.at(index);
        }
    }
};
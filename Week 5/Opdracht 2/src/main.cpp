#include <condition_variable>
#include <iostream>
#include <queue>
#include <thread>

int c = 0;
bool done = false;
std::queue<int> goods;

std::condition_variable consumerFlag;
std::condition_variable producerFlag;
std::mutex mutex1;
std::mutex mutex2;

void producer() {
    std::unique_lock<std::mutex> locker(mutex2);
    for (int i = 0; i < 500; ++i) {
        {
            std::lock_guard<std::mutex> guard(mutex1);
            goods.push(i);
            c++;
        }
        consumerFlag.notify_one();
        producerFlag.wait(locker);
    }

    done = true;
    consumerFlag.notify_one();
}

void consumer() {
    std::unique_lock<std::mutex> lock(mutex1);
    while (!done) {
        consumerFlag.wait(lock);
        while (!goods.empty()) {
            {
                std::lock_guard<std::mutex> guard(mutex2);
                goods.pop();
                c--;
            }
        }
        producerFlag.notify_one();
    }
}

int main() {
    std::thread consumerThread(consumer);
    std::thread producerThread(producer);

    consumerThread.detach();
    producerThread.join();
    std::cout << "Net: " << c << std::endl;
}
#include <iostream>              // std::cout
#include <atomic>                // std::atomic, std::atomic_flag, ATOMIC_FLAG_INIT
#include <thread>                // std::thread, std::this_thread::yield
#include <vector>                // std::vector

std::atomic<bool> ready(false);    // can be checked without being set
std::atomic_flag winner = ATOMIC_FLAG_INIT;    // always set when checked

void count1m(int id)
{
    while (!ready) {
        std::this_thread::yield();
    } //wait main thread ready be true.

    for (unsigned long long i = 0; i < 20000000000; ++i) {
    } // count.

    // some thread complete count 1m task then print self ID.
    // so other thread call test_and_set, if statement refer to false, will not print self ID.
    if (!winner.test_and_set()) {
        std::cout << "thread #" << id << " won!\n";
    }
};

int main()
{
    std::vector<std::thread> threads;
    std::cout << "spawning 10 threads that count to 1 million...\n";
    for (int i = 1; i <= 10; ++i)
        threads.push_back(std::thread(count1m, i));
    ready = true;

    for (auto & th:threads)
        th.join();

    return 0;
}
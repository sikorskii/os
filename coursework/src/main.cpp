#include <iostream>
#include <unistd.h>
#include "BlockAllocator.h"
#include "BuddyAllocator.h"
#include <vector>
#include <chrono>

int main() {
    BlockAllocator all = BlockAllocator(1024);
    void* mem = all.allocate(10000000);
    BuddyAllocator allocator = BuddyAllocator(1024);

    std::vector<void*> v(1000);

    auto t1 = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < v.size(); i++) {
        v[i] = allocator.malloc(i + (i / 2 % 5 + 1));
    }


    for (auto & i : v) {
        allocator.free(i);
    }

    auto t2 = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
    std::cout << duration << std::endl;

    t1 = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < v.size(); i++) {
        v[i] = all.allocate(i + (i / 2 % 5 + 1));
    }
    for (auto & i : v) {
        all.deallocate(i);
    }
    t2 = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
    std::cout << duration;
}

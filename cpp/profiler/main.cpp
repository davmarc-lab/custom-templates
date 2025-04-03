#include <iostream>

#include "Profiler.hpp"

int main(int argc, char *argv[]) {
    Profiler p{ProfileFilter::PROFILE_ALL, DumpFilter::DUMP_ALL};
    double sum = 0, add = 1;
    int it = 1000 * 1000 * 1000;
    p.start();
    for (auto i = 0; i < it; i++) {
        sum += add;
        add /= 2.0;
    }
    p.end();
    std::cout << "Result: " << sum << "\n";
    p.dump();
    return 0;
}

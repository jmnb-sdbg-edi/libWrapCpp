#include "Timespan_us.h"

#include <iostream>

void wait(const unsigned long repeats = 1000UL) {
    double x(0);
    for(unsigned long i = 1; i <= repeats; ++i)
    for(unsigned long i = 1; i <= repeats; ++i)
    for(unsigned long j = 1; j <= repeats; ++j)
    x += i%j;
}

void testTimespan_us() {
    Timespan_us ts;
    wait();
    std::clog << ts << " microseconds\n";
}

int main(int argc, char* argv[]) {
    testTimespan_us();
    return 0;
}


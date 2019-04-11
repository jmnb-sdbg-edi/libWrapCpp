#include "Timespan_us.h"

Timespan_us::Timespan_us() : start(Timespan_us::now_us()) {
}

Timespan_us::~Timespan_us() {
}

Timespan_us::operator long() const {
    long delta = Timespan_us::now_us() - start;
    return delta;
}

const unsigned long Timespan_us::now_us() {
    struct timeval tv;
    gettimeofday(&tv, 0);
    unsigned long microseconds = tv.tv_sec * 1000000UL + tv.tv_usec;
    return microseconds;
}


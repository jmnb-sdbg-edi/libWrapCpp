#ifndef Timespan_us_h_
#define Timespan_us_h_

#include <sys/time.h>

class Timespan_us {
public:
    Timespan_us();
    virtual ~Timespan_us();
    operator long() const;
private:
    const unsigned long start;
    Timespan_us(const Timespan_us&);
    Timespan_us operator=(const Timespan_us&);
    static const unsigned long now_us();
};

#endif/*Timespan_us_h_*/

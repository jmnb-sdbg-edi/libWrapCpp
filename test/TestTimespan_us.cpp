/*
 * TestTimespan_us.cpp
 *
 *  Created on: 25/04/2019
 *      Author: jbatista
 */

#include "TestTimespan_us.h"
CPPUNIT_TEST_SUITE_REGISTRATION(TestTimespan_us);

void TestTimespan_us::setUp() {
}

void TestTimespan_us::tearDown() {
}

void TestTimespan_us::testTimespan_us(void) {
	Timespan_us ts;
	wait(1000UL);
	CPPUNIT_ASSERT(static_cast<unsigned long>(ts) > 0UL);
}

void TestTimespan_us::wait(const unsigned long repeats) {
    double x(0);
    for(unsigned long i = 1; i <= repeats; ++i)
    for(unsigned long j = 1; j <= repeats; ++j)
    x += i%j;
}

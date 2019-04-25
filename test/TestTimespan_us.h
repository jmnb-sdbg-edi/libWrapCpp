/*
 * TestTimespan_us.h
 *
 *  Created on: 25/04/2019
 *      Author: jbatista
 */

#ifndef TEST_TESTTIMESPAN_US_H_
#define TEST_TESTTIMESPAN_US_H_

#include <cppunit/extensions/HelperMacros.h>

#include "Timespan_us.h"

class TestTimespan_us : public CppUnit::TestFixture {
	CPPUNIT_TEST_SUITE(TestTimespan_us);
	CPPUNIT_TEST(testTimespan_us);
	CPPUNIT_TEST_SUITE_END();
private:
	static void wait(const unsigned long repeats = 1000UL);
public:
	void setUp();
	void tearDown();
	void testTimespan_us(void);
};

#endif /* TEST_TESTTIMESPAN_US_H_ */

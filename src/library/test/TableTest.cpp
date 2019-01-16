#include <boost/test/unit_test.hpp>
////////////////////////////////////////////////////////////////////////////////////////////////////
#include "Table.h"
//--------------------------------------------------------------------------------------------------
BOOST_AUTO_TEST_SUITE(Table_CoreFunctionality_TestSuite)
	BOOST_AUTO_TEST_CASE(Table_ConstructAndGet_TestCase)
	{
		int const seatCount1 = 0;

		Restaurant::Table table(seatCount1);
		int const seatCount2 = table.getSeatCount();
		BOOST_REQUIRE_EQUAL(seatCount1, seatCount2);
	}
BOOST_AUTO_TEST_SUITE_END()
////////////////////////////////////////////////////////////////////////////////////////////////////
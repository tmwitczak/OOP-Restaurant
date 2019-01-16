#include <boost/test/unit_test.hpp>
////////////////////////////////////////////////////////////////////////////////////////////////////
#include "RestaurantException.h"
//--------------------------------------------------------------------------------------------------
BOOST_AUTO_TEST_SUITE(RestaurantException_CoreFunctionality_TestSuite)
	BOOST_AUTO_TEST_CASE(RestaurantException_ConstructAndGetMessage_TestCase)
	{
		std::string message1 = "RestaurantException message";

		Restaurant::RestaurantException restaurantException(message1);
		std::string message2 = restaurantException.getMessage();

		BOOST_REQUIRE_EQUAL(message1, message2);
	}
BOOST_AUTO_TEST_SUITE_END()
////////////////////////////////////////////////////////////////////////////////////////////////////
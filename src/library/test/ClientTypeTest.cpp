#include <boost/test/unit_test.hpp>
////////////////////////////////////////////////////////////////////////////////////////////////////
#include "ClientType.h"
#include "Basic.h"
#include "Premium.h"
//--------------------------------------------------------------------------------------------------
BOOST_AUTO_TEST_SUITE(ClientType_CoreFunctionality_TestSuite)
	BOOST_AUTO_TEST_CASE(ClientType_ConstructBasicAndGetClientType_TestCase)
	{
		Restaurant::Basic clientType;
		std::string clientTypeStr = clientType.getClientType();

		BOOST_REQUIRE_EQUAL(clientTypeStr, "basic");
	}
	BOOST_AUTO_TEST_CASE(ClientType_ConstructPremiumAndGetClientType_TestCase)
	{
		Restaurant::Premium clientType;
		std::string clientTypeStr = clientType.getClientType();

		BOOST_REQUIRE_EQUAL(clientTypeStr, "premium");
	}
BOOST_AUTO_TEST_SUITE_END()
////////////////////////////////////////////////////////////////////////////////////////////////////
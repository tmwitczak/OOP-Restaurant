#include <boost/test/unit_test.hpp>
////////////////////////////////////////////////////////////////////////////////////////////////////
#include "Client.h"
#include "HelperFunctions.h"
//--------------------------------------------------------------------------------------------------
BOOST_AUTO_TEST_SUITE(Client_CoreFunctionality_TestSuite)
	BOOST_AUTO_TEST_CASE(Client_ConstructAndGetFirstName_TestCase)
	{
		auto const [firstName1, lastName1, telephoneNumber1, clientType1] = getClientParameters();

		Restaurant::Client client(firstName1, lastName1, telephoneNumber1, clientType1);
		std::string firstName2 = client.getFirstName();

		BOOST_REQUIRE_EQUAL(firstName1, firstName2);
	}
	BOOST_AUTO_TEST_CASE(Client_ConstructAndGetLastName_TestCase)
	{
		auto const [firstName1, lastName1, telephoneNumber1, clientType1] = getClientParameters();

		Restaurant::Client client(firstName1, lastName1, telephoneNumber1, clientType1);
		std::string lastName2 = client.getLastName();

		BOOST_REQUIRE_EQUAL(lastName1, lastName2);
	}
	BOOST_AUTO_TEST_CASE(Client_ConstructAndGetTelephoneNumber_TestCase)
	{
		auto const [firstName1, lastName1, telephoneNumber1, clientType1] = getClientParameters();

		Restaurant::Client client(firstName1, lastName1, telephoneNumber1, clientType1);
		std::string telephoneNumber2 = client.getTelephoneNumber();

		BOOST_REQUIRE_EQUAL(telephoneNumber1, telephoneNumber2);
	}
BOOST_AUTO_TEST_SUITE_END()
////////////////////////////////////////////////////////////////////////////////////////////////////
#include <boost/test/unit_test.hpp>
////////////////////////////////////////////////////////////////////////////////////////////////////
#include "Client.h"
#include "ClientManager.h"
#include "RestaurantException.h"
#include <string>
#include <vector>
//--------------------------------------------------------------------------------------------------
template <typename T>
bool compareVectors(std::vector<T> const &vector1, std::vector<T> const &vector2)
{
	if(vector1.size() < vector2.size())
		return std::equal(vector1.begin(), vector1.end(), vector2.begin());
	else
		return std::equal(vector2.begin(), vector2.end(), vector1.begin());
}
std::tuple<std::string, std::string, std::string, std::string> getClientParameters()
{
	return 	{
				/* firstName */ 		"John",
				/* lastName */ 			"Smith",
				/* telephoneNumber */ 	"123456789",
				/* clientType */ 		"basic"
			};
}
bool operator==(Restaurant::Client const &client1,
				Restaurant::Client const &client2)
{
	return ( 	client1.getFirstName() 			== client2.getFirstName()
		 	&& 	client1.getLastName() 			== client2.getLastName()
			&& 	client1.getTelephoneNumber() 	== client2.getTelephoneNumber()
			&& 	client1.getDiscountPercentage() == client2.getDiscountPercentage()
			&& 	client1.getMaximumTableCount() 	== client2.getMaximumTableCount());
}
//--------------------------------------------------------------------------------------------------
BOOST_AUTO_TEST_SUITE(ClientManager_CoreFunctionality_TestSuite)
	BOOST_AUTO_TEST_CASE(ClientManager_MakeClient_TestCase)
	{
		Restaurant::ClientManager clientManager;
		auto const [firstName1, lastName1, telephoneNumber1, clientType1] = getClientParameters();
		Restaurant::Client client1(firstName1, lastName1, telephoneNumber1, clientType1);

		Restaurant::Client_Ptr client2 = clientManager.makeClient(firstName1, lastName1,
																  telephoneNumber1, clientType1);

		BOOST_REQUIRE_EQUAL(client1 == *client2, true);
	}
	BOOST_AUTO_TEST_CASE(ClientManager_MakeClientAndGetAllClients_TestCase)
	{
		Restaurant::ClientManager clientManager;

		Restaurant::Client_Ptr client = clientManager.makeClient("John", "Smith",
																 "123456789", "basic");
		std::vector<Restaurant::Client_Ptr> allClients = clientManager.getAllClients();

		BOOST_REQUIRE_EQUAL(compareVectors({ client }, allClients), true);
	}
	BOOST_AUTO_TEST_CASE(ClientManager_MakeClientThenRemoveClientAndGetAllClients_TestCase)
	{
		Restaurant::ClientManager clientManager;

		Restaurant::Client_Ptr 	client1 = clientManager.makeClient("John", "Smith",
																 "123456789", "basic"),
								client2 = clientManager.makeClient("Jane", "Smith",
																   "123456789", "premium");
		clientManager.removeClient(client1);
		std::vector<Restaurant::Client_Ptr> allClients = clientManager.getAllClients();

		BOOST_REQUIRE_EQUAL(compareVectors({ client2 }, allClients), true);
	}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(ClientManager_Exceptions_TestSuite)
	BOOST_AUTO_TEST_CASE(ClientManager_MakeClientWithWrongFirstName_TestCase)
	{
		Restaurant::ClientManager clientManager;
		auto const [firstName, lastName, telephoneNumber, clientType] = getClientParameters();
		std::string message;

		try
		{
			clientManager.makeClient(firstName + "12+=", lastName, telephoneNumber, clientType);
		}
		catch(Restaurant::RestaurantException const &exception)
		{
			message = exception.getMessage();
		}

		BOOST_REQUIRE_EQUAL(message, "First name must contain only letters or spaces!");
	}
	BOOST_AUTO_TEST_CASE(ClientManager_MakeClientWithWrongLastName_TestCase)
	{
		Restaurant::ClientManager clientManager;
		auto const [firstName, lastName, telephoneNumber, clientType] = getClientParameters();
		std::string message;

		try
		{
			clientManager.makeClient(firstName, lastName + "2323", telephoneNumber, clientType);
		}
		catch(Restaurant::RestaurantException const &exception)
		{
			message = exception.getMessage();
		}

		BOOST_REQUIRE_EQUAL(message, "Last name must contain only letters, spaces or hyphens!");
	}
	BOOST_AUTO_TEST_CASE(ClientManager_MakeClientWithWrongTelephoneNumber_TestCase)
	{
		Restaurant::ClientManager clientManager;
		auto const [firstName, lastName, telephoneNumber, clientType] = getClientParameters();
		std::string message;

		try
		{
			clientManager.makeClient(firstName, lastName, telephoneNumber + "qwerty", clientType);
		}
		catch(Restaurant::RestaurantException const &exception)
		{
			message = exception.getMessage();
		}

		BOOST_REQUIRE_EQUAL(message, "Telephone number must contain only digits or spaces!");
	}
	BOOST_AUTO_TEST_CASE(ClientManager_MakeClientWithWrongClientType_TestCase)
	{
		Restaurant::ClientManager clientManager;
		auto const [firstName, lastName, telephoneNumber, clientType] = getClientParameters();
		std::string message;

		try
		{
			clientManager.makeClient(firstName, lastName, telephoneNumber, clientType + "123qwerty");
		}
		catch(Restaurant::RestaurantException const &exception)
		{
			message = exception.getMessage();
		}

		BOOST_REQUIRE_EQUAL(message, "Client type must be either \"basic\" or \"premium\"!");
	}
BOOST_AUTO_TEST_SUITE_END()
////////////////////////////////////////////////////////////////////////////////////////////////////
#include <boost/test/unit_test.hpp>
////////////////////////////////////////////////////////////////////////////////////////////////////
#include <vector>
#include "Client.h"
#include "ClientManager.h"
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
	if(		client1.getFirstName() 			== client2.getFirstName()
		&& 	client1.getLastName() 			== client2.getLastName()
		&& 	client1.getTelephoneNumber() 	== client2.getTelephoneNumber()
		&& 	client1.getDiscountPercentage() == client2.getDiscountPercentage()
		&& 	client1.getMaximumTableCount() 	== client2.getMaximumTableCount())
		return true;
	else
		return false;
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
////////////////////////////////////////////////////////////////////////////////////////////////////
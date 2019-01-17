#include <boost/test/unit_test.hpp>
////////////////////////////////////////////////////////////////////////////////////////////////////
#include "Client.h"
#include "ClientManager.h"
#include "RestaurantException.h"
#include "HelperFunctions.h"
#include <fstream>
//--------------------------------------------------------------------------------------------------
bool operator==(Restaurant::Client const &client1,
				Restaurant::Client const &client2)
{
	return ( 	client1.getFirstName() 			== client2.getFirstName()
		 	&& 	client1.getLastName() 			== client2.getLastName()
			&& 	client1.getTelephoneNumber() 	== client2.getTelephoneNumber()
			&& 	client1.getClientType() 		== client2.getClientType());
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
	BOOST_AUTO_TEST_CASE(ClientManager_FindClientsByFirstName_TestCase)
	{
		Restaurant::ClientManager clientManager;
		clientManager.makeClient("Jon", "Snow", "111111111", "basic");
		clientManager.makeClient("Aegon", "Snow", "222222222", "basic");
		clientManager.makeClient("Jon", "Targaryen", "333333333", "basic");
		clientManager.makeClient("Ned", "Stark", "444444444", "basic");
		clientManager.makeClient("Arya", "Stark", "555555555", "basic");
		std::vector<Restaurant::Client_Ptr> const clientsExpectedResult
		{
			clientManager.getAllClients().at(0),
			clientManager.getAllClients().at(2)
		};

		std::vector<Restaurant::Client_Ptr> clientsActualResult =
				clientManager.findClientsByFirstName("Jon");

		BOOST_REQUIRE_EQUAL(compareVectors(clientsExpectedResult, clientsActualResult), true);
	}
	BOOST_AUTO_TEST_CASE(ClientManager_FindClientsByLastName_TestCase)
	{
		Restaurant::ClientManager clientManager;
		clientManager.makeClient("Jon", "Snow", "111111111", "basic");
		clientManager.makeClient("Aegon", "Snow", "222222222", "basic");
		clientManager.makeClient("Jon", "Targaryen", "333333333", "basic");
		clientManager.makeClient("Ned", "Stark", "444444444", "basic");
		clientManager.makeClient("Arya", "Stark", "555555555", "basic");
		std::vector<Restaurant::Client_Ptr> const clientsExpectedResult
		{
			clientManager.getAllClients().at(2)
		};

		std::vector<Restaurant::Client_Ptr> const clientsActualResult =
				clientManager.findClientsByLastName("Targaryen");

		BOOST_REQUIRE_EQUAL(compareVectors(clientsExpectedResult, clientsActualResult), true);
	}
	BOOST_AUTO_TEST_CASE(ClientManager_FindClientsByTelephoneNumber_TestCase)
	{
		Restaurant::ClientManager clientManager;
		clientManager.makeClient("Jon", "Snow", "111111111", "basic");
		clientManager.makeClient("Aegon", "Snow", "222222222", "basic");
		clientManager.makeClient("Jon", "Targaryen", "333333333", "basic");
		clientManager.makeClient("Ned", "Stark", "444444444", "basic");
		clientManager.makeClient("Arya", "Stark", "555555555", "basic");
		std::vector<Restaurant::Client_Ptr> const clientsExpectedResult
		{
			clientManager.getAllClients().at(3)
		};

		std::vector<Restaurant::Client_Ptr> const clientsActualResult =
				clientManager.findClientsByTelephoneNumber("444444444");

		BOOST_REQUIRE_EQUAL(compareVectors(clientsExpectedResult, clientsActualResult), true);
	}
	BOOST_AUTO_TEST_CASE(ClientManager_SaveClientsToFile_TestCase)
	{
		Restaurant::ClientManager clientManager;
		clientManager.makeClient("Jon", "Snow", "111111111", "basic");
		clientManager.makeClient("Aegon", "Snow", "222222222", "basic");
		clientManager.makeClient("Jon", "Targaryen", "333333333", "basic");
		clientManager.makeClient("Ned", "Stark", "444444444", "basic");
		clientManager.makeClient("Arya", "Stark", "555555555", "basic");

		clientManager.saveClientsToFile("ClientManagerTest.tmp");

		std::ifstream file;
		file.open("ClientManagerTest.tmp");
		std::string fileContent((std::istreambuf_iterator<char>(file)),
								 std::istreambuf_iterator<char>());
		file.close();
		BOOST_REQUIRE_EQUAL(fileContent,
				"Jon\nSnow\n111111111\nbasic\n\n"
				"Aegon\nSnow\n222222222\nbasic\n\n"
				"Jon\nTargaryen\n333333333\nbasic\n\n"
				"Ned\nStark\n444444444\nbasic\n\n"
				"Arya\nStark\n555555555\nbasic\n\n");
	}
	BOOST_AUTO_TEST_CASE(ClientManager_ReadClientsFromFile_TestCase)
	{
		Restaurant::ClientManager clientManager1, clientManager2;
		clientManager1.makeClient("Jon", "Snow", "111111111", "basic");
		clientManager1.makeClient("Aegon", "Snow", "222222222", "basic");
		clientManager1.makeClient("Jon", "Targaryen", "333333333", "basic");
		clientManager1.makeClient("Ned", "Stark", "444444444", "basic");
		clientManager1.makeClient("Arya", "Stark", "555555555", "basic");

		std::ofstream file;
		file.open("ClientManagerTest.tmp");
		file << "Jon\nSnow\n111111111\nbasic\n\n"
				"Aegon\nSnow\n222222222\nbasic\n\n"
				"Jon\nTargaryen\n333333333\nbasic\n\n"
				"Ned\nStark\n444444444\nbasic\n\n"
				"Arya\nStark\n555555555\nbasic\n\n";
		file.close();

		clientManager2.readClientsFromFile("ClientManagerTest.tmp");

		std::vector<Restaurant::Client_Ptr> clients1 = clientManager1.getAllClients(),
											clients2 = clientManager2.getAllClients();

		bool areEqual = true;

		for(auto i = clients1.begin(), j = clients2.begin();
			i != clients1.end() && j != clients2.end();
			i++, j++)
			if(!operator==(**i, **j))
			{
				areEqual = false;
				break;
			}

		BOOST_REQUIRE_EQUAL(areEqual, true);
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
    /*BOOST_AUTO_TEST_CASE(ClientManager_MakeClientAndSaveToFile_TestCase)
    {
        Restaurant::ClientManager clientManager;

        Restaurant::Client_Ptr client = clientManager.makeClient("John", "Smith",
                                                                 "123456789", "basic");
        clientManager.saveClientsToFile("~/clients.txt");

        //BOOST_REQUIRE_EQUAL(compareVectors({ client }, allClients), true);
    }*/
BOOST_AUTO_TEST_SUITE_END()
////////////////////////////////////////////////////////////////////////////////////////////////////
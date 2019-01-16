#include <boost/test/unit_test.hpp>
////////////////////////////////////////////////////////////////////////////////////////////////////
#include "Client.h"
#include "ClientRepository.h"
#include "ClientManager.h"
#include "HelperFunctions.h"
//--------------------------------------------------------------------------------------------------
BOOST_AUTO_TEST_SUITE(ClientRepository_CoreFunctionality_TestSuite)
	BOOST_AUTO_TEST_CASE(ClientRepository_FindClientsByFirstName_TestCase)
	{
		std::vector<Restaurant::Client_Ptr> const clients =
				{
					std::make_shared<Restaurant::Client>("Jon", "Snow", "111111111", "basic"),
					std::make_shared<Restaurant::Client>("Aegon", "Snow", "222222222", "basic"),
					std::make_shared<Restaurant::Client>("Jon", "Targaryen", "333333333", "basic"),
					std::make_shared<Restaurant::Client>("Ned", "Stark", "444444444", "basic"),
					std::make_shared<Restaurant::Client>("Arya", "Stark", "555555555", "basic")
				};
		std::vector<Restaurant::Client_Ptr> const clientsFirstName =
				{
					clients.at(0),
					clients.at(2)
				};

		Restaurant::ClientRepository clientRepository;
		for(auto const &client : clients)
			clientRepository.add(client);

		std::vector<Restaurant::Client_Ptr> foundClients =
				clientRepository.findClientsByFirstName("Jon");

		BOOST_REQUIRE_EQUAL(compareVectors(clientsFirstName, foundClients), true);
	}
	BOOST_AUTO_TEST_CASE(ClientRepository_FindClientsByLastName_TestCase)
	{
		std::vector<Restaurant::Client_Ptr> const clients =
				{
					std::make_shared<Restaurant::Client>("Jon", "Snow", "111111111", "basic"),
					std::make_shared<Restaurant::Client>("Aegon", "Stark", "222222222", "basic"),
					std::make_shared<Restaurant::Client>("Jon", "Targaryen", "333333333", "basic"),
					std::make_shared<Restaurant::Client>("Ned", "Snow", "444444444", "basic"),
					std::make_shared<Restaurant::Client>("Arya", "Stark", "555555555", "basic")
				};
		std::vector<Restaurant::Client_Ptr> const clientsLastName =
				{
					clients.at(1),
					clients.at(4)
				};

		Restaurant::ClientRepository clientRepository;
		for(auto const &client : clients)
			clientRepository.add(client);

		std::vector<Restaurant::Client_Ptr> foundClients =
				clientRepository.findClientsByLastName("Stark");

		BOOST_REQUIRE_EQUAL(compareVectors(clientsLastName, foundClients), true);
	}
	BOOST_AUTO_TEST_CASE(ClientRepository_FindClientsByTelephoneNumber_TestCase)
	{
		std::vector<Restaurant::Client_Ptr> const clients =
				{
					std::make_shared<Restaurant::Client>("Jon", "Snow", "111111111", "basic"),
					std::make_shared<Restaurant::Client>("Aegon", "Snow", "222222222", "basic"),
					std::make_shared<Restaurant::Client>("Jon", "Targaryen", "333333333", "basic"),
					std::make_shared<Restaurant::Client>("Ned", "Stark", "111111111", "basic"),
					std::make_shared<Restaurant::Client>("Arya", "Stark", "555555555", "basic")
				};
		std::vector<Restaurant::Client_Ptr> const clientsTelephoneNumber =
				{
					clients.at(0),
					clients.at(3)
				};

		Restaurant::ClientRepository clientRepository;
		for(auto const &client : clients)
			clientRepository.add(client);

		std::vector<Restaurant::Client_Ptr> foundClients =
				clientRepository.findClientsByTelephoneNumber("111111111");

		BOOST_REQUIRE_EQUAL(compareVectors(clientsTelephoneNumber, foundClients), true);
	}
BOOST_AUTO_TEST_SUITE_END()
////////////////////////////////////////////////////////////////////////////////////////////////////
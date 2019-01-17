#include "ClientManager.h"
#include "Client.h"
#include "RestaurantException.h"
#include <sstream>
#include <fstream>

////////////////////////////////////////////////////////////////////////////////////////////////////
Restaurant::Client_Ptr
Restaurant::ClientManager::makeClient(std::string const &firstName, std::string const &lastName,
									  std::string const &telephoneNumber,
									  std::string const &clientType)
{
	Restaurant::Client_Ptr client = std::make_shared<Restaurant::Client>(
										checkFirstName(firstName),
										checkLastName(lastName),
										checkTelephoneNumber(telephoneNumber),
										checkClientType(clientType)
									);
	clientRepository.add(client);
	return client;
}
//--------------------------------------------------------------------------------------------------
void Restaurant::ClientManager::removeClient(Restaurant::Client_Ptr const &client)
{
	clientRepository.remove(client);
}
//--------------------------------------------------------------------------------------------------
std::vector<Restaurant::Client_Ptr>
Restaurant::ClientManager::findClientsByFirstName(std::string const &firstName) const
{
	return clientRepository.findClientsByFirstName(firstName);
}
//--------------------------------------------------------------------------------------------------
std::vector<Restaurant::Client_Ptr>
Restaurant::ClientManager::findClientsByLastName(std::string const &lastName) const
{
	return clientRepository.findClientsByLastName(lastName);
}
//--------------------------------------------------------------------------------------------------
std::vector<Restaurant::Client_Ptr>
Restaurant::ClientManager::findClientsByTelephoneNumber(std::string const &telephoneNumber) const
{
	return clientRepository.findClientsByTelephoneNumber(telephoneNumber);
}
//--------------------------------------------------------------------------------------------------
void Restaurant::ClientManager::saveClientsToFile(std::string const &filename) const
{
	clientRepository.saveToFile(filename);
}
//--------------------------------------------------------------------------------------------------
void Restaurant::ClientManager::readClientsFromFile(std::string const &filename)
{
	std::ifstream file;
	file.open(filename);
	while(file.good())
	{
		std::string firstName, lastName, telephoneNumber, clientType;
		file >> firstName;
		file.get();
		file >> lastName;
		file.get();
		file >> telephoneNumber;
		file.get();
		file >> clientType;
		file.get();
		file.get();

		if(file.good())
		{
			checkFirstName(firstName);
			checkLastName(lastName);
			checkTelephoneNumber(telephoneNumber);
			checkClientType(clientType);
		}
	}
	file.close();

	clientRepository.readFromFile(filename);
}
//--------------------------------------------------------------------------------------------------
std::vector<Restaurant::Client_Ptr> Restaurant::ClientManager::getAllClients() const
{
	return clientRepository.getAll();
}
//--------------------------------------------------------------------------------------------------
std::string Restaurant::ClientManager::getInfo() const
{
	std::stringstream info;
	std::vector<Restaurant::Client_Ptr> clients = getAllClients();

	info << "Overall number of clients: " << clients.size();

	for(auto const &client : clients)
		info << "> "
			 << client->getFirstName() << " " << client->getLastName() << " | "
			 << client->getTelephoneNumber() << " | "
			 << "max. tables: " << client->getMaximumTableCount() << " | "
			 << client->getDiscountPercentage() << " % discount";


	return info.str();
}
//--------------------------------------------------------------------------------------------------
std::string const &
Restaurant::ClientManager::checkFirstName(std::string const &firstName) const
{
	for(auto const &character : firstName)
		if(		!(character >= 'a' && character <= 'z')
			&& 	!(character >= 'A' && character <= 'Z')
			&&	!(character == ' '))
			throw Restaurant::RestaurantException("First name must contain only "
												  "letters or spaces!");
	return firstName;
}
//--------------------------------------------------------------------------------------------------
std::string const &
Restaurant::ClientManager::checkLastName(std::string const &lastName) const
{
	for(auto const &character : lastName)
		if(		!(character >= 'a' && character <= 'z')
		   	&& 	!(character >= 'A' && character <= 'Z')
		   	&&	!(character == ' ' || character == '-'))
			throw Restaurant::RestaurantException("Last name must contain only "
												  "letters, spaces or hyphens!");
	return lastName;
}
//--------------------------------------------------------------------------------------------------
std::string const &
Restaurant::ClientManager::checkTelephoneNumber(std::string const &telephoneNumber) const
{
	for(auto const &character : telephoneNumber)
		if(		!(character >= '0' && character <= '9')
		  	&&	!(character == ' ' || character == '-'))
			throw Restaurant::RestaurantException("Telephone number must contain only "
												  "digits or spaces!");
	return telephoneNumber;
}
//--------------------------------------------------------------------------------------------------
std::string const &
Restaurant::ClientManager::checkClientType(std::string const &clientType) const
{
	if(clientType != "basic" && clientType != "premium")
		throw Restaurant::RestaurantException("Client type must be either "
											  "\"basic\" or \"premium\"!");
	return clientType;
}
////////////////////////////////////////////////////////////////////////////////////////////////////
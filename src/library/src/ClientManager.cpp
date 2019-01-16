#include "ClientManager.h"
#include "Client.h"
////////////////////////////////////////////////////////////////////////////////////////////////////
Restaurant::Client_Ptr
Restaurant::ClientManager::makeClient(std::string const &firstName, std::string const &lastName,
									  std::string const &telephoneNumber,
									  std::string const &clientType)
{
	/* TODO: Check parameters */
	Restaurant::Client_Ptr client = std::make_shared<Restaurant::Client>(firstName, lastName,
			telephoneNumber, clientType);
	clientRepository.add(client);
	return client;
}
//--------------------------------------------------------------------------------------------------
void Restaurant::ClientManager::removeClient(const Restaurant::Client_Ptr &client)
{
	clientRepository.remove(client);
}
//--------------------------------------------------------------------------------------------------
std::vector<Restaurant::Client_Ptr>
Restaurant::ClientManager::findClientsByFirstName(std::string const &firstName) const
{
	return std::vector<Restaurant::Client_Ptr>();
}
//--------------------------------------------------------------------------------------------------
std::vector<Restaurant::Client_Ptr>
Restaurant::ClientManager::findClientsByLastName(std::string const &lastName) const
{
	return std::vector<Restaurant::Client_Ptr>();
}
//--------------------------------------------------------------------------------------------------
std::vector<Restaurant::Client_Ptr>
Restaurant::ClientManager::findClientsByTelephoneNumber(std::string const &telephoneNumber) const
{
	return std::vector<Restaurant::Client_Ptr>();
}
//--------------------------------------------------------------------------------------------------
void Restaurant::ClientManager::saveClientsToFile(std::string const &filename) const
{

}
//--------------------------------------------------------------------------------------------------
void Restaurant::ClientManager::readClientsFromFile(std::string const &filename)
{

}
//--------------------------------------------------------------------------------------------------
std::vector<Restaurant::Client_Ptr> Restaurant::ClientManager::getAllClients() const
{
	return clientRepository.getAll();
}
//--------------------------------------------------------------------------------------------------
std::string Restaurant::ClientManager::getInfo() const
{
	return std::__cxx11::string();
}
////////////////////////////////////////////////////////////////////////////////////////////////////
#include "ClientManager.h"
////////////////////////////////////////////////////////////////////////////////////////////////////
Restaurant::Client_Ptr
Restaurant::ClientManager::makeClient(std::string const &firstName, std::string const &lastName,
									  std::string const &telephoneNumber,
									  std::string const &clientType)
{
	return Restaurant::Client_Ptr();
}
//--------------------------------------------------------------------------------------------------
void Restaurant::ClientManager::removeClient(const Restaurant::Client_Ptr &client)
{

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
	return std::vector<Restaurant::Client_Ptr>();
}
//--------------------------------------------------------------------------------------------------
std::string Restaurant::ClientManager::getInfo() const
{
	return std::__cxx11::string();
}
////////////////////////////////////////////////////////////////////////////////////////////////////
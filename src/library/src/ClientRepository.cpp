#include "Client.h"
#include "ClientRepository.h"
#include <algorithm>
#include <fstream>
////////////////////////////////////////////////////////////////////////////////////////////////////
std::vector<Restaurant::Client_Ptr>
Restaurant::ClientRepository::findClientsByFirstName(std::string const &firstName) const
{
	return findClientsByValue(firstName, "firstName");
}
//--------------------------------------------------------------------------------------------------
std::vector<Restaurant::Client_Ptr>
Restaurant::ClientRepository::findClientsByLastName(std::string const &lastName) const
{
	return findClientsByValue(lastName, "lastName");
}
//--------------------------------------------------------------------------------------------------
std::vector<Restaurant::Client_Ptr>
Restaurant::ClientRepository::findClientsByTelephoneNumber(std::string const &telephoneNumber) const
{
	return findClientsByValue(telephoneNumber, "telephoneNumber");
}
//--------------------------------------------------------------------------------------------------
void Restaurant::ClientRepository::saveToFile(std::string const &filename) const
{
	std::ofstream file;
	file.open(filename);

	for(auto const &client : getAll())
		file << client->getFirstName() << "\n"
			 << client->getLastName() << "\n"
			 << client->getTelephoneNumber() << "\n"
			 << client->getClientType() << "\n\n";

	file.close();
}
void Restaurant::ClientRepository::readFromFile(std::string const &filename)
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

		if(file.good())
			add(std::make_shared<Restaurant::Client>(firstName, lastName,
					telephoneNumber, clientType));
	}
	file.close();
}
//--------------------------------------------------------------------------------------------------
std::vector<Restaurant::Client_Ptr>
Restaurant::ClientRepository::findClientsByValue(std::string const &value,
												 std::string const &type) const
{
	std::vector<Restaurant::Client_Ptr> clients;

	for(auto i = elements.begin();
		(i = std::find_if(i, elements.end(),
			[&value, &type](Restaurant::Client_Ptr const &client) -> bool
			{
					 if(type == "firstName") 		return (client->getFirstName() == value);
				else if(type == "lastName") 		return (client->getLastName() == value);
				else if(type == "telephoneNumber") 	return (client->getTelephoneNumber() == value);
				else 								return false;
			}
			)) != elements.end();
		i++)
		clients.push_back(*i);

	return clients;
}
////////////////////////////////////////////////////////////////////////////////////////////////////
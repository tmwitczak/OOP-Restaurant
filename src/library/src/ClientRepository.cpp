#include "Client.h"
#include "ClientRepository.h"
#include <algorithm>
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
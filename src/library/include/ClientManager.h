#ifndef RESTAURANT_CLIENTMANAGER_H
#define RESTAURANT_CLIENTMANAGER_H
////////////////////////////////////////////////////////////////////////////////////////////////////
#include <boost/date_time/local_time/local_date_time.hpp>
#include "ClientRepository.h"

namespace Restaurant
{
	class Client;
	//class Table;

	typedef std::shared_ptr<Client> Client_Ptr;
	//typedef std::shared_ptr<Table> Table_Ptr;

	//typedef std::shared_ptr<boost::local_time::local_date_time> DateTime_Ptr;
}
//--------------------------------------------------------------------------------------------------
namespace Restaurant
{
	class ClientManager
	{
	public:
		Client_Ptr makeClient(std::string const &firstName, std::string const &lastName,
							  std::string const &telephoneNumber, std::string const &clientType);
		void removeClient(Client_Ptr const &client);
		std::vector<Client_Ptr> findClientsByFirstName(std::string const &firstName) const;
		std::vector<Client_Ptr> findClientsByLastName(std::string const &lastName) const;
		std::vector<Client_Ptr> findClientsByTelephoneNumber(
				std::string const &telephoneNumber) const;
		void saveClientsToFile(std::string const &filename) const;
		void readClientsFromFile(std::string const &filename);
		std::vector<Client_Ptr> getAllClients() const;
		std::string getInfo() const;

	private:
		ClientRepository clientRepository;
	};
}
////////////////////////////////////////////////////////////////////////////////////////////////////
#endif /* RESTAURANT_CLIENTMANAGER_H */
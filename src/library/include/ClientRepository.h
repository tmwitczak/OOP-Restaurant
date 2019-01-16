#ifndef RESTAURANT_CLIENTREPOSITORY_H
#define RESTAURANT_CLIENTREPOSITORY_H
////////////////////////////////////////////////////////////////////////////////////////////////////
//#include "Client.h"
#include "Repository.h"
#include <memory>

namespace Restaurant
{
	class Client;

	typedef std::shared_ptr<Client> Client_Ptr;
}
//--------------------------------------------------------------------------------------------------
namespace Restaurant
{
	class ClientRepository
			: public Repository<Client_Ptr>
	{
	public:
		std::vector<Client_Ptr> findClientsByFirstName(std::string firstName) const;
		std::vector<Client_Ptr> findClientsByLastName(std::string lastName) const;
		std::vector<Client_Ptr> findClientsByTelephoneNumber(std::string telephoneNumber) const;
	};
}
////////////////////////////////////////////////////////////////////////////////////////////////////
#endif /* RESTAURANT_CLIENTREPOSITORY_H */
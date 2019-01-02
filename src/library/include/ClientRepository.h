#ifndef RESTAURANT_CLIENTREPOSITORY_H
#define RESTAURANT_CLIENTREPOSITORY_H
////////////////////////////////////////////////////////////////////////////////////////////////////
//#include "Client.h"
#include "Repository.h"
#include <memory>
//--------------------------------------------------------------------------------------------------
namespace Restaurant
{
	class Client;//#include "Client.h"

	class ClientRepository
			: public Repository<std::shared_ptr<Client>>
	{
	public:
		std::vector<std::shared_ptr<Client>> findClientsByFirstName(std::string firstName) const;
		std::vector<std::shared_ptr<Client>> findClientsByLastName(std::string lastName) const;
		std::vector<std::shared_ptr<Client>> findClientsByTelephoneNumber(std::string telephoneNumber) const;
	};
}
////////////////////////////////////////////////////////////////////////////////////////////////////
#endif /* RESTAURANT_CLIENTREPOSITORY_H */
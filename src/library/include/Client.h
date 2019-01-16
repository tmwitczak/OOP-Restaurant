#ifndef RESTAURANT_CLIENT_H
#define RESTAURANT_CLIENT_H
////////////////////////////////////////////////////////////////////////////////////////////////////
#include <string>
#include <memory>
#include "ClientType.h"

namespace Restaurant
{
	class ClientType;

	typedef std::shared_ptr<ClientType> ClientType_Ptr;
}
//--------------------------------------------------------------------------------------------------
namespace Restaurant
{
	class Client
	{
	public:
		Client(std::string const &firstName, std::string const &lastName,
				std::string const &telephoneNumber, std::string const &clientType);
		~Client();

		std::string getFirstName() 			const;
		std::string getLastName() 			const;
		std::string getTelephoneNumber() 	const;
		double 		getDiscountPercentage() const;
		int 		getMaximumTableCount() 	const;

	private:
		std::string const firstName,
						  lastName,
						  telephoneNumber;
		ClientType_Ptr const clientType;

		ClientType_Ptr makeClientType(std::string const &clientTypeString) const;
	};
}
////////////////////////////////////////////////////////////////////////////////////////////////////
#endif /* RESTAURANT_CLIENT_H */
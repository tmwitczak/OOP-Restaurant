#ifndef RESTAURANT_CLIENT_H
#define RESTAURANT_CLIENT_H
/////////////////////////////////////////////////////////////////////////////////// Included headers
#include "ClientType.h"
#include <string>
#include <memory>

namespace Restaurant
{
	/////////////////////////////////////////////////////////////////////////// Forward declarations
	class ClientType;

	/////////////////////////////////////////////////////////////////////////////////////// Typedefs
	typedef std::shared_ptr<ClientType> ClientType_Ptr;

	/////////////////////////////////////////////////////////////////////////////// Class definition
	class Client
	{
	//---------------------------------------------------------------------------------- [ Methods ]
	public:
		//--------------------------------------------------------------------------- Constructors <
		Client(std::string const &firstName, std::string const &lastName,
				std::string const &telephoneNumber, std::string const &clientType);

		//-------------------------------------------------------------------------------- Getters <
		std::string 	getFirstName() 			const;
		std::string 	getLastName() 			const;
		std::string 	getTelephoneNumber() 	const;
		double 			getDiscountPercentage() const;
		int 			getMaximumTableCount() 	const;
		std::string 	getClientType() 		const;

	private:
		//-------------------------------------------------------- Construct ClientType delegation <
		ClientType_Ptr makeClientType(std::string const &clientTypeString) const;

	//----------------------------------------------------------------------------------- [ Fields ]
	private:
		std::string 	const 	firstName,
						  		lastName,
						  		telephoneNumber;
		ClientType_Ptr 	const 	clientType;
	};
}
////////////////////////////////////////////////////////////////////////////////////////////////////
#endif /* RESTAURANT_CLIENT_H */
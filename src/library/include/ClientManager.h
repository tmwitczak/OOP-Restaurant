#ifndef RESTAURANT_CLIENTMANAGER_H
#define RESTAURANT_CLIENTMANAGER_H
/////////////////////////////////////////////////////////////////////////////////// Included headers
#include "ClientRepository.h"

namespace Restaurant
{
	/////////////////////////////////////////////////////////////////////////// Forward declarations
	class Client;

	/////////////////////////////////////////////////////////////////////////////////////// Typedefs
	typedef std::shared_ptr<Client> Client_Ptr;

	/////////////////////////////////////////////////////////////////////////////// Class definition
	class ClientManager
	{
	//---------------------------------------------------------------------------------- [ Methods ]
	public:
		//------------------------------------------------------------ Client creation and removal <
		Client_Ptr 	makeClient(std::string const &firstName, std::string const &lastName,
							   std::string const &telephoneNumber, std::string const &clientType);
		void 		removeClient(Client_Ptr const &client);

		//------------------------------------------------------------------------- Search methods <
		std::vector<Client_Ptr> findClientsByFirstName(std::string const &firstName) 	const;
		std::vector<Client_Ptr> findClientsByLastName(std::string const &lastName) 		const;
		std::vector<Client_Ptr> findClientsByTelephoneNumber(
												std::string const &telephoneNumber) 	const;

		//------------------------------------------------------------------------ File operations <
		void saveClientsToFile(std::string const &filename) 	const;
		void readClientsFromFile(std::string const &filename);

		//-------------------------------------------------------------------------------- Getters <
		std::vector<Client_Ptr> getAllClients() const;
		std::string 			getInfo() 		const;

	private:
		//------------------------------------------------------------------------ Parameter check <
		std::string const &checkFirstName(std::string const &firstName) 			const;
		std::string const &checkLastName(std::string const &lastName) 				const;
		std::string const &checkTelephoneNumber(std::string const &telephoneNumber) const;
		std::string const &checkClientType(std::string const &clientType) 			const;

	//----------------------------------------------------------------------------------- [ Fields ]
	private:
		ClientRepository clientRepository;
	};
}
////////////////////////////////////////////////////////////////////////////////////////////////////
#endif /* RESTAURANT_CLIENTMANAGER_H */
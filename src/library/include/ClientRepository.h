#ifndef RESTAURANT_CLIENTREPOSITORY_H
#define RESTAURANT_CLIENTREPOSITORY_H
/////////////////////////////////////////////////////////////////////////////////// Included headers
#include "Repository.h"
#include <string>
#include <vector>
#include <memory>

namespace Restaurant
{
	/////////////////////////////////////////////////////////////////////////// Forward declarations
	class Client;

	/////////////////////////////////////////////////////////////////////////////////////// Typedefs
	typedef std::shared_ptr<Client> Client_Ptr;

	/////////////////////////////////////////////////////////////////////////////// Class definition
	class ClientRepository
			: public Repository<Client_Ptr>
	{
	//---------------------------------------------------------------------------------- [ Methods ]
	public:
		//------------------------------------------------------------------------- Search methods <
		std::vector<Client_Ptr> findClientsByFirstName(std::string const &firstName) const;
		std::vector<Client_Ptr> findClientsByLastName(std::string const &lastName) const;
		std::vector<Client_Ptr> findClientsByTelephoneNumber(
				std::string const &telephoneNumber) const;

		//------------------------------------------------------------------------ File operations <
		void saveToFile(std::string const &filename) const override;
		void readFromFile(std::string const &filename) override;

	private:
		//----------------------------------------------------------------------- Helper functions <
		std::vector<Client_Ptr> findClientsByValue(std::string const &value,
				std::string const &type) const;
	};
}
////////////////////////////////////////////////////////////////////////////////////////////////////
#endif /* RESTAURANT_CLIENTREPOSITORY_H */
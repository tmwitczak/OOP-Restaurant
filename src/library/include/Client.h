#ifndef RESTAURANT_CLIENT_H
#define RESTAURANT_CLIENT_H
////////////////////////////////////////////////////////////////////////////////////////////////////
#include <string>
//--------------------------------------------------------------------------------------------------
namespace Restaurant
{
	class Client
	{
	public:
		Client(std::string const &firstName, std::string const &lastName,
				std::string const &telephoneNumber, std::string const &clientType);
	private:
		std::string const firstName,
						  lastName,
						  telephoneNumber;
	};
}
////////////////////////////////////////////////////////////////////////////////////////////////////
#endif /* RESTAURANT_CLIENT_H */
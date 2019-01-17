#ifndef RESTAURANT_CLIENTTYPE_H
#define RESTAURANT_CLIENTTYPE_H
/////////////////////////////////////////////////////////////////////////////////// Included headers
#include <string>

namespace Restaurant
{
	/////////////////////////////////////////////////////////////////////////////// Class definition
	class ClientType
	{
	//---------------------------------------------------------------------------------- [ Methods ]
	public:
		//--------------------------------------------------------------------------- Constructors <
		ClientType(std::string const &clientType);

		//----------------------------------------------------------------------------- Destructor <
		virtual ~ClientType() = default;

		//-------------------------------------------------------------------------------- Getters <
		virtual double 		getDiscountPercentage() const = 0;
		virtual int 		getMaximumTableCount() 	const = 0;
		virtual std::string getClientType() 		const;

	//----------------------------------------------------------------------------------- [ Fields ]
	private:
		std::string const clientType;
	};
}
////////////////////////////////////////////////////////////////////////////////////////////////////
#endif /* RESTAURANT_CLIENTTYPE_H */
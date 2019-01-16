#ifndef RESTAURANT_RESTAURANTEXCEPTION_H
#define RESTAURANT_RESTAURANTEXCEPTION_H
/////////////////////////////////////////////////////////////////////////////////// Included headers
#include <string>

namespace Restaurant
{
	/////////////////////////////////////////////////////////////////////////////// Class definition
	class RestaurantException
	{
	//---------------------------------------------------------------------------------- [ Methods ]
	public:
		//--------------------------------------------------------------------------- Constructors <
		explicit RestaurantException(std::string const &message);

		//-------------------------------------------------------------------------------- Getters <
		std::string getMessage() const;

	//----------------------------------------------------------------------------------- [ Fields ]
	private:
		std::string const message;
	};
}
////////////////////////////////////////////////////////////////////////////////////////////////////
#endif /* RESTAURANT_RESTAURANTEXCEPTION_H */
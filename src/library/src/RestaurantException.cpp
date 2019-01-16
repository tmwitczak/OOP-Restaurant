#include "RestaurantException.h"
////////////////////////////////////////////////////////////////////////////////////////////////////
Restaurant::RestaurantException::RestaurantException(std::string const &message)
	:	message(message)
{
}
//--------------------------------------------------------------------------------------------------
std::string Restaurant::RestaurantException::getMessage() const
{
	return message;
}
////////////////////////////////////////////////////////////////////////////////////////////////////
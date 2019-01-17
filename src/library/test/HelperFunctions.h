#ifndef RESTAURANT_HELPERFUNCTIONS_H
#define RESTAURANT_HELPERFUNCTIONS_H
////////////////////////////////////////////////////////////////////////////////////////////////////
#include <boost/date_time/local_time/local_date_time.hpp>
#include <algorithm>

namespace Restaurant
{
	class Client;
	class Table;

	typedef std::shared_ptr<Client> 							Client_Ptr;
	typedef std::shared_ptr<Table> 								Table_Ptr;
	typedef std::shared_ptr<boost::local_time::local_date_time> DateTime_Ptr;
}
//--------------------------------------------------------------------------------------------------
std::tuple<std::string, std::string, std::string, std::string> getClientParameters();
std::tuple<Restaurant::Client_Ptr, std::vector<Restaurant::Table_Ptr>, Restaurant::DateTime_Ptr,
		Restaurant::DateTime_Ptr> getReservationParameters();
//--------------------------------------------------------------------------------------------------
template <typename T>
bool compareVectors(std::vector<T> const &vector1, std::vector<T> const &vector2)
{
	if(vector1.empty() && vector2.empty())
		return true;

	if(vector1.empty() != vector2.empty())
		return false;

	if(vector1.size() < vector2.size())
		return std::equal(vector1.begin(), vector1.end(), vector2.begin());
	else
		return std::equal(vector2.begin(), vector2.end(), vector1.begin());
}
////////////////////////////////////////////////////////////////////////////////////////////////////
#endif /* RESTAURANT_HELPERFUNCTIONS_H */

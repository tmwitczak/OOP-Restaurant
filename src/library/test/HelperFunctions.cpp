#include <string>
#include <tuple>
#include <vector>
#include "ClientManager.h"
#include "TableManager.h"
#include "Reservation.h"
#include "Client.h"
#include "Table.h"
#include <boost/date_time/local_time/local_time.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>

using namespace boost::gregorian;
using namespace boost::local_time;
using namespace boost::posix_time;
////////////////////////////////////////////////////////////////////////////////////////////////////
std::tuple<std::string, std::string, std::string, std::string> getClientParameters()
{
	return 	{
			/* firstName */ 		"John",
			/* lastName */ 			"Smith",
			/* telephoneNumber */ 	"123456789",
			/* clientType */ 		"basic"
	};
}
//--------------------------------------------------------------------------------------------------
std::tuple<Restaurant::Client_Ptr, std::vector<Restaurant::Table_Ptr>, Restaurant::DateTime_Ptr,
		   Restaurant::DateTime_Ptr> getReservationParameters()
{
	return	{	std::make_shared<Restaurant::Client>(
					Restaurant::Client("John", "Smith", "123456789", "basic")),
				   { std::make_shared<Restaurant::Table>(Restaurant::Table(2)) },
				   { std::make_shared<local_date_time>(
						   local_date_time( ptime(date(2019, 01, 07), hours(18)), time_zone_ptr (new posix_time_zone("CET+01"))) )} ,
				   { std::make_shared<local_date_time>(
						   local_date_time( ptime(date(2019, 01, 07), hours(20)), time_zone_ptr (new posix_time_zone("CET+01"))) )}
			};
}
////////////////////////////////////////////////////////////////////////////////////////////////////
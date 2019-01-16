#include <boost/test/unit_test.hpp>
////////////////////////////////////////////////////////////////////////////////////////////////////
#include "Reservation.h"
#include "Client.h"
#include "Table.h"
#include "HelperFunctions.h"
#include <boost/date_time/local_time/local_time.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>
//--------------------------------------------------------------------------------------------------
using namespace boost::gregorian;
using namespace boost::local_time;
using namespace boost::posix_time;
//--------------------------------------------------------------------------------------------------
std::tuple<Restaurant::Client_Ptr, std::vector<Restaurant::Table_Ptr>, Restaurant::DateTime_Ptr, Restaurant::DateTime_Ptr> getReservationParameters()
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
//--------------------------------------------------------------------------------------------------
BOOST_AUTO_TEST_SUITE(Reservation_CoreFunctionality_TestSuite)
	BOOST_AUTO_TEST_CASE(Reservation_ConstructAndGetClient_TestCase)
	{
		auto const [client1, tables, beginTime, endTime] = getReservationParameters();

		Restaurant::Reservation reservation(client1, tables, beginTime, endTime);
		Restaurant::Client_Ptr const client2 = reservation.getClient();

		BOOST_REQUIRE_EQUAL(client1, client2);
	}
	BOOST_AUTO_TEST_CASE(Reservation_ConstructAndGetTables_TestCase)
	{
		auto const [client, tables1, beginTime, endTime] = getReservationParameters();

		Restaurant::Reservation reservation(client, tables1, beginTime, endTime);
		std::vector<Restaurant::Table_Ptr> const tables2 = reservation.getTables();

		BOOST_REQUIRE_EQUAL(compareVectors(tables1, tables2), true);
	}
	BOOST_AUTO_TEST_CASE(Reservation_ConstructAndGetID_TestCase)
	{
		// TODO: Is this test really needed?
	}
	BOOST_AUTO_TEST_CASE(Reservation_ConstructAndGetBeginTime_TestCase)
	{
		auto const [client, tables, beginTime1, endTime] = getReservationParameters();

		Restaurant::Reservation reservation(client, tables, beginTime1, endTime);
		Restaurant::DateTime_Ptr const beginTime2 = reservation.getBeginTime();

		BOOST_REQUIRE_EQUAL(beginTime1, beginTime2);
	}
	BOOST_AUTO_TEST_CASE(Reservation_ConstructAndGetEndTime_TestCase)
	{
		auto const [client, tables, beginTime, endTime1] = getReservationParameters();

		Restaurant::Reservation reservation(client, tables, beginTime, endTime1);
		Restaurant::DateTime_Ptr const endTime2 = reservation.getEndTime();

		BOOST_REQUIRE_EQUAL(endTime1, endTime2);
	}
	// TODO: Write tests for exceptions in constructor
BOOST_AUTO_TEST_SUITE_END()
////////////////////////////////////////////////////////////////////////////////////////////////////
#include <boost/test/unit_test.hpp>
////////////////////////////////////////////////////////////////////////////////////////////////////
#include "Reservation.h"
#include "Client.h"
#include "Table.h"
#include "HelperFunctions.h"
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
		auto const [client, tables, beginTime, endTime] = getReservationParameters();

		std::vector<Restaurant::Reservation> reservations;
		for(int i = 0; i < 10; i++)
			reservations.push_back(Restaurant::Reservation(client, tables, beginTime, endTime));

		for(auto i = reservations.begin(); i != reservations.end(); i++)
			for(auto j = reservations.begin(); j != reservations.end(); j++)
				if(i != j)
					BOOST_REQUIRE_EQUAL(i->getID() != j->getID(), true);
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
BOOST_AUTO_TEST_SUITE_END()
////////////////////////////////////////////////////////////////////////////////////////////////////
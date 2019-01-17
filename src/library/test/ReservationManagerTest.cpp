#include <boost/test/unit_test.hpp>
////////////////////////////////////////////////////////////////////////////////////////////////////
#include <vector>
#include "Reservation.h"
#include "ReservationManager.h"
#include "TableManager.h"
#include "ClientManager.h"
#include "Client.h"
#include "Table.h"
#include "HelperFunctions.h"
#include <boost/date_time/local_time/local_time.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>
#include "RestaurantException.h"
#include <iostream>
#include <string>


//--------------------------------------------------------------------------------------------------
using namespace boost::gregorian;
using namespace boost::local_time;
using namespace boost::posix_time;
//--------------------------------------------------------------------------------------------------
std::tuple<Restaurant::Client_Ptr, std::vector<Restaurant::Table_Ptr>, Restaurant::DateTime_Ptr, Restaurant::DateTime_Ptr> getReservationParameters2() //TODO: Can we use getReservationParameters() from ReservationTest??
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
bool operator==(Restaurant::Reservation const &reservation1,
                Restaurant::Reservation const &reservation2)
{
    if(		reservation1.getClient() 			== reservation2.getClient()
               && 	reservation1.getTables() 	== reservation2.getTables()
             //&& 	reservation1.getID() 	    == reservation2.getID()
               && 	reservation1.getBeginTime() == reservation2.getBeginTime()
               && 	reservation1.getEndTime() 	== reservation2.getEndTime())
        return true;
    else
        return false;
}
//--------------------------------------------------------------------------------------------------
BOOST_AUTO_TEST_SUITE(ReservationManager_CoreFunctionality_TestSuite)
    BOOST_AUTO_TEST_CASE(ReservationManager_MakeReservation_TestCase)
    {
        Restaurant::ReservationManager reservationManager;
        auto const [client1, tables, beginTime, endTime] =  getReservationParameters2();
        Restaurant::Reservation reservation1(client1, tables, beginTime, endTime);
        	//	std::make_shared<local_date_time>(local_date_time( ptime(date(2019, 01, 07), hours(18)), time_zone_ptr (new posix_time_zone("CET+01"))) ),
        	//	std::make_shared<local_date_time>(local_date_time( ptime(date(2019, 01, 07), hours(19)), time_zone_ptr (new posix_time_zone("CET+01"))) ));

        Restaurant::Reservation_Ptr reservation2 = reservationManager.makeReservation(client1, tables, beginTime, endTime);

        BOOST_REQUIRE_EQUAL(reservation1 == *reservation2, true);
    }
    BOOST_AUTO_TEST_CASE(ReservationManager_MakeReservationAndGetAllReservations_TestCase)
    {
        Restaurant::ReservationManager reservationManager;
        auto const [client1, tables, beginTime, endTime] =  getReservationParameters2();

        Restaurant::Reservation_Ptr reservation1 = reservationManager.makeReservation(client1, tables, beginTime, endTime);
        std::vector<Restaurant::Reservation_Ptr> allReservations = reservationManager.getAllReservations();

        BOOST_REQUIRE_EQUAL(compareVectors({ reservation1 }, allReservations), true);
    }
    BOOST_AUTO_TEST_CASE(ReservationManager_MakeReservationThenRemoveReservationAndGetAllReservation_TestCase)
    {
        Restaurant::ReservationManager reservationManager;
        auto const [client1, tables, beginTime, endTime] =  getReservationParameters2();

        Restaurant::Reservation_Ptr reservation1 = reservationManager.makeReservation(client1, tables, beginTime, endTime),
                                    reservation2 = reservationManager.makeReservation( std::make_shared<Restaurant::Client>(Restaurant::Client("Jane", "Smith",
                                                                                                         "123456789", "premium")), { std::make_shared<Restaurant::Table>(Restaurant::Table(3)) },
                                                                                                         beginTime, endTime);
        reservationManager.cancelReservation(reservation1);
        std::vector<Restaurant::Reservation_Ptr> allReservations = reservationManager.getAllReservations();

        BOOST_REQUIRE_EQUAL(compareVectors({ reservation2 }, allReservations), true);
    }
    BOOST_AUTO_TEST_CASE(ReservationManager_MakeReservationWithWrongDate_TestCase)
    {
        Restaurant::ReservationManager reservationManager;
        auto const [client1, tables, beginTime, endTime] =  getReservationParameters2();
        std::string message;

        try
        {
            Restaurant::Reservation_Ptr reservation1 = reservationManager.makeReservation(client1, tables,
                    std::make_shared<local_date_time>(local_date_time( ptime(date(2019, 1, 7), hours(18)), time_zone_ptr (new posix_time_zone("CET+01"))) ),
                    std::make_shared<local_date_time>(local_date_time( ptime(date(2018, 1, 8), hours(18)), time_zone_ptr (new posix_time_zone("CET+01"))) ));
        }
        catch(Restaurant::RestaurantException const &exception)
        {
            message = exception.getMessage();
        }
        BOOST_REQUIRE_EQUAL(message, "EndTime can not be before BeginTime!");
    }
    BOOST_AUTO_TEST_CASE(ReservationManager_MakeReservationDuringAnotherOne_TestCase)
    {
        Restaurant::ReservationManager reservationManager;
        auto const [client1, tables, beginTime, endTime] =  getReservationParameters2();
        std::string message;
        try
        {
            Restaurant::Reservation_Ptr reservation1 = reservationManager.makeReservation(client1, tables, beginTime, endTime),
                    reservation2 = reservationManager.makeReservation( std::make_shared<Restaurant::Client>(Restaurant::Client("Jane", "Smith",
                                                                                                                               "123456789", "premium")),
                                                                       tables, beginTime, endTime);


        }
        catch(Restaurant::RestaurantException const &exception)
        {
            message = exception.getMessage();
        }

        BOOST_REQUIRE_EQUAL(message, "This table is unavailable at this time!");
    }
	BOOST_AUTO_TEST_CASE(ReservationManager_SaveReservationToFile_TestCase)
	{
		auto const [client, tables, beginTime, endTime] = getReservationParameters();

		Restaurant::ClientManager clientManager;
		clientManager.makeClient("Jon", "Snow", "111111111", "basic");
		clientManager.makeClient("Aegon", "Snow", "222222222", "basic");
		clientManager.makeClient("Jon", "Targaryen", "333333333", "basic");
		clientManager.makeClient("Ned", "Stark", "444444444", "basic");
		clientManager.makeClient("Arya", "Stark", "555555555", "basic");

		Restaurant::TableManager tableManager;
		tableManager.makeTable(1);
		tableManager.makeTable(1);
		tableManager.makeTable(1);
		tableManager.makeTable(1);
		tableManager.makeTable(1);

		Restaurant::ReservationManager reservationManager;
		for(int i = 0; i < 5; i++)
			reservationManager.makeReservation(clientManager.getAllClients().at(i), tableManager.getAllTables().at(i), beginTime, endTime);

		reservationManager.saveReservationsToFile("ReservationManagerTest.tmp");

		std::ifstream file;
		file.open("ReservationManagerTest.tmp");
		std::string fileContent((std::istreambuf_iterator<char>(file)),
								std::istreambuf_iterator<char>());
		file.close();
		BOOST_REQUIRE_EQUAL(fileContent,
							"Jon\nSnow\n111111111\nbasic\n1\n1\n2019-Jan-07 19:00:00 CET\n2019-Jan-07 21:00:00 CET\n\n"
							"Aegon\nSnow\n222222222\nbasic\n1\n1\n2019-Jan-07 19:00:00 CET\n2019-Jan-07 21:00:00 CET\n\n"
							"Jon\nTargaryen\n333333333\nbasic\n1\n1\n2019-Jan-07 19:00:00 CET\n2019-Jan-07 21:00:00 CET\n\n"
							"Ned\nStark\n444444444\nbasic\n1\n1\n2019-Jan-07 19:00:00 CET\n2019-Jan-07 21:00:00 CET\n\n"
							"Arya\nStark\n555555555\nbasic\n1\n1\n2019-Jan-07 19:00:00 CET\n2019-Jan-07 21:00:00 CET\n\n");
	}
	BOOST_AUTO_TEST_CASE(ReservationManager_ReadReservationsFromFile_TestCase)
	{
		auto const [client, tables, beginTime, endTime] = getReservationParameters();

		Restaurant::ClientManager clientManager;
		clientManager.makeClient("Jon", "Snow", "111111111", "basic");
		clientManager.makeClient("Aegon", "Snow", "222222222", "basic");
		clientManager.makeClient("Jon", "Targaryen", "333333333", "basic");
		clientManager.makeClient("Ned", "Stark", "444444444", "basic");
		clientManager.makeClient("Arya", "Stark", "555555555", "basic");

		Restaurant::TableManager tableManager;
		tableManager.makeTable(1);
		tableManager.makeTable(1);
		tableManager.makeTable(1);
		tableManager.makeTable(1);
		tableManager.makeTable(1);

		Restaurant::ReservationManager reservationManager, reservationManager2;
        for(int i = 0; i < 5; i++)
            reservationManager.makeReservation(clientManager.getAllClients()[i], tableManager.getAllTables()[i],
                                               std::make_shared<local_date_time>(local_date_time( ptime(date(2019, 1, 7), hours(18+5*i)), time_zone_ptr (new posix_time_zone("CET+01"))) ),
                                               std::make_shared<local_date_time>(local_date_time( ptime(date(2019, 1, 8), hours(19+5*i)), time_zone_ptr (new posix_time_zone("CET+01"))) ));

		reservationManager.saveReservationsToFile("ReservationManagerTest.tmp");

		std::ofstream file;
		file.open("ReservationManagerTest.tmp");
		file << "Jon\nSnow\n111111111\nbasic\n1\n1\n2019-Jan-07 19:00:00 CET\n2019-Jan-07 21:00:00 CET\n\n"
				"Aegon\nSnow\n222222222\nbasic\n1\n1\n2019-Jan-07 19:00:00 CET\n2019-Jan-07 21:00:00 CET\n\n"
				"Jon\nTargaryen\n333333333\nbasic\n1\n1\n2019-Jan-07 19:00:00 CET\n2019-Jan-07 21:00:00 CET\n\n"
				"Ned\nStark\n444444444\nbasic\n1\n1\n2019-Jan-07 19:00:00 CET\n2019-Jan-07 21:00:00 CET\n\n"
				"Arya\nStark\n555555555\nbasic\n1\n1\n2019-Jan-07 19:00:00 CET\n2019-Jan-07 21:00:00 CET\n\n";
		file.close();

		reservationManager2.readReservationsFromFile("ReservationManagerTest.tmp");

		std::vector<Restaurant::Reservation_Ptr> reservations1 = reservationManager.getAllReservations(),
				reservations2 = reservationManager2.getAllReservations();

		bool areEqual = true;

		for(auto i = reservations1.begin(), j = reservations2.begin();
			i != reservations1.end() && j != reservations2.end();
			i++, j++)
			if(!operator==(**i, **j))
			{
				areEqual = false;
				break;
			}

		BOOST_REQUIRE_EQUAL(areEqual, false);
	}
BOOST_AUTO_TEST_SUITE_END()
////////////////////////////////////////////////////////////////////////////////////////////////////
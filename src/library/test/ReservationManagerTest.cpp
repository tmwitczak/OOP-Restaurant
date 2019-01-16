#include <boost/test/unit_test.hpp>
////////////////////////////////////////////////////////////////////////////////////////////////////
#include <vector>
#include "Reservation.h"
#include "ReservationManager.h"
#include "Client.h"
#include "Table.h"
#include <boost/date_time/local_time/local_time.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>
//--------------------------------------------------------------------------------------------------
using namespace boost::gregorian;
using namespace boost::local_time;
using namespace boost::posix_time;
//--------------------------------------------------------------------------------------------------
template <typename T>
bool compareVectors(std::vector<T> const &vector1, std::vector<T> const &vector2)
{
    if(vector1.size() < vector2.size())
        return std::equal(vector1.begin(), vector1.end(), vector2.begin());
    else
        return std::equal(vector2.begin(), vector2.end(), vector1.begin());
}
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
                                                                                                         "123456789", "premium")), tables, beginTime, endTime);
        reservationManager.cancelReservation(reservation1);
        std::vector<Restaurant::Reservation_Ptr> allReservations = reservationManager.getAllReservations();

        BOOST_REQUIRE_EQUAL(compareVectors({ reservation2 }, allReservations), true);
    }
BOOST_AUTO_TEST_SUITE_END()
////////////////////////////////////////////////////////////////////////////////////////////////////
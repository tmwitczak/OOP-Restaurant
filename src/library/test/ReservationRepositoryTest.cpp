#include <boost/test/unit_test.hpp>
////////////////////////////////////////////////////////////////////////////////////////////////////
#include "Client.h"
#include "Table.h"
#include "Reservation.h"
#include "ReservationRepository.h"
#include "ReservationManager.h"
#include "HelperFunctions.h"
//--------------------------------------------------------------------------------------------------
BOOST_AUTO_TEST_SUITE(ReservationRepository_CoreFunctionality_TestSuite)
	BOOST_AUTO_TEST_CASE(ReservationRepository_FindReservationByID_TestCase)
	{
		auto const [client, tables, beginTime, endTime] = getReservationParameters();
		Restaurant::Reservation_Ptr const reservation1 =
				std::make_shared<Restaurant::Reservation>(client, tables, beginTime, endTime);
		Restaurant::Reservation_Ptr const reservation2 =
				std::make_shared<Restaurant::Reservation>(client, tables, beginTime, endTime);

		std::vector<Restaurant::Reservation_Ptr> const reservations
		{
			reservation1,
			reservation2,
			reservation1,
			reservation1
		};
		std::vector<Restaurant::Reservation_Ptr> const reservationsID
		{
			reservations.at(1)
		};
		Restaurant::ReservationRepository reservationRepository;
		for(auto const &reservation : reservations)
			reservationRepository.add(reservation);

		std::vector<Restaurant::Reservation_Ptr> foundReservations =
				reservationRepository.findReservationByID(reservation2->getID());

		BOOST_REQUIRE_EQUAL(compareVectors(reservationsID, foundReservations), true);
	}
	BOOST_AUTO_TEST_CASE(ReservationRepository_FindReservationsByClient_TestCase)
	{
		auto const [client1, tables, beginTime, endTime] = getReservationParameters();
		auto const [firstName, lastName, telephoneNumber, clientType] = getClientParameters();
		Restaurant::Client_Ptr const client2 = std::make_shared<Restaurant::Client>
				(firstName, lastName, telephoneNumber, clientType);
		std::vector<Restaurant::Reservation_Ptr> const reservations
		{
			std::make_shared<Restaurant::Reservation>(client2, tables, beginTime, endTime),
			std::make_shared<Restaurant::Reservation>(client2, tables, beginTime, endTime),
			std::make_shared<Restaurant::Reservation>(client1, tables, beginTime, endTime),
			std::make_shared<Restaurant::Reservation>(client1, tables, beginTime, endTime),
			std::make_shared<Restaurant::Reservation>(client2, tables, beginTime, endTime),
			std::make_shared<Restaurant::Reservation>(client1, tables, beginTime, endTime)
		};
		std::vector<Restaurant::Reservation_Ptr> const reservationsClient
		{
			reservations.at(2),
			reservations.at(3),
			reservations.at(5)
		};
		Restaurant::ReservationRepository reservationRepository;
		for(auto const &reservation : reservations)
			reservationRepository.add(reservation);

		std::vector<Restaurant::Reservation_Ptr> foundReservations =
				reservationRepository.findReservationsByClient(client1);

		BOOST_REQUIRE_EQUAL(compareVectors(reservationsClient, foundReservations), true);
	}
	BOOST_AUTO_TEST_CASE(ReservationRepository_FindReservationsByTable_TestCase)
	{
		auto const [client, tables1, beginTime, endTime] = getReservationParameters();
		std::vector<Restaurant::Table_Ptr> const tables2
		{
			std::make_shared<Restaurant::Table>(321654)
		};
		std::vector<Restaurant::Reservation_Ptr> const reservations
		{
			std::make_shared<Restaurant::Reservation>(client, tables1, beginTime, endTime),
			std::make_shared<Restaurant::Reservation>(client, tables1, beginTime, endTime),
			std::make_shared<Restaurant::Reservation>(client, tables2, beginTime, endTime),
			std::make_shared<Restaurant::Reservation>(client, tables1, beginTime, endTime),
			std::make_shared<Restaurant::Reservation>(client, tables2, beginTime, endTime),
			std::make_shared<Restaurant::Reservation>(client, tables1, beginTime, endTime)
		};
		std::vector<Restaurant::Reservation_Ptr> const reservationsTable
		{
			reservations.at(2),
			reservations.at(4)
		};
		Restaurant::ReservationRepository reservationRepository;
		for(auto const &reservation : reservations)
			reservationRepository.add(reservation);

		std::vector<Restaurant::Reservation_Ptr> foundReservations =
				reservationRepository.findReservationsByTable(tables2.at(0));

		BOOST_REQUIRE_EQUAL(compareVectors(reservationsTable, foundReservations), true);
	}
BOOST_AUTO_TEST_SUITE_END()
////////////////////////////////////////////////////////////////////////////////////////////////////
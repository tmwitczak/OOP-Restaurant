#ifndef RESTAURANT_RESERVATIONMANAGER_H
#define RESTAURANT_RESERVATIONMANAGER_H
////////////////////////////////////////////////////////////////////////////////////// Included headers
#include "ReservationRepository.h"
#include <boost/date_time/local_time/local_date_time.hpp>

namespace Restaurant
{
    ////////////////////////////////////////////////////////////////////////////// Forward declarations
	class Reservation;

    /////////////////////////////////////////////////////////////////////////////////////// Typedefs
	typedef std::shared_ptr<Reservation> Reservation_Ptr;
	typedef std::shared_ptr<boost::local_time::local_date_time> DateTime_Ptr;

    /////////////////////////////////////////////////////////////////////////////// Class definition

    class ReservationManager
	{
	public:
        //-------------------------------------------------------- Reservation creation and removal <

        Reservation_Ptr makeReservation(Client_Ptr const &client, Table_Ptr const &table,
										DateTime_Ptr const &beginTime, DateTime_Ptr const &endTime);

		Reservation_Ptr makeReservation(Client_Ptr const &client, std::vector<Table_Ptr> const &tables,
										DateTime_Ptr const &beginTime, DateTime_Ptr const &endTime);

		void cancelReservation(Reservation_Ptr &reservation);
		void cancelReservation(boost::uuids::uuid ID);

        //------------------------------------------------------------------------- Search methods <
		std::vector<Reservation_Ptr>	findReservationByID(boost::uuids::uuid id) const;
		std::vector<Reservation_Ptr> 	findReservationsByClient(Client_Ptr client) const;
		std::vector<Reservation_Ptr> 	findReservationsByTable(Table_Ptr table) const;

        //------------------------------------------------------------------------ File operations <
        void saveReservationsToFile(std::string const &filename) const;
		void readReservationsFromFile(std::string const &filename);

        //-------------------------------------------------------------------------------- Getters <
        std::vector<Reservation_Ptr> getAllReservations() const;
		std::string getInfo() const;

	private:
		//------------------------------------------------------------------------ Parameter check <
		Client_Ptr const &checkClient(Client_Ptr const &client) const;
		Table_Ptr const &checkTable(Table_Ptr const &table) const;
		std::vector<Table_Ptr> const &checkTables(std::vector<Table_Ptr> const &table) const;
		DateTime_Ptr const &checkBeginTime(DateTime_Ptr const &beginTime) const;
		DateTime_Ptr const &checkEndTime(DateTime_Ptr const &endTime) const;
	private:
		ReservationRepository reservationRepository;
	};


}
////////////////////////////////////////////////////////////////////////////////////////////////////
#endif /* RESTAURANT_RESERVATIONMANAGER_H */
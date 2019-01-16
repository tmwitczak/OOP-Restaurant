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

        Reservation_Ptr 				findReservationByID(boost::uuids::uuid id);
		std::vector<Reservation_Ptr> 	findReservationByClient(Client_Ptr client);
		std::vector<Reservation_Ptr> 	findReservationByTable(Table_Ptr table);

        //------------------------------------------------------------------------ File operations <
        void saveReservationsToFile(std::string const &filename) const;
		void readReservationsFromFile(std::string const &filename);

        //-------------------------------------------------------------------------------- Getters <
        std::vector<Reservation_Ptr> getAllReservations() const;
		std::string getInfo() const;

	private:
		ReservationRepository reservationRepository;
	};


}
////////////////////////////////////////////////////////////////////////////////////////////////////
#endif /* RESTAURANT_RESERVATIONMANAGER_H */
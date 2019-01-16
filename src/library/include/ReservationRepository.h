#ifndef RESTAURANT_RESERVATIONREPOSITORY_H
#define RESTAURANT_RESERVATIONREPOSITORY_H
////////////////////////////////////////////////////////////////////////////////////////////////////
#include "Repository.h"
#include <memory>
#include <boost/uuid/uuid.hpp>

namespace Restaurant
{
	class Reservation;
	class Client;
	class Table;

	typedef std::shared_ptr<Reservation> Reservation_Ptr;
	typedef std::shared_ptr<Client> Client_Ptr;
	typedef std::shared_ptr<Table> Table_Ptr;
}

namespace Restaurant
{
	class ReservationRepository
			: public  Repository<Reservation_Ptr>
	{
	public:
		Reservation_Ptr 				findReservationByID(boost::uuids::uuid id);
		std::vector<Reservation_Ptr> 	findReservationByClient(Client_Ptr client);
		std::vector<Reservation_Ptr> 	findReservationByTable(Table_Ptr table);

	};
}
////////////////////////////////////////////////////////////////////////////////////////////////////
#endif /* RESTAURANT_RESERVATIONREPOSITORY_H */
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

	typedef std::shared_ptr<Reservation> 	Reservation_Ptr;
	typedef std::shared_ptr<Client> 		Client_Ptr;
	typedef std::shared_ptr<Table> 			Table_Ptr;
	typedef boost::uuids::uuid 				UUID;
}

namespace Restaurant
{
	class ReservationRepository
			: public  Repository<Reservation_Ptr>
	{
	public:
		std::vector<Reservation_Ptr> 	findReservationByID(UUID const &id) const;
		std::vector<Reservation_Ptr> 	findReservationsByClient(Client_Ptr const &client) const;
		std::vector<Reservation_Ptr> 	findReservationsByTable(Table_Ptr const &table) const;

		void saveToFile(std::string const &filename) const override;
		void readFromFile(std::string const &filename) override;

	private:
		template <typename Value>
		std::vector<Reservation_Ptr> findReservationsByValue(Value const &value) const;

	};
}
////////////////////////////////////////////////////////////////////////////////////////////////////
#endif /* RESTAURANT_RESERVATIONREPOSITORY_H */
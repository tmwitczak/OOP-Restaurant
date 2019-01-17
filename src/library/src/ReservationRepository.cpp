#include "Reservation.h"
#include "ReservationRepository.h"
#include <algorithm>
////////////////////////////////////////////////////////////////////////////////////////////////////
std::vector<Restaurant::Reservation_Ptr>
Restaurant::ReservationRepository::findReservationByID(Restaurant::UUID const &id) const
{
	return findReservationsByValue(id);
}
//--------------------------------------------------------------------------------------------------
std::vector<Restaurant::Reservation_Ptr>
Restaurant::ReservationRepository::findReservationsByClient(Client_Ptr const &client) const
{
	return findReservationsByValue(client);
}
//--------------------------------------------------------------------------------------------------
std::vector<Restaurant::Reservation_Ptr>
Restaurant::ReservationRepository::findReservationsByTable(Table_Ptr const &table) const
{
	return findReservationsByValue(table);
}
//--------------------------------------------------------------------------------------------------
template <typename Value>
std::vector<Restaurant::Reservation_Ptr>
Restaurant::ReservationRepository::findReservationsByValue(Value const &value) const
{
	std::vector<Restaurant::Reservation_Ptr> reservations;

	for(auto i = elements.begin();
		(i = std::find_if(i, elements.end(),
			[&value](Restaurant::Reservation_Ptr const &reservation) -> bool
			{
				if constexpr(std::is_same<Value, Restaurant::UUID>::value)
					 return (reservation->getID() == value);
				else if constexpr(std::is_same<Value, Restaurant::Client_Ptr>::value)
					return (reservation->getClient() == value);
				else if constexpr(std::is_same<Value, Restaurant::Table_Ptr>::value)
				{
					std::vector<Restaurant::Table_Ptr> tables = reservation->getTables();
					return (std::find(tables.begin(), tables.end(), value) != tables.end());
				}
				else
					return false;
			}
		)) != elements.end();
		i++)
		reservations.push_back(*i);

	return reservations;
}
////////////////////////////////////////////////////////////////////////////////////////////////////
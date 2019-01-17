#include "Reservation.h"
#include "ReservationRepository.h"
#include "Client.h"
#include "Table.h"
#include <algorithm>
#include <sstream>

using namespace boost::gregorian;
using namespace boost::local_time;
using namespace boost::posix_time;
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
void Restaurant::ReservationRepository::saveToFile(std::string const &filename) const
{
	std::ofstream file;
	file.open(filename);

	for(auto const &reservation : getAll())
	{
		file << reservation->getClient()->getFirstName() << "\n"
			 << reservation->getClient()->getLastName() << "\n"
			 << reservation->getClient()->getTelephoneNumber() << "\n"
			 << reservation->getClient()->getClientType() << "\n";

		file << reservation->getTables().size() << "\n";
		for(auto const &table : reservation->getTables())
			file << table->getSeatCount() << "\n";

		file << *reservation->getBeginTime() << "\n"
			 << *reservation->getEndTime() << "\n\n";
	}

	file.close();
}
//--------------------------------------------------------------------------------------------------
void Restaurant::ReservationRepository::readFromFile(std::string const &filename)
{
	std::ifstream file;
	file.open(filename);
	while(file.good())
	{
		std::string firstName, lastName, telephoneNumber, clientType;
		file >> firstName;
		file.get();
		file >> lastName;
		file.get();
		file >> telephoneNumber;
		file.get();
		file >> clientType;
		file.get();

		Restaurant::Client_Ptr client;
		if(file.good())
			client = std::make_shared<Restaurant::Client>(firstName, lastName,
					 telephoneNumber, clientType);

		int tableSize;
		file >> tableSize;
		file.get();

		std::vector<Restaurant::Table_Ptr> tables;
		for(int i = 0; i < tableSize; i++)
		{
			int seatCount;
			file >> seatCount;

			if(file.good())
				tables.push_back(std::make_shared<Restaurant::Table>(seatCount));
		}

		std::string beginTimeStr1, beginTimeStr2, beginTimeStr3, beginTimeStr, endTimeStr, endTimeStr1, endTimeStr2, endTimeStr3;
		file >> beginTimeStr1;
		file.get();
		file >> beginTimeStr2;
		file.get();
		file >> beginTimeStr3;
		file.get();
		beginTimeStr = beginTimeStr1 + " " + beginTimeStr2 + " " + beginTimeStr3 ;
		file >> endTimeStr1;
		file.get();
		file >> endTimeStr2;
		file.get();
		file >> endTimeStr3;
		file.get();
		endTimeStr = endTimeStr1 + " " + endTimeStr2 + " " + endTimeStr3;

		std::stringstream str;
		str.str(beginTimeStr);
		boost::posix_time::ptime beginTimeP;
		str >> beginTimeP;
		str.str(endTimeStr);
		boost::posix_time::ptime endTimeP;
		str >> endTimeP;

		if(file.good())
			add(std::make_shared<Restaurant::Reservation>(client, tables,
					std::make_shared<boost::local_time::local_date_time>(beginTimeP,time_zone_ptr (new posix_time_zone("CET+01"))),
					std::make_shared<boost::local_time::local_date_time>(endTimeP,time_zone_ptr (new posix_time_zone("CET+01")))));
	}
	file.close();
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
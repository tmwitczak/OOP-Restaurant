#include "Reservation.h"
////////////////////////////////////////////////////////////////////////////////////////////////////
Restaurant::Reservation::Reservation(Restaurant::Client_Ptr const &client,
									 std::vector<Restaurant::Table_Ptr> const &tables,
									 int const &beginTime, int const &endTime)
 	:	client(client),
 		tables(tables),
 		uuid(0), //TODO
 		beginTime(beginTime),
 		endTime(endTime)
{
}
//--------------------------------------------------------------------------------------------------
Restaurant::Client_Ptr Restaurant::Reservation::getClient() const
{
	return client;
}
//--------------------------------------------------------------------------------------------------
std::vector<Restaurant::Table_Ptr> Restaurant::Reservation::getTables() const
{
	return tables;
}
//--------------------------------------------------------------------------------------------------
int Restaurant::Reservation::getID() const
{
	return uuid;
}
//--------------------------------------------------------------------------------------------------
int Restaurant::Reservation::getBeginTime() const
{
	return beginTime;
}
//--------------------------------------------------------------------------------------------------
int Restaurant::Reservation::getEndTime() const
{
	return endTime;
}
////////////////////////////////////////////////////////////////////////////////////////////////////
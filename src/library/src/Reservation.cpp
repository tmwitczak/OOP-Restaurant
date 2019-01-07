#include "Reservation.h"
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/random_generator.hpp>
////////////////////////////////////////////////////////////////////////////////////////////////////
Restaurant::Reservation::Reservation(Restaurant::Client_Ptr const &client,
									 std::vector<Restaurant::Table_Ptr> const &tables,
									 DateTime_Ptr const &beginTime, DateTime_Ptr const &endTime)
 	:	client(client),
 		tables(tables),
 		beginTime(beginTime),
 		endTime(endTime)
{
	boost::uuids::random_generator generator;
	uuid = generator();
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
boost::uuids::uuid Restaurant::Reservation::getID() const
{
	return uuid;
}
//--------------------------------------------------------------------------------------------------
Restaurant::DateTime_Ptr Restaurant::Reservation::getBeginTime() const
{
	return beginTime;
}
//--------------------------------------------------------------------------------------------------
Restaurant::DateTime_Ptr Restaurant::Reservation::getEndTime() const
{
	return endTime;
}
////////////////////////////////////////////////////////////////////////////////////////////////////

#include <ReservationManager.h>

#include "ReservationManager.h"
#include "Reservation.h"
#include "RestaurantException.h"
#include <sstream>
#include <boost/date_time/local_time/local_time.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
////////////////////////////////////////////////////////////////////////////////////////////////////
Restaurant::Reservation_Ptr
Restaurant::ReservationManager::makeReservation(const Restaurant::Client_Ptr &client,
                                                const Restaurant::Table_Ptr &table,
                                                const Restaurant::DateTime_Ptr &beginTime,
                                                const Restaurant::DateTime_Ptr &endTime)
{
    std::vector<Table_Ptr> tables;
    tables.push_back(table);
    Restaurant::Reservation_Ptr reservation = std::make_shared<Restaurant::Reservation>(client, tables,
            beginTime, endTime);
    reservationRepository.add(reservation);
    return reservation;
}
//--------------------------------------------------------------------------------------------------
Restaurant::Reservation_Ptr
Restaurant::ReservationManager::makeReservation(const Restaurant::Client_Ptr &client,
                                                const std::vector<Restaurant::Table_Ptr> &tables,
                                                const Restaurant::DateTime_Ptr &beginTime,
                                                const Restaurant::DateTime_Ptr &endTime)
{
    Restaurant::Reservation_Ptr reservation = std::make_shared<Restaurant::Reservation>(client, tables,
                                                                                        beginTime, endTime);
    if( (endTime->date() - beginTime->date() ).days() < 0) //TODO: left side +1 ???
        throw  Restaurant::RestaurantException("EndTime can not be before BeginTime!");
    reservationRepository.add(reservation);
    return reservation;
}
//--------------------------------------------------------------------------------------------------
void Restaurant::ReservationManager::cancelReservation(Restaurant::Reservation_Ptr &reservation)
{
    reservationRepository.remove(reservation);
}
//--------------------------------------------------------------------------------------------------
/*
void Restaurant::ReservationManager::cancelReservation(boost::uuids::uuid ID)
{
    reservationRepository.remove( findReservationByID(ID) );
}*/
//--------------------------------------------------------------------------------------------------
Restaurant::Reservation_Ptr Restaurant::ReservationManager::findReservationByID(boost::uuids::uuid id)
{
    return Restaurant::Reservation_Ptr();
}
//--------------------------------------------------------------------------------------------------
std::vector<Restaurant::Reservation_Ptr>
Restaurant::ReservationManager::findReservationByClient(Restaurant::Client_Ptr client)
{
    return std::vector<Restaurant::Reservation_Ptr>();
}
//--------------------------------------------------------------------------------------------------
std::vector<Restaurant::Reservation_Ptr>
Restaurant::ReservationManager::findReservationByTable(Restaurant::Table_Ptr table)
{
    return std::vector<Restaurant::Reservation_Ptr>();
}
//--------------------------------------------------------------------------------------------------
void Restaurant::ReservationManager::saveReservationsToFile(std::string const &filename) const
{

}
//--------------------------------------------------------------------------------------------------
void Restaurant::ReservationManager::readReservationsFromFile(std::string const &filename)
{

}
//--------------------------------------------------------------------------------------------------
std::vector<Restaurant::Reservation_Ptr> Restaurant::ReservationManager::getAllReservations() const
{
    return reservationRepository.getAll();
}
//--------------------------------------------------------------------------------------------------
std::string Restaurant::ReservationManager::getInfo() const
{
    return std::__cxx11::string();
}

const Restaurant::Client_Ptr
&Restaurant::ReservationManager::checkClient(const Restaurant::Client_Ptr &client) const
{
    if(client == nullptr)
        throw Restaurant::RestaurantException("Client_Ptr can not be a nullptr!");
    return client;
}

const Restaurant::Table_Ptr
&Restaurant::ReservationManager::checkTable(const Restaurant::Table_Ptr &table) const
{
    if(table == nullptr)
        throw Restaurant::RestaurantException("Table_Ptr can not be a nullptr!");
    return table;
}

const Restaurant::DateTime_Ptr &
Restaurant::ReservationManager::checkBeginTime(const Restaurant::DateTime_Ptr &beginTime) const
{
    if(beginTime == nullptr)
        throw Restaurant::RestaurantException("BeginTime_Ptr can not be a nullptr!");
    return beginTime;
}

const Restaurant::DateTime_Ptr &
Restaurant::ReservationManager::checkEndTime(const Restaurant::DateTime_Ptr &endTime) const {
    if(endTime == nullptr)
        throw Restaurant::RestaurantException("EndTime_Ptr can not be a nullptr!");
    return endTime;
}

const std::vector<Restaurant::Table_Ptr> &
Restaurant::ReservationManager::checkTables(const std::vector<Restaurant::Table_Ptr> &tables) const {
    if(tables.size() == 0)
        throw Restaurant::RestaurantException("Tables vector can not be empty!");
    return tables;
}
////////////////////////////////////////////////////////////////////////////////////////////////////
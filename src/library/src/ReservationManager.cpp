
#include <ReservationManager.h>

#include "ReservationManager.h"
#include "Reservation.h"
#include "Table.h"
#include "Client.h"
#include "RestaurantException.h"
#include <sstream>
#include <boost/date_time/local_time/local_time.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

using namespace boost::gregorian;
using namespace boost::local_time;
using namespace boost::posix_time;
////////////////////////////////////////////////////////////////////////////////////////////////////
Restaurant::Reservation_Ptr
Restaurant::ReservationManager::makeReservation(const Restaurant::Client_Ptr &client,
                                                const Restaurant::Table_Ptr &table,
                                                const Restaurant::DateTime_Ptr &beginTime,
                                                const Restaurant::DateTime_Ptr &endTime)
{
    std::vector<Table_Ptr> tables;
    tables.push_back(table);

    if( endTime < beginTime ) // TODO < or > ?
        throw  Restaurant::RestaurantException("EndTime can not be before BeginTime!");


    for(auto &table : tables)
    {
        for(auto &reservation : reservationRepository.findReservationsByTable(table))
        {
            if( ((reservation->getBeginTime() >= beginTime) && (reservation->getBeginTime() <= endTime))
                ||((reservation->getEndTime()   >= beginTime) && (reservation->getEndTime()   <= endTime)))
                throw Restaurant::RestaurantException("This table is unavailable at this time!");
        }
    }
    Restaurant::Reservation_Ptr reservation = std::make_shared<Restaurant::Reservation>(checkClient(client),
            checkTables(tables),
            checkBeginTime(beginTime), checkEndTime(endTime));
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
    Restaurant::Reservation_Ptr reservation = std::make_shared<Restaurant::Reservation>(checkClient(client),
                                                                                        checkTables(tables),
                                                                                        checkBeginTime(beginTime), checkEndTime(endTime));
    if( endTime < beginTime )
        throw  Restaurant::RestaurantException("EndTime can not be before BeginTime!");


    for(auto &table : tables)
    {
        for(auto &reservation : reservationRepository.findReservationsByTable(table))
        {
            if( ((reservation->getBeginTime() >= beginTime) && (reservation->getBeginTime() <= endTime))
                ||((reservation->getEndTime()   >= beginTime) && (reservation->getEndTime()   <= endTime)))
                throw Restaurant::RestaurantException("This table is unavailable at this time!");
        }
    }

    reservationRepository.add(reservation);
    return reservation;
}


//--------------------------------------------------------------------------------------------------
void Restaurant::ReservationManager::cancelReservation(Restaurant::Reservation_Ptr &reservation)
{
    reservationRepository.remove(reservation);
}
//--------------------------------------------------------------------------------------------------
void Restaurant::ReservationManager::cancelReservation(boost::uuids::uuid ID)
{
    //reservationRepository.remove(findReservationByID(ID));
}
//--------------------------------------------------------------------------------------------------
std::vector<Restaurant::Reservation_Ptr>
Restaurant::ReservationManager::findReservationByID(boost::uuids::uuid id) const
{
    return reservationRepository.findReservationByID(id);
}
//--------------------------------------------------------------------------------------------------
std::vector<Restaurant::Reservation_Ptr>
Restaurant::ReservationManager::findReservationsByClient(Restaurant::Client_Ptr client) const
{
    return std::vector<Restaurant::Reservation_Ptr>();
}
//--------------------------------------------------------------------------------------------------
std::vector<Restaurant::Reservation_Ptr>
Restaurant::ReservationManager::findReservationsByTable(Restaurant::Table_Ptr table) const
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
    std::stringstream info;
    std::vector<Restaurant::Reservation_Ptr> reservations = getAllReservations();

    info << "Overall number of reservations: " << reservations.size() << "\n";

    for(auto const &reservation : reservations)
    {
        info << "> "
             << reservation->getClient()->getFirstName()    << " "
             << reservation->getClient()->getLastName()     << " "
             << " Tables: ";
        for(auto const &table : reservation->getTables())
        {
            info << table->getSeatCount() << " ";
        }
        info << reservation->getBeginTime()->date() << " "
             << reservation->getEndTime()->date() << "\n";
    }
    return info.str();
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
        throw Restaurant::RestaurantException("EndTime_`Ptr can not be a nullptr!");
    return endTime;
}

const std::vector<Restaurant::Table_Ptr> &
Restaurant::ReservationManager::checkTables(const std::vector<Restaurant::Table_Ptr> &tables) const {
    if(tables.size() == 0)
        throw Restaurant::RestaurantException("Tables vector can not be empty!");
    return tables;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
#include "ReservationManager.h"
#include "Reservation.h"
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
    reservationRepository.add(reservation);
    return reservation;
}
//--------------------------------------------------------------------------------------------------
/*void Restaurant::ReservationManager::cancelReservation(Restaurant::Reservation_Ptr &reservation)
{
    reservationRepository.remove(reservation);
}*/
//--------------------------------------------------------------------------------------------------
/*
 * void Restaurant::ReservationManager::cancelReservation(boost::uuids::uuid ID)
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
////////////////////////////////////////////////////////////////////////////////////////////////////
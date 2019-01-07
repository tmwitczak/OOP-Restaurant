#ifndef RESTAURANT_RESERVATION_H
#define RESTAURANT_RESERVATION_H
////////////////////////////////////////////////////////////////////////////////////////////////////
#include <memory>
#include <vector>
#include <boost/uuid/uuid.hpp>
#include <boost/date_time/local_time/local_time.hpp>

namespace Restaurant
{
	class Client;
	class Table;

	typedef std::shared_ptr<Client> Client_Ptr;
	typedef std::shared_ptr<Table> Table_Ptr;

    typedef std::shared_ptr<boost::local_time::local_date_time> DateTime_Ptr;
}
//--------------------------------------------------------------------------------------------------
namespace Restaurant
{
	class Reservation
	{
	public:
		Reservation(Client_Ptr const &client, std::vector<Table_Ptr> const &tables,
                    DateTime_Ptr const &beginTime, DateTime_Ptr const &endTime);

		Client_Ptr 				getClient() 	const;
		std::vector<Table_Ptr> 	getTables() 	const;
        boost::uuids::uuid 		getID() 		const;
        DateTime_Ptr 			getBeginTime() 	const;
        DateTime_Ptr 			getEndTime() 	const;

	private:
		Client_Ptr 				const client;
		std::vector<Table_Ptr> 	const tables;
        boost::uuids::uuid 	          uuid; 		// TODO: Replace int with UUID
        DateTime_Ptr 			const beginTime; 	// TODO: Replace int with localDateTime
        DateTime_Ptr 			const endTime; 		// TODO: Replace int with localDateTime
	};
}
////////////////////////////////////////////////////////////////////////////////////////////////////
#endif /* RESTAURANT_RESERVATION_H */
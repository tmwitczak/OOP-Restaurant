#ifndef RESTAURANT_RESERVATION_H
#define RESTAURANT_RESERVATION_H
/////////////////////////////////////////////////////////////////////////////////// Included headers
#include <memory>
#include <vector>
#include <boost/uuid/uuid.hpp>
#include <boost/date_time/local_time/local_time.hpp>

namespace Restaurant
{
	/////////////////////////////////////////////////////////////////////////// Forward declarations
	class Client;
	class Table;

	/////////////////////////////////////////////////////////////////////////////////////// Typedefs
	typedef std::shared_ptr<Client> 							Client_Ptr;
	typedef std::shared_ptr<Table> 								Table_Ptr;
    typedef std::shared_ptr<boost::local_time::local_date_time> DateTime_Ptr;
	typedef boost::uuids::uuid									UUID;

	/////////////////////////////////////////////////////////////////////////////// Class definition
	class Reservation
	{
	//---------------------------------------------------------------------------------- [ Methods ]
	public:
		//--------------------------------------------------------------------------- Constructors <
		Reservation(Client_Ptr const &client, std::vector<Table_Ptr> const &tables,
                    DateTime_Ptr const &beginTime, DateTime_Ptr const &endTime);

		//-------------------------------------------------------------------------------- Getters <
		Client_Ptr 				getClient() 	const;
		std::vector<Table_Ptr> 	getTables() 	const;
        UUID 					getID() 		const;
        DateTime_Ptr 			getBeginTime() 	const;
        DateTime_Ptr 			getEndTime() 	const;

	//----------------------------------------------------------------------------------- [ Fields ]
	private:
		Client_Ptr 				const client;
		std::vector<Table_Ptr> 	const tables;
        UUID			 	    const uuid;
        DateTime_Ptr 			const beginTime;
        DateTime_Ptr 			const endTime;
	};
}
////////////////////////////////////////////////////////////////////////////////////////////////////
#endif /* RESTAURANT_RESERVATION_H */
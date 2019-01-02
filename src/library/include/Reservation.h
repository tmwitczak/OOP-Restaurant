#ifndef RESTAURANT_RESERVATION_H
#define RESTAURANT_RESERVATION_H
////////////////////////////////////////////////////////////////////////////////////////////////////
#include <memory>
#include <vector>

namespace Restaurant
{
	class Client;
	class Table;

	typedef std::shared_ptr<Client> Client_Ptr;
	typedef std::shared_ptr<Table> Table_Ptr;
}
//--------------------------------------------------------------------------------------------------
namespace Restaurant
{
	class Reservation
	{
	public:
		Reservation(Client_Ptr const &client, std::vector<Table_Ptr> const &tables,
					int const &beginTime, int const &endTime);

		Client_Ptr 				getClient() 	const;
		std::vector<Table_Ptr> 	getTables() 	const;
		int 					getID() 		const;
		int 					getBeginTime() 	const;
		int 					getEndTime() 	const;

	private:
		Client_Ptr 				const client;
		std::vector<Table_Ptr> 	const tables;
		int 					const uuid; 		// TODO: Replace int with UUID
		int 					const beginTime; 	// TODO: Replace int with localDateTime
		int 					const endTime; 		// TODO: Replace int with localDateTime
	};
}
////////////////////////////////////////////////////////////////////////////////////////////////////
#endif /* RESTAURANT_RESERVATION_H */
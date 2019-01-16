#ifndef RESTAURANT_TABLEREPOSITORY_H
#define RESTAURANT_TABLEREPOSITORY_H
////////////////////////////////////////////////////////////////////////////////////////////////////
#include "Repository.h"
#include <memory>

namespace Restaurant
{
	class Table;

	typedef std::shared_ptr<Table> Table_Ptr;
}


namespace Restaurant
{
	class TableRepository
			: public Repository<Table_Ptr>
	{
	public:
		std::vector<Table_Ptr> findTableBySeatCount(int seatCount) const;
	};
}
////////////////////////////////////////////////////////////////////////////////////////////////////
#endif /* RESTAURANT_TABLEREPOSITORY_H */
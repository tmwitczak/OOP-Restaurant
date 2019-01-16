#ifndef RESTAURANT_TABLEMANAGER_H
#define RESTAURANT_TABLEMANAGER_H
////////////////////////////////////////////////////////////////////////////////////////////////////
#include "TableRepository.h"

namespace Restaurant
{
	class Table;

	typedef std::shared_ptr<Table> Table_Ptr;

	class TableManager
	{
	public:
		Table_Ptr makeTable(int &seatCount);
		std::vector<Table_Ptr> makeTables(int &tableCount, int &seatCount);
		void removeTable(Table_Ptr &table);

		std::vector<Table_Ptr> findTableBySeatCount(int &seatCount);

		void saveTablesToFile(std::string const &filename) const;
		void readTablesFromFile(std::string const &filename);

		std::vector<Table_Ptr> getAllTables() const;
		std::string getInfo() const;

	private:
		TableRepository tableRepository;
	};
}
////////////////////////////////////////////////////////////////////////////////////////////////////
#endif /* RESTAURANT_TABLEMANAGER_H */
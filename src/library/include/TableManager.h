#ifndef RESTAURANT_TABLEMANAGER_H
#define RESTAURANT_TABLEMANAGER_H
/////////////////////////////////////////////////////////////////////////////////// Included headers
#include "TableRepository.h"

namespace Restaurant
{
	/////////////////////////////////////////////////////////////////////////// Forward declarations
	class Table;

    /////////////////////////////////////////////////////////////////////////////// Class definition

	typedef std::shared_ptr<Table> Table_Ptr;

	class TableManager
	{
	//---------------------------------------------------------------------------------- [ Methods ]
	public:
		Table_Ptr makeTable(int &seatCount);
		std::vector<Table_Ptr> makeTables(int &tableCount, int &seatCount);
		void removeTable(Table_Ptr const &table);

		//------------------------------------------------------------------------- Search methods <
		std::vector<Table_Ptr> findTableBySeatCount(int &seatCount);

		//------------------------------------------------------------------------ File operations <
		void saveTablesToFile(std::string const &filename) const;
		void readTablesFromFile(std::string const &filename);


		//-------------------------------------------------------------------------------- Getters <

		std::vector<Table_Ptr> getAllTables() const;
		std::string getInfo() const;

    private:
        //------------------------------------------------------------------------ Parameter check <
        int const &checkseatCount(int const &seatCount) const;
	//------------------------------------------------------------------------------------- [ Fields ]
	private:
		TableRepository tableRepository;
	};
}
////////////////////////////////////////////////////////////////////////////////////////////////////
#endif /* RESTAURANT_TABLEMANAGER_H */


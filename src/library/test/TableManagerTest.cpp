#include <boost/test/unit_test.hpp>
////////////////////////////////////////////////////////////////////////////////////////////////////
#include <vector>
#include "Table.h"
#include "TableManager.h"

template <typename T>
bool compareVectors(std::vector<T> const &vector1, std::vector<T> const &vector2)
{
    if(vector1.size() < vector2.size())
        return std::equal(vector1.begin(), vector1.end(), vector2.begin());
    else
        return std::equal(vector2.begin(), vector2.end(), vector1.begin());
}

std::tuple<int, int> getTableParameters()
{
    return {
                /* tablesCount */   1,
                /* seatCount */     5
    };
}

bool operator==(Restaurant::Table const &table1,
                Restaurant::Table const &table2)
{
    if(	table1.getSeatCount()  ==  table2.getSeatCount() )
        return true;
    else
        return false;
}

BOOST_AUTO_TEST_SUITE(TableManager_CoreFunctionality_TestSuite)
    BOOST_AUTO_TEST_CASE(TableManager_MakeTable_TestCase)
    {
        Restaurant::TableManager tableManager;

        int seatCount = 5;
        Restaurant::Table table1(seatCount);

        Restaurant::Table_Ptr table2 = tableManager.makeTable(seatCount);

        BOOST_REQUIRE_EQUAL( table1 == *table2, true);
    }

    BOOST_AUTO_TEST_CASE(TableManager_MakeTableAndGetAllTables_TestCase)
    {
        Restaurant::TableManager tableManager;
        int seatCount = 5;
        Restaurant::Table_Ptr table = tableManager.makeTable(seatCount);
        std::vector<Restaurant::Table_Ptr> allTables = tableManager.getAllTables();

        BOOST_REQUIRE_EQUAL( compareVectors({ table }, allTables), true);
    }
    BOOST_AUTO_TEST_CASE(TableManager_MakeTableThenRemoveTableAndGetAllTables_TestCase)
    {
        Restaurant::TableManager tableManager;

        int seatCount = 5;
        Restaurant::Table_Ptr table1 = tableManager.makeTable(seatCount);
        seatCount = 3;
        Restaurant::Table_Ptr table2 = tableManager.makeTable(seatCount);

        tableManager.removeTable(table1);
        std::vector<Restaurant::Table_Ptr> allTables = tableManager.getAllTables();

        BOOST_REQUIRE_EQUAL( compareVectors({ table2 }, allTables), true);
    }
BOOST_AUTO_TEST_SUITE_END()
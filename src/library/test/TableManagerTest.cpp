#include <boost/test/unit_test.hpp>
////////////////////////////////////////////////////////////////////////////////////////////////////
#include <vector>
#include <string>
#include <RestaurantException.h>
#include "Table.h"
#include "TableManager.h"
#include <iostream>
#include "HelperFunctions.h"

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
    BOOST_AUTO_TEST_CASE(TableManager_MakeTableTableWithNegativeSeatCount_TestCase)
    {
        Restaurant::TableManager tableManager;
        std::string message;

        int seatCount = -5;

        try
        {
            Restaurant::Table_Ptr table1 = tableManager.makeTable(seatCount);
        }
        catch(Restaurant::RestaurantException const &exception)
        {
            message = exception.getMessage();
        }
        BOOST_REQUIRE_EQUAL(message, "Seat count must be positive integer!");
    }
    BOOST_AUTO_TEST_CASE(TableManager_SaveTablesToFile_TestCase)
    {
        Restaurant::TableManager tableManager;

        int seatCount = 5;
        Restaurant::Table_Ptr table1 = tableManager.makeTable(seatCount);
        seatCount = 3;
        Restaurant::Table_Ptr table2 = tableManager.makeTable(seatCount);

        tableManager.saveTablesToFile("TableMangerTest.tmp");

        std::ifstream file;
        file.open("TableMangerTest.tmp");
        std::string fileContent((std::istreambuf_iterator<char>(file)),
                                std::istreambuf_iterator<char>());
        file.close();

        BOOST_REQUIRE_EQUAL( fileContent, "5 3 ");
    }
BOOST_AUTO_TEST_SUITE_END()
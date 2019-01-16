#include "TableManager.h"
#include "Table.h"
////////////////////////////////////////////////////////////////////////////////////////////////////
Restaurant::Table_Ptr
Restaurant::TableManager::makeTable(int &seatCount)
{
    Restaurant::Table_Ptr table = std::make_shared<Restaurant::Table>(seatCount);
    tableRepository.add(table);
    return table;

}
//--------------------------------------------------------------------------------------------------
std::vector<Restaurant::Table_Ptr>
Restaurant::TableManager::makeTables(int &tableCount, int &seatCount)
{
    std::vector<Restaurant::Table_Ptr> tables;
    Restaurant::Table_Ptr table = nullptr;
    for(int i=0; i<tableCount; i++)
    {
        table = std::make_shared<Restaurant::Table>(seatCount);
        tableRepository.add(table);
        tables.push_back(table);
    }
    return tables;
}
//--------------------------------------------------------------------------------------------------
/*void Restaurant::TableManager::removeTable(Restaurant::Table_Ptr &table)
{
    tableRepository.remove(table);
}*/
//--------------------------------------------------------------------------------------------------
std::vector<Restaurant::Table_Ptr>
Restaurant::TableManager::findTableBySeatCount(int &seatCount)
{
    return std::vector<Restaurant::Table_Ptr>();
}
//--------------------------------------------------------------------------------------------------
void Restaurant::TableManager::saveTablesToFile(std::string const &filename) const
{

}
//--------------------------------------------------------------------------------------------------
void Restaurant::TableManager::readTablesFromFile(std::string const &filename)
{

}
//--------------------------------------------------------------------------------------------------
std::vector<Restaurant::Table_Ptr> Restaurant::TableManager::getAllTables() const
{
    return tableRepository.getAll();
}
//--------------------------------------------------------------------------------------------------
std::string Restaurant::TableManager::getInfo() const {
    return std::__cxx11::string();
}
////////////////////////////////////////////////////////////////////////////////////////////////////
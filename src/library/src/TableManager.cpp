#include "TableManager.h"
#include "Table.h"
#include "RestaurantException.h"
#include <sstream>
////////////////////////////////////////////////////////////////////////////////////////////////////
Restaurant::Table_Ptr
Restaurant::TableManager::makeTable(int const &seatCount)
{
    Restaurant::Table_Ptr table = std::make_shared<Restaurant::Table>(
            checkseatCount(seatCount));
    tableRepository.add(table);
    return table;

}
//--------------------------------------------------------------------------------------------------
std::vector<Restaurant::Table_Ptr>
Restaurant::TableManager::makeTables(int const &tableCount, int const &seatCount)
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
void Restaurant::TableManager::removeTable(Restaurant::Table_Ptr const &table)
{
    tableRepository.remove(table);
}
//--------------------------------------------------------------------------------------------------
std::vector<Restaurant::Table_Ptr>
Restaurant::TableManager::findTableBySeatCount(int const &seatCount)
{
    return tableRepository.findTableBySeatCount(seatCount);
}
//--------------------------------------------------------------------------------------------------
void Restaurant::TableManager::saveTablesToFile(std::string const &filename) const
{
    tableRepository.saveToFile(filename);
   /* std::ofstream outFile(filename, std::ios::binary);
    for(auto &table : this->getAllTables()) outFile << table->getSeatCount() << " ";*/
}
//--------------------------------------------------------------------------------------------------
void Restaurant::TableManager::readTablesFromFile(std::string const &filename)
{
    tableRepository.readFromFile(filename);
    /*std::ifstream file;
    file.open(filename);
    while(file.good())
    {
        int seatCount;
        file >> seatCount;
        file.get();

        if(file.good())
        {
            checkseatCount(seatCount);
        }
    }
    file.close();*/
}
//--------------------------------------------------------------------------------------------------
std::vector<Restaurant::Table_Ptr> Restaurant::TableManager::getAllTables() const
{
    return tableRepository.getAll();
}
//--------------------------------------------------------------------------------------------------
std::string Restaurant::TableManager::getInfo() const
{
    std::stringstream info;
    std::vector<Restaurant::Table_Ptr> tables = getAllTables();
    info << "Overall number of tables: " << tables.size();
    info << "\nTables: ";

    for(auto const &table : tables)
    {
        info << table->getSeatCount() << " ";
    }
    return info.str();
}

int const &
Restaurant::TableManager::checkseatCount(int const &seatCount) const
{
    if(seatCount <= 0)
        throw RestaurantException("Seat count must be positive integer!");
    return seatCount;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
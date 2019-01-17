
#include <TableRepository.h>
#include "Table.h"
#include "TableRepository.h"
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
std::vector<Restaurant::Table_Ptr> Restaurant::TableRepository::findTableBySeatCount(int seatCount) const {
    std::vector<Restaurant::Table_Ptr> tables;

    for(auto &table : elements)
    {
        if(table->getSeatCount() == seatCount)
            tables.push_back(table);
    }

    return tables;
}

void Restaurant::TableRepository::saveToFile(std::string const &filename) const {
    std::ofstream file;
    file.open(filename);

    for(auto const &table : getAll())
        file << table->getSeatCount() << " ";

    file.close();
}

void Restaurant::TableRepository::readFromFile(std::string const &filename) {
    std::ifstream file;
    file.open(filename);
    while(file.good())
    {
        int seatCount;
        file >> seatCount;
        file.get();

        if(file.good())
            add(std::make_shared<Restaurant::Table>(seatCount));
    }
    file.close();
}

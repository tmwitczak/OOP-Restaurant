
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

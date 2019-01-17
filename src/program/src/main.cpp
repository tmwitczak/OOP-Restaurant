#include <Table.h>
#include <TableManager.h>
#include <iostream>
#include <ClientManager.h>

////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    /*Restaurant::TableManager tableManager;
    int tmp = 5;
    tableManager.makeTables(tmp,tmp);
    std::cout << tableManager.getInfo();*/
    Restaurant::ClientManager clientManager;

    Restaurant::Client_Ptr client1 = clientManager.makeClient("John", "Smith",
                                                             "1234214124789", "basic"),
                            client2 = clientManager.makeClient("JAcek", "Smith",
                                              "123456789", "basic");
    clientManager.saveClientsToFile("clients.txt");
    return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////
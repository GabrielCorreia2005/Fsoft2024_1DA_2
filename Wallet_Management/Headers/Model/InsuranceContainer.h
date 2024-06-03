//
// Created by gvice on 13/05/2024.
//

#ifndef WALLET_MANAGEMENT_CLIENTSCONTAINER_H
#define WALLET_MANAGEMENT_CLIENTSCONTAINER_H

#include <list>
#include "Client.h"
#include "Date.h"

class ClientsContainer {
private:
    list<Client> clients;
    list<Client>::iterator search(int number);

public:
    list<Client> getAll();
    Client* get(int number);
    void add(const Client &obj);
    void remove(int number);
    void update(int number, const string& name, const Date& birth);
    bool isThereClient(int number);
};

#endif //WALLET_MANAGEMENT_CLIENTSCONTAINER_H
//
// Created by gvice on 13/05/2024.
//

#ifndef WALLET_MANAGEMENT_CLIENTSCONTAINER_H
#define WALLET_MANAGEMENT_CLIENTSCONTAINER_H

#include <list>
#include "Client.h"

class ClientsContainer{
private:
    list<Clients> clients;
    list<Clients>::iterator search(int &number);

public:
    list<Clients> getAll();
    Instructor* get(int &number);
    void add(const Client& obj);
    void remove(int &number);
    void update(char name, int number, float birth);
    bool  isThereSubject(int &number);

};


#endif //WALLET_MANAGEMENT_CLIENTSCONTAINER_H

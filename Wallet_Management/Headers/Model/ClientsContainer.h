//
// Created by gvice on 13/05/2024.
//

#ifndef WALLET_MANAGEMENT_CLIENTSCONTAINER_H
#define WALLET_MANAGEMENT_CLIENTSCONTAINER_H

#include <list>
#include "Client.h"
#include "DuplicatedDataException.h"

using namespace std;

class ClientsContainer {
private:
    list<Client> clients;
    list<Client>::iterator search(int number); // Private function to search for a client by number

public:
    // Get a list of all clients in the container.
    list<Client> getAll();

    // Get a pointer to a specific client by their unique number.
    // Returns nullptr if the client is not found.
    Client* get(int number);

    // Add a new client to the container.
    // Throws a DuplicatedDataException if a client with the same number already exists.
    void add(const Client& obj);

    // Remove a client from the container by their unique number.
    void remove(int number);

    // Update the name and birth date of an existing client in the container.
    void update(int number, const string& name, const Date& birth);

    // Check if a client with a specific number exists in the container.
    bool isThereClient(int number);

    static int nextClientNumber;
};

#endif //WALLET_MANAGEMENT_CLIENTSCONTAINER_H
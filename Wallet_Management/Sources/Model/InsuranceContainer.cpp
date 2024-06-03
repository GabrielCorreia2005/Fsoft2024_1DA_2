//
// Created by gvice on 13/05/2024.
//

#include "ClientsContainer.h"
#include "DuplicatedDataException.h"

// Get all clients
list<Client> ClientsContainer::getAll() {
    return clients;
}

// Get a specific client by number
Client* ClientsContainer::get(int number) {
    list<Client>::iterator it = search(number);
    if(it != clients.end())
        return &(*it);
    else
        return nullptr;
}

// Add a new client to the container
void ClientsContainer::add(const Client& obj) {
    // Check if a client with the same number already exists
    if(isThereClient(obj.getNumber()))
        throw DuplicatedDataException("There is already a client with the same number");

    clients.push_back(obj);
}

// Remove a client by number
void ClientsContainer::remove(int number) {
    list<Client>::iterator it = search(number);
    if (it != clients.end()) {
        clients.erase(it);
    }
}

// Update client information
void ClientsContainer::update(int number, const string& name, const Date& birth) {
    list<Client>::iterator it = search(number);
    if (it != clients.end()) {
        it->setName(name);
        it->setBirth(birth);
    }
}

// Check if a client with a given number exists
bool ClientsContainer::isThereClient(int number) {
    return search(number) != clients.end();
}

// Search for a client by number
list<Client>::iterator ClientsContainer::search(int number) {
    for(list<Client>::iterator it = clients.begin(); it != clients.end(); it++){
        if((*it).getNumber() == number)
            return it;
    }
    return clients.end();
}
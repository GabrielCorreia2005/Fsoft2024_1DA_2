//
// Created by Gabriel on 13/05/2024.
//

#include "ClientsContainer.h"
#include "DuplicatedDataException.h"

// Get a list of all clients
list<Client> ClientsContainer::getAll() {
    return clients;
}

// Get a specific client by client number
Client* ClientsContainer::get(int number) {
    list<Client>::iterator it = search(number);
    if (it != clients.end()) {
        return &(*it); // Return a pointer to the client object
    } else {
        return nullptr; // Client not found
    }
}

// Add a new client to the container
void ClientsContainer::add(const Client& obj) {
    if(search(obj.getNumber()) == clients.end()){
        clients.push_back(obj);
    }
    else
        throw DuplicatedDataException ("Client with that number already exists");
}

// Remove a client by client number
void ClientsContainer::remove(int number) {
    list<Client>::iterator it = search(number);
    if (it != clients.end()) {
        clients.erase(it);
    }
}

// Update the information of an existing client
void ClientsContainer::update(int number, const string& name, const Date& birth) {
    list<Client>::iterator it = search(number);
    if (it != clients.end()) {
        it->setName(name);
        it->setBirth(birth);
    }
}

// Check if a client with a specific number already exists
bool ClientsContainer::isThereClient(int number) {
    return search(number) != clients.end();
}

// Search for a client by client number
list<Client>::iterator ClientsContainer::search(int number) {
    for (list<Client>::iterator it = clients.begin(); it != clients.end(); ++it) {
        if (it->getNumber() == number) {
            return it;
        }
    }
    return clients.end(); // Client not found
}
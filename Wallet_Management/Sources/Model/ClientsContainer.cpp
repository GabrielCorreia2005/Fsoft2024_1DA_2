#include "ClientsContainer.h"
#include <algorithm> // For std::find
#include <iostream>
using namespace std;

// Define nextClientNumber only once in the .cpp file
int ClientsContainer::nextClientNumber = 1;

// Get a list of all clients in the container.
list<Client> ClientsContainer::getAll() {
    return clients;
}

// Get a pointer to a specific client by their unique number.
// Returns nullptr if the client is not found.
Client* ClientsContainer::get(int number) {
    list<Client>::iterator it = search(number);
    if (it != clients.end()) {
        return &(*it); // Return a pointer to the Client object
    }
    return nullptr; // Client not found
}

// Add a new client to the container.
// Throws a DuplicatedDataException if a client with the same number already exists.
void ClientsContainer::add(const Client& obj) {
    if (isThereClient(obj.getNumber())) {
        throw DuplicatedDataException("Client with this number already exists.");
    }

    clients.push_back(obj);
    nextClientNumber++; // Increment after adding the client
}


// Remove a client from the container by their unique number.
void ClientsContainer::remove(int number) {
    list<Client>::iterator it = search(number);
    if (it != clients.end()) {
        clients.erase(it);
        cout << "Client with number " << number << " removed." << endl; // For debugging
    } else {
        cout << "Client with number " << number << " not found." << endl; // For debugging
    }
}

// Update the name and birth date of an existing client in the container.
void ClientsContainer::update(int number, const string& name, const Date& birth) {
    list<Client>::iterator it = search(number);
    if (it != clients.end()) {
        it->setName(name);
        it->setBirth(birth);
        cout << "Client with number " << number << " updated." << endl; // For debugging
    } else {
        cout << "Client with number " << number << " not found." << endl; // For debugging
    }
}

// Check if a client with a specific number exists in the container.
bool ClientsContainer::isThereClient(int number) {
    return (search(number) != clients.end());
}

// Private function to search for a client by number
list<Client>::iterator ClientsContainer::search(int number) {
    return find_if(clients.begin(), clients.end(),
                   [number](const Client& c) { return c.getNumber() == number; });
}
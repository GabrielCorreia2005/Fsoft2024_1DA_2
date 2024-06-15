//
// Created by gvice on 20/05/2024.
//

#include <iostream>
#include "ClientView.h"
#include "Utils.h"
#include "InvalidDataException.h"
#include "ClientsContainer.h"


using namespace std;

// Keep only one definition of getClient()

Client ClientView::getClient() {
    string name = Utils::getString("Name: ");
    Date birth = getDate();
    int number = ClientsContainer::nextClientNumber; // Assign the next available number

    return Client(name, birth, number);
}


Date ClientView::getDate() {
    int day, month, year;
    do {
        day = Utils::getNumber("Day:");
        month = Utils::getNumber("Month:");
        year = Utils::getNumber("Year:");
    } while (!Date::isValid(day, month, year));

    return Date(day, month, year);
}

void ClientView::printClient(Client *client)
{
    int day, month, year;

    client -> getBirth().getDate(day, month, year);
    string date = to_string(day) + "/" + to_string(month) + "/" + to_string(year);

    cout << client -> getNumber() << ":" << client -> getName() << ":" << date << endl;
}

void ClientView::printClients(list<Client>& clients) {
    for (Client& client : clients) {
        cout << client.getNumber() << ":";
        cout << client.getName() << ":";

        int day, month, year;
        client.getBirth().getDate(day, month, year);  // Get date components

        cout << day << "/" << month << "/" << year << endl;
    }
}
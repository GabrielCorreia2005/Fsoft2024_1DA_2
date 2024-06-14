//
// Created by gvice on 20/05/2024.
//

#include <iostream>
#include "ClientView.h"
#include "Utils.h"
#include "InvalidDataException.h"

using namespace std;

Client ClientView::getClient() {
    string name;
    Date birth;

    do {
        name = Utils::getString("Name:");
    } while (!Client::isNameValid(name)); // Validate name immediately

    birth = getDate(); // Get the birth date

    return Client(name, birth);
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

//
// Created by gvice on 20/05/2024.
//

#include <iostream>
#include "ClientView.h"
#include "Utils.h"
#include "InvalidDataException.h"

using namespace std;

Date ClientView::getDate() {
    int day, month, year;
    bool validDate = false;

    while (!validDate) {
        cout << " Date" << endl;
        day = Utils::getNumber("Day:");
        month = Utils::getNumber("Month:");
        year = Utils::getNumber("Year:");

        try {
            Date tempDate(day, month, year); // Try creating a Date object
            validDate = true; // If successful, date is valid
            return tempDate;   // Return the valid date
        } catch (InvalidDataException &e) {
            cout << e.what() << endl; // Print the exception message
        }
    }
}

Client ClientView:: getClient()
{
    Date birthday;
    Client Client("Temporary Name", birthday);

    bool flag = false;

    do
    {
        try
        {
            flag = false;

            cout << "Client" << endl;

            string name = Utils::getString("Name");
            birthday = getDate();

            Client.setName(name);
            Client.setBirth(birthday);
        }catch(InvalidDataException &e)
        {
            flag = true;
        }
    }while(flag == true);

    return Client;
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

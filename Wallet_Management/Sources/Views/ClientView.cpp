//
// Created by gvice on 20/05/2024.
//

#include <iostream>
#include "ClientView.h"
#include "Utils.h"
#include "InvalidDataException.h"

using namespace std;

Date ClientView::getDate()
{
    Date date;
    bool flag = false;

    do
    {
        try
        {
            flag = true;
            cout << "Date" << endl;

            int day = Utils::getNumber("Day");
            int month = Utils::getNumber("Month");
            int year = Utils::getNumber("Year");

            date.setDate(day, month, year);
        }catch(InvalidDataException& e)
        {
            flag = true;
        }
    }while(flag == true);
    return date;
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
        }catch(InvalidDataException& e)
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

void ClientView::printClients(list <Client>& students)
{
    for(list<Client>::iterator it = students.begin(); it != students.end(); ++it)
        printClient(&*it);
}


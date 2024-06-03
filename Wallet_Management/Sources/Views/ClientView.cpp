//
// Created by gvice on 20/05/2024.
//

#include <iostream>
#include "ClientView.h"
#include "Utils.h"
#include "InvalidDataException.h"

using namespace std;

Client ClientView::getDate()
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
    Client client("Temporary Name", birthday);

    bool flag = false;

    do
    {
        try
        {
            flag = false;

            cout << "Client" << endlM;

            string name = Utils::getString("Name");
            birthday = getDate();

            client.setName(name);
            client.setBirthday(birthday);
        }catch(InvalidDataException& e)
        {
            flag = true;
        }
    }while(flag == true);

    return client;
}

void ClientView::printClient(Client *client)
{
    int day, month, year;

    student -> getBirthday.getDate(day, month, year);
    string date = to_string(day) + "/" + to_string(month) + "/" + to_string(year);

    cout << student -> getNumber() << ":" << student -> getName() << ":" << date << endl;
}

void ClientView::printClients(list <Client>& students)
{
    for(list<Client>::iterator it = students.begin(); it != students.end(); ++it)
        printClient(&*it);
}


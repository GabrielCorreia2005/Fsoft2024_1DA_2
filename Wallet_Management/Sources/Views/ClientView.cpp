//
// Created by gvice on 20/05/2024.
//

#include <iostream>
#include "ClientView.h"
#include "Utils.h"
#include "InvalidDataException.h"

using namespace std;

Client ClientView:: getClient()
{
    Client client("XXX", "Temporary Name") //verificar se vai ter no nome INICIAIS!!

    bool flag = false;

    do
    {
        try
        {
            flag = false;

            cout << "Client" << endl;

            string initials = Utils::getString("Initials");
            string designation = Utils::getString("Designation");

            client.setDesignation(initials);
            client.setDesignation(designation);
        }catch(InvalidDataException& e)
        {
            flag = true;
        }
    }while(flag == true);

    return client;
}

Client ClientView::
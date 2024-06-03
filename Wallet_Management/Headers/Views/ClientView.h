//
// Created by gvice on 20/05/2024.
//

#ifndef FSOFT_PROJECT_CLIENTVIEW_H
#define FSOFT_PROJECT_CLIENTVIEW_H

#include <list>
#include "Client.h"

class ClientView
{

    public:
        Date getDate();
        Client getClient();

        void printClient(Client *client);
        void printClients(list<Client>& clients);
};
#endif //FSOFT_PROJECT_CLIENTVIEW_H

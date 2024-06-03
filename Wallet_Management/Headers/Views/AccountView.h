//
// Created by gvice on 20/05/2024.
//

#ifndef FSOFT_PROJECT_ACCOUNTVIEW_H
#define FSOFT_PROJECT_ACCOUNTVIEW_H

#endif //FSOFT_PROJECT_ACCOUNTVIEW_H

#include <list>
#include <tuple>
#include "Accounts.h"
#include "ClientsContainer.h"

class EnrollView{
public:
    Accounts getAccount(ClientsContainer & clients);
    void printAccount(Accounts *account);
    void printAccounts(list<Accounts>& accounts);
    void printStudentAccounts(Client * client, list<tuple<Accounts *, int>>& subjects);
};
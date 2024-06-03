//
// Created by gvice on 20/05/2024.
//

#include <iostream>

#include "View.h"
#include "Utils.h"

using namespace std;

View::View(){
}

int View::menuClient()
{
    int op = -1;

    do{
        cout << "\n**************** Menu Client ****************\n";
        cout << "1- Create Account\n";
        cout << "2- List\n";
        cout << "3- Delete\n";

        cout << "0- Exit\n";
        op = Utils::getNumber("Option");

    }while(op < 0 || op > 3);
    return op;
}

int View::menuBank()
{
    int op = -1;

    do{
        cout << "\n**************** Menu Bank ****************\n";
        cout << "1- Account\n";
        cout << "2- Loans\n";
        cout << "3- Transactions\n";
        cout << "4- Insurance\n";

        cout << "0- Log Out\n";
        op = Utils::getNumber("Option");

    }while(op < 0 || op > 4);
    return op;
}

int View::menuAccount()
{
    int op = -1;

    do{
        cout << "\n**************** Menu Account ****************\n";
        cout << "1- Account Information\n";
        cout << "2- Close Account\n";

        cout << "0- Bank\n";
        op = Utils::getNumber("Option");

    }while(op < 0 || op > 2);
    return op;
}

int View::menuLoans()
{
    int op = -1;

    do{
        cout << "\n**************** Menu Loans ****************\n";
        cout << "1- Acquire\n";
        cout << "2- List\n";
        cout << "3- Monitor\n";
        cout << "4- Amortize\n";

        cout << "0- Back\n";
        op = Utils::getNumber("Option");

    }while(op < 0 || op > 4);
    return op;
}

int View::menuTransactions()
{
    int op = -1;

    do{
        cout << "\n**************** Menu Transactions ****************\n";
        cout << "1- History\n";
        cout << "2- Make\n";

        cout << "0- Back\n";
        op = Utils::getNumber("Option");

    }while(op < 0 || op > 2);
    return op;
}

int View::menuBank()
{
    int op = -1;

    do{
        cout << "\n**************** Menu Insurance ****************\n";
        cout << "1- Acquire\n";
        cout << "2- Cancel\n";
        cout << "3- List\n";

        cout << "0- Log Out\n";
        op = Utils::getNumber("Option");

    }while(op < 0 || op > 3);
    return op;
}
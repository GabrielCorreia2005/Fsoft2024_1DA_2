//
// Created by gvice on 13/05/2024.
//

#include <iostream>
#include "WalletManagement.h"

#include "Controller.h"
using namespace std;

int main()
{
    WalletManagement WalletManagement ("Wallet Management");

    Controller controller (WalletManagement);
    controller.run();

    cout << "Application has existed" << endl;
    return 0;
}
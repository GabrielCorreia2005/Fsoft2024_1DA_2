
#include <iostream>
#include "View.h"
#include "Utils.h"
#include "WalletManagement.h"
#include "Controller.h"


using namespace std;

int main() {
    WalletManagement walletManagement("Wallet Management");

    Controller controller(walletManagement);
    controller.run();

    cout << "Application has exited" << endl;



    return 0;
}//
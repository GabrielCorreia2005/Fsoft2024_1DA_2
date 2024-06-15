
#include <iostream>
#include "View.h"
#include "Utils.h"
#include "WalletManagement.h"
#include "Controller.h"
#include "MockData.h"

using namespace std;

int main() {
    WalletManagement walletManagement("Wallet Management");

    // Generate mock data
    MockData mockData;
    mockData.generateData(walletManagement);

    Controller controller(walletManagement);
    controller.run();

    cout << "Application has exited" << endl;
    return 0;
}
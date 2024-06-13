//
// Created by gvice on 13/05/2024.
//

#include <iostream>
#include "WalletManagement.h"
#include "Controller.h"
#include "MockData.h"

using namespace std;

int main() {
    WalletManagement walletManagement;

    // Use MockData to populate the walletManagement with initial data (optional)
    MockData mockData;
    mockData.generateData(walletManagement);

    Controller controller(walletManagement);
    controller.run();

    return 0;
}
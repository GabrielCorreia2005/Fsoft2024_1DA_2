#ifndef WALLET_MANAGEMENT_MOCKDATA_H
#define WALLET_MANAGEMENT_MOCKDATA_H

#include "WalletManagement.h"
#include <random> // Make sure to include <random>

class MockData {
private:
    // Random number generation setup
    random_device rd;
    mt19937 gen{rd()};
    // Correct way to define the range:
    uniform_real_distribution<float> balanceDist{500.0f, 10000.0f};

public:
    void generateData(WalletManagement &walletManagement);
};

#endif //WALLET_MANAGEMENT_MOCKDATA_H
#ifndef WALLET_MANAGEMENT_MOCKDATA_H
#define WALLET_MANAGEMENT_MOCKDATA_H

#include "WalletManagement.h"

class MockData {
public:
    void generateData(WalletManagement &walletManagement);

private:
    void insertClients(ClientsContainer& container);

};

#endif //WALLET_MANAGEMENT_MOCKDATA_H
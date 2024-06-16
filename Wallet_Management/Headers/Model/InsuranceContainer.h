#ifndef WALLET_MANAGEMENT_INSURANCECONTAINER_H
#define WALLET_MANAGEMENT_INSURANCECONTAINER_H

#include <list>
#include "Insurance.h"
#include "Client.h"

using namespace std;

class InsuranceContainer {
private:
    list<Insurance> insurances;
    list<Insurance>::iterator search(const string &name, int clientNumber); // Search by name and client number

public:
    list<Insurance> getAll();
    Insurance* get(const string &name, int clientNumber);
    void add(const Insurance &obj);
    void remove(const string &name, int clientNumber);
    void update(const string &name, int clientNumber, float price, float length, int installments, float fees);
    bool isThereInsurance(const string &name, int clientNumber);
    list<Insurance> getClientInsurances(int clientNumber); // Get insurances for a specific client
};

#endif //WALLET_MANAGEMENT_INSURANCECONTAINER_H
//
// Created by corre on 20/05/2024.
//

#ifndef WALLET_MANAGEMENT_TRANSACTIONS_H
#define WALLET_MANAGEMENT_TRANSACTIONS_H

#include <string>
#include "Date.h"
using namespace std;

class Transactions{
private :
    long int id;
    float amount;
    Date date;
    string type;
public:
    Transactions( long int id,  float amount, const Date& date,string type);
    Transactions(const Transactions &obj);
    ~Transactions();
};

#endif //WALLET_MANAGEMENT_TRANSACTIONS_H

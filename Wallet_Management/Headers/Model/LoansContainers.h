#ifndef WALLET_MANAGEMENT_LOANSCONTAINERS_H
#define WALLET_MANAGEMENT_LOANSCONTAINERS_H

#include <list>
#include "Loans.h"
#include "DuplicatedDataException.h"
#include "Client.h" // Include Client.h here
#include "AccountsContainers.h"

using namespace std;

class LoansContainers {
private:
    list<Loans> loans;

    // Correctly compare client numbers here
    list<Loans>::iterator searchByClient(int clientNumber);
    list<Loans>::iterator search(const string& type, float amount);

public:
    list<Loans> getAll();
    Loans* getsingle(int number);
    Loans* get(const string& type, float amount);
    void add(const Loans& obj, Client* client, AccountsContainers &accountsContainer);
    void remove(const string& type, float amount);
    void update(const string& type, float amount, float interestRate, int durationMonths);
    bool isThereLoan(const string& type, float amount);

    float amortizeLoan(int clientNumber, const string& type, float amount, float paymentAmount);
};

#endif //WALLET_MANAGEMENT_LOANSCONTAINERS_H
#include "LoansContainers.h"
#include <algorithm>


using namespace std;

list<Loans>::iterator LoansContainers::searchByClient(int clientNumber){
    for(auto it= loans.begin(); it != loans.end(); it++){
        if((*it).getClient()->getNumber() == clientNumber){
            return it;
        }
    }
    return loans.end();
}

list<Loans>::iterator LoansContainers::search(const string &type, float amount) {
    for (auto it = loans.begin(); it != loans.end(); it++) {
        if ((*it).getType() == type && (*it).getAmount() == amount) {
            return it;
        }
    }
    return loans.end();
}

list<Loans> LoansContainers::getAll() {
    return loans;
}

Loans *LoansContainers::getsingle(int number) {
    for (auto it = loans.begin(); it != loans.end(); it++) {
        if ((*it).getAccountNumber() == number)
            return &(*it);
    }
    return nullptr;
}

Loans* LoansContainers::get(const string &type, float amount) {
    auto it = search(type, amount);
    if (it != loans.end()) {
        return &(*it);
    } else {
        return nullptr;
    }
}

void LoansContainers::add(const Loans &obj, Client *client, AccountsContainers &accountsContainer) {
    if (!isThereLoan(obj.getType(), obj.getAmount())) {
        loans.push_back(obj);

        // Find the account and update the balance
        Accounts* accountToUpdate = accountsContainer.get(obj.getAccountNumber());
        if (accountToUpdate != nullptr) {
            accountToUpdate->setBalance(accountToUpdate->getBalance() + obj.getAmount());
        } else {
            // Handle the case where the account is not found (e.g., throw an exception)
        }
    } else {
        throw DuplicatedDataException("The Loan already exists");
    }
}

void LoansContainers::remove(const string &type, float amount) {
    auto it = search(type, amount);
    if (it != loans.end()) {
        loans.erase(it);
    } else {
        // error
    }
}

void LoansContainers::update(const string &type, float amount, float interestRate, int durationMonths) {
    auto it = search(type, amount);
    if (it != loans.end()) {
        (*it).setType(type);
        (*it).setAmount(amount);
        (*it).setDurationMonths(durationMonths);
    }
}

bool LoansContainers::isThereLoan(const string &type, float amount) {
    return search(type, amount) != loans.end();
}

float LoansContainers::amortizeLoan(int clientNumber, const string& type, float amount, float paymentAmount) {
    list<Loans>::iterator it = searchByClient(clientNumber);

    if (it != loans.end() && it->getType() == type && it->getAmount() == amount) {
        if (paymentAmount >= it->getAmount()) {
            // If payment covers the entire loan, remove it
            loans.erase(it);
            cout << "Loan fully paid off!" << endl;
            return 0.0f; // Loan fully paid
        } else {
            float remainingBalance = it->getAmount() - paymentAmount;
            it->setAmount(remainingBalance);
            cout << "Loan amortized successfully. Remaining balance: " << remainingBalance << endl;
            return remainingBalance;
        }
    } else {
        cout << "Loan not found for this client." << endl;
        return -1.0f; // Indicates loan not found
    }
}
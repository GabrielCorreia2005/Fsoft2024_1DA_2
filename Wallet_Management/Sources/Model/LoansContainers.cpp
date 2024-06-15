#include "LoansContainers.h"
#include "DuplicatedDataException.h"
#include <algorithm>
#include "Client.h" // Include Client.h here

list<Loans> LoansContainers::getAll() {
    return loans;
}

Loans* LoansContainers::getsingle(int number) {
    for (const Loans& loan : loans) {
        if (loan.getAccountNumber() == number) {
            return const_cast<Loans*>(&loan);
        }
    }
    return nullptr;
}

Loans* LoansContainers::get(const string& type, float amount) {
    list<Loans>::iterator it = search(type, amount);
    if (it != loans.end()) {
        return &(*it);
    } else {
        return nullptr;
    }
}

void LoansContainers::add(const Loans& obj, Client* client) {
    if (isThereLoan(obj.getType(), obj.getAmount())) {
        throw DuplicatedDataException("Error: [Loan with this account number already exists for this client.] duplicated!!");
    }
    loans.push_back(obj);
}

list<Loans>::iterator LoansContainers::searchByClient(int clientNumber) {
    return find_if(loans.begin(), loans.end(),
                   [clientNumber](const Loans& l) { return l.getClient() != nullptr && l.getClient()->getNumber() == clientNumber; });
}

void LoansContainers::remove(const string& type, float amount) {
    list<Loans>::iterator it = search(type, amount);
    if (it != loans.end()) {
        loans.erase(it);
    }
}

void LoansContainers::update(const string& type, float amount, float interestRate, int durationMonths) {
    list<Loans>::iterator it = search(type, amount);
    if (it != loans.end()) {
        it->setDurationMonths(durationMonths);
    }
}

bool LoansContainers::isThereLoan(const string& type, float amount) {
    return search(type, amount) != loans.end();
}

list<Loans>::iterator LoansContainers::search(const string& type, float amount) {
    for (list<Loans>::iterator it = loans.begin(); it != loans.end(); ++it) {
        if (it->getType() == type && it->getAmount() == amount) {
            return it;
        }
    }
    return loans.end();
}
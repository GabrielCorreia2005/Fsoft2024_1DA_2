// TransactionsContainers.cpp
#include "TransactionsContainers.h"

list<Transactions> TransactionsContainers::getAll() {
    return transactions;
}

Transactions* TransactionsContainers::get(int transactionId) {
    list<Transactions>::iterator it = search(transactionId);
    if (it != transactions.end()) {
        return &(*it);
    }
    return nullptr;
}

void TransactionsContainers::add(const Transactions &obj) {
    transactions.push_back(obj);
}

void TransactionsContainers::remove(int transactionId) {
    list<Transactions>::iterator it = search(transactionId);
    if (it != transactions.end()) {
        transactions.erase(it);
    }
}

void TransactionsContainers::update(int transactionId, const Date &date, const string &type, float amount, Client* client) {
    list<Transactions>::iterator it = search(transactionId);
    if (it != transactions.end()) {
        it->setDate(date);
        it->setAmount(amount);
        it->setClient(client);
    }
}

list<Transactions>::iterator TransactionsContainers::search(int transactionId) {
    for (list<Transactions>::iterator it = transactions.begin(); it != transactions.end(); ++it) {
        if (it->getTransactionId() == transactionId) {
            return it;
        }
    }
    return transactions.end();
}
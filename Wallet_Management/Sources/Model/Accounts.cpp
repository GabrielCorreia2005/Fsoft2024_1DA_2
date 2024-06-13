//
// Created by corre on 20/05/2024.
//

#include "Accounts.h"
#include "DataConsistencyException.h"

Accounts::Accounts(int nr, float balance, Client *client) : nr(nr), balance(balance), client(client) {
    if (balance < 0) {
        throw DataConsistencyException("Balance cannot be negative.");
    }
    if (!isPointerNotNull(client)) {
        throw DataConsistencyException("Client pointer cannot be null.");
    }
}

Accounts::Accounts(const Accounts &obj) : nr(obj.nr), balance(obj.balance), client(obj.client) {
    if (balance < 0) {
        throw DataConsistencyException("Balance cannot be negative.");
    }
    if (!isPointerNotNull(client)) {
        throw DataConsistencyException("Client pointer cannot be null.");
    }
}

Accounts::~Accounts() {

}

bool Accounts::isPointerNotNull(void *pointer) {
    return pointer != nullptr;
}

int Accounts::getNr() const {
    return nr;
}

float Accounts::getBalance() const {
    return balance;
}

Client *Accounts::getClient() const {
    return client;
}

void Accounts::setNumber(int &nr) {
    Accounts::nr = nr;
}
//
// Created by corre on 20/05/2024.
//

#include "Accounts.h"
#include "DataConsistencyException.h"

const float Accounts::MIN_BALANCE = 500.0f;

// Constructor with validation
Accounts::Accounts(int nr, float balance, Client * client) : nr(nr), balance(balance), client(client) {
    validateBalance(balance); // Validate upon creation
}

// Validation function
void Accounts::validateBalance(float balance) const {
    if (balance < MIN_BALANCE) {
        throw InvalidDataException("Account balance cannot be less than "
                                   + to_string(MIN_BALANCE));
    }
}

// setBalance method with validation
void Accounts::setBalance(float &balance) {
    validateBalance(balance); // Validate before setting
    this->balance = balance;
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


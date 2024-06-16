#include "Acquire.h"

Acquire::Acquire(Insurance *insurance, Client *client) : insurance(insurance), client(client) {}

Acquire::Acquire(const Acquire &obj) : insurance(obj.insurance), client(obj.client) {}

Acquire::~Acquire() {}

Insurance* Acquire::getInsurance() const {
    return insurance;
}

void Acquire::setInsurance(Insurance *insurance) {
    Acquire::insurance = insurance;
}

Client* Acquire::getClient() const {
    return client;
}

void Acquire::setClient(Client *client) {
    Acquire::client = client;
}

bool Acquire::operator==(const Acquire& rhs) const {
    return insurance == rhs.insurance &&
           client == rhs.client;
}
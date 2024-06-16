#include "InsuranceContainer.h"
#include "DuplicatedDataException.h" // Include for handling duplicated data exception

list<Insurance> InsuranceContainer::getAll() {
    return insurances;
}

Insurance *InsuranceContainer::get(const string &name, int clientNumber) {
    list<Insurance>::iterator it = search(name, clientNumber);
    if (it != insurances.end()) {
        return &(*it);
    } else {
        return nullptr;
    }
}

void InsuranceContainer::add(const Insurance &obj) {
    if (isThereInsurance(obj.getName(), obj.getClient()->getNumber())) {
        throw DuplicatedDataException("Duplicated insurance: " + obj.getName() + " for client " + to_string(obj.getClient()->getNumber()));
    }
    insurances.push_back(obj);
}

void InsuranceContainer::remove(const string &name, int clientNumber) {
    list<Insurance>::iterator it = search(name, clientNumber);
    if (it != insurances.end()) {
        insurances.erase(it);
    }
}

void InsuranceContainer::update(const string &name, int clientNumber, float price, float length, int installments, float fees) {
    list<Insurance>::iterator it = search(name, clientNumber);
    if (it != insurances.end()) {
        it->setPrice(price);
        it->setLength(length);
        it->setInstallments(installments);
        it->setFees(fees);
    }
}

bool InsuranceContainer::isThereInsurance(const string &name, int clientNumber) {
    return search(name, clientNumber) != insurances.end();
}

list<Insurance>::iterator InsuranceContainer::search(const string &name, int clientNumber) {
    for (list<Insurance>::iterator it = insurances.begin(); it != insurances.end(); ++it) {
        if (it->getName() == name && it->getClient()->getNumber() == clientNumber) {
            return it;
        }
    }
    return insurances.end();
}

// Get a list of insurances for a specific client
list<Insurance> InsuranceContainer::getClientInsurances(int clientNumber) {
    list<Insurance> clientInsurances;
    for (const auto& insurance : insurances) {
        if (insurance.getClient()->getNumber() == clientNumber) {
            clientInsurances.push_back(insurance);
        }
    }
    return clientInsurances;
}
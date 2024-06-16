#include "AcquireView.h"
#include "Utils.h"

Acquire AcquireView::getAcquire(ClientsContainer &clients, InsuranceContainer &insurances) {
    int clientNumber = Utils::getNumber("Enter client number: ");
    Client* client = clients.get(clientNumber);

    if (client == nullptr) {
        throw InvalidDataException("Client not found.");
    }

    string insuranceName = Utils::getString("Enter insurance name: ");
    Insurance* insurance = insurances.get(insuranceName, clientNumber); // Now pass client number

    if (insurance == nullptr) {
        throw InvalidDataException("Insurance not found.");
    }

    return Acquire(insurance, client);
}

void AcquireView::printAcquire(Acquire *acquire) {
    if (acquire != nullptr) {
        cout << "Client: " << acquire->getClient()->getName() << endl;
        cout << "Insurance: " << acquire->getInsurance()->getName() << endl;
    } else {
        cout << "Acquire not found." << endl;
    }
}

void AcquireView::printAcquires(list<Acquire> &acquires) {
    for (auto &acquire : acquires) {
        printAcquire(&acquire);
        cout << endl;
    }
}
#include "InsuranceView.h"
#include "Utils.h"
#include <iostream>

Insurance InsuranceView::getInsurance(ClientsContainer& clients) {
    string name = Utils::getString("Enter insurance name: ");
    float price = Utils::getNumber("Enter insurance price: ");
    float length = Utils::getNumber("Enter insurance length: ");
    int installments = Utils::getNumber("Enter number of installments: ");
    float fees = Utils::getNumber("Enter insurance fees: ");

    int clientNumber = Utils::getNumber("Enter client number: ");
    Client* client = clients.get(clientNumber);

    if (client == nullptr) {
        throw InvalidDataException("Client not found.");
    }

    return Insurance(name, price, length, installments, fees, client);
}

void InsuranceView::printInsurance(Insurance *insurance) {
    if (insurance != nullptr) {
        cout << "Insurance Name: " << insurance->getName() << endl;
        cout << "Price: " << insurance->getPrice() << endl;
        cout << "Length: " << insurance->getLength() << endl;
        cout << "Installments: " << insurance->getInstallments() << endl;
        cout << "Fees: " << insurance->getFees() << endl;
    } else {
        cout << "Insurance not found." << endl;
    }
}

void InsuranceView::printInsurances(list<Insurance> &insurances) {
    for (auto &insurance : insurances) {
        printInsurance(&insurance);
        cout << endl;
    }
}
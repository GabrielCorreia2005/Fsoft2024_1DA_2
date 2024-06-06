#include "InsuranceView.h"
#include "Utils.h"

Insurance InsuranceView::getInsurance() {
    string name = Utils::getString("Enter insurance name");
    float price = Utils::getNumber("Enter insurance price");
    float length = Utils::getNumber("Enter insurance length (in years)");
    int installments = Utils::getNumber("Enter the number of installments");
    float fees = Utils::getNumber("Enter any fees");

    return Insurance(name, price, length, installments, fees);
}

void InsuranceView::printInsurance(Insurance insurance) {
    cout << "=== Insurance Details ===" << endl;
    cout << "Name: " << insurance.getName() << endl;
    cout << "Price: " << insurance.getPrice() << endl;
    cout << "Length: " << insurance.getLength() << " years" << endl;
    cout << "Installments: " << insurance.getInstallments() << endl;
    cout << "Fees: " << insurance.getFees() << endl;
    cout << "========================" << endl;
}

void InsuranceView::printInsurances(list<Insurance> &insurances) {
    cout << "=== List of Insurances ===" << endl;
    for (const Insurance& insurance : insurances) {
        printInsurance(insurance);
    }
    cout << "=========================" << endl;
}
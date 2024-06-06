#include "InsuranceView.h"
#include "Utils.h"
#include <iostream>
#include <iomanip>

using namespace std;

Insurance InsuranceView::getInsurance() {
    string name;
    float price;
    float length;

    // Get insurance name
    name = Utils::getString("Enter insurance name: ");

    // Get insurance price
    do {
        price = Utils::getNumber("Enter insurance price: ");
        if (price <= 0) {
            cout << "Invalid insurance price. Please enter a positive number." << endl;
        }
    } while (price <= 0);

    // Get insurance length
    do {
        length = Utils::getNumber("Enter insurance length (in months): ");
        if (length <= 0) {
            cout << "Invalid insurance length. Please enter a positive number." << endl;
        }
    } while (length <= 0);

    return Insurance(name, price, length);
}

void InsuranceView::printInsurance(Insurance *insurance) {
    if (insurance) {
        cout << "Insurance Name: " << insurance->getName() << endl;
        cout << "Price: " << fixed << setprecision(2) << insurance->getPrice() << endl;
        cout << "Length (months): " << fixed << setprecision(2) << insurance->getLength() << endl;
    } else {
        cout << "Invalid Insurance (nullptr)." << endl;
    }
}

void InsuranceView::printInsurances(list<Insurance> &insurances) {
    if (insurances.empty()) {
        cout << "There are no insurances to display." << endl;
        return;
    }

    cout << "List of Insurances:" << endl;
    for (const Insurance &insurance : insurances) {
        printInsurance(&insurance);
        cout << "--------------------" << endl;
    }
}
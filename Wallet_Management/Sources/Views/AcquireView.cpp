//
// Created by gvice on 20/05/2024.
//

#include "AcquireView.h"
#include "Utils.h"
#include <iostream>

using namespace std;

Acquire AcquireView::getAcquire(InsuranceContainer &insurances, LoansContainers &loans) {
    int choice;
    Insurance insurance;
    Loans loan;

    do {
        cout << "Do you want to acquire:" << endl;
        cout << "1. Insurance" << endl;
        cout << "2. Loan" << endl;
        cout << "3. Both" << endl;
        cout << "0. Back" << endl;
        choice = Utils::getNumber("Enter your choice");

        switch (choice) {
            case 1:
                insurance = getInsuranceOnly(insurances);
                loan = Loans("", 0, 0, 0); // Create a default loan object
                break;
            case 2:
                loan = getLoanOnly(loans);
                insurance = Insurance("", 0, 0, 0, 0); // Create a default insurance object
                break;
            case 3:
                insurance = getInsuranceOnly(insurances);
                loan = getLoanOnly(loans);
                break;
            case 0:
                break;
            default:
                cout << "Invalid choice. Please enter a number between 0 and 3." << endl;
        }
    } while (choice < 0 || choice > 3);

    return Acquire(insurance, loan);
}

Insurance AcquireView::getInsuranceOnly(InsuranceContainer &insurances) {
    int choice;
    Insurance insurance;

    list<Insurance> availableInsurances = insurances.getAll();
    if (availableInsurances.empty()) {
        cout << "There are no insurances available at the moment." << endl;
        return insurance;
    }

    cout << "Available Insurances:" << endl;
    int insuranceCount = 1;
    for (const Insurance &ins : availableInsurances) {
        cout << insuranceCount << ". " << ins.getName() << endl;
        insuranceCount++;
    }

    do {
        choice = Utils::getNumber("Select insurance (enter number): ");
        if (choice <= 0 || choice > availableInsurances.size()) {
            cout << "Invalid choice. Please enter a valid insurance number." << endl;
        }
    } while (choice <= 0 || choice > availableInsurances.size());

    auto it = availableInsurances.begin();
    advance(it, choice - 1);
    insurance = *it;

    return insurance;
}

Loans AcquireView::getLoanOnly(LoansContainers &loans) {
    int choice;
    Loans loan;

    list<Loans> availableLoans = loans.getAll();
    if (availableLoans.empty()) {
        cout << "There are no loans available at the moment." << endl;
        return loan;
    }

    cout << "Available Loans:" << endl;
    int loanCount = 1;
    for (const Loans &l : availableLoans) {
        cout << loanCount << ". " << l.getType() << " (Amount: " << l.getAmount() << ")" << endl;
        loanCount++;
    }

    do {
        choice = Utils::getNumber("Select loan (enter number): ");
        if (choice <= 0 || choice > availableLoans.size()) {
            cout << "Invalid choice. Please enter a valid loan number." << endl;
        }
    } while (choice <= 0 || choice > availableLoans.size());

    auto it = availableLoans.begin();
    advance(it, choice - 1);
    loan = *it;

    return loan;
}

void AcquireView::printAcquire(Acquire *acquire) {
    cout << "=== Acquire Details ===" << endl;

    if (acquire->getInsurance().getName() != "") { // Check if insurance is valid
        cout << "-- Insurance --" << endl;
        cout << "Name: " << acquire->getInsurance().getName() << endl;
        cout << "Price: " << acquire->getInsurance().getPrice() << endl;
        cout << "Length: " << acquire->getInsurance().getLength() << " years" << endl;
        cout << "Installments: " << acquire->getInsurance().getInstallments() << endl;
        cout << "Fees: " << acquire->getInsurance().getFees() << endl;
    }

    if (acquire->getLoans().getType() != "") { // Check if loan is valid
        cout << "-- Loan --" << endl;
        cout << "Type: " << acquire->getLoans().getType() << endl;
        cout << "Amount: " << acquire->getLoans().getAmount() << endl;
        cout << "Interest Rate: " << acquire->getLoans().getInterestRate() << "%" << endl;
        cout << "Duration: " << acquire->getLoans().getDurationMonths() << " months" << endl;
    }

    cout << "======================" << endl;
}
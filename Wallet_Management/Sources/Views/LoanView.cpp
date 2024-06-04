//
// Created by gvice on 20/05/2024.
//

#include "LoanView.h"
#include "Utils.h"
#include <iostream>
#include <iomanip>

using namespace std;

Loans LoanView::getLoan() {
    string type;
    float amount;
    float interestRate;
    int durationMonths;

    // Get loan type
    type = Utils::getString("Enter loan type: ");

    // Get loan amount
    do {
        amount = Utils::getNumber("Enter loan amount: ");
        if (amount <= 0) {
            cout << "Invalid loan amount. Please enter a positive number." << endl;
        }
    } while (amount <= 0);

    // Get interest rate
    do {
        interestRate = Utils::getNumber("Enter interest rate (as a percentage): ");
        if (interestRate < 0) {
            cout << "Invalid interest rate. Please enter a non-negative number." << endl;
        }
    } while (interestRate < 0);

    // Get loan duration in months
    do {
        durationMonths = Utils::getNumber("Enter loan duration (in months): ");
        if (durationMonths <= 0) {
            cout << "Invalid loan duration. Please enter a positive number." << endl;
        }
    } while (durationMonths <= 0);

    return Loans(type, amount, interestRate, durationMonths);
}

void LoanView::printLoan(Loans *loan) {
    if (loan) {
        cout << "Loan Type: " << loan->getType() << endl;
        cout << "Amount: " << fixed << setprecision(2) << loan->getAmount() << endl;
        cout << "Interest Rate: " << fixed << setprecision(2) << loan->getInterestRate() << "%" << endl;
        cout << "Duration (months): " << loan->getDurationMonths() << endl;
    } else {
        cout << "Invalid Loan (nullptr)" << endl;
    }
}

void LoanView::printLoans(list<Loans> &loans) {
    if (loans.empty()) {
        cout << "There are no loans to display." << endl;
        return;
    }

    cout << "List of Loans:" << endl;
    for (const Loans &loan : loans) {
        printLoan(&loan);
        cout << "--------------------" << endl;
    }
}
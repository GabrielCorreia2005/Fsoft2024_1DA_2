#include "LoanView.h"
#include "Utils.h"
#include <iostream>


Loans LoanView::getLoan(int accountNumber, Client* client) {
    string type = Utils::getString("Enter loan type: ");
    float amount = Utils::getNumber("Enter loan amount: ");
    int durationMonths = Utils::getNumber("Enter loan duration (in months): ");

    return Loans(accountNumber, type, amount, durationMonths, client);
}

void LoanView::printLoan(Loans *loan) {
    if (loan != nullptr) { // Make sure the pointer is valid
        cout << "Account Number: " << loan->getAccountNumber() << endl;
        cout << "Type: " << loan->getType() << endl;
        cout << "Amount: " << loan->getAmount() << endl;
        cout << "Duration (Months): " << loan->getDurationMonths() << endl;
        cout << "Interest Rate: " << loan->getFixedInterestRate() * 100 << "%" << endl; // Access through the object pointer
    }
}

void LoanView::printLoans(list<Loans> &loans) {
    cout << "List of Loans:" << endl;
    for (auto &loan : loans) {
        printLoan(&loan);
    }
}
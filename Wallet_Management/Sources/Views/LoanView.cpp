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
    if (loan != nullptr) {
        cout << "Loan Type: " << loan->getType() << endl;
        cout << "Amount: " << loan->getAmount() << endl;
        cout << "Interest Rate: " << Loans::getFixedInterestRate() * 100 << "%" << endl;
        cout << "Duration (months): " << loan->getDurationMonths() << endl;
        cout << "--------------------" << endl;
    } else {
        cout << "Invalid Loan (nullptr)" << endl;
    }
}

void LoanView::printLoans(list<Loans> &loans) {
    cout << "List of Loans:" << endl;
    for (auto &loan : loans) {
        printLoan(&loan);
    }
}
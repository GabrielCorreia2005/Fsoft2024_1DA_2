#include "LoanView.h"
#include "Utils.h"
#include "Loans.h"
#include <iostream>
#include <string>
#include "Date.h"
using namespace std;

Loans LoanView::getLoan(int accountNumber, Client* client) {
    string type = Utils::getString("Enter the loan type: ");
    float amount = Utils::getNumber("Enter the loan amount: ");
    int durationMonths = Utils::getNumber("Enter the loan duration in months: ");

    return Loans(accountNumber, type, amount, durationMonths, client);
}

void LoanView::printLoan(Loans *loan) {
    if (loan != nullptr) {
        cout << "Loan details:" << endl;
        cout << "Account Number: " << loan->getAccountNumber() << endl;
        cout << "Loan type: " << loan->getType() << endl;
        cout << "Loan amount: " << loan->getAmount() << endl;
        cout << "Loan duration (months): " << loan->getDurationMonths() << endl;
    } else {
        cout << "Loan not found." << endl;
    }
}

void LoanView::printLoans(list<Loans> &loans) {
    if (!loans.empty()) {
        cout << "List of loans:" << endl;
        for (Loans &loan : loans) {
            printLoan(&loan);
        }
    } else {
        cout << "No loans found." << endl;
    }
}
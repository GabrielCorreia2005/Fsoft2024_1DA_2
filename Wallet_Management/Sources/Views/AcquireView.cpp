//
// Created by gvice on 20/05/2024.
//

#include "AcquireView.h"
#include "Utils.h"
#include <iostream>

using namespace std;

Acquire AcquireView::getAcquire(InsuranceContainer &insurances, LoansContainers &loans) {
    Insurance *selectedInsurance = nullptr;
    Loans *selectedLoan = nullptr;

    // Insurance selection
    int insuranceChoice;
    do {
        cout << "Do you want to acquire insurance?" << endl;
        cout << "1. Yes" << endl;
        cout << "2. No" << endl;
        insuranceChoice = Utils::getNumber("Enter your choice: ");

        if (insuranceChoice != 1 && insuranceChoice != 2) {
            cout << "Invalid choice. Please enter 1 or 2." << endl;
        }
    } while (insuranceChoice != 1 && insuranceChoice != 2);

    if (insuranceChoice == 1) {
        cout << "Available Insurances:" << endl;
        list<Insurance> allInsurances = insurances.getAll();
        int insuranceCount = 1;
        for (const Insurance &i : allInsurances) {
            cout << insuranceCount << ". " << i.getName() << endl;
            insuranceCount++;
        }

        int insuranceSelection;
        do {
            insuranceSelection = Utils::getNumber("Select Insurance (enter number): ");
            if (insuranceSelection <= 0 || insuranceSelection > allInsurances.size()) {
                cout << "Invalid insurance selection." << endl;
            }
        } while (insuranceSelection <= 0 || insuranceSelection > allInsurances.size());

        auto insuranceIt = allInsurances.begin();
        advance(insuranceIt, insuranceSelection - 1);
        selectedInsurance = &(*insuranceIt);
    }

    // Loan selection
    int loanChoice;
    do {
        cout << "Do you want to acquire a loan?" << endl;
        cout << "1. Yes" << endl;
        cout << "2. No" << endl;
        loanChoice = Utils::getNumber("Enter your choice: ");

        if (loanChoice != 1 && loanChoice != 2) {
            cout << "Invalid choice. Please enter 1 or 2." << endl;
        }
    } while (loanChoice != 1 && loanChoice != 2);

    if (loanChoice == 1) {
        cout << "Available Loans:" << endl;
        list<Loans> allLoans = loans.getAll();
        int loanCount = 1;
        for (const Loans &l : allLoans) {
            cout << loanCount << ". " << l.getType() << " (Amount: " << l.getAmount() << ")" << endl;
            loanCount++;
        }

        int loanSelection;
        do {
            loanSelection = Utils::getNumber("Select Loan (enter number): ");
            if (loanSelection <= 0 || loanSelection > allLoans.size()) {
                cout << "Invalid loan selection." << endl;
            }
        } while (loanSelection <= 0 || loanSelection > allLoans.size());

        auto loanIt = allLoans.begin();
        advance(loanIt, loanSelection - 1);
        selectedLoan = &(*loanIt);
    }

    // Create and return the Acquire object
    return Acquire(*selectedInsurance, *selectedLoan);
}

// Add functions to print Acquire objects if needed.
void AcquireView::printAcquire(Acquire *acquire){

    if (acquire) {
        cout << "Insurance: " << acquire->getInsurance().getName() << endl;
        cout << "Loan: " << acquire->getLoans().getType() << endl;
    } else {
        cout << "No acquire found (nullptr)." << endl;
    }

<<<<<<< Updated upstream
}
=======
}
>>>>>>> Stashed changes

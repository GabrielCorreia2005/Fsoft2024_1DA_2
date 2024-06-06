#include "AcquireView.h"
#include "Utils.h"
#include <iostream>
#include <limits> // For numeric_limits

using namespace std;

// Get Acquire data from the user
Acquire AcquireView::getAcquire(InsuranceContainer &insurances, LoansContainers &loans) {
    Acquire acquire; // Create an Acquire object (using the default constructor)

    int choice = Utils::getNumber("Do you want to acquire:\n1 - Insurance\n2 - Loan\n3 - Both\n0 - Back\nEnter your choice: ");

    switch (choice) {
        case 1: {
            Insurance insurance = getInsuranceOnly(insurances);
            acquire.setInsurance(insurance); // Set only the insurance
            break;
        }
        case 2: {
            Loans loan = getLoanOnly(loans);
            acquire.setLoans(loan);  // Set only the loan
            break;
        }
        case 3: {
            Insurance insurance = getInsuranceOnly(insurances);
            Loans loan = getLoanOnly(loans);
            acquire.setInsurance(insurance);
            acquire.setLoans(loan);
            break;
        }
        case 0:
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
    }

    return acquire;
}

// Get insurance data (helper function for case 1 and 3)
Insurance AcquireView::getInsuranceOnly(InsuranceContainer &insurances) {
    string name = Utils::getString("Enter insurance name: ");

    // Check for existing insurance with the same name
    if (insurances.isThereInsurance(name)) {
        throw DuplicatedDataException("An insurance with this name already exists.");
    }

    float price;
    float length;
    int installments;
    float fees;

    // Input and Validation Loop for price:
    while (true) {
        price = Utils::getNumber("Enter insurance price (positive value): ");
        if (price > 0) {
            break; // Valid price entered, exit loop
        } else {
            cout << "Invalid price. Please enter a positive value." << endl;
            cin.clear(); // Clear error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        }
    }

    // Input and Validation Loop for length:
    while (true) {
        length = Utils::getNumber("Enter insurance length (in months, positive value): ");
        if (length > 0) {
            break;
        } else {
            cout << "Invalid length. Please enter a positive value." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    // Input and Validation Loop for installments:
    while (true) {
        installments = Utils::getNumber("Enter number of installments (positive value): ");
        if (installments > 0) {
            break;
        } else {
            cout << "Invalid number of installments. Please enter a positive value." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    // Input and Validation Loop for fees:
    while (true) {
        fees = Utils::getNumber("Enter insurance fees (non-negative value): ");
        if (fees >= 0) {
            break;
        } else {
            cout << "Invalid fees. Please enter a non-negative value." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    return Insurance(name, price, length, installments, fees);
}

// Get loan data (helper function for case 2 and 3)
Loans AcquireView::getLoanOnly(LoansContainers &loans) {
    string type = Utils::getString("Enter loan type: ");
    float amount = Utils::getNumber("Enter loan amount: ");
    float interestRate = Utils::getNumber("Enter interest rate: ");
    int durationMonths = Utils::getNumber("Enter loan duration (in months): ");

    // Additional validation for loan data
    if (amount <= 0) {
        throw InvalidDataException("Loan amount must be a positive value.");
    }
    if (interestRate < 0) {
        throw InvalidDataException("Interest rate cannot be negative.");
    }
    if (durationMonths <= 0) {
        throw InvalidDataException("Loan duration must be a positive value.");
    }

    return Loans(type, amount, interestRate, durationMonths);
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
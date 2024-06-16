#include "View.h"
#include "Utils.h"
#include <iostream>

using namespace std;

View::View() {}

int View::menuClient() {
    int choice;
    cout << "**************** Menu Client ****************" << endl;
    cout << "1- Create Account" << endl;
    cout << "2- List" << endl;
    cout << "3- Account Information" << endl;
    cout << "4- Delete" << endl;
    cout << "0- Exit" << endl;
    cout << "Option: ";
    cin >> choice;
    return choice;
}

int View::menuBank() {
    int choice;
    cout << "**************** Menu Bank ****************" << endl;
    cout << "1- Account" << endl;
    cout << "2- Loans" << endl;
    cout << "3- Transactions" << endl;
    cout << "4- Insurance" << endl;
    cout << "0- Log Out" << endl;
    cout << "Option: ";
    cin >> choice;
    return choice;
}

int View::menuLoans() {
    int choice;
    cout << "**************** Menu Loans ****************" << endl;
    cout << "1- Add Loan" << endl;
    cout << "2- List Loans" << endl;
    cout << "3- Loan Details" << endl;
    cout << "4- Delete Loan" << endl;
    cout << "0- Exit" << endl;
    cout << "Option: ";
    cin >> choice;
    return choice;
}

int View::menuTransactions() {
    int option;
    do {
        cout << "----- Transactions Menu -----" << endl;
        cout << "1- Add Transaction" << endl;
        cout << "2- List Transactions" << endl;
        cout << "0- Exit" << endl;
        cout << "Option: ";
        cin >> option;

        if (option < 0 || option > 2) {
            cout << "Invalid option. Please try again." << endl;
        }
    } while (option < 0 || option > 2);

    return option;
}

int View::menuInsurance() {
    cout << "\nInsurance Menu" << endl;
    cout << "1. Add new insurance" << endl;
    cout << "2. List all insurances" << endl;
    cout << "3. Monitor insurance for a client" << endl; // Add new option
    cout << "0. Back to main menu" << endl;
    return Utils::getNumber("Select an option: ");
}
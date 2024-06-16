#include "View.h"
#include "Utils.h"
#include <iostream>

using namespace std;

View::View() {}

int View::menuClient() {
    int option;
    cout << "**************** Menu Client ****************" << endl;
    cout << "1- Create Account" << endl;
    cout << "2- List" << endl;
    cout << "3- Account Information" << endl;
    cout << "4- Delete" << endl;
    cout << "0- Exit" << endl;
    cout << "Option: ";
    option = Utils::getNumber("Option: ");
    return option;
}

int View::menuBank() {
    int option;
    cout << "**************** Menu Bank ****************" << endl;
    cout << "1- Account" << endl;
    cout << "2- Loans" << endl;
    cout << "3- Transactions" << endl;
    cout << "4- Insurance" << endl;
    cout << "0- Log Out" << endl;
    cout << "Option: ";
    option = Utils::getNumber("Option: ");
    return option;
}

int View::menuLoans() {
    int option;
    cout << "**************** Menu Loans ****************" << endl;
    cout << "1- Add Loan" << endl;
    cout << "2- List Loans" << endl;
    cout << "3- Loan Details" << endl;
    cout << "4- Amortize Loan" << endl;
    cout << "0- Exit" << endl;
    option = Utils::getNumber("Option: ");
    return option;
}

int View::menuTransactions() {
    int option;
        cout << "----- Transactions Menu -----" << endl;
        cout << "1- Add Transaction" << endl;
        cout << "2- List Transactions" << endl;
        cout << "0- Exit" << endl;
        cout << "Option: ";
        cin >> option;
        option = Utils::getNumber("Option: ");
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
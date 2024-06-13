#include "Controller.h"
#include <iostream> // For input/output

using namespace std;

Controller::Controller(WalletManagement &walletManagement) : model(walletManagement) {}

void Controller::run() {
    int choice;
    do {
        // Display main menu (you'll need to define this content)
        cout << "Main Menu\n";
        cout << "1. Manage Accounts\n";
        cout << "2. Manage Clients\n";
        // ... other options
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: runAccount(); break;
            case 2: runClient(); break;
                // ... handle other cases
            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice. Please try again.\n";
        }   
    } while (choice != 0);
}

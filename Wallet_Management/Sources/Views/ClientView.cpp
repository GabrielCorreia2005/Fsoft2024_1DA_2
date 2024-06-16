// clientview.cpp
#include "clientview.h"
#include "utils.h"
#include <iostream>

using namespace std;

Client ClientView::getClient() {
    string name;
    Date birth;

    while (true) {
        // Prompt for name input
        cout << "Name:";
        cin.ignore(); // Ignore any leftover newline characters
        getline(cin, name);

        // Check if user wants to cancel
        if (name.empty() || name.length() < 3 || name.length() > 100) {
            char choice;
            cout << "Invalid name. Name must be between 3 and 100 characters long." << endl;
            cout << "Enter 'Y' to try again or 'N' to cancel:";
            cin >> choice;
            cin.ignore(); // Ignore any leftover newline character
            if (toupper(choice) != 'Y') {
                cout << "Operation canceled." << endl;
                return Client("", Date(), 0); // Return empty client or handle accordingly
            } else {
                continue; // Prompt again for name
            }
        }

        // Validate the name (ensure it only contains letters)
        if (!Client::isNameValid(name)) {
            char choice;
            cout << "Invalid name. Name must contain only letters." << endl;
            cout << "Enter 'Y' to try again or 'N' to cancel:";
            cin >> choice;
            cin.ignore(); // Ignore any leftover newline character
            if (toupper(choice) != 'Y') {
                cout << "Operation canceled." << endl;
                return Client("", Date(), 0); // Return empty client or handle accordingly
            } else {
                continue; // Prompt again for name
            }
        }

        birth = getDate();

        int age = birth.calculateAge();
        if (age >= 18 && age <= 150) {
            // Generate a client number (replace with your logic)
            int number = 1; // Replace with actual logic
            return Client(name, birth, number);
        } else {
            char choice;
            cout << "Client must be between 18 and 150 years old. Enter 'Y' to try again or 'N' to cancel:";
            cin >> choice;
            cin.ignore(); // Ignore any leftover newline character
            if (toupper(choice) != 'Y') {
                cout << "Operation canceled." << endl;
                return Client("", Date(), 0); // Return empty client or handle accordingly
            }
        }
    }
}

Date ClientView::getDate() {
    int day, month, year;
    do {
        cout << "Day:";
        day = Utils::getNumber("");
        cout << "Month:";
        month = Utils::getNumber("");
        cout << "Year:";
        year = Utils::getNumber("");
    } while (!Date::isValid(day, month, year));

    return Date(day, month, year);
}



void ClientView::printClients(list<Client>& clients) {
    for (Client& client : clients) {
        cout << client.getNumber() << ":";
        cout << client.getName() << ":";

        int day, month, year;
        client.getBirth().getDate(day, month, year);  // Get date components

        cout << day << "/" << month << "/" << year << endl;
    }
}

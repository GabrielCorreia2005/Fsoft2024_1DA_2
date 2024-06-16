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
            if (name.empty() || name.length() < 3) {
                char choice;
                cout << "Invalid name. Name must be at least 3 characters long." << endl;
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

            // Validate the name
            Client::isNameValid(name); // This should throw an exception if the name is invalid

            birth = getDate();

            int age = birth.calculateAge();
            if (age >= 18) {
                // Generate a client number (replace with your logic)
                int number = 1; // Replace with actual logic
                return Client(name, birth, number);
            } else {
                char choice;
                cout << "Client must be 18 years or older. Enter 'Y' to try again or 'N' to cancel:";
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

void ClientView::printClient(Client *client) {
    if (client != nullptr) {
        int day, month, year;
        client->getBirth().getDate(day, month, year);
        string date = to_string(day) + "/" + to_string(month) + "/" + to_string(year);
        cout << client->getNumber() << ":" << client->getName() << ":" << date << endl;
    } else {
        cout << "Invalid Client (nullptr)" << endl;
    }
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

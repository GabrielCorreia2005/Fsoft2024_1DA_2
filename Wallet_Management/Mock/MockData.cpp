
//
// Created by gvice on 20/05/2024.
//

#include <time.h>
#include <string>
#include <vector>
#include <random>
#include "MockData.h"
#include "WalletManagement.h"

using namespace std;

class MockData {
private:
    // Constants for data generation
    const int CLIENTS_NR = 5;
    const int ACCOUNTS_NR = 8;
    const int TRANSACTIONS_NR = 10;
    const int LOANS_NR = 3;
    const int INSURANCES_NR = 3;

    // Data vectors for clients
    const vector<string> clientNames = {
            "Alice Johnson", "Bob Smith", "Charlie Brown", "David Wilson", "Eve Williams"
    };
    const vector<int> clientNumbers = {1001, 1002, 1003, 1004, 1005};

    // Data vectors for accounts
    const vector<float> accountBalances = {500.00f, 1200.50f, 2500.00f, 800.75f, 5000.20f, 300.00f, 1800.00f, 950.50f};

    // Data vectors for transactions
    const vector<string> transactionTypes = {"Deposit", "Withdrawal", "Transfer"};

    // Data vectors for loans
    const vector<string> loanTypes = {"Personal Loan", "Car Loan", "Home Loan"};
    const vector<float> loanAmounts = {5000.00f, 20000.00f, 100000.00f};
    const vector<float> loanInterestRates = {3.5f, 5.0f, 2.8f};
    const vector<int> loanDurations = {36, 60, 120}; // Durations in months

    // Data vectors for insurance
    const vector<string> insuranceNames = {"Health Insurance", "Car Insurance", "Home Insurance"};
    const vector<float> insurancePrices = {100.00f, 50.00f, 80.00f};
    const vector<float> insuranceLengths = {12.0f, 6.0f, 12.0f}; // Lengths in months

    // Random number generator
    random_device rd;
    mt19937 generator{rd()};

    // Helper function to generate a random date within a range
    Date genDate(const Date &minDate, const Date &maxDate);

    // Helper functions to insert data into containers
    void insertClients(ClientsContainer &container);
    void insertAccounts(ClientsContainer &clients, AccountsContainers &container);
    void insertTransactions(AccountsContainers &accounts, TransactionsContainers &container);
    void insertLoans(LoansContainers &container);
    void insertInsurances(InsuranceContainer &container);

public:
    // Main function to generate mock data for the entire WalletManagement system
    void generateData(WalletManagement &walletManagement);
};

// Implementation of helper function genDate
Date MockData::genDate(const Date &minDate, const Date &maxDate) {
    uniform_int_distribution<> yearDist(minDate.getYear(), maxDate.getYear());
    uniform_int_distribution<> monthDist(1, 12);
    uniform_int_distribution<> dayDist(1, 31); // Simplified for demonstration purposes

    int year = yearDist(generator);
    int month = monthDist(generator);
    int day = dayDist(generator);

    // Basic validation for day based on month and year
    if (month == 2 && day > 28) {
        day = 28;
    } else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
        day = 30;
    }

    return Date(day, month, year);
}

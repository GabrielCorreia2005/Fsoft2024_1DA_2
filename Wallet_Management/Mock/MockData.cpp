#include "MockData.h"
#include "Accounts.h"
#include "Client.h"
#include "Loans.h"
#include <random>
#include "Insurance.h"

using namespace std;

// Function to generate a random number within a range
int getRandomNumber(int min, int max) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(min, max);
    return dis(gen);
}

void MockData::generateData(WalletManagement &walletManagement) {
    // Clients
    vector<string> names = {
            "Alice", "Bob", "Charlie", "David", "Emily", "Frank", "Grace", "Henry", "Isabella", "Jack"
    };

    for (int i = 0; i < names.size(); ++i) {
        Date birth(26, 4, 1982); // Example birth date
        Client client(names[i], birth, i + 1); // Assign unique client number
        try {
            walletManagement.getClientContainer().add(client);
        } catch (DuplicatedDataException& e) {
            cerr << "Error adding client: " << e.what() << endl;
        }
    }

    // Accounts (ensure minimum balance)
    int accountNumber = 1;
    for (int i = 0; i < names.size(); ++i) {
        Client *client = walletManagement.getClientContainer().get(i + 1);

        if (client) {
            // Generate a random balance that is at least 500
            float initialBalance = 500 + getRandomNumber(0, 9500);

            Accounts account(accountNumber++, initialBalance, client);
            try {
                walletManagement.getAccountsContainer().add(account);
            } catch (DuplicatedDataException& e) {
                cerr << "Error adding account: " << e.what() << endl;
            }
        } else {
            cerr << "Error: Client not found for account creation." << endl;
        }
    }

    // Loans
    vector<string> loanTypes = {"Personal Loan", "Car Loan", "Home Loan"};
    for (int i = 0; i < 10; ++i) {
        string loanType = loanTypes[getRandomNumber(0, loanTypes.size() - 1)];
        float loanAmount = getRandomNumber(1000, 50000);
        int durationMonths = getRandomNumber(12, 72);

        // Get a random client from the container
        list<Client> allClients = walletManagement.getClientContainer().getAll();
        int randomClientIndex = getRandomNumber(0, allClients.size() - 1);
        auto it = allClients.begin();
        std::advance(it, randomClientIndex);
        Client* randomClient = &(*it);

        // Get the client's account (if it exists)
        Accounts* clientAccount = walletManagement.getAccountsContainer().get(randomClient->getNumber());

        // Create the loan and associate it with the account and client
        if (clientAccount) {
            // Associate the loan with the existing account
            Loans loan(clientAccount->getNr(), loanType, loanAmount, durationMonths, randomClient);
            try {
                walletManagement.getLoansContainer().add(loan, randomClient);
            } catch (DuplicatedDataException& e) {
                cerr << "Error adding loan: " << e.what() << endl;
            }
        } else {
            // Create a new account with a random balance for the client
            float randomBalance = 500 + getRandomNumber(0, 9500);
            Accounts account(accountNumber++, randomBalance, randomClient);
            try {
                walletManagement.getAccountsContainer().add(account);
            } catch (DuplicatedDataException& e) {
                cerr << "Error adding account: " << e.what() << endl;
            }
            // Create the loan
            Loans loan(account.getNr(), loanType, loanAmount, durationMonths, randomClient);
            try {
                walletManagement.getLoansContainer().add(loan, randomClient);
            } catch (DuplicatedDataException& e) {
                cerr << "Error adding loan: " << e.what() << endl;
            }
        }
    }

    // Insurance
    vector<string> insuranceTypes = {"Health Insurance", "Life Insurance", "Car Insurance", "Home Insurance"};
    for (int i = 0; i < 10; ++i) {
        string insuranceType = insuranceTypes[getRandomNumber(0, insuranceTypes.size() - 1)];
        float price = getRandomNumber(100, 1000);
        float length = getRandomNumber(1, 12); // Length in months
        int installments = getRandomNumber(1, 12); // Number of installments for payment
        float fees = getRandomNumber(0, 100); // Additional fees associated with the insurance

        Insurance insurance(insuranceType, price, length, installments, fees);
        try {
            //     walletManagement.getInsuranceContainer().add(insurance);
        } catch (DuplicatedDataException& e) {
            cerr << "Error adding insurance: " << e.what() << endl;
        }
    }

    // Transactions (You might want to improve this with more realistic transactions)
    list<Accounts> allAccounts = walletManagement.getAccountsContainer().getAll();
    for (int i = 0; i < 10; ++i) {
        float transactionAmount = getRandomNumber(10, 1000);
        string transactionType = (getRandomNumber(0, 1) == 0) ? "Deposit" : "Withdrawal"; // Example types
        Date transactionDate(1, 1, 2024); // Example date

        // Get random accounts for transactions
        auto it1 = allAccounts.begin();
        std::advance(it1, getRandomNumber(0, allAccounts.size() - 1));
        Accounts* originAccount = &(*it1);

        auto it2 = allAccounts.begin();
        std::advance(it2, getRandomNumber(0, allAccounts.size() - 1));
        Accounts* destinationAccount = &(*it2);

        //  Transactions transaction(transactionAmount, transactionType, transactionDate, originAccount, destinationAccount);
        // walletManagement.getTransactionsContainer().add(transaction);
    }

    // Ensure minimum balance in mock accounts
    Client* mockClient = walletManagement.getClientContainer().get(1);
    if (mockClient) {
        float randomBalance = balanceDist(gen);
        Accounts mockAccount(1, randomBalance, mockClient);
        walletManagement.getAccountsContainer().add(mockAccount);
    }
}
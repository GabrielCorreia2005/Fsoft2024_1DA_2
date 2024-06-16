#ifndef FSOFT_PROJECT_LOANVIEW_H
#define FSOFT_PROJECT_LOANVIEW_H

#include <list>
#include "Loans.h"
#include "Client.h" // Include Client.h for getLoan function

class LoanView {
public:
    Loans getLoan(int accountNumber, Client* client); // Add client to getLoan
    void printLoan(Loans *loan);
    void printLoans(list<Loans> &loans);
};

#endif //FSOFT_PROJECT_LOANVIEW_H
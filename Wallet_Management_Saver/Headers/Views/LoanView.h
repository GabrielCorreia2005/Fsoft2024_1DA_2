//
// Created by gvice on 20/05/2024.
//

#ifndef FSOFT_PROJECT_LOANVIEW_H
#define FSOFT_PROJECT_LOANVIEW_H

#include <list>
#include "Loans.h"

class LoanView {
public:
    // Get loan data from user input
    Loans getLoan();

    // Print details of a single loan to the console
    void printLoan(Loans *loan);

    // Print a list of loans to the console
    void printLoans(list<Loans> &loans);

    // You might want to add functions like:
    // void printClientLoans(Client * client, list<Loans>& loans); // To print loans for a specific client
    // Loans* selectLoan(list<Loans>& loans); // To allow user to select a loan from a list
};

#endif //FSOFT_PROJECT_LOANVIEW_H
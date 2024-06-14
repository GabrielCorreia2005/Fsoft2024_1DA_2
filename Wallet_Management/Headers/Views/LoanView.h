//
// Created by gvice on 20/05/2024.
//

#ifndef FSOFT_PROJECT_LOANVIEW_H
#define FSOFT_PROJECT_LOANVIEW_H

#include <list>  // Add this line
#include "Loans.h"

class LoanView {
public:
    Loans getLoan();
    void printLoan(Loans *loan);
    void printLoans(list<Loans> &loans);
};

#endif //FSOFT_PROJECT_LOANVIEW_HANVIEW_H
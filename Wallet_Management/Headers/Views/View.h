//
// Created by gvice on 20/05/2024.
//

#ifndef FSOFT_PROJECT_VIEW_H
#define FSOFT_PROJECT_VIEW_H

using namespace std;
class View {
public:
    View();

    int menuClient();
    int menuBank();
    int menuLoans();
    int menuTransactions();
    int menuInsurance();
    int menuAccount(); // New menu for account options
};

#endif //FSOFT_PROJECT_VIEW_H
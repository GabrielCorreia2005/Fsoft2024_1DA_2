//
// Created by gvice on 20/05/2024.
//

#include <iostream>
#include <limits>
#include "Utils.h"

using namespace std;

int Utils::getNumber(const string& label)
{
    int number;
    bool flag = false;

    do
    {
        cout << label << ": ";
        flag = false;

        cin >> number;

        if (cin.fail()) {
            cout << "Not a number, please enter a number" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            flag = true;
        }
    }while (flag == true);

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return number;
    }
}

string Utils::getString(const string& label)
{
    string input;

    cout << label << ": ";
    getline (cin, input);

    return input;
}
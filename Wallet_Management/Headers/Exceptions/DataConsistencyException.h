//
// Created by gvice on 13/05/2024.
//

#ifndef WALLET_MANAGEMENT_DATACONSISTENCYEXCEPTION_H
#define WALLET_MANAGEMENT_DATACONSISTENCYEXCEPTION_H

#include <exception>
#include <string>
using namespace std;

class DataConsistencyException : public exception {
private:
    string data;
public:
    explicit DataConsistencyException(const string &data);

    const char *what()  override;
};


#endif //WALLET_MANAGEMENT_DATACONSISTENCYEXCEPTION_H
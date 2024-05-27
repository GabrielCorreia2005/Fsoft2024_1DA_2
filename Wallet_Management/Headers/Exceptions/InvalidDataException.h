//
// Created by gvice on 13/05/2024.
//

#ifndef WALLET_MANAGEMENT_INVALIDDATAEXCEPTION_H
#define WALLET_MANAGEMENT_INVALIDDATAEXCEPTION_H

#include <exception>
#include <string>
using namespace std;

class InvalidDataException : public exception {
private:
    string data;
public:
    explicit InvalidDataException(const string &data);

    const char *what()  override;
};


#endif //WALLET_MANAGEMENT_INVALIDDATAEXCEPTION_H
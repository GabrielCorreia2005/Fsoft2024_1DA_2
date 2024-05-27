//
// Created by gvice on 13/05/2024.
//

#ifndef WALLET_MANAGEMENT_DUPLICATEDDATAEXCEPTION_H
#define WALLET_MANAGEMENT_DUPLICATEDDATAEXCEPTION_H

#include <exception>
#include <string>
using namespace std;

class DuplicatedDataException : public exception {
private:
    string data;
public:
    explicit DuplicatedDataException(const string &data);

    const char *what()  override;
};


#endif //WALLET_MANAGEMENT_DUPLICATEDDATAEXCEPTION_H
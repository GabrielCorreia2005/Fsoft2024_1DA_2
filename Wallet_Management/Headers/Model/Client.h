//
// Created by corre on 20/05/2024.
//

#ifndef WALLET_MANAGEMENT_CLIENT_H
#define WALLET_MANAGEMENT_CLIENT_H

#include <string>
#include "Date.h"
#include "InvalidDataException.h"

using namespace std;

class Client {
private:
    string name;
    int number;
    Date birth;
    bool isNameValid(const string& name);

public:
    Client(const string& name, int number, const Date& birth);
    Client(const Client &obj);
    ~Client();

    const string& getName() const;
    void setName(const string &name);

    int getNumber() const;
    void setNumber(int number);

    const Date& getBirth() const;
    void setBirth(const Date &birth);

    bool operator==(const Client &obj) const;
    bool operator==(int nr) const;
};

#endif //WALLET_MANAGEMENT_CLIENT_H
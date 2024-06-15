#ifndef WALLET_MANAGEMENT_CLIENT_H
#define WALLET_MANAGEMENT_CLIENT_H

#include <string>
#include "Date.h"
#include "InvalidDataException.h"
#include "Loans.h"  // Include Loans.h

using namespace std;

class Client {
private:
    string name;
    Date birth;

public:
    Client(const string &name, const Date &birth, const int number);
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

    static bool isNameValid(const string& name);
};

#endif //WALLET_MANAGEMENT_CLIENT_H
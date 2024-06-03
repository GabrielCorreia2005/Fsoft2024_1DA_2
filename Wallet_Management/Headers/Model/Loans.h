//
// Created by corre on 20/05/2024.
//

#ifndef WALLET_MANAGEMENT_LOANS_H
#define WALLET_MANAGEMENT_LOANS_H
#include <string>
using namespace std;

class Loans{
public:
    string type;
    float value;
    float lentgh;
    float instalemets;
    float fees;
private:
    Loans( string type,  float value, float lentgh,float instalemets, float fees );
    Loans(const Loans &obj);
    ~Loans();
};

#endif //WALLET_MANAGEMENT_LOANS_H

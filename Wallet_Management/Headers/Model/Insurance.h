//
// Created by corre on 20/05/2024.
//

#ifndef WALLET_MANAGEMENT_INSURANCE_H
#define WALLET_MANAGEMENT_INSURANCE_H

using namespace std;

class Insurance{
public:
    float value;
    float lentgh;
private:
    Insurance(float value, float lentgh);
    Insurance(const Insurance &obj);
    ~Insurance();
};
#endif //WALLET_MANAGEMENT_INSURANCE_H

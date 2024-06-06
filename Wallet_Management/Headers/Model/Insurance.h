//
// Created by corre on 20/05/2024.
//

#ifndef WALLET_MANAGEMENT_INSURANCE_H
#define WALLET_MANAGEMENT_INSURANCE_H

#include <string>
#include "InvalidDataException.h" // Include your custom exception class

using namespace std;

class Insurance {
private:
    string name;      // The name or type of insurance
    float price;     // The premium or cost of the insurance
    float length;   // The duration of the insurance policy (e.g., in months or years)
    int installments;
    float fees;

public:
    // Constructor: Takes the insurance name, price, length, installments and fees as input
    Insurance(const string& name, float price, float length, int installments, float fees);

    // Copy Constructor: Creates a copy of an existing Insurance object
    Insurance(const Insurance &obj);

    // Destructor: Cleans up any resources used by the Insurance object
    ~Insurance();

    // Getters and setters for the private member variables:
    const string& getName() const;
    void setName(const string& name);

    float getPrice() const;
    void setPrice(float price); // Might include validation to ensure price is positive

    float getLength() const;
    void setLength(float length); // Might include validation for length

    int getInstallments() const;
    void setInstallments(int installments);

    float getFees() const;
    void setFees(int fees);
    // Overloaded equality operator: Compares two Insurance objects based on their name
    bool operator==(const Insurance &rhs) const;
};

#endif //WALLET_MANAGEMENT_INSURANCE_H
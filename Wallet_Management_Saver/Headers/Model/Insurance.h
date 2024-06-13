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
    int installments;  // Number of installments for payment
    float fees;        // Any additional fees associated with the insurance

    // Helper function to validate the insurance name
    bool isNameValid(const string& name);

public:
    // Default Constructor
    Insurance() = default;

    // Constructor: Takes the insurance name, price, length, installments and fees as input
    Insurance(const string& name, float price, float length, int installments, float fees);

    // Copy Constructor: Creates a copy of an existing Insurance object
    Insurance(const Insurance &obj);

    // Destructor: Cleans up any resources used by the Insurance object
    ~Insurance();

    // Getters
    const string& getName() const;
    float getPrice() const;
    float getLength() const;
    int getInstallments() const;
    float getFees() const;

    // Setters
    void setName(const string& name);
    void setPrice(float price);
    void setLength(float length);
    void setInstallments(int installments);
    void setFees(float fees);

    // Overloaded equality operator: Compares two Insurance objects based on their name
    bool operator==(const Insurance &rhs) const;
};

#endif //WALLET_MANAGEMENT_INSURANCE_H
#ifndef FSOFT_PROJECT_DATE_H
#define FSOFT_PROJECT_DATE_H

#include <iostream>
#include <exception> // Include the <exception> header for throwing exceptions
#include <string> // Include for error messages
using namespace std;

class InvalidDateException : public exception {
private:
    string message;
public:
    InvalidDateException(const string& msg) : message(msg) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};

class Date
{
private:
    int day;
    int month;
    int year;

    static bool isLeapYear(int year);

public:
    Date();
    Date(int day, int month, int year);
    Date(const Date & date);

    void setDate(int day, int month, int year);
    void getDate(int& day, int& month, int& year) const;

    bool operator == (const Date& obj) const;
    bool operator > (const Date& obj) const;
    bool operator < (const Date& obj) const;

    static bool isValid(int day, int month, int year);
};
#endif //FSOFT_PROJECT_DATE_H
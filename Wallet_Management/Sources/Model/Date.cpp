//
// Created by gvice on 03/06/2024.
//

#include "Date.h"
#include "InvalidDataException.h"

Date::Date() {
    this->day = 1;
    this->month = 1;
    this->year = 1900;
}

Date::Date(int day, int month, int year) {
    if(!isValid(day, month, year)){
        throw InvalidDataException("Date not valid.");
    }
    this->day = day;
    this->month = month;
    this->year = year;
}

Date::Date(const Date &date) {
    this->day = date.day;
    this->month = date.month;
    this->year = date.year;
}

void Date::setDate(int day, int month, int year) {
    if(!isValid(day, month, year)){
        throw InvalidDataException("Date not valid.");
    }
    this->day = day;
    this->month = month;
    this->year = year;
}

void Date::getDate(int &day, int &month, int &year) const {
    day = this->day;
    month = this->month;
    year = this->year;
}

bool Date::operator==(const Date &obj) const {
    return day == obj.day &&
           month == obj.month &&
           year == obj.year;
}

bool Date::operator>(const Date &obj) const {
    if (year > obj.year)
        return true;
    if (year == obj.year && month > obj.month)
        return true;
    if (year == obj.year && month == obj.month && day > obj.day)
        return true;
    return false;
}

bool Date::operator<(const Date &obj) const {
    return !(*this == obj || *this > obj);
}

bool Date::isLeapYear(int year) {
    return (((year % 4 == 0) &&
             (year % 100 != 0)) ||
            (year % 400 == 0));
}

bool Date::isValid(int day, int month, int year) {
    if (year < 0)
        return false;
    if (month < 1 || month > 12)
        return false;
    if (day < 1 || day > 31)
        return false;

    // Handle February
    if (month == 2) {
        if (isLeapYear(year))
            return (day <= 29);
        else
            return (day <= 28);
    }

    // Handle April, June, September, November
    if (month == 4 || month == 6 || month == 9 || month == 11)
        return (day <= 30);

    return true;
}
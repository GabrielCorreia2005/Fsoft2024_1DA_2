#include "Date.h"

Date::Date() {
    day = 1;
    month = 1;
    year = 1970;
}

Date::Date(int day, int month, int year) {
    if (!isValid(day, month, year)) {
        throw InvalidDateException("Invalid date values provided.");
    }
    this->day = day;
    this->month = month;
    this->year = year;
}

Date::Date(const Date & date) {
    this->day = date.day;
    this->month = date.month;
    this->year = date.year;
}

void Date::setDate(int day, int month, int year) {
    if (!isValid(day, month, year)) {
        throw InvalidDateException("Invalid date values provided.");
    }
    this->day = day;
    this->month = month;
    this->year = year;
}

void Date::getDate(int& day, int& month, int& year) const {
    day = this->day;
    month = this->month;
    year = this->year;
}

bool Date::isLeapYear(int year) {
    return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
}

bool Date::isValid(int day, int month, int year) {
    if (year < 1900 || year > 2200) { // Adjust year range if needed
        return false;
    }
    if (month < 1 || month > 12) {
        return false;
    }
    if (day < 1 || day > 31) {
        return false;
    }

    // Handle February with 29 days in leap years
    if (month == 2 && isLeapYear(year)) {
        return day <= 29;
    } else if (month == 2) {
        return day <= 28;
    }

    // Handle months with 30 days
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        return day <= 30;
    }

    return true;
}

bool Date::operator==(const Date &obj) const {
    return day == obj.day && month == obj.month && year == obj.year;
}

bool Date::operator>(const Date &obj) const {
    if (year > obj.year) {
        return true;
    } else if (year == obj.year && month > obj.month) {
        return true;
    } else if (year == obj.year && month == obj.month && day > obj.day) {
        return true;
    }
    return false;
}

bool Date::operator<(const Date &obj) const {
    if (year < obj.year) {
        return true;
    } else if (year == obj.year && month < obj.month) {
        return true;
    } else if (year == obj.year && month == obj.month && day < obj.day) {
        return true;
    }
    return false;
}
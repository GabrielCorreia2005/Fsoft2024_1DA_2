#include "Date.h"

Date::Date() : day(0), month(0), year(0) {}

Date::Date(int day, int month, int year) {
    setDate(day, month, year);
}

Date::Date(const Date &date) : day(date.day), month(date.month), year(date.year) {}

void Date::setDate(int day, int month, int year) {
    if (!isValid(day, month, year)) {
        throw InvalidDateException("Invalid date provided.");
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
    return (day == obj.day) && (month == obj.month) && (year == obj.year);
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

bool Date::isValid(int day, int month, int year) {
    if (year < 1900 || year > 2100) {
        return false;
    }
    if (month < 1 || month > 12) {
        return false;
    }
    if (day < 1 || day > 31) {
        return false;
    }
    if (month == 2) {
        if (isLeapYear(year)) {
            return day <= 29;
        } else {
            return day <= 28;
        }
    }
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        return day <= 30;
    }
    return true;
}

bool Date::isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return true;
    }
    return false;
}

ostream& operator<<(ostream& os, const Date& date) {
    os << date.day << "/" << date.month << "/" << date.year;
    return os;
}
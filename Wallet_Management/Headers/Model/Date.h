//
// Created by gvice on 03/06/2024.
//

#ifndef FSOFT_PROJECT_DATE_H
#define FSOFT_PROJECT_DATE_H

class Date
{
    private:
        int day;
        int month;
        int year;

        bool isLeapYear(int year);
        bool isValid(int day, int month, int year);

    public:
        Date();
        Date(int day, int month, int year);
        Date(const Date & date);

        void setDate(int day, int month, int year);
        void getDate(int& day, int& month, int& year) const;

        bool operator == (const Date& obj) const;
        bool operator > (const Date& obj) const;
        bool operator < (const Date& obj) const;
};
#endif //FSOFT_PROJECT_DATE_H

/
// Created by Gabriel on 20/05/2024.
//
#include "InvalidDataException.h"

InvalidDataException::InvalidDataException(string data) : data(data) {}

const char* InvalidDataException::what() const noexcept {
return ("Invalid data: " + data).c_str();
}


//how to use
//#include "Student.h"
//#include "InvalidDataException.h"
//
//Student::Student(const string& name, const Date& birthday) : Person(name), birthday(birthday) {
//    if (birthday.getYear() > 2023) {  // Basic validation: Year cannot be in the future
//        throw InvalidDataException("Birth year cannot be in the future.");
//    }
//}




//exemple
//#include "Student.h"
//#include "InvalidDataException.h"
//
//void Student::validateBirthday(const Date& birthday) {
//    if (birthday.getYear() > 2023) {
//        throw InvalidDataException("Birth year cannot be in the future.");
//    }
//    // ... Add other specific date validation rules for a birthday ...
//}
//
//Student::Student(const string& name, const Date& birthday) : Person(name), birthday(birthday) {
//    validateBirthday(birthday);
//}
//
// Created by Gabriel on 20/05/2024.
//
#include "DataConsistencyException.h"

DataConsistencyException::DataConsistencyException(string data) : data(data) {}

const char* DataConsistencyException::what() const noexcept {
return ("Data consistency error: " + data).c_str();
}

//how to use
//if (student.getAge() < subject.getMinimumAge()) {
//    throw DataConsistencyException("Student's age is below the minimum age for this subject.");
//}
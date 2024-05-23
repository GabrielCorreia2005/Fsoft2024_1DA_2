//
// Created by Gabriel on 20/05/2024.
//

#include "DuplicatedDataException.h"

DuplicatedDataException::DuplicatedDataException(string data) : data(data) {}

const char* DuplicatedDataException::what() const noexcept {
return ("Duplicate data error: " + data).c_str();
}

//how to use
//// Example: Trying to add a student with an existing student ID
//if (students.isThereStudent(newStudent.getNumber())) {
//    throw DuplicatedDataException("Student ID: " + std::to_string(newStudent.getNumber()));
//}


//example
//#include "StudentContainer.h"
//#include "DuplicatedDataException.h"
//// ... (other includes)
//
//void StudentContainer::add(const Student& obj) {
//    if (search(obj.getNumber()) != students.end()) { // Check if a student with this number already exists
//        throw DuplicatedDataException("Student ID: " + std::to_string(obj.getNumber()));
//    }
//    students.push_back(obj);
//}
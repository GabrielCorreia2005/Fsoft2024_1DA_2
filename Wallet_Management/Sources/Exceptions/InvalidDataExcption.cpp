// InvalidDataException.cpp
#include "InvalidDataException.h"

InvalidDataException::InvalidDataException(string data) : data(data) {}

const char* InvalidDataException::what() const noexcept {
    // Convert data (a string) to a const char*
    return data.c_str();
}
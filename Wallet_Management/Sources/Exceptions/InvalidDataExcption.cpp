//
// Created by gvice on 13/05/2024.
//

#include "InvalidDataException.h"

InvalidDataException::InvalidDataException(const string &data) : data(data) {}

const char *InvalidDataException::what() {
    return data.c_str();
}
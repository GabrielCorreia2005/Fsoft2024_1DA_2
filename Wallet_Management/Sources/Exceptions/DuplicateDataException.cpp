//
// Created by gvice on 13/05/2024.
//

#include "DuplicatedDataException.h"

DuplicatedDataException::DuplicatedDataException(const string &data) : data(data) {}

const char *DuplicatedDataException::what() {
    return data.c_str();
}
//
// Created by corre on 20/05/2024.
//

#include "DuplicatedDataException.h"

DuplicatedDataException::DuplicatedDataException(const string &what_arg) : runtime_error(what_arg) {}

DuplicatedDataException::DuplicatedDataException(const char *what_arg) : runtime_error(what_arg) {}
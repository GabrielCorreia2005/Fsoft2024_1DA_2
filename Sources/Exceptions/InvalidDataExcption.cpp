//
// Created by corre on 20/05/2024.
//
#include "InvalidDataException.h"

InvalidDataException::InvalidDataException(const string &what_arg) : runtime_error(what_arg) {}

InvalidDataException::InvalidDataException(const char *what_arg) : runtime_error(what_arg) {}
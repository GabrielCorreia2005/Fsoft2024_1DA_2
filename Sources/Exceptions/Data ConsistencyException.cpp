//
// Created by corre on 20/05/2024.
//
#include "DataConsistencyException.h"

DataConsistencyException::DataConsistencyException(const string &what_arg) : runtime_error(what_arg) {}

DataConsistencyException::DataConsistencyException(const char *what_arg) : runtime_error(what_arg) {}
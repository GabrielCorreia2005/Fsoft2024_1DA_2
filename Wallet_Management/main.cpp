// main.cpp
#include <iostream>
#include "View.h"
#include "Utils.h"

int main() {
    View view;

    // Example usage:
    int clientMenuChoice = view.menuClient();
    std::cout << "Client Menu Choice: " << clientMenuChoice << std::endl;

    int bankMenuChoice = view.menuBank();
    std::cout << "Bank Menu Choice: " << bankMenuChoice << std::endl;

    return 0;
}
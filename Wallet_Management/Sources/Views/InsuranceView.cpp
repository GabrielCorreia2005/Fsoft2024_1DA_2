//
// Created by gvice on 20/05/2024.
//
#include <iostream>
#include "InsuranceView.h"
#include "Utils.h"
#include "InvalidDataException.h"
#include "Insurance.h";

using namespace std;

Insurance InsuranceView::getInsurance();
{
    Insurance insurance("Temporary name", price, length, installments, fees);
    bool flag = false;

    do
    {
        try
        {
            flag = false;

            cout << "Insurance" << endl;

            string Ins_name = Utils::getString("Insurance Name");


        }catch(InvalidDataException& e)
        {
            flag = true;
        }
    }while(flag == true);
}
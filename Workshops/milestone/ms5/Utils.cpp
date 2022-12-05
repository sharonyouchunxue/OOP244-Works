/*
*****************************************************************************
                        Milestone 5
Full Name  : Chunxue You(Sharon)
Student ID#: 127632214
Email      : cyou8@myseneca.ca
Section    : OOP244 NAA
Date       : 2022-12-04

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. I have done all
the coding by myself and only copied the code that my professor provided to
complete my workshops and assignments.
*****************************************************************************
*/
#include <iostream>
#include <string>
#include "Utils.h"
using namespace std;


namespace sdds {
    //to valid the user selection
    bool isValid(){
        string select;
        bool res, valid;
        do {
            valid = true;
            cin >> select;
            cin.ignore(1000, '\n');
            if (select == "Y" || select == "y") {
                res = true;
            }
            else if (select == "N" || select == "n") {
                res = false;
            }
            else {
                cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
                valid = false;
            }
        } while (!valid);
        return res;
    }
}
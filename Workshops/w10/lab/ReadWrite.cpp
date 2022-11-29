/*
*****************************************************************************
                        Workshop 10
Full Name  : Chunxue You(Sharon)
Student ID#: 127632214
Email      : cyou8@myseneca.ca
Section    : OOP244 NAA
Date       : 2022-11-28
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. I have done all
the coding by myself and only copied the code that my professor provided to
complete my workshops and assignments.
*****************************************************************************
*/
#include <iostream>
#include "ReadWrite.h"
using namespace std;
namespace sdds {
    ostream& operator<<(ostream& os, const ReadWrite& c) {
        return c.display(os);
    }

    istream& operator >> (istream& is, ReadWrite& c) {
        return c.read(is);
    }
}
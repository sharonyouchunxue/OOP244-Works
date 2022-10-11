/*
*****************************************************************************
                        Workshop 5 - part 1
Full Name  : Chunxue You
Student ID#: 127632214
Email      : cyou8@myseneca.ca
Section    : OOP244 NAA
Date       : 2022-10-12

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. I have done all
the coding by myself and only copied the code that my professor provided to
complete my workshops and assignments.
*****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Apartment.h"

using namespace std;
namespace sdds
{
    Apartment::Apartment(int number, double balance)
    {

        if (number >= 1000 && number <= 9999
            && balance >= 0)
        {
            m_number = number;
            m_balance = balance;
        }
    }
    std::ostream& Apartment::display() const
    {
        if (*this)
        {
            cout.width(4);
            cout << m_number;
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << m_balance;
            cout.unsetf(ios::right);
            cout << " ";
        }
        else
        {
            cout << "Invld|  Apartment   ";
        }
        return cout;
    }
}
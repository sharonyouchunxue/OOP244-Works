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
#pragma once
#ifndef SDDS_APARTMENT_H_
#define SDDS_APARTMENT_H_
#include <iostream>

namespace sdds
{
    class Apartment
    {
        int m_number = -1;
        double m_balance = 0.0;

    public:
        Apartment(int number, double balance);
        std::ostream& display()const;
    };
}

#endif // SDDS_APARTMENT_H_
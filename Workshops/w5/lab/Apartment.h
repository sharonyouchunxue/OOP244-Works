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
        bool InvalidEmptyState()const;
        bool ValidState()const;
        int value()const;
        Apartment(int value = 0);
        Apartment(int number, double balance);
        std::ostream& display()const;
        operator bool()const;
        operator int()const;
        operator double()const;
        bool operator~()const;
        Apartment& operator=(int rightOperand);
        Apartment& operator=(Apartment& ref);
        Apartment& operator+=(double value);
        Apartment& operator-=(double value);
        Apartment& operator<<(Apartment& rightOperand);
        Apartment& operator>>(Apartment& leftOperand);
        //helper standalone operator
        friend double operator+(const Apartment& leftOperand, const Apartment& rightOperand);
        friend double operator+=(double& leftOperand, const Apartment& rightOperand);
    };

   

}

#endif // SDDS_APARTMENT_H_
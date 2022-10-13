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
#include <cstring>
#include "Apartment.h"

using namespace std;
namespace sdds
{
    bool Apartment::InvalidEmptyState() const
    {
        return m_number == -1 && m_balance == 0.0;
    }

    bool Apartment::ValidState() const
    {
        return (m_number > 999 && m_number < 10000)&& m_balance > -1;
    }

    int Apartment::value() const
    {
        return m_number;
    }

    Apartment::Apartment(int value)
    {
        m_number = value;
    }

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

    Apartment::operator bool() const
    {
        bool valid = false;
        if (ValidState()) {
            valid = true;
        }
        return valid;
    }

    Apartment::operator int() const
    {
        return m_number;
    }

    Apartment::operator double() const
    {
        return m_balance;
    }

    bool Apartment::operator~() const
    {
        bool valid = false;
        if (m_balance == 0.0) {
            valid = true;
        }
        return valid;
    }

    Apartment& Apartment::operator=(int rightOperand)
    {
        if(ValidState()){
            m_number = rightOperand;
        }
        else {
            InvalidEmptyState();
        }
        return *this;
    }

    Apartment& Apartment::operator=(Apartment& ref) {
        Apartment temp;
        temp.m_balance = m_balance;
        temp.m_number = m_number;
        ref.m_balance = temp.m_balance;
        ref.m_number = temp.m_number;
        return *this;
    }

    Apartment& Apartment::operator+=(double value) {
        if (ValidState()) {
            m_balance += value;
        }    
        return *this;
    }

    Apartment& Apartment::operator-=(double value) {
        if (ValidState()) {
            m_balance -= value;
        }
        return *this;
    }

    Apartment& Apartment::operator<<(Apartment& rightOperand){
        if (this->m_number > 0 && rightOperand.m_number > 0 && this->m_number != rightOperand.m_number)
        {
            this->m_balance += rightOperand.m_balance ;
            rightOperand.m_balance = 0;
        }
        return *this;
    }

    Apartment& Apartment::operator>>(Apartment& leftOperand) {
        if (this->m_number > 0 && leftOperand.m_number > 0 && this->m_number != leftOperand.m_number)
        {
            leftOperand.m_balance += this->m_balance;
            this->m_balance = 0;
        }
        return *this;
    }

    double operator+(const Apartment& leftOperand, const Apartment& rightOperand) {
        double sum = 0.0;
        if (leftOperand.m_number > 0 && rightOperand.m_number > 0) {
            sum = leftOperand.m_balance + rightOperand.m_balance;
        }
        return sum;
    }

    double operator+=(double& leftOperand, const Apartment& rightOperand){
        if (rightOperand.m_number > 0) {
            leftOperand += rightOperand.m_balance;
        }
        return leftOperand;
    }

}
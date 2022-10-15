#pragma once
/*
*****************************************************************************
                        Workshop 5 - part 2
Full Name  : Chunxue You
Student ID#: 127632214
Email      : cyou8@myseneca.ca
Section    : OOP244 NAA
Date       : 2022-10-14

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. I have done all
the coding by myself and only copied the code that my professor provided to
complete my workshops and assignments.
*****************************************************************************
*/
#pragma once
#ifndef SDDS_MARK_H_
#define SDDS_MARK_H_
#include <iostream>


namespace sdds
{
    class Mark {
    private:
        int m_mark{};
    public:
        Mark();
        ~Mark();
        Mark(const int value);
        operator int()const;
        operator double()const;
        operator char()const;
        operator bool()const;
        //== , != , <, >, <= and >=
        bool operator==(const Mark& rightOperand);
        bool operator!=(const Mark& rightOperand);
        bool operator<(const Mark& rightOperand);
        bool operator>(const Mark& rightOperand);
        bool operator<=(const Mark& rightOperand);
        bool operator>=(const Mark& rightOperand);
        Mark& operator++();
        Mark operator++(int);
        Mark& operator--();
        Mark operator--(int);
        bool operator~()const;
        Mark& operator<<(Mark& rightOperand);
        Mark& operator>>(Mark& leftOperand);
        Mark& operator=(int value);
        Mark& operator+=(int value);
        Mark& operator-=(int value);
        friend int operator +=(int& lefOperand, const Mark& rightOperand);
        
        

    };



}
#endif

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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Mark.h"
using namespace std;

namespace sdds {
    //1. construction
    Mark::Mark() {
        m_mark = 0;
    }

    Mark::~Mark() {
        
    }

    Mark::Mark(const int value) {
        m_mark = 0;
        if (value >= 0 && value <= 100) {
            m_mark = value;
        }
        else m_mark = -1;
    }

    //2. Type conversion Operators
    Mark::operator int() const {
        int res = 0;
        if (m_mark >= 0 && m_mark <= 100) {
            res = m_mark;
        }
        return res;
    }

    Mark::operator double() const {
        int res = 0;
        if (m_mark >= 50 && m_mark < 60) {
            res = 1.0;
        }
        else if (m_mark >= 60 && m_mark < 70) {
            res = 2.0;
        }
        else if (m_mark >= 70 && m_mark < 80) {
            res == 3.0;
        }
        else if (m_mark >= 80 && m_mark <= 100) {
            res = 4.0;
        }
        else {
            res = 0.0;
        }
        return res;
    }

    Mark::operator char() const {
        char res = 'X';
        if (m_mark >= 0&& m_mark < 50) {
            res = 'F';
        }
        else if (m_mark >= 50 && m_mark < 60) {
            res = 'D';
        }
        else if (m_mark >= 60 && m_mark < 70) {
            res = 'C';
        }
        else if (m_mark >= 70 && m_mark < 80) {
            res = 'B';
        }
        else if (m_mark >= 80 && m_mark <= 100) {
            res = 'A';
        }
        return res;
    }

    Mark::operator bool() const {
        bool res = false;
        if (m_mark >= 0 && m_mark<=100) {
            res = true;
        }
        return res;
    }

    //3. Comparison operator overloads
    /*A Mark can be compared with other Marks using ==, !=, <, >, <= and >= returning a boolean in
    result. Comparison results involving invalid marks are undefined*/
    
    bool Mark::operator==(const Mark& rightOperand)
    {
        /*bool valid = false;
        if (this->m_mark>=0&& rightOperand.m_mark>=0) {
            if (m_mark == rightOperand.m_mark) {
                valid = true;
            }       
        }
        return valid;*/
        return(*this == rightOperand);
    }
    bool Mark::operator!=(const Mark& rightOperand) {
        return !(*this == rightOperand);
    }

    bool Mark::operator<(const Mark& rightOperand) {
        return (*this < rightOperand);
    }
    bool Mark::operator>(const Mark& rightOperand) {
        return (*this < rightOperand);

    }
    bool Mark::operator<=(const Mark& rightOperand) {
        return(*this <= rightOperand);
    }
    bool Mark::operator>=(const Mark& rightOperand) {
        return(*this >= rightOperand);
    }

    //4. Unary operators:
    //The ++ and -- operators (postfix and prefix) work with a mark exactly as they do with an integer, 
    //except that they don't take any action if the mark is invalid
    Mark& Mark::operator++() {
        m_mark++;
        return *this;
    }
    Mark Mark::operator++(int) {
        m_mark++;
        return Mark(m_mark - 1);
    }

    Mark& Mark::operator--() {
        m_mark--;
        return *this;
    }
    Mark Mark::operator--(int) {
        m_mark--;
        return Mark(m_mark + 1);
    }

    //~ operator returns true if the mark is a pass.
    bool Mark::operator~() const
    {
        bool pass = false;
        if (m_mark >= 50&&m_mark<= 100) {
            pass = true;
        }
        return pass;
    }

    //5. Binary Operators
    //assignment operator
    Mark& Mark::operator=(int value){
        if (value >= 0 && value <= 100) {
            m_mark = value;
        }
        else {
            m_mark = 0;
        }
        return *this;
    }

    // add value and deduct value
    Mark& Mark::operator+=(int value) {
        if (m_mark >= 0 && m_mark <= 100) {
            m_mark += value;
        }
        else {
            m_mark = 0;
        }
        return *this;
    }
    Mark& Mark::operator-=(int value) {
        if (m_mark >= 0 && m_mark <= 100) {
            m_mark -= value;
        }
        else {
            m_mark = 0;
        }
        return *this;
    }

    //sum value
    int operator+=(int& lefOperand, const Mark& rightOperand) {
        lefOperand += int(rightOperand);
        return lefOperand;
    }

    //left shift and right shift mark
    Mark& Mark::operator<<(Mark& rightOperand) {
        if (m_mark > 0 && rightOperand.m_mark > 0 && m_mark != rightOperand.m_mark)
        {
            m_mark += rightOperand.m_mark;
            rightOperand.m_mark = 0;
        }
        return *this;
    }

    Mark& Mark::operator>>(Mark& leftOperand) {
        if (m_mark > 0 && leftOperand.m_mark > 0 && this->m_mark != leftOperand.m_mark)
        {
            leftOperand.m_mark += m_mark;
            m_mark = 0;
        }
        return *this;
    }

}
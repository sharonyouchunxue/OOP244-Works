
/*
*****************************************************************************
                        Workshop 5 - part 2
Full Name  : Chunxue You
Student ID#: 127632214
Email      : cyou8@myseneca.ca
Section    : OOP244 NAA
Date       : 2022-10-17

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. I have done all
the coding by myself and only copied the code that my professor provided to
complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_MARK_H_
#define SDDS_MARK_H_

namespace sdds
{
    class Mark {
    private:
        int m_mark = -1;
    public:    
        Mark(const int value=0);
        operator int()const;
        operator double()const;
        operator char()const;
        operator bool()const;
        bool operator~()const;
        //== , != , <, >, <= and >=
        bool operator==(const Mark& rightOperand)const;
        bool operator!=(const Mark& rightOperand)const;
        bool operator<(const Mark& rightOperand)const;
        bool operator>(const Mark& rightOperand)const;
        bool operator<=(const Mark& rightOperand)const;
        bool operator>=(const Mark& rightOperand)const;
        Mark& operator++();
        Mark operator++(const int);
        Mark& operator--();
        Mark operator--(const int);
        Mark& operator<<(Mark& rightOperand);
        Mark& operator>>(Mark& rightOperand);
        Mark& operator=(const int value); 
        Mark& operator+=(const int rightOperand);
        Mark& operator-=(const int rightOperand);
        Mark operator+(const int rightOperand)const;     
    };
    int operator+=(int& value, const Mark& rightOperand);
    int operator-=(int& value, const Mark& rightOperand);
    int operator+(const int mark, const Mark& rightoperand);
    Mark operator +(const Mark& lefOperand, const Mark& rightOperand);
}
#endif

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
#ifndef SDDS_STUDENT_H_
#define SDDS_STUDENT_H_
#include "ReadWrite.h"
namespace sdds {
    class Student : public ReadWrite {
        int _stno;
        char _name[41];
    public:
        Student();
        Student(int stno, const char* name);
        void set(int stno, const char* name);
        std::ostream& display(std::ostream& os)const;
        std::istream& read(std::istream& is);
        bool operator==(const char* nameSubstr)const;
    };
}
#endif // !SDDS_STUDENT_H_
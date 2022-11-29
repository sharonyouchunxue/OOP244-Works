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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

using namespace std;
#include "Student.h"
namespace sdds {
    Student::Student() {
        set(0, "");
    }
    Student::Student(int stno, const char* name) {
        set(stno, name);
    }
    void Student::set(int stno, const char* name) {
        _stno = stno;
        strcpy(_name, name);
    }
    ostream& Student::display(ostream& os)const {
        return os << _stno << " " << _name;
    }
    istream& Student::read(istream& is) {
        is >> _stno;
        is.getline(_name, 40, '\n');
        return is;
    }
    bool Student::operator==(const char* nameSubstr)const {
        return strstr(_name, nameSubstr) != nullptr;
    }
}
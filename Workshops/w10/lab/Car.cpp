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

#include "Car.h"
using namespace std;
namespace sdds {
    Car::Car(const char* plate, const char* makeModel) {
        set(plate, makeModel);
    }
    void Car::set(const char* plate, const char* makeModel) {
        strncpy(_plate, plate, 8);
        _plate[8] = 0;
        strncpy(_makeModel, makeModel, 40);
        _makeModel[40] = 0;;
    }
    std::ostream& Car::display(std::ostream& os)const {
        return os << _plate << " " << _makeModel;
    }
    std::istream& Car::read(std::istream& is) {
        is >> _plate;
        is.getline(_makeModel, 40, '\n');
        return is;
    }
    bool Car::operator==(const char* mmSubstr)const {
        return strstr(_makeModel, mmSubstr) != nullptr;
    }
}
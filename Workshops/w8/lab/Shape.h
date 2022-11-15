/*
*****************************************************************************
                        Workshop 8 - part 1
Full Name  : Chunxue You(Sharon)
Student ID#: 127632214
Email      : cyou8@myseneca.ca
Section    : OOP244 NAA
Date       : 2022-11-15
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. I have done all
the coding by myself and only copied the code that my professor provided to
complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_SHAPE_H_
#define SDDS_SHAPE_H_
#include <iostream>

namespace sdds {
    //pure vertual function
    class Shape {
    public:
        //pure virtual function does not have implementation set its prototype to zero
        virtual std::ostream& draw(std::ostream& ostr)const = 0;
        virtual std::istream& getSpecs(std::istream& istr) = 0;
        //empty destructor
        virtual ~Shape();
    };
    //Shape helper functions
    std::ostream& operator<<(std::ostream& os, const Shape& S);
    std::istream& operator>>(std::istream& istr, Shape& S);



}

#endif
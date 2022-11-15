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
#include <iostream>
#include "Shape.h"

using namespace std;
namespace sdds {

    //empty destructor
    Shape::~Shape(){
    }

    std::ostream& operator<<(std::ostream& ostr, const Shape& S){
        return S.draw(ostr);
    }
    std::istream& operator>>(std::istream& istr, Shape& S){
        //return S.getSpecs(istr);
        return S.getSpecs(istr);
         
    }
}
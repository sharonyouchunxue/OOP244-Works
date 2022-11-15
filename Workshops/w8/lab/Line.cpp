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
#include "Line.h"

using namespace std;
namespace sdds {
    //two argument constructor
    //Receives a Cstring and a value for the length of the line.
    //Passes the Cstring to the constructor of the base class and 
    //sets the m_length member variable to the value of the second argument
    Line::Line(const char* label, int length):LblShape(label){
            m_length = length;
    }
    //empty destructor
    Line::~Line(){
    }
    //overrides the getSpecs function of the base class
    std::istream& Line::getSpecs(std::istream& istr){
        int tempLength;
        //read label by calling getSpecs function from LblShape
        LblShape::getSpecs(istr);
        istr >> tempLength;
        if (istr.fail()) {
            istr.clear();
            istr.ignore(10000, '\n');
        }
        else {
            // ignore The rest of the characters up to and including the newline character '\n'.
            istr.ignore();
            m_length = tempLength;
        }
        return istr;

    }
    //overrides the draw function of the base clas
    std::ostream& Line::draw(std::ostream& ostr)const{
        if (m_length > 0 && LblShape::label()) {
            ostr << label();
            ostr.width(m_length);
            ostr.fill('=');
            ostr << '=';
        }
        return ostr;
    }
}
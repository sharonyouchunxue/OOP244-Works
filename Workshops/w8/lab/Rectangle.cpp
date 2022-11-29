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
#include <cstring>
#include "Rectangle.h"
using namespace std;
namespace sdds {
    //three argument constructor
    // Passes the Cstring to the constructor of the base class and 
    //sets the m_width and m_height member variables to the corresponding values received from the argument list. 
    //However if the m_height is less than 3 or m_width is less the length of the label() + 2 it will 
    //set the Rectangle to an empty state.
    Rectangle::Rectangle(const char* label, int width, int height):LblShape(label) {
        if (height > 3 && width > atoi(LblShape::label() + 2)) {
            m_width = width;
            m_height = height;
        }
        else {
            setEmpty();
        }
    }
    //empty destructor
    Rectangle::~Rectangle(){
    }

    //overrides the getSpecs function of the base class
    std::istream& Rectangle::getSpecs(std::istream& istr){
        int tempWidth;
        int tempHeight;
        char tempComma;
        LblShape::getSpecs(istr);
        istr >> tempWidth >> tempComma >> tempHeight;
        if (istr.fail()) {
            istr.clear();
            istr.ignore(10000, '\n');
        }
        else {
            // ignore The rest of the characters up to and including the newline character '\n'.
            istr.ignore();
            m_width = tempWidth;
            m_height = tempHeight;
        }
        return istr;
    }

    //overrides the draw function of the base class
    std::ostream& Rectangle::draw(std::ostream& ostr)const{
        if (m_width > 0 && m_height > 0) {
            //print first line
            ostr << "+";
            ostr.width(m_width - 2);
            ostr.fill('-');
            ostr << "-" << "+" << endl;
            //print second line
            ostr << "|";
            ostr.width(m_width - 2);
            ostr.fill(' ');
            ostr.setf(ios::left);
            ostr << LblShape::label() << "|";
            ostr.unsetf(ios::left);
            ostr << endl;
            //In next (m_height - 3) lines:
            for (int i = 0; i < (m_height - 3); i++) {
                ostr << "|";
                ostr.width(m_width - 2);
                ostr.fill(' ');
                ostr << " " << "|" << endl;
            }
            //Last line: exactly like first line.
            ostr << "+";
            ostr.width(m_width - 2);
            ostr.fill('-');
            ostr << "-" << "+" ;
        }
        return ostr;
    }

    void Rectangle::setEmpty(){
        m_height = 0;
        m_width = 0;
    }
}
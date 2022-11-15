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
#ifndef SDDS_LINE_H_
#define SDDS_LINE_H_

#include "LblShape.h"
namespace sdds {

    //Line inherits the LblShape class to create a horizontal line with a label.
    class Line :public LblShape {
        int m_length{0};
    public:
        Line() = default;
        //Two argument constructor
        Line(const char* label, int length);
        virtual ~Line();
        std::istream& getSpecs(std::istream& istr);
        std::ostream& draw(std::ostream& ostr)const;
    };

}

#endif
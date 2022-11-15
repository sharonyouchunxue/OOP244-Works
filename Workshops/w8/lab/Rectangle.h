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
#ifndef SDDS_RECTANGLE_H_
#define SDDS_RECTANGLE_H_
#include "LblShape.h"

namespace sdds {
    //The Rectangle concrete class
    //The Rectangle class inherits the LblShape class to create a frame with a label inside.
    class Rectangle :public LblShape {
        int m_width{0};
        int m_height{0};
    public:
        //default constructor
        Rectangle() = default;
        //Three argument constructor
        Rectangle(const char* label, int width, int height);
        //Destructor
        virtual ~Rectangle();
        std::istream& getSpecs(std::istream& istr);
        std::ostream& draw(std::ostream& ostr)const;
        void setEmpty();
    };

}

#endif // !SDDS_RECTANGLE_H_

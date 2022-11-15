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
#ifndef SDDS_LBLSHAPE_H_
#define SDDS_LBLSHAPE_H_
#include <iostream>

#include "Shape.h"

namespace sdds {
    class LblShape:public Shape {
        char* m_label{};
    protected:
        const char* label()const;
    public:
        LblShape() = default;
        LblShape(const char* label);//one argument constructor
        virtual ~LblShape();
        //deleted copy constructor and assignment operator to prevent copy
        LblShape(const LblShape&) = delete;
        void operator=(const LblShape&) = delete;
        //getSpecs, override the base calss getSpecs pure vitual function
        std::istream& getSpecs(std::istream& istr);

    };
}

#endif
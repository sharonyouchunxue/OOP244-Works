/*
*****************************************************************************
                        Workshop 9
Full Name  : Chunxue You(Sharon)
Student ID#: 127632214
Email      : cyou8@myseneca.ca
Section    : OOP244 NAA
Date       : 2022-11-20

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. I have done all
the coding by myself and only copied the code that my professor provided to
complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_TEXT_H__
#define SDDS_TEXT_H__
#include <iostream>
#include "Text.h"

namespace sdds {

    class Text {
        char* m_content{};
    protected:
        const char& operator[](int index)const;
    public:
        Text();
        Text(const char* content);
        //rule of three
        Text(const Text& T);
        Text& operator=(const Text& T); 
        //read
        std::istream& read(std::istream& istr = std::cin);
        //write
        virtual std::ostream& write(std::ostream& ostr = std::cout)const; 
        unsigned getFileLength(std::istream& is);
        ~Text();
    };
    //helper function
    std::ostream& operator<<(std::ostream& ostr, const Text& RW);
    std::istream& operator>>(std::istream& istr, Text& RW);
}

#endif // !SDDS_TEXT_H__

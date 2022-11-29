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
#include <iostream>
#ifndef SDDS_READWRITE_H_
#define SDDS_READWRITE_H_
namespace sdds {
    class ReadWrite {
    public:
        virtual std::ostream& display(std::ostream& os)const = 0;
        virtual std::istream& read(std::istream& is) = 0;
        virtual ~ReadWrite() {
        }
    };
    std::ostream& operator<<(std::ostream& os, const ReadWrite& c);
    std::istream& operator>>(std::istream& is, ReadWrite& c);
}
#endif // !SDDS_READWRITE_H_
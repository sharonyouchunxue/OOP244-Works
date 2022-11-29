/*
*****************************************************************************
                        Milestone 5
Full Name  : Chunxue You(Sharon)
Student ID#: 127632214
Email      : cyou8@myseneca.ca
Section    : OOP244 NAA
Date       : 2022-11-27

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. I have done all
the coding by myself and only copied the code that my professor provided to
complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_READWRITABLE_H__
#define SDDS_READWRITABLE_H__
#include <iostream>

namespace sdds {
    class ReadWritable {
        bool flag;
    public:
        ReadWritable();
        virtual ~ReadWritable();
        bool isCsv()const;
        void setCsv(bool value);
        virtual std::ostream& write(std::ostream& ostr = std::cout)const = 0;
        virtual std::istream& read(std::istream& istr = std::cin) = 0;
    };
    std::ostream& operator<<(std::ostream& ostr, const ReadWritable& RW);
    std::istream& operator>>(std::istream& istr, ReadWritable& RW);
}
#endif // !SDDS_READWRITABLE_H__

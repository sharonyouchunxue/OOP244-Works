/*
*****************************************************************************
                        Workshop 6 - part 1
Full Name  : Chunxue You(Sharon)
Student ID#: 127632214
Email      : cyou8@myseneca.ca
Section    : OOP244 NAA
Date       : 2022-10-19

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. I have done all
the coding by myself and only copied the code that my professor provided to
complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_NUMBERS_H_
#define SDDS_NUMBERS_H_
#include <iostream>
namespace sdds {
    class Numbers {
        double* m_numbers{};
        char* m_filename{};
        bool m_isOriginal;
        int m_numCount;
        bool isEmpty()const;
        void setEmpty();
        void deallocate();
        void setFilename(const char* filename);
        Numbers& sort(bool ascending);
    public:
        Numbers();
        Numbers(const char* filename);
        double average()const;
        double max()const;
        double min()const;
        ~Numbers();
        Numbers(const Numbers& I);
        Numbers& operator=(const Numbers& I);
        Numbers operator-()const;
        Numbers operator+()const;
        int numberCount()const;
        bool load();
        void save();
        Numbers& operator+=(const double M);
        std::ostream& display(std::ostream& ostr) const;
    };
    std::ostream& operator<<(std::ostream& os, const Numbers& N);
    std::istream& operator>>(std::istream& istr, Numbers& N);
}
#endif // !SDDS_NUMBERS_H_

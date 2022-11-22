/*
*****************************************************************************
                        Milestone 4
Full Name  : Chunxue You(Sharon)
Student ID#: 127632214
Email      : cyou8@myseneca.ca
Section    : OOP244 NAA
Date       : 2022-11-21

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. I have done all
the coding by myself and only copied the code that my professor provided to
complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_MOTORCYCLE_H__
#define SDDS_MOTORCYCLE_H__
#include "Vehicle.h"
namespace sdds {
    class Motorcycle: public Vehicle{
        bool m_sidecar;
    public:
        Motorcycle();
        Motorcycle(const char* licensePlate, const char* makeModel);
        //rule of three, should be safely copied and assigned to another
        Motorcycle(const Motorcycle& M);
        Motorcycle& operator=(const Motorcycle& M);
        std::ostream& writeType(std::ostream& ostr = std::cout)const;
        std::istream& read(std::istream& istr = std::cin);
        std::ostream& write(std::ostream& ostr = std::cout)const;
        ~Motorcycle();


    };
}
#endif // !
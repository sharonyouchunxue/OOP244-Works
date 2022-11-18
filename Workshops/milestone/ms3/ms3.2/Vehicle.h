/*
*****************************************************************************
                        Milestone 3
Full Name  : Chunxue You(Sharon)
Student ID#: 127632214
Email      : cyou8@myseneca.ca
Section    : OOP244 NAA
Date       : 2022-11-17

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. I have done all
the coding by myself and only copied the code that my professor provided to
complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_VEHICLE_H__
#define SDDS_VEHICLE_H__

#include "ReadWritable.h"
#include "Utils.h"

namespace sdds {
    const int MAX_CHARACTERS = 8;

    class Vehicle : public ReadWritable {
        char m_licensePlate[MAX_CHARACTERS + 1]{};
        char* m_makeModel{};
        int m_parkingLotNum{};
    protected:
        const char* getLicensePlate()const;
        const char* getMakeModel()const;

    public:
        Vehicle() = default;
        virtual ~Vehicle();
        Vehicle(const char* licensePlate, const char* makeModel);
        //rule of three
        Vehicle(const Vehicle&) = default;
        Vehicle& operator=(const Vehicle&) = delete;
        void setEmpty();
        bool isEmpty()const;
        void setMakeModel(const char* makeModel);
        int getParkingSpot()const;
        void setParkingSpot(const int parkingSpotNum);
        bool operator==(const char* licensePlate)const;
        bool operator==(const Vehicle& vehicle)const;
        std::istream& read(std::istream& istr = std::cin);
        virtual std::ostream& writeType(std::ostream& ostr = std::cout)const = 0;
        std::ostream& write(std::ostream& ostr = std::cout)const;

    };


}

#endif // !SDDS_VEHICLE_H__

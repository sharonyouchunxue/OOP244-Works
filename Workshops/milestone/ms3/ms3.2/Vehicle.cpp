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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Vehicle.h"
using namespace std;
namespace sdds {
    //This function returns a read-only address of the license plate of the Vehicle.
    const char* Vehicle::getLicensePlate() const {
        return m_licensePlate;
    }
    //returns a read-only address of the make and model of the Vehicle.
    const char* Vehicle::getMakeModel() const {
        return m_makeModel;
    }
    /* Vehicle::Vehicle(){
         setEmpty();
     }*/
    Vehicle::~Vehicle() {
        delete[] m_makeModel;
        m_makeModel = nullptr;
    }
    //three argument constructor
    Vehicle::Vehicle(const char* licensePlate, const char* makeModel) {
        setEmpty();
        if (licensePlate != nullptr && licensePlate[0] != '\0' && makeModel != nullptr && makeModel[0] != '\0') {
            if (strlen(licensePlate) < 9 && strlen(makeModel) > 1 && strlen(makeModel) < 61) {
                strcpy(m_licensePlate, licensePlate);
                m_makeModel = new char[strlen(makeModel) + 1];
                strcpy(m_makeModel, makeModel);
                m_parkingLotNum = 0;
            }
            else {
                setEmpty();
            }
        }
        else {
            setEmpty();
        }
    }
    //sets the Vehicle to an invalid empty state
    void Vehicle::setEmpty() {
        m_licensePlate[0] = '\0';
        m_makeModel = nullptr;
        m_parkingLotNum = 0;
    }
    //returns true if the Vehicle is in an invalid empty state, or else, it returns false
    bool Vehicle::isEmpty()const {
        return m_licensePlate[0] == '\0' && m_makeModel == nullptr && m_parkingLotNum == 0;

    }
    //This function resets the make and model of the Vehicle to a new value. 
    //If the new value is null or empty, the object is set to an invalid empty state. 
    //Public Member function and operator overload implementations:
    void Vehicle::setMakeModel(const char* makeModel) {
        if (makeModel != nullptr && makeModel[0] != '\0') {
            delete[] m_makeModel;
            m_makeModel = new char[strlen(makeModel) + 1];
            strcpy(m_makeModel, makeModel);
        }
        else {
            delete[] m_makeModel;
            setEmpty();
        }

    }
    //This function returns the parking spot number of the Vehicle.
    int Vehicle::getParkingSpot() const {
        return m_parkingLotNum;
    }
    //Resets the parking spot number to a new value. If the value is invalid, it will set the vehicle to an Invalid empty state.
    void Vehicle::setParkingSpot(const int parkingSpotNum) {
        if (parkingSpotNum > 0) {
            m_parkingLotNum = parkingSpotNum;
        }
        else {
            setEmpty();
        }
    }


    //Compares the license plate of the Vehicle with a license plate value and 
    //returns true if the two license plates are identical or else it returns false. 
    //This comparison is NOT case sensitive (i.e. “123ABC” is the same as “123abc”).
    //If any value is invalid, this function returns false;

    bool Vehicle::operator==(const char* licensePlate) const {
        bool identical = false;
        if (licensePlate != nullptr && licensePlate[0] != '\0' && strlen(licensePlate) <= MAX_CHARACTERS) {
            if (strcmp(m_licensePlate, licensePlate));
            identical = true;
        }
        return identical;
    }

    //Compares two Vehicles and if they have the same license plate, it will return true, or else it returns false. 
    //This comparison is NOT case-sensitive.If any value is invalid, this function returns false;
    bool Vehicle::operator==(const Vehicle& vehicle) const {
        bool identical = false;
        if (strcmp(m_licensePlate, vehicle.m_licensePlate) == 0) {
            identical = true;
        }
        return identical;
    }

    std::istream& Vehicle::read(std::istream& istr) {
        char temp[61]{};
        if (isCsv()) {
            istr >> m_parkingLotNum;
            istr.ignore();
            istr.getline(m_licensePlate, MAX_CHARACTERS + 1, ',');

            istr.getline(temp, 61, ',');
            setMakeModel(temp);
        }
        else {
            cout << "Enter Licence Plate Number : ";
            istr >> m_licensePlate;
            istr.ignore();
            if (strlen(m_licensePlate) > 8) {
                cout << "Invalid Licence Plate, try again: ";
                istr >> m_licensePlate;
            }
            cout << "Enter Make and Model: ";
            istr >> temp;
            if (strlen(temp) < 2 || strlen(temp) > 60) {
                cout << "Invalid Make and model, try again: ";
                istr >> temp;
            }
            setMakeModel(temp);
            m_parkingLotNum = 0;
        }
        if (istr.fail()) {
            istr.clear();
            setEmpty();
        }
        return istr;
    }


    std::ostream& Vehicle::write(std::ostream& ostr) const {
        if (isEmpty()) {
            ostr << "Invalid Vehicle Object" << endl;
        }
        else {
            writeType();
            if (isCsv()) {
                ostr << m_parkingLotNum << "," << m_licensePlate << "," << m_makeModel << ",";
            }
            else {
                ostr << "Parking Spot Number: ";
                if (m_parkingLotNum > 0) {
                    ostr << m_parkingLotNum << endl;
                }
                else {
                    ostr << "N/A" << endl;
                }
                ostr << "License Plate: " << m_licensePlate << endl;
                ostr << "Make and Model: " << m_makeModel << endl;
            }
        }
        return ostr;
    }
}


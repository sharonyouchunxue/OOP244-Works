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
#ifndef SDDS_PARKING_H__
#define SDDS_PARKING_H__
#include "Menu.h"
#include "Car.h"
#include "Motorcycle.h"
namespace sdds {
    //Maximum Number of Parking Spots and initialize it to the value 100.
    const int MAX_PARKINGSPOT = 100;

    class Parking {
        char* m_filename{};//Parking holds a C-style string with an unknown size to hold the data path and file name of the application
        Menu m_parkingMenu;
        Menu m_vSelectionMenu;
        int m_numOfSpot{}; //Number of Spots:
        Vehicle* parkingSpot[MAX_PARKINGSPOT]{}; //Parking Spots:
        int m_numOfparkingVehicles{0};//Number of Parked Vehicles
        bool isEmpty()const;
        void parkingStatus()const;
        void parkVehicle()const;
        void returnVehicle()const;
        void listParkedVehicles()const;
        void findVehicle()const;
        bool closeParking()const;
        bool exitParkingApp()const;
        bool loadDateFile()const;
        void saveDataFile()const;

    public:
        int run();
        //constructor
        Parking() = default;
        //constructor modified
        Parking(const char* datafile, int noOfSpots);
        //Copy and assignment are denied in the Parking class. (Parking class can not be copied or 
        //assigned to another Parking object)
        Parking(const Parking&) = delete;
        Parking& operator=(const Parking&) = delete;
        void setFileName(const char* filename);
        void printHeader(const char* title)const;
        void printHeaderWithFilename(const char* filename) const;
        ~Parking();
    };
}
#endif // !


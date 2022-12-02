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
#include "Utils.h"
#include "Vehicle.h"
namespace sdds {
  
    //Maximum Number of Parking Spots and initialize it to the value 100.
    const int MAX_PARKINGSPOT = 100;
    class Parking:public Menu{
        char* m_filename{};//Parking holds a C-style string with an unknown size to hold the data path and file name of the application
        Menu m_parkingMenu;
        Menu m_vSelectionMenu;
        int m_numOfSpot{}; //Number of Spots: always less than Max_parking spot
        Vehicle* parkingSpot[MAX_PARKINGSPOT]{}; //Parking Spots:
        int m_numOfparkedVehicles{};//Number of Parked Vehicles,always less than Max parking spot
        void setEmpty();
        bool isValid()const;
        bool isEmpty()const;
        void parkingStatus()const;
        void parkVehicle();
        void returnVehicle();
        void listParkedVehicles()const;
        void findVehicle();
        bool closeParking();
        bool exitParkingApp()const;
        bool loadDataFile();
        void saveDataFile()const;

    public:
        using Menu::Menu;
        //constructor
        Parking();        
        //constructor modified
        Parking(const char* datafile, int noOfSpots);
        //Copy and assignment are denied in the Parking class. (Parking class can not be copied or 
        //assigned to another Parking object)
        Parking(const Parking&) = delete;
        Parking& operator=(const Parking&) = delete;
        void setFileName(const char* filename);
        int run();
        void pause()const;
        ~Parking();
    };
}
#endif // !


/*
*****************************************************************************
                        Milestone 2
Full Name  : Chunxue You(Sharon)
Student ID#: 127632214
Email      : cyou8@myseneca.ca
Section    : OOP244 NAA
Date       : 2022-11-07

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
namespace sdds {

    class Parking : public Menu {
        char* m_filename{};//Parking holds a C-style string with an unknown size to hold the data path and file name of the application
        Menu m_parkingMenu;
        Menu m_vSelectionMenu;
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
        using Menu::Menu;
        int run();
        //constructor
        Parking() = default;
        Parking(const char* filename);
        //Copy and assignment are denied in the Parking class. (Parking class can not be copied or 
        //assigned to another Parking object)
        Parking(const Parking&) = delete;
        Parking& operator=(const Parking&) = delete;
        void setFileName(const char* filename);
        void printDash();
        ~Parking();
    };
}
#endif // !

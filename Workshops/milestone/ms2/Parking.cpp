/*
*****************************************************************************
                        Milestone 2
Student ID#: 127632214
Email      : cyou8@myseneca.ca
Section    : OOP244 NAA
Filename: Parking.cpp
Version 1.0
Full Name  : Chunxue You(Sharon)
Revision History
----------------------------------------------------------------
Date      Reason
2020/11/08  Preliminary release
2020/11/09  Added printHeader function to load the dash frame format
-----------------------------------------------------------------

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
#include "Menu.h"
#include "Utils.h"
#include "Parking.h"
using namespace std;
namespace sdds {

    //one argument constructor
    Parking::Parking(const char* filename) {
        setFileName(filename);
        if (loadDateFile()) {
            m_parkingMenu.setTitle("Parking Menu, select an action:");
            m_parkingMenu.setIndentation(0);
            m_parkingMenu << "Park Vehicle"
                << "Return Vehicle"
                << "List Parked Vehicles"
                << "Find Vehicle"
                << "Close Parking (End of day)"
                << "Exit Program";
            m_vSelectionMenu.setTitle("Select type of the vehicle:");
            m_vSelectionMenu.setIndentation(1);
            m_vSelectionMenu << "Car" << "Motorcycle" << "Cancel";
        }
        else {
            cout << "Error in data file" << endl;
            m_parkingMenu = 0;
            m_vSelectionMenu = 0;
        }
    }
    //destructor
    Parking::~Parking() {
        saveDataFile();
        delete[] m_filename;
        m_filename = nullptr;
    }

    void Parking::setFileName(const char* filename) {
        if (filename != nullptr && filename[0] != '\0') {
            m_filename = new char[strlen(filename) + 1];
            strcpy(m_filename, filename);
        }
    }

    void Parking::printHeader(const char* title)const {
        char oldFill = cout.fill('-');
        cout.width(33);
        cout << ""<< endl;
        cout << title << endl;
        cout.fill('-');
        cout.width(33);
        cout << "" << endl << endl;
        cout.fill(oldFill);
    }

    void Parking::printHeaderWithFilename(const char* filename) const{
        char oldFill = cout.fill('-');
        cout.width(33);
        cout << "" << endl;
        cout << filename << m_filename << endl;
        cout.fill('-');
        cout.width(33);
        cout << "" << endl << endl;
        cout.fill(oldFill);
    }

    //isEmpty function that returns true if the Parking is in an invalid empty State or false if the 
    //parking is valid and usable
    bool Parking::isEmpty() const {
        return m_filename == nullptr;
    }

    //does not receive or return anything and at this stage only prints:
    //******Valet Parking****** <NEWLINE>
    void Parking::parkingStatus() const {
        cout << "****** Valet Parking ******" << endl;
       
    }

    //This function does not receive or return anything.
    //The function displays the Vehicle Selection sub - menu.Then based on the user's selection; 
    //Car, Motorcycle or Cancel, it will print the corresponding message. Afterwards, it goes to a new line.
    void Parking::parkVehicle() const {
        int selection = m_vSelectionMenu.run();
        if (selection == 1) {
            printHeader("Parking Car");
        }
        else if (selection == 2) {
            printHeader("Parking Motorcycle");
        }
        else {
            printHeader("Cancelled parking");
        }
    }
    //This function does not receive or return anything and only prints the corresponding message
    void Parking::returnVehicle() const {
        printHeader("Returning Vehicle");
    }

    void Parking::listParkedVehicles() const {
        printHeader("Listing Parked Vehicles");
    }

    void Parking::findVehicle() const {
        printHeader("Finding a Vehicle");
    }

    /*This function does not receive anything and returns a Boolean.
     Follow the instruction in the Close Parking (End of day) menu selection and then return true,
     if the user’s response is Yes. Otherwise, return false if the user’s response is No.*/
    bool Parking::closeParking() const {
        cout << "This will close the parking; All the vehicles will be removed!" << endl;
        cout << "Are you sure? (Y)es/(N)o: ";
        string select;
        bool res, valid;
        do {
            valid = true;
            cin >> select;
            cin.ignore(1000, '\n');

            if (select == "Y" || select == "y") {
                res = true;
            }
            else if (select == "N" || select == "n") {
                res = false;
            }
            else {
                cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
                valid = false;
            }
        } while (!valid);

        return res;
            
    }
    //if the user’s response is Yes. Otherwise, return false if the user’s response is No.
    bool Parking::exitParkingApp() const {
        cout << "This will terminate the application and save the data!" << endl;
        cout << "Are you sure? (Y)es/(N)o: ";
        string select;
        bool res, valid;
        do {
            valid = true;
            cin >> select;
            cin.ignore(1000, '\n');
            if (select == "Y" || select == "y") {
                res = true;
            }
            else if (select == "N" || select == "n") {
                res = false;
            }
            else {
                cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
                valid = false;
            }
        } while (!valid);

        return res;
    }
    //This function does not receive anything and returns a Boolean.
    //If the Parking is not in an invalid empty state, Print the following : "loading data from " 
    //and then print the name of the data file followed by a <NEWLINE> and finally return true.
    //If the Parking is in an invalid empty state, return false (and print nothing).
    bool Parking::loadDateFile() const {
        bool valid = false;
        if (!isEmpty()) { 
            printHeaderWithFilename("loading data from ");
            valid = true;
        }
        return valid;
    }

    //This function does not receive or return anything and if the Parking is not in an invalid empty 
    //state it prints: "Saving data into " then prints the name of the data file followed by a <NEWLINE>.
    void Parking::saveDataFile() const {
        if (!isEmpty()) {
            printHeaderWithFilename("Saving data into ");
        }
    }

    int Parking::run() {
        int res = 1;
        if (!isEmpty()) {
            res = 0;
            int selection,valid;
            do
            {
                parkingStatus();
                valid = 1;
                selection = m_parkingMenu.run();

                switch (selection)
                {
                case 1:
                    parkVehicle();
                    break;
                case 2:
                    returnVehicle();
                    break;
                case 3:
                    listParkedVehicles();
                    break;
                case 4:
                    findVehicle();
                    break;
                case 5:
                    if (closeParking()) {
                        cout << "Ending application!" << endl;
                        valid = 0;
                    };
                    break;
                default:
                    if (exitParkingApp()) {
                        cout << "Exiting application!" << endl;
                        valid = 0;
                    }
                    break;
                }
            } while (valid);
        }

        return res;

    }

}
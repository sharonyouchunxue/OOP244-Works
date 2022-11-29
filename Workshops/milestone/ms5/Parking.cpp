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
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
#include <cstring>
#include <string>
#include "Utils.h"
#include "Parking.h"
using namespace std;
namespace sdds {

    //one argument constructor
    Parking::Parking(const char* datafile, int noOfSpots) {
        setFileName(datafile);
        //If this number is invalid (less than 10 or more than the Maximum Number 
        //of Parking Spots constant value) then the Parking is set as an Invalid Empty State.
        if (noOfSpots >= 10 && noOfSpots <= MAX_PARKINGSPOT) {
            m_numOfSpot = noOfSpots;
        }
        else {
            m_numOfSpot = 0;
        }
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
           /* m_parkingMenu = 0;
            m_vSelectionMenu = 0;*/
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
        cout << "" << endl;
        cout << title << endl;
        cout.fill('-');
        cout.width(33);
        cout << "" << endl << endl;
        cout.fill(oldFill);
    }

    void Parking::printHeaderWithFilename(const char* filename) const {
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
        cout << "***** Available spots: ";
        cout.width(4);
        cout.setf(ios::left);
        cout << m_numOfSpot - m_numOfparkingVehicles << " *****" << endl;
        cout.unsetf(ios::left);
    }

    //This function does not receive or return anything.
    //The function displays the Vehicle Selection sub - menu.Then based on the user's selection; 
    //Car, Motorcycle or Cancel, it will print the corresponding message. Afterwards, it goes to a new line.
    void Parking::parkVehicle() const {
        if (m_numOfSpot == m_numOfparkingVehicles) {
            cout << "Parking is full" << endl;
        }
        else {
            int selection = m_vSelectionMenu.run();
            if (selection == 3) {
                printHeader("Parking Cancelled");
            }
            else {
                Vehicle* vehicleType{};
                if (selection == 1) {
                    //dynamically create an instance of a Car
                    vehicleType = new Car();
                }
                else if (selection == 2) {
                    //dynamically create an instance of a Motorcycle
                    vehicleType = new Motorcycle();
                }
                //set it NOT to be in Comma Separated mode
                vehicleType->setCsv(false);
                // reads it from the console
                cin >> *vehicleType;

                bool valid = true;
                if (valid && m_numOfparkingVehicles < m_numOfSpot) {
                    for (int i = 0; i < m_numOfSpot && valid; i++) {
                        if (parkingSpot[i] == nullptr) {
                            parkingSpot[i] == vehicleType;
                            parkingSpot[i]->setParkingSpot(i + 1);
                            cout << "Parking Ticket" << endl;
                            cout << *parkingSpot[i] << endl;
                            //m_numOfparkingVehicles++;
                            valid = false;
                        }
                    }
                }
            }
        }
    }
    //This function does not receive or return anything and only prints the corresponding message
    void Parking::returnVehicle() const {
        cout << "Return Vehicle" << endl;
        char licensePlate[MAX_CHARACTERS + 1]{};
        bool invalid;
        cout << "Enter License Plate Number: ";
        do {
            invalid = false;
            cin >> licensePlate;
            cin.ignore();
            if (strlen(licensePlate) < 1 || strlen(licensePlate) > 8) {
                cout << "Invalid License Plate, try again: ";
                invalid = true;
            }
        } while (invalid);
        toupper(*licensePlate);

        bool flag = true;
        for (int i = 0; i < m_numOfSpot && flag; i++) {
            if (parkingSpot[i] != nullptr && *parkingSpot[i] == licensePlate) {
                cout << "Returning:" << endl;
                parkingSpot[i]->setCsv(false);
                cout << *parkingSpot[i] << endl;
                delete parkingSpot[i];
                //m_numOfparkingVehicles--;
                flag = false;
            }
        }
        if (flag) {
            cout << "License plate " << licensePlate << " Not found" << endl;
        }
    }

    //oes not receive or return anything and goes through all the Parking Spot elements of the Parking 
    //(obviously up to the Number of Spots) and prints all that is not empty (not null) and separates 
    //them with the following line: "-------------------------------"<NEWLINE>
    void Parking::listParkedVehicles() const {
        //printHeader("Listing Parked Vehicles");
        for (int i = 0; i < m_numOfSpot; i++) {
            if (parkingSpot[i] != nullptr) {
                parkingSpot[i]->setCsv(false);
                cout << *parkingSpot[i];
                cout << "-------------------------------" << endl;
            }
        }

    }

    void Parking::findVehicle() const {
        char licensePlate[MAX_CHARACTERS + 1]{};
        bool invalid;
        //printHeader("Finding a Vehicle");
        cout << "Vehicle Search" << endl;
        cout << "Enter Licence Plate Number: ";
        do {
            invalid = false;
            cin >> licensePlate;
            cin.ignore();
            if (strlen(licensePlate) < 1 || strlen(licensePlate) > 8) {
                cout << "Invalid License Plate, try again: ";
                invalid = true;
            }
        } while (invalid);
        toupper(*licensePlate);

        bool flag = true;
        for (int i = 0; i < m_numOfSpot && flag; i++) {
            if (parkingSpot[i] != nullptr && *parkingSpot[i] == licensePlate) {
                cout << "Vechicle found:" << endl;
                parkingSpot[i]->setCsv(true);
                cout << *parkingSpot[i] << endl;
                flag = true;
            }
            else {
                cout << "License plate " << licensePlate << " Not found" << endl;
            }
        }

    }

    /*This function does not receive anything and returns a Boolean.
     Follow the instruction in the Close Parking (End of day) menu selection and then return true,
     if the user’s response is Yes. Otherwise, return false if the user’s response is No.*/
    bool Parking::closeParking() const {
        bool parkingClose = false;
        if (isEmpty()) {
            cout << "Closing Parking" << endl;
            parkingClose = true;
        }
        else {
            cout << "This will Remove and tow all remaining Vehicles from the Parking!" << endl;
            cout << "Are you sure? (Y)es/(N)o: ";
            string select;
            bool res, valid;
            do {
                valid = true;
                cin >> select;
                cin.ignore(1000, '\n');

                if (select == "Y" || select == "y") {
                    cout << "Closing Parking" << endl;
                    for (int i = 0; i < m_numOfSpot; i++) {
                        cout << "Towing request" << endl;
                        cout << "*********************" << endl;
                        cout << *parkingSpot[i];
                        delete parkingSpot[i];
                        *parkingSpot[i] == nullptr;
                        //m_numOfparkingVehicles--;
                    }
                    saveDataFile();
                    parkingClose = true;
                }        
                else if (select == "N" || select == "n") {
                    res = false;
                }
                else {
                    cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
                    valid = false;
                }
            } while (!valid);
        }
        return parkingClose;

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
        bool valid = true;
        ifstream fin;//instance of the ifstream class opens the file named in the Filename member variable.
        if (!isEmpty()) {
            fin.open(m_filename);         
        }
        else {
            char ch;
            Vehicle* vehicleType{};
             int numOfparkingVehicles = 0;
            while (numOfparkingVehicles < m_numOfSpot && valid && fin) {
                ch = 'x';
                fin >> ch;
                fin.ignore();
                if (ch == 'C') {
                    vehicleType = new Car();
                }
                else if (ch == 'M') {
                    vehicleType = new Motorcycle();
                }
                if (vehicleType) {
                    vehicleType->setCsv(true);
                    fin >> *vehicleType;
                    if (fin) {
                        //m_numOfSpot[vehicleType->getParkingSpot() - 1] = vehicleType;
                        numOfparkingVehicles++;
                    }
                    else {
                        delete vehicleType;
                        vehicleType = nullptr;
                        valid = false;
                    }
                }
            }
        }
        return valid;
    }

    //This function does not receive or return anything and if the Parking is not in an invalid empty 
    //state it prints: "Saving data into " then prints the name of the data file followed by a <NEWLINE>.
    void Parking::saveDataFile() const {
        if (!isEmpty()) {
            //printHeaderWithFilename("Saving data into ");
            ofstream fileout(m_filename);// instance of the ofstream class open the file
            //If the file is opened successfully go through all the elements of the Parking Spots 
            //that are not null and save the Vehicles pointed by them in the data file in Comma Separated mode.
            if (fileout) {
                for (int i = 0; i < m_numOfSpot; i++) {
                    if (parkingSpot[i] != nullptr) {
                        parkingSpot[i]->setCsv(true);
                        fileout << *parkingSpot[i];
                    }
                }
            }

        }
    }

    int Parking::run() {
        int res = 1;
        if (!isEmpty()) {
            res = 0;
            int selection, valid;
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
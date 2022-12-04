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
#include "Vehicle.h"
using namespace std;

namespace sdds {
    Parking::Parking(){
        setEmpty();
    }
    void Parking::setEmpty(){
        m_filename = nullptr;
        for (int i = 0; i < MAX_CHARACTERS; i++) {
            parkingSpot[i] = nullptr;
        }
        m_numOfparkedVehicles = 0;
        m_numOfSpot = 0;
    }
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
        if (loadDataFile()) {
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
        }
    }
    //destructor
    Parking::~Parking() { 
        saveDataFile();
        delete[] m_filename;
        m_filename = nullptr;
        for (int i = 0; i < MAX_PARKINGSPOT; i++) {
            delete parkingSpot[i];
            parkingSpot[i] = nullptr;          
        }       
    }

    void Parking::setFileName(const char* filename) {
        if (filename != nullptr && filename[0] != '\0') {
            m_filename = new char[strlen(filename) + 1];
            strcpy(m_filename, filename);
        }
    }

    bool Parking::isValid() const{
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
        cout << m_numOfSpot - m_numOfparkedVehicles << " *****" << endl;
        cout.unsetf(ios::left);
    }

    //This function does not receive or return anything.
    //The function displays the Vehicle Selection sub - menu.Then based on the user's selection; 
    //Car, Motorcycle or Cancel, it will print the corresponding message. Afterwards, it goes to a new line.
    void Parking::parkVehicle() {
        if (m_numOfSpot == m_numOfparkedVehicles) {
            cout << "Parking is full" << endl;
        }
        else {
            int selection = m_vSelectionMenu.run();
            if (selection == 3) {
                cout << "Parking Cancelled";
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
                if (valid && m_numOfparkedVehicles < m_numOfSpot) {
                    for (int i = 0; i < m_numOfSpot && valid; i++) {
                        if (parkingSpot[i] == nullptr) {
                            parkingSpot[i] = vehicleType;
                            parkingSpot[i]->setParkingSpot(i + 1);
                            m_numOfparkedVehicles++;
                            cout << "\nParking Ticket" << endl;
                            parkingSpot[i]->writeType(cout);
                            cout << *parkingSpot[i] << endl;       
                            valid = false;
                        }
                    }
                }
            }
        }
    }

    //This function does not receive or return anything and only prints the corresponding message
    void Parking::returnVehicle(){
        char licensePlate[MAX_CHARACTERS + 1]{};
        bool invalid;
        cout << "Return Vehicle" << endl;
        cout << "Enter Licence Plate Number: ";
        do {
            invalid = false;
            cin >> licensePlate;
            cin.ignore();
            if (strlen(licensePlate) < 1 || strlen(licensePlate) > 8) {
                cout << "Invalid Licence Plate, try again: ";
                invalid = true;
            }
        } while (invalid);
        for (int i = 0; i < strlen(licensePlate); i++) {
            licensePlate[i] = toupper(licensePlate[i]);
        }

        bool found = true;
        for (int i = 0; i < m_numOfSpot && found; i++) {
            if (parkingSpot[i] != nullptr){
                if (*parkingSpot[i] == licensePlate) {
                    cout << endl << "Returning: " << endl;
                    parkingSpot[i]->setCsv(false);
                    parkingSpot[i]->writeType(cout);
                    parkingSpot[i]->write();
                    cout << endl;
                    delete parkingSpot[i];
                    parkingSpot[i] = nullptr;
                    m_numOfparkedVehicles--;
                    found = false;
                }
            }
        }
        if (found) {
            cout << "\nLicense plate " << licensePlate << " Not found\n" << endl;
        }
    }
             
    //oes not receive or return anything and goes through all the Parking Spot elements of the Parking 
    //(obviously up to the Number of Spots) and prints all that is not empty (not null) and separates 
    //them with the following line: "-------------------------------"<NEWLINE>
    void Parking::listParkedVehicles() const {
        for (int i = 0; i < m_numOfSpot; i++) {
            if (parkingSpot[i] != nullptr) {
                parkingSpot[i]->setCsv(false);
                parkingSpot[i]->writeType(cout);
                cout << *parkingSpot[i];
                cout << "-------------------------------" << endl;
            }
        }
    }

    void Parking::findVehicle() {
        char licensePlate[MAX_CHARACTERS + 1]{};
        bool invalid;
        cout << "Vehicle Search" << endl;
        cout << "Enter Licence Plate Number: ";
        do {
            invalid = false;
            cin >> licensePlate;
            cin.ignore();
            if (strlen(licensePlate) < 1 || strlen(licensePlate) > 8) {
                cout << "Invalid Licence Plate, try again: ";
                invalid = true;
            } 
        } while (invalid);
        for (int i = 0; i < strlen(licensePlate); i++) {
            licensePlate[i] = toupper(licensePlate[i]);
        }

        bool found = true;
        for (int i = 0; i < m_numOfSpot && found; i++) {
            if (parkingSpot[i] != nullptr) {
                if (*parkingSpot[i] == licensePlate) {
                    cout << "\nVechicle found: " << endl;
                    parkingSpot[i]->setCsv(false);
                    parkingSpot[i]->writeType(cout);
                    parkingSpot[i]->write();
                    cout << endl;
                    found = false;                
                }
            }
        }
        if (found) {
            cout << "\nLicense plate " << licensePlate << " Not found\n" << endl;
            //pause();
        }
    }
    /*This function does not receive anything and returns a Boolean.
     Follow the instruction in the Close Parking (End of day) menu selection and then return true,
     if the users response is Yes. Otherwise, return false if the users response is No.*/
    bool Parking::closeParking() {
        bool valid = false;
        if (m_numOfparkedVehicles == 0) {
            std::cout << "Closing Parking" << endl;
            valid = true;
        }
        else {
                cout << "This will Remove and tow all remaining vehicles from the parking!" << endl;
                cout << "Are you sure? (Y)es/(N)o: ";
            if (isValid()) {
                std::cout << "Closing Parking" << endl;
                for (int i = 0; i < m_numOfSpot; i++) {
                    if (parkingSpot[i] != nullptr) {
                        cout << endl << "Towing request" << endl;
                        cout << "*********************" << endl;
                        parkingSpot[i]->setCsv(false);
                        parkingSpot[i]->writeType(cout);
                        cout << *parkingSpot[i];
                        delete parkingSpot[i];
                        parkingSpot[i] = nullptr;
                        m_numOfparkedVehicles--;                       
                    }
                }
                valid = true;
            }
        }
        return valid;
    }


    //if the users response is Yes. Otherwise, return false if the users response is No.
    bool Parking::exitParkingApp() const {
        cout << "This will terminate the program!!" << endl;
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
    bool Parking::loadDataFile(){      
        bool valid = true;
        if (!isEmpty()) {
            ifstream filein;
            filein.open(m_filename);

            if (filein) {
                bool flag = false;
                do {
                    char vehicleType{};
                    Vehicle* V = nullptr;

                    filein.get(vehicleType);
                    filein.ignore();

                    if (vehicleType == 'M' || vehicleType == 'C') {
                        if (vehicleType == 'M') {
                            V = new Motorcycle();
                        }
                        else if (vehicleType == 'C') {
                            V = new Car();
                        }
                        V->setCsv(true);
                        filein >> *V;

                        if (V != nullptr) {
                            parkingSpot[V->getParkingSpot() - 1] = V;
                            m_numOfparkedVehicles++;
                        }
                        else {
                            valid = false;
                            delete V;
                            V = nullptr;
                        }
                   }
                    else  flag = true;
                } while (!flag&& m_numOfparkedVehicles < m_numOfSpot);
            }
        }
        return valid;
    }

    //This function does not receive or return anything and if the Parking is not in an invalid empty 
    //state it prints: "Saving data into " then prints the name of the data file followed by a <NEWLINE>.
    void Parking::saveDataFile() const {
        if (!isEmpty()) {
            ofstream fileout(m_filename);
            if (fileout) {
                for (int i = 0; i < m_numOfSpot; i++) {
                    if (parkingSpot[i] != nullptr) {
                        parkingSpot[i]->setCsv(true);                     
                        parkingSpot[i]->writeType(fileout);
                        parkingSpot[i]->write(fileout);
                    }
                }
            }
        }
    }

    int Parking::run() {
        bool res = true;
        if (!isEmpty()) {
            res = false;
            bool valid;
            int selection;
            do
            {
                parkingStatus();
                valid = true;
                selection = m_parkingMenu.run();

                switch (selection)
                {
                case 1:
                    parkVehicle();
                    pause();
                    break;
                case 2:
                    returnVehicle();
                    pause();
                    break;
                case 3:
                    listParkedVehicles();
                    pause();
                    break;
                case 4:
                    findVehicle();
                    pause();
                    break;
                case 5:
                    if (closeParking()) {;
                        valid = false;
                    };
                    break;
                default:
                    if (exitParkingApp()) {
                        cout << "Exiting program!" << endl;
                        valid = false;
                    }
                    break;
                }
            } while (valid);
        }
        return res;
    }

    void Parking::pause() const{
        cout << "Press <ENTER> to continue...";
        cin.ignore();
    }

}
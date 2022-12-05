/*
*****************************************************************************
                        Milestone 5
Full Name  : Chunxue You(Sharon)
Student ID#: 127632214
Email      : cyou8@myseneca.ca
Section    : OOP244 NAA
Date       : 2022-12-04

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
#include "Parking.h"
using namespace std;

namespace sdds {
    //no argument constructor, set to empty state
    Parking::Parking(){
        setEmpty();
    }

    //invalid empty state
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
        //loadDataFile to display the parking menu items
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

    //destructor, saveDatafile and free memories
    Parking::~Parking() { 
        saveDataFile();
        delete[] m_filename;
        m_filename = nullptr;
        for (int i = 0; i < MAX_PARKINGSPOT; i++) {
            delete parkingSpot[i];
            parkingSpot[i] = nullptr;          
        }       
    }

    //setFileName function to dynamic allocate the filename
    void Parking::setFileName(const char* filename) {
        if (filename != nullptr && filename[0] != '\0') {
            m_filename = new char[strlen(filename) + 1];
            strcpy(m_filename, filename);
        }
    }

    //isEmpty function that returns true if the Parking is in an invalid empty State or false if the 
    //parking is valid and usable
    bool Parking::isEmpty() const {
        return m_filename == nullptr;
    }

    //does not receive or return anything and prints:
    // print the number of available Parking Spots with formating
    void Parking::parkingStatus() const {
        cout << "****** Valet Parking ******" << endl;
        cout << "*****  Available spots: ";
        cout.width(4);
        cout.setf(ios::left);
        cout << m_numOfSpot - m_numOfparkedVehicles << " *****" << endl;
        cout.unsetf(ios::left);
    }

    //This function does not receive or return anything.
    void Parking::parkVehicle() {
        //if number pf spot == number pf vehicle parked, then parking is full
        if (m_numOfSpot == m_numOfparkedVehicles) {
            cout << "Parking is full" << endl;
        }
        else {
            //run the vehicle selection menu
            int selection = m_vSelectionMenu.run();
            //if user select 3, shows parking cancelled
            if (selection == 3) {
                cout << "Parking Cancelled";
            }
            else {
                //create an instance of a Car or Motorcycle type in a Vehicle pointer.
                Vehicle* vehicleType{};
                if (selection == 1) {
                    //if user select 1, dynamically create an instance of a Car
                    vehicleType = new Car();
                }
                else if (selection == 2) {
                    //if user select 2 dynamically create an instance of a Motorcycle
                    vehicleType = new Motorcycle();
                }
                //set it NOT to be in Comma Separated mode
                vehicleType->setCsv(false);
                // reads it from the console
                cin >> *vehicleType;

                bool valid = true;
                // search through the Parking Spots array and finds the first available(null) Parking Spot
                if (valid && m_numOfparkedVehicles < m_numOfSpot) {
                    for (int i = 0; i < m_numOfSpot && valid; i++) {
                        if (parkingSpot[i] == nullptr) {
                            //sets it to the Vehicle pointer
                            parkingSpot[i] = vehicleType;
                            //set the Parking Spot member variable of the Vehicle to the spot number it was parked in (index + 1)
                            parkingSpot[i]->setParkingSpot(i + 1);
                            //number of parked Vehicle increment by 1
                            m_numOfparkedVehicles++;
                            cout << "\nParking Ticket" << endl;
                            //print the type of vehicle to the console
                            parkingSpot[i]->writeType(cout);
                            //prints the Vehicle information to the console
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
        cout << "Enter License Plate Number: ";
        do {
            invalid = false;
            //Prompt the user for the license plate
            cin >> licensePlate;
            cin.ignore();
            //validate the string length for license plate that user entered
            if (strlen(licensePlate) < 1 || strlen(licensePlate) > 8) {
                cout << "Invalid Licence Plate, try again: ";
                invalid = true;
            }
        } while (invalid);
        //to convert the license plate from lowercase to uppercase
        int len = strlen(licensePlate);
        for (int i = 0; i < len; i++) {
            licensePlate[i] = toupper(licensePlate[i]);
        }

        bool found = true;
        //search through the parked Vehicles for a matching license plate, if it matches, then print the corresponding info
        for (int i = 0; i < m_numOfSpot && found; i++) {
            if (parkingSpot[i] != nullptr){
                //if the parked Vehicle is matching the license plate that user entered
                if (*parkingSpot[i] == licensePlate) {
                    //print Returning header message out to the console
                    cout << endl << "Returning:" << endl;
                    //set it NOT to be in Comma Separated mode
                    parkingSpot[i]->setCsv(false);
                    //print the mathced vehicle type 
                    parkingSpot[i]->writeType(cout);
                    //print the vehicle information
                    parkingSpot[i]->write();
                    cout << endl;
                    // delete the Vehicle from the memory and set the Parking Spot element back to nullptr.
                    delete parkingSpot[i];
                    parkingSpot[i] = nullptr;
                    //number of vehicle parked decrement by 1
                    m_numOfparkedVehicles--;
                    found = false;
                }
            }
        }
        //otherwise print license plate is not found
        if (found) {
            cout << "\nLicense plate " << licensePlate << " Not found\n" << endl;
        }
    }
             
    //does not receive or return anything and goes through all the Parking Spot elements of the Parking 
    //(obviously up to the Number of Spots) and prints all that is not empty (not null) and separates 
    //them with the following line: "-------------------------------"<NEWLINE>
    void Parking::listParkedVehicles() const {
        cout << "*** List of parked vehicles ***" << endl;
        for (int i = 0; i < m_numOfSpot; i++) {
            if (parkingSpot[i] != nullptr) {
                parkingSpot[i]->setCsv(false);
                parkingSpot[i]->writeType(cout);
                cout << *parkingSpot[i];
                cout << "-------------------------------" << endl;
            }
        }
    }

    //this function does not receive or return anything, it will find the matched licenplate
    void Parking::findVehicle() {
        char licensePlate[MAX_CHARACTERS + 1]{};
        bool invalid;
        cout << "Vehicle Search" << endl;
        cout << "Enter Licence Plate Number: ";
        do {
            invalid = false;
            //Prompt the user for the license plate
            cin >> licensePlate;
            cin.ignore();
            //validate the string length for license plate that user entered
            if (strlen(licensePlate) < 1 || strlen(licensePlate) > 8) {
                cout << "Invalid Licence Plate, try again: ";
                invalid = true;
            } 
        } while (invalid);
        //to convert the license plate from lowercase to uppercase
        int len = strlen(licensePlate);
        for (int i = 0; i < len; i++) {
            licensePlate[i] = toupper(licensePlate[i]);
        }

        bool found = true;
        //search through the parked Vehicles for a matching license plate, if it matches, then print the corresponding info
        for (int i = 0; i < m_numOfSpot && found; i++) {
            if (parkingSpot[i] != nullptr) {
                //if the parked Vehicle is matching the license plate that user entered
                if (*parkingSpot[i] == licensePlate) {
                    //print header message out
                    cout << "\nVehicle found:" << endl;
                    //set it NOT to be in Comma Separated mode
                    parkingSpot[i]->setCsv(false);
                    //print the mathced vehicle type 
                    parkingSpot[i]->writeType(cout);
                    //print the vehicle information
                    parkingSpot[i]->write();
                    cout << endl;
                    found = false;                
                }
            }
        }
        //if is not match any of the license plate, print license plate not found
        if (found) {
            cout << "\nLicense plate " << licensePlate << " Not found\n" << endl;
        }
    }
    /*This function does not receive anything and returns a Boolean.
     Follow the instruction in the Close Parking (End of day) menu selection and then return true,
     if the users response is Yes. Otherwise, return false if the users response is No.*/
    bool Parking::closeParking() {
        bool valid = false;
        //if the number of parked vehicle == 0, print the closing parking message
        if (m_numOfparkedVehicles == 0) {
            std::cout << "Closing Parking" << endl;
            valid = true;
        }
        else { 
                cout << "This will Remove and tow all remaining vehicles from the parking!" << endl;
                cout << "Are you sure? (Y)es/(N)o: ";
                //valid user entered selectionm if user enter yes, then close the parking,
            if (isValid()) {
                std::cout << "Closing Parking" << endl;
                //search through all the parked vehicle, remove and tow all the vehicles, save it to the dataFile
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
        cout << "This will terminate the program!" << endl;
        cout << "Are you sure? (Y)es/(N)o: ";
        return isValid();      
    }

    //This function does not receive anything and returns a Boolean.
    bool Parking::loadDataFile(){      
        bool valid = true;
        //if is not an invalid empty state
        if (!isEmpty()) {
            //create an instance of the ifstream class
            ifstream filein;
            //open the file named in the Filename member variable
            filein.open(m_filename);
            //If the opening of the file successfully
            //Loop through the records of the opened file and read each record into a vehicle pointer
            if (filein) {
                bool flag = false;
                do {
                    //declare character "vehicle type variable
                    char vehicleType{};
                    //create an instance of V in a Vehicle pointer, initialise it to nullptr
                    Vehicle* V = nullptr;
                    //Extract one Character from the file 
                    filein.get(vehicleType);
                    //ignore the next
                    filein.ignore();

                    if (vehicleType == 'M' || vehicleType == 'C') {
                        //If the Character is 'M' 
                        if (vehicleType == 'M') {
                            //create a dynamic instance of a Motorcycle and keep the address in the Vehicle pointer
                            V = new Motorcycle();
                        }
                        //f the Character is 'C'
                        else if (vehicleType == 'C') {
                           // create a dynamic instance of a Carand keep the address in the Vehicle pointer
                            V = new Car();
                        }
                        //f either of the two Vehicles is allocated, then set the Vehicle to Comma Separate Value mode 
                        V->setCsv(true);
                        //extract its values from the data file.
                        filein >> *V;
                        //If the read was successful 
                        if (V != nullptr) {
                            //add the Vehicle to the Parking by saving the Vehicle pointer in the element of the Parking Spot array 
                            //that corresponds to the Parking Spot of the Vehicle
                            //index of the element of the Parking Spot array is always the Parking Spot number of the Vehicle minus one
                            parkingSpot[V->getParkingSpot() - 1] = V;
                            m_numOfparkedVehicles++;
                        }
                        else {
                            //if the read was unsuccessful deallocate the Vehicle
                            //set the function to a false state and end the loop.
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

    //This function does not receive or return anything
    void Parking::saveDataFile() const {
        //if the Parking is not in an invalid empty 
        if (!isEmpty()) {
            //create an instance of the ofstream class
            ofstream fileout(m_filename);
            //If the file is opened successfully
            if (fileout) {
                //go through all the elements of the Parking Spots
                for (int i = 0; i < m_numOfSpot; i++) {
                    //if they are not null and save the Vehicles pointed by them in the data file
                    if (parkingSpot[i] != nullptr) {
                        //set it in Comma Separated mode.
                        parkingSpot[i]->setCsv(true);
                        //write the vehicle type out
                        parkingSpot[i]->writeType(fileout);
                        //write the vehicle info out
                        parkingSpot[i]->write(fileout);
                    }
                }
            }
        }
    }

    //Run function in Parking to runs the whole Parking Application 
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

    //pause function
    void Parking::pause() const{
        cout << "Press <ENTER> to continue....";
        cin.ignore();
    }

}
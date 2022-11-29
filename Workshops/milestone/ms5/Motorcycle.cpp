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
#include <iostream>
#include "Motorcycle.h"
using namespace std;
namespace sdds {
    //no argument constructor
    Motorcycle::Motorcycle() {
        Vehicle::setEmpty();
        m_sidecar = false;
    }

    Motorcycle::Motorcycle(const char* licensePlate, const char* makeModel) :Vehicle(licensePlate, makeModel) {
    }

    //copy constructor
    Motorcycle::Motorcycle(const Motorcycle& M) {
        setEmpty();
        operator = (M);
        ReadWritable::setCsv(false);
    }
    Motorcycle& Motorcycle::operator=(const Motorcycle& M) {
        if (this != &M) {
            Vehicle::operator=(M);
            ReadWritable::setCsv(true);
        }
        return *this;
    }

    bool Motorcycle::isValid() const {
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


    //Override the pure virtual method writeType to write "M," 
    //if the object is in comma - separated values format(isCsv()), 
    //or otherwise write "Vehicle type: Motorcycle" and a NEWLINE.
    std::ostream& Motorcycle::writeType(std::ostream& ostr) const {
        if (isCsv()) {
            ostr << "M,";
        }
        else {
            ostr << "Vehicle type: Motorcycle" << endl;
        }
        return ostr;
    }

    //overrides the read method of the Vehicle class.
    std::istream& Motorcycle::read(std::istream& istr) {
        if (isCsv()) {
            Vehicle::read(istr);//It calls the read of the Base class
            //It reads a Boolean value(integer value of 1 or 0) into the carwash flag.
            int selection;
            istr >> selection;
            m_sidecar = bool(selection);
            //It ignores whatever character is left up toand including a newline character('\n').
            istr.ignore();
        }
        else {
            cout << "\nMotorcycle information entry" << endl;
            Vehicle::read(istr);//calls read base class
            cout << "Does the Motorcycle have a side car? (Y)es/(N)o: ";
            m_sidecar = isValid();
        }
        return istr;
    }

    //overrides the write method of the Vehicle class
    std::ostream& Motorcycle::write(std::ostream& ostr) const {

        if (isEmpty()) {
            ostr << "Invalid Motorcycle Object" << endl;
        }
        else {
            Vehicle::write(ostr);
            if (isCsv()) {
                ostr << m_sidecar << endl;
            }
            else {
                if (m_sidecar) {
                    ostr << "With Sidecar" << endl;
                }
            }
        }
        return ostr;
    }
    //destructor
    Motorcycle::~Motorcycle() {
    }













}
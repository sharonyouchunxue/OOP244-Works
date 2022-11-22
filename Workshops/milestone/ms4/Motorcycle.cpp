/*
*****************************************************************************
                        Milestone 4
Full Name  : Chunxue You(Sharon)
Student ID#: 127632214
Email      : cyou8@myseneca.ca
Section    : OOP244 NAA
Date       : 2022-11-21

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
    Motorcycle::Motorcycle() {
        //no argument constructor
        Vehicle::setEmpty();
        m_sidecar = false;
    }

    Motorcycle::Motorcycle(const char* licensePlate, const char* makeModel):Vehicle(licensePlate,makeModel) {
       /* if (licensePlate == nullptr && licensePlate != '\0' || makeModel == nullptr && makeModel != '\0') {
            setEmpty();
        }*/
    }

    //copy constructor
    Motorcycle::Motorcycle(const Motorcycle& M){
        operator = (M);
    }
    //Override the pure virtual method writeType to write "M," 
    //if the object is in comma - separated values format(isCsv()), 
    //or otherwise write "Vehicle type: Motorcycle" and a NEWLINE.
    std::ostream& Motorcycle::writeType(std::ostream& ostr) const{
        if (isCsv()) {
            ostr << "M," << endl;
        }
        else {
            ostr << "Vehcle type: Motorcycle" << endl;
        }
        return ostr;
    }

    //overrides the read method of the Vehicle class.
    std::istream& Motorcycle::read(std::istream& istr){
        if (isCsv()) {
            Vehicle::read(istr);//It calls the read of the Base class
            //It reads a Boolean value(integer value of 1 or 0) into the carwash flag.
            int value;
            istr >> value;
            m_sidecar = value;
            //It ignores whatever character is left up toand including a newline character('\n').
            istr.ignore();
        }
        else {
            cout << "Motorcycle information entry" << endl;
            Vehicle::read(istr);//calls read base class
            cout << "Does the Motorcycle have a sidecar? (Y)es/(N)o: ";
            string select;
            bool res;
            do {
                m_sidecar = true;
                istr >> select;
                istr.ignore(1000, '\n');
                if (select == "Y" || select == "y") {
                    res = true;
                }
                else if (select == "N" || select == "n") {
                    res = false;
                }
                else {
                    cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
                    m_sidecar = false;
                }
            } while (!m_sidecar);
        }
        return istr;
    }

    //overrides the write method of the Vehicle class
    std::ostream& Motorcycle::write(std::ostream& ostr) const{
        if (isEmpty()) {
            ostr << "Invalid Car Object" << endl;
        }
        else {
            Vehicle::write(ostr);
            if (isCsv()) { 
                ostr << int(m_sidecar) << endl;
                if (m_sidecar) {
                    ostr << "With Sidecar" << endl;
                }
                else {
                    ostr << "Without Sidecar" << endl;
                }
            }
        }
        return ostr;  
    }

    Motorcycle::~Motorcycle(){
    }











    

}
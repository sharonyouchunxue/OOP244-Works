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
#include "Car.h"

using namespace std;
namespace sdds {
	//no argument constructor
	//sets the Car (and therefore the Base class Vehicle) to a safe Invalid empty state.
	Car::Car() {
		Vehicle::setEmpty();
		m_carWash = false;
	}

	//two argument constructor
	Car::Car(const char* licensePlate, const char* makeModel) :Vehicle(licensePlate, makeModel) {
	}

	Car::Car(const Car& C) :Vehicle(C) {
		setEmpty();
		operator = (C);
		ReadWritable::setCsv(false);
	}
	//copy assignment operator
	Car& Car::operator=(const Car& C) {
		if (this != &C) {
			Vehicle::operator=(C);
			ReadWritable::setCsv(true);
		}
		return *this;
	}

	bool Car::isValid() const {
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


	//Override the pure virtual method writeType to write "C," 
	//if the object is in comma-separated values format (isCsv()), 
	//or otherwise write Vehicle type: Car" and a NEWLINE.
	std::ostream& Car::writeType(std::ostream& ostr) const {
		if (isCsv()) {
			ostr << "C,";
		}
		else {
			ostr << "Vehicle type: Car" << endl;
		}
		return ostr;
	}

	//overrides the read method of the Vehicle class.
	std::istream& Car::read(std::istream& istr) {
		if (isCsv()) {//If the Motorcycle is set to Comma Separated mode
			Vehicle::read(istr);//It calls the read of the Base class
			//It reads a Boolean value(integer value of 1 or 0) into the carwash flag.
			bool selection;
			istr >> selection;
			m_carWash = selection;
			//It ignores whatever character is left up toand including a newline character('\n').
			istr.ignore();
		}
		else {
			cout << "\nCar information entry" << endl;
			Vehicle::read(istr);//calls read base class
			cout << "Carwash while parked? (Y)es/(N)o: ";
			m_carWash = isValid();
		}
		return istr;
	}
	//This function overrides the write method of the Vehicle class
	std::ostream& Car::write(std::ostream& ostr) const {
		if (isEmpty()) {
			ostr << "Invalid Car Object" << endl;
		}
		else {
			Vehicle::write(ostr);
			if (isCsv()) {
				ostr << m_carWash << endl;
			}
			else {
				if (m_carWash) {
					ostr << "With Carwash" << endl;
				}
				else {
					ostr << "Without Carwash" << endl;
				}
			}
		}
		return ostr;
	}

	//empty destructor
	Car::~Car() {
	}















}
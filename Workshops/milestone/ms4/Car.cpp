#include <iostream>
#include <cstring>
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
	Car::Car(const char* licensePlate, const char* makeModel):Vehicle(licensePlate,makeModel) {
		/*if (licensePlate == nullptr&&licensePlate!='\0' || makeModel == nullptr&&makeModel!='\0') {
			setEmpty();
		}*/
	}

	Car::Car(const Car& C){
		operator = (C);
	}

	//Override the pure virtual method writeType to write "C," 
	//if the object is in comma-separated values format (isCsv()), 
	//or otherwise write Vehicle type: Car" and a NEWLINE.
	std::ostream& Car::writeType(std::ostream& ostr) const {
		if (isCsv()) {
			ostr << "C," << endl;
		}
		else {
			ostr << "Vehcle type: Car" << endl;
		}
		return ostr;
	}

	//overrides the read method of the Vehicle class.
	std::istream& Car::read(std::istream& istr){
		if (isCsv()) {
			Vehicle::read(istr);//It calls the read of the Base class
			//It reads a Boolean value(integer value of 1 or 0) into the carwash flag.
			int value;
			istr >> value;
			m_carWash = value;
			//It ignores whatever character is left up toand including a newline character('\n').
			istr.ignore();
		}
		else {
			cout << "Car information entry" << endl;
			Vehicle::read(istr);//calls read base class
			cout << "Carwash while parked? (Y)es/(N)o: ";
			string select;
			bool res;
			do {
				m_carWash = true;
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
					m_carWash = false;
				}
			} while (!m_carWash);
		}
		return istr;
	}

	//This function overrides the write method of the Vehicle class
	std::ostream& Car::write(std::ostream& ostr) const{
		if (isEmpty()) {
			ostr << "Invalid Car Object" << endl;
		}
		else {
			if (isCsv()) {
				Vehicle::write(ostr);
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
	Car::~Car(){
	}

	













}
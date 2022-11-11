#include<iostream>
#include "Dumper.h"
#include "VehicleBasic.h"
using namespace std;

namespace sdds
{
	//:VehicleBasic(licensePlate, builtYear) is to Call the constructor from the base class and pass the license number and year to it.
	Dumper::Dumper(const char* licensePlate, int builtYear, double capacity, const char* currentCargo) :VehicleBasic(licensePlate, builtYear) {
		m_capacity = capacity;
		m_currCargoLoad = 0;
		VehicleBasic::NewAddress(currentCargo);
	}

	double Dumper::getCapacity()const{
		return m_capacity;
	}

	double Dumper::getCurrCargoLoad() const{
		return m_currCargoLoad;
	}

	void Dumper::setCapacity(double capacity){
		m_capacity = capacity;

	}

	void Dumper::setCargo(double cargo){
		m_currCargoLoad = cargo;
	}

	//check if the crago plus current cargo load weight within the capacity range
	//if it is in the range, the add the cargo by 1, result is equal to true otherwise return false;
	bool Dumper::loaddCargo(double cargo){
		bool res = false;
		if (cargo + m_currCargoLoad <= m_capacity) {
			m_currCargoLoad += cargo;
			res = true;
		}	
		return res;
	}

	bool Dumper::unloadCargo(){
		bool res = false;
		if (m_currCargoLoad > 0) {
			m_currCargoLoad = 0.0;
			res = true;
		}
		return res;
	}

	std::ostream& Dumper::write(std::ostream& os)const{
		cout << "| " << getYear() << " | " << getLicenseNum() << " | " << getAddress() << " | " << getCurrCargoLoad() << "/" << getCapacity();
		return os;
	}

	std::istream& Dumper::read(std::istream& in){
		int tempYear;
		char tempLicenseNum[9];
		char tempLocation[64];
		double tempCapacity;
		double tempCargo;
		cout << "Built year: ";
		cin >> tempYear;
		setYear(tempYear);
		cout << "License plate: ";
		cin >> tempLicenseNum;
		setLicense(tempLicenseNum);
		cout << "Current location: ";
		cin >> tempLocation;
		setLocation(tempLocation);
		cout << "Capacity: ";
		cin >> tempCapacity;
		//tempCapacity = m_capacity;
		setCapacity(tempCapacity);
		cout << "Cargo: ";
		cin >> tempCargo;
		//tempCargo = m_currCargoLoad;
		setCargo(tempCargo);

		return in;		
	}

	Dumper::~Dumper(){
	}


	std::ostream& operator<<(std::ostream& os, const Dumper& D){
		return D.write(os);
	}

	std::istream& operator>>(std::istream& istr, Dumper& D){
		return D.read(istr);
	}

}
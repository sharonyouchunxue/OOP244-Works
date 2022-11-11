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

	//function to get value of capacity from the private class
	double Dumper::getCapacity()const{
		return m_capacity;
	}

	//function to get value of current cargo load from the private class
	double Dumper::getCurrCargoLoad() const{
		return m_currCargoLoad;
	}

	//copy m_capacity value to temperory argument capacity
	void Dumper::setCapacity(double capacity){
		m_capacity = capacity;

	}

	//copy m_currCargoLoad value to temperory argument cargo
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

	//a mutator that unloads current cargo (sets the attribute to 0). 
	//If the current load has been changed, return true, otherwise, return false. 
	//** the mutator will not do anything if the current cargo is 0 and thus return false **
	bool Dumper::unloadCargo(){
		bool res = false;
		if (m_currCargoLoad > 0) {
			m_currCargoLoad = 0.0;
			res = true;
		}
		return res;
	}

	//inserts into os the content of the object in the format 
	std::ostream& Dumper::write(std::ostream& os)const{
		cout << "| " << getYear() << " | " << getLicenseNum() << " | " << getAddress() << " | " << getCurrCargoLoad() << "/" << getCapacity();
		return os;
	}

	//a mutator that reads from the stream in the data for the current object 
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
		setCapacity(tempCapacity);
		cout << "Cargo: ";
		cin >> tempCargo;
		setCargo(tempCargo);

		return in;		
	}

    //destructor
	Dumper::~Dumper(){
	}

    //helper function to overload insertion operator to insert a Dumper into a stream
    //this operator will call write member function  in the class Dumper
	std::ostream& operator<<(std::ostream& os, const Dumper& D){
		return D.write(os);
	}

    //overload extraction operator to extract a Dumper into a stream
	//this operator will call read member function  in the class Dumper
	std::istream& operator>>(std::istream& istr, Dumper& D){
		return D.read(istr);
	}

}
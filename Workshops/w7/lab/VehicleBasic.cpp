#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "VehicleBasic.h"
using namespace std;
namespace sdds
{
	//Assume all data is valid.
	//a custom constructor that receives as parameters the license plate number 
	//and the year when the vehicle was built
	VehicleBasic::VehicleBasic(const char* licenseNumber, int year, const char* location){
		strcpy(m_licenseNum, licenseNumber);
		m_year = year;
		strcpy(m_address, location);
	}

	void VehicleBasic::setYear(int year){
		m_year = year;
	}
	void VehicleBasic::setLicense(const char* licenseNumber) {
		strcpy(m_licenseNum, licenseNumber);
	}
	// Set the location of the vehicle at Factory,copy m_address to location
	void VehicleBasic::setLocation(const char* loaction){
		strcpy(m_address, loaction);
	}

	void VehicleBasic::NewAddress(const char* address){
		cout << "|";
		cout.width(8);
		cout.setf(ios::right);
		cout << m_licenseNum << "| " << "|";
		cout.width(20);
		cout << m_address << " ---> ";
		strcpy(m_address, address);
		cout.unsetf(ios::right);
		cout.setf(ios::left);
		cout.width(23);
		cout << m_address << "|" << endl;
		cout.unsetf(ios::left);
	}
	const char* VehicleBasic::getLicenseNum() const{
		return m_licenseNum;
	}
	const char* VehicleBasic::getAddress() const{
		return m_address;
	}
	const int VehicleBasic::getYear() const{
		return m_year;
	}
	//a query that inserts into os the content of the object in the format
	std::ostream& VehicleBasic::write(std::ostream& os)const{
		os << "| " << m_year << " | " << m_licenseNum << " | " << m_address;
		return os;
	}
	// a mutator that reads from the stream in the data for the current object
	std::istream& VehicleBasic::read(std::istream& in){
		int tempYear;
		char tempLicenseNum[9];
		char tempLocation[64];
		cout << "Built year: ";
		cin >> tempYear;
		m_year = tempYear;
		cout << "License plate: ";
		cin >> tempLicenseNum;
		strcpy(m_licenseNum, tempLicenseNum);
		cout << "Current location: ";
		cin >> tempLocation;
		strcpy(m_address, tempLocation);
		return in;
	}
	VehicleBasic::~VehicleBasic(){

	}
	//overload insertion operator to insert a VehicleBasic into a stream
	//this operator should call write member function  in the class VehicleBasic
	std::ostream& operator<<(std::ostream& os, const VehicleBasic& V){
		return V.write(os);
	}

	//overload extraction operator to extract a VehicleBasic into a stream
	//this operator should call read member function  in the class VehicleBasic
	std::istream& operator>>(std::istream& istr, VehicleBasic& V){
		return V.read(istr);
	}

}
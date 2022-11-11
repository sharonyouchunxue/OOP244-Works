#ifndef SDDS_DUMPER_H
#define SDDS_DUMPER_H
#include <iostream>
#include "VehicleBasic.h"

namespace sdds
{
	//This class should inherit from VehicleBasic class
	//on top of data coming from the parent class
	class Dumper:public VehicleBasic{
	private:
		double m_capacity{};//the maximum weight of the cargo the Dumper can carry
		double m_currCargoLoad{};// the load cannot exceed the capacity
	public:
		Dumper() = default;
		Dumper(const char* licensePlate, int builtYear,double capacity, const char* currentCargo);
		double getCapacity()const;
		double getCurrCargoLoad()const;
		void setCapacity(double capacity);
		void setCargo(double cargo);
		bool loaddCargo(double cargo);
		bool unloadCargo();
		std::ostream& write(std::ostream& os)const;
		std::istream& read(std::istream& in);
		~Dumper();
	};
	//helper function
	std::ostream& operator<<(std::ostream& os, const Dumper& D);
	std::istream& operator>>(std::istream& istr, Dumper& D);
}
#endif
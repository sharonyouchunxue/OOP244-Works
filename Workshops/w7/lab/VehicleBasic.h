#ifndef SDDS_VEHICLEBASIC_H
#define SDDS_VEHICLEBASIC_H
#include<iostream>
namespace sdds
{
	class VehicleBasic {
	private:
		char m_licenseNum[9]{}; //size 9
		char m_address[64]{}; //size 64
		int m_year{};
	public:
		VehicleBasic() = default;
		//Set the location of the vehicle at Factory
		VehicleBasic(const char* licenseNumber, int year,const char* location = "Factory");
		void setYear(int year);
		void setLicense(const char* licenseNumber);
		void setLocation(const char* loaction);
		void NewAddress(const char* address);
		const char* getLicenseNum() const;
		const char* getAddress()const;
		const int getYear()const;
		std::ostream& write(std::ostream& os)const;
		std::istream& read(std::istream& in);
		~VehicleBasic();
	};

	std::ostream& operator<<(std::ostream& os, const VehicleBasic& V);
	std::istream& operator>>(std::istream& istr, VehicleBasic& V);

}

#endif
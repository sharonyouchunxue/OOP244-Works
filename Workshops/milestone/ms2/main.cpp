/*
*****************************************************************************
						Milestone 2
Student ID#: 127632214
Email      : cyou8@myseneca.ca
Section    : OOP244 NAA
Filename: Parking.cpp
Version 1.0
Full Name  : Chunxue You(Sharon)
Revision History
--------------------------------------------------------------------
Date      Reason
2020/11/08  Preliminary release
2020/11/09  Added printHeader function to load the dash frame format
--------------------------------------------------------------------

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. I have done all
the coding by myself and only copied the code that my professor provided to
complete my workshops and assignments.
*****************************************************************************
*/
#include "Parking.h"
#include <iostream>
using namespace sdds;
int main() {
	Parking P("ParkingData.csv"), bad1(nullptr), bad2("");
	bad1.run();
	bad2.run();
	P.run();
	std::cout << std::endl << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << std::endl << std::endl;
	P.run();
	return 0;
}
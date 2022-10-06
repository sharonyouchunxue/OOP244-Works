/*
*****************************************************************************
						Workshop 2 - part 1
Full Name  : Chunxue You
Student ID#: 127632214
Email      : cyou8@myseneca.ca
Section    : OOP244 NAA
Date       : 2022-09-24

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. I have done all
the coding by myself and only copied the code that my professor provided to
complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_
#include "File.h"

namespace sdds {
	const char* const filename = "PCpopulations.csv";
	struct PopulationData {
		char* m_postalcode;
		int m_population;
	};

	void sort();
	bool load(PopulationData& populationata);
	bool load(const char filename[]);
	void display();
	void deallocateMemory();

}
#endif // SDDS_POPULATION_H_

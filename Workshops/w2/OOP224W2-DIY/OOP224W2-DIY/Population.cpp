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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cstdio>
#include "File.h"
#include "Population.h"

using namespace std;
namespace sdds {
	int noOfPopulation = 0;
	PopulationData* populationdata = nullptr;
	void sort() {
		int i, j;
		PopulationData temp;
		for (i = noOfPopulation - 1; i > 0; i--) {
			for (j = 0; j < i; j++) {
				if (populationdata[j].m_population > populationdata[j + 1].m_population) {
					temp = populationdata[j];
					populationdata[j] = populationdata[j + 1];
					populationdata[j + 1] = temp;
				}
			}
		}
	}

	bool load(PopulationData& populationdata) {
		bool success = false;
		char tempPostalcode[128];
		int tempPopulation;
		if (read(tempPostalcode)&&read(tempPopulation)) {
			//populationdata.m_population = new int;
			populationdata.m_postalcode = new char[strlen(tempPostalcode) + 1];
			populationdata.m_population = tempPopulation;
			strcpy(populationdata.m_postalcode, tempPostalcode);
			success = true;
		}
		return success;
	}
	bool load(const char filename[]) {
		int i = 0;
		int readRec = 0;
		openFile(filename);
		noOfPopulation = noOfRecords();
		populationdata = new PopulationData[noOfPopulation];
		for (i = 0; i < noOfPopulation; i++) {
			readRec += load(populationdata[i]);
		}
		if (noOfPopulation != readRec) {
			cout << "Error: incorrect number of records read; the data is possibly corrupted!<ENDL>" << endl;
		}
		
		return noOfPopulation == readRec;
	}
	void display() {
		sort();
		cout << "Postal Code: population" << endl;
		cout << "-------------------------" << endl;
		int i;
		int sum = 0;
		for (i = 0; i < noOfPopulation; i++) {
			
			cout << i + 1 << "- " << populationdata[i].m_postalcode << ":  " << populationdata[i].m_population << endl;
			sum += populationdata[i].m_population;
		}
		
		cout << "-------------------------" << endl;
		cout << "Population of Canada: " << sum << endl;
	}
	void deallocateMemory() {
		int i;
		closeFile();
		for (i = 0; i < noOfPopulation; i++) {
			delete[] populationdata[i].m_postalcode;
			populationdata[i].m_postalcode = nullptr;
		}
		delete[] populationdata;
		populationdata = nullptr;

	}
}
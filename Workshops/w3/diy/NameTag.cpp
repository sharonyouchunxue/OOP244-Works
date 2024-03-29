/*
*****************************************************************************
                        Workshop 3 - part 2
Full Name  : Chunxue You
Student ID#: 127632214
Email      : cyou8@myseneca.ca
Section    : OOP244 NAA
Date       : 2022-09-29

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
#include "NameTag.h"

using namespace std;
namespace sdds {
	//sets the name, held by the NameTag object.
	void NameTag::set(const char* name) {
		strcpy(m_name,name);
	}
	// get name function return name
	char* NameTag::getName() {
		return m_name;
	}      
    }





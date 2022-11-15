/*
*****************************************************************************
                        Workshop 8 - part 1
Full Name  : Chunxue You(Sharon)
Student ID#: 127632214
Email      : cyou8@myseneca.ca
Section    : OOP244 NAA
Date       : 2022-11-15
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
#include "LblShape.h"

using namespace std;
namespace sdds {
    //Protected members that returns the unmodifiable value of m_label member variable.
    const char* LblShape::label() const{
        return m_label;
    }
    //One argument constructor
    //Allocates memory large enough to hold the incoming Cstring argument pointed by 
    //the m_label member variable.Then copies the Cstring argument to the newly allocated memory.
    LblShape::LblShape(const char* label){
        if (label && label[0] != '\0') {
            m_label = new char[strlen(label) + 1];
            strcpy(m_label, label);
        }
    }
    //destructor
    LblShape::~LblShape(){
        delete[] m_label;
        m_label = nullptr;
    }
    //getSpecs, override the base calss getSpecs pure vitual function
    std::istream& LblShape::getSpecs(std::istream& istr){
        char tempLabel[71]{};
        //Reads a comma-delimited Cstring form istream: 
        istr.getline(tempLabel, 71, ',');
        delete[] m_label;
        m_label = new char[strlen(tempLabel) + 1];
        strcpy(m_label, tempLabel);  
        return istr;
    }
}
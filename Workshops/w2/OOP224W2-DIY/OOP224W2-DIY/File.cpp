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
#include <cstdio>
#include "File.h"
#include "Population.h"
#include <iostream>
#include <cstring>
using namespace std;

namespace sdds {
    FILE* fptr;
    // Opens a file and keeps the file pointer in the File.cpp (file scope)
    bool openFile(const char filename[]) {
        fptr = fopen(filename, "r");
        return fptr != NULL;
    }
    // Finds and returns the number of records kept in the file 
    // to be used for the dynamic memory allocation of the records in the program
    int noOfRecords() {
        int noOfRecs = 0;
        char ch;
        while (fscanf(fptr, "%c", &ch) == 1) {
            noOfRecs += (ch == '\n');
        }
        rewind(fptr);
        return noOfRecs;
    }
    // Closes the open file
    void closeFile() {
        if (fptr) fclose(fptr);
    }

    bool read(char* m_postalcode) {
        return (fscanf(fptr, "%[^,]", m_postalcode) == 1);
       
    }
   
    bool read(int& m_population) {
        return(fscanf(fptr, ",%d\n", &m_population)==1);
       
    }
 

}
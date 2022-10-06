/*
*****************************************************************************
                        Workshop 2 - part 1
Full Name  : Chunxue You
Student ID#: 127632214
Email      : cyou8@myseneca.ca
Section    : OOP244 NAA
Date       : 2022-09-22

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. I have done all
the coding by myself and only copied the code that my professor provided to
complete my workshops and assignments.
*****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "Utils.h"
#include "Assessment.h"

//#include <fstream>
using namespace std;

namespace sdds {

    bool read(int& value, FILE* fptr) {
        std::fscanf(fptr, "%d\n", &value);
        if (value) {
            return 1;
        }
        else {
            return 0;
        }
        //return (std::fscanf(fptr, "%d", &value) == 1);
    }
    bool read(double& value, FILE* fptr) {
        std::fscanf(fptr, "%lf", &value);
        if (value) {
            return 1;
        }
        else {
            return 0;
        }
        //return (std::fscanf(fptr, "%lf", &value) == 1);
    }
    bool read(char* cstr, FILE* fptr) {
        std::fscanf(fptr, ",%60[^\n]\n", cstr);
        if (cstr) {
            return 1;
        }
        else {
            return 0;
        }
        //return (std::fscanf(fptr, ",%60[^\n]\n", cstr) == 1);
    }

    bool read(Assessment& asmnt, FILE* fptr) {
        bool success = false;
        double tempMark;
        char tempTitle[61] ;
        if (read(tempMark, fptr)&&read(tempTitle, fptr)) {
            asmnt.m_mark = new double;
            asmnt.m_title = new char[strlen(tempTitle) + 1];
            *asmnt.m_mark = tempMark;
            strcpy(asmnt.m_title, tempTitle);
            success = true;
            //success = read(asmnt.m_title, fptr);
        }
        return success;
    }

    void freeMem(Assessment*& aptr, int size) {
        int i;
        for (i = 0; i < size; i++) {
            delete aptr[i].m_mark;
            //aptr[i].m_mark = nullptr;

            delete[] aptr[i].m_title;
            //aptr[i].m_title = nullptr;
        }
            delete[] aptr;
            //aptr = nullptr;
        
    }

    //1.open file to read first line(integer number) if it's not empty print the number
    //2. read rest of line number to see if the line number is match the first line integer number.

    int read(Assessment*& aptr, FILE* fptr) {
        int assessmentRecs = 0;
        int readRec = 0;
        std::fscanf(fptr, "%d", &assessmentRecs);
        if (assessmentRecs == 13) {
            aptr = new Assessment[assessmentRecs];
            bool count = true;
            for (int i = 0; i < 13 && count; i++) {
                if (read(aptr[i], fptr)) {
                    count = true;
                    readRec++;
                }
                else {
                    count = false;
                }
            }
        
        }
        //if (readRec < assessmentRecs) {
         //   freeMem(aptr, readRec);
           // readRec = 0;
        //}
        return readRec;
    }
}


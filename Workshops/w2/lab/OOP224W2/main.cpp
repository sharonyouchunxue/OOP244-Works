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
#include <cstdio>
#include <iostream>
#include "Assessment.h"
#include "Utils.h"
using namespace sdds;
using namespace std;
void display(const Assessment& a);
bool readTesters();
int main() {
    if (readTesters()) {
        int cnt;
        Assessment* aptr = nullptr;
        FILE* fptr = fopen("baddata.txt", "r");
        cnt = read(aptr, fptr);
        if (cnt) {
            cout << "This should have failed, keep working on the workshop!" << endl;
            
        }
        else {
            cout << "File records and number of records do not match" << endl;
         
        }
        fclose(fptr);
        cout << "Listing Good Data:" << endl;
        fptr = fopen("gooddata.txt", "r");
        cnt = read(aptr, fptr);
        if (cnt) {
            for (int i = 0; i < cnt; i++) {
                cout << (i + 1) << ": ";
                display(aptr[i]);
            }
            freeMem(aptr, cnt);
        }
        else {
            cout << "This should not have failed, keep working on the workshop!" << endl;
        }
        fclose(fptr);
    }
    return 0;
}
void display(const Assessment& a) {
    cout.setf(ios::fixed);// setting the number of digits
    cout.precision(1);    // after the decimal point to 1
                          // this will be covered later
    cout << a.m_title << ": " << *a.m_mark << endl;
}

bool readTesters() {
    FILE* fptr = fopen("gooddata.txt", "r");
    bool passed = true;
    int i;
    double d;
    char str[61];
    if (read(i, fptr) && i == 13) {
        cout << "bool read(int& value, FILE* fptr) test passed" << endl;
    }
    else {
        cout << "bool read(int& value, FILE* fptr) test failed" << endl;
        passed = false;
    }
    if (passed && read(d, fptr) && (d - 70.9) < 0.0001 && (d - 70.9) > -0.0001) {
        cout << "bool read(double& value, FILE* fptr) test passed" << endl;
    }
    else {
        cout << "bool read(double& value, FILE* fptr) test failed" << endl;
        passed = false;
    }
    if (passed && read(str, fptr) && sdds::strcmp(str, "Applied Problem Solving") == 0) {
        cout << "bool read(double& value, FILE* fptr) test passed" << endl;
    }
    else {
        cout << "bool read(double& value, FILE* fptr) test failed" << endl;
        passed = false;
    }
    fclose(fptr);
    return passed;
}
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
#include "Population.h"
using namespace sdds;
// The Load, display and deallocateMemory functions are the mandatory 
// function to be created in part 2 of the lab

int main() {
    // if loading of the population recrods into the dynamic memroy is successful
    if (load("PCpopulations.csv")) {
        // display all the records
        display();
    }
    // in any case delete the dynmaic memory if it is allocated
    deallocateMemory();
    return 0;
}
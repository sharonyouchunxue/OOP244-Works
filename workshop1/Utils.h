#pragma once
/*
*****************************************************************************
                        Workshop 1 - part 1
Full Name  : Chunxue You
Student ID#: 127632214
Email      : cyou8@myseneca.ca
Section    : OOP244 NAA
Date       : 2022-09-12

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. I have done all
the coding by myself and only copied the code that my professor provided to
complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_UTILS_H// replace with relevant names
#define SDDS_UTILS_H

namespace sdds {

    void flushkeys();
    bool ValidYesResponse(char ch);
    bool yes();
    void readCstr(char cstr[], int len);
    int readInt(int min, int max);


}
#endif

